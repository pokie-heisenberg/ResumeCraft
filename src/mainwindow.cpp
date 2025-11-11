#include "../include/MainWindow.h"
#include "../include/PDFExporter.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QUrl>
#include <QHeaderView>
#include <QIcon>
#include <algorithm>

namespace ResumeCraft {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_engine(TemplateEngine::resolveTemplatesDir()) {
    ui->setupUi(this);

    m_preview = ui->previewBrowser;
    m_preview->setOpenExternalLinks(true);

    if (ui->templateCombo->count() == 0) {
        ui->templateCombo->addItem("Classic", "classic");
        ui->templateCombo->addItem("Modern", "modern");
        ui->templateCombo->addItem("Minimal", "minimal");
    }
    ui->templateCombo->setCurrentIndex(0);

    // Configure tables
    ui->eduTable->setColumnCount(4);
    ui->eduTable->setHorizontalHeaderLabels({"School", "Degree", "Period", "Details"});
    ui->eduTable->horizontalHeader()->setStretchLastSection(true);

    ui->expTable->setColumnCount(4);
    ui->expTable->setHorizontalHeaderLabels({"Role", "Company", "Period", "Details"});
    ui->expTable->horizontalHeader()->setStretchLastSection(true);

    ui->skillTable->setColumnCount(2);
    ui->skillTable->setHorizontalHeaderLabels({"Skill", "Level (0-100)"});
    ui->skillTable->horizontalHeader()->setStretchLastSection(true);

    // Set button icons (look for ui/icons next to templates dir)
    const QString templatesDir = TemplateEngine::resolveTemplatesDir();
    const QString iconsDir = QDir(QDir(templatesDir).filePath("..")).filePath("icons");
    if (QDir(iconsDir).exists()) {
        ui->generateButton->setIcon(QIcon(QDir(iconsDir).filePath("play.svg")));
        ui->exportHtmlButton->setIcon(QIcon(QDir(iconsDir).filePath("html.svg")));
        ui->exportPdfButton->setIcon(QIcon(QDir(iconsDir).filePath("pdf.svg")));
    }

    bindSignals();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::bindSignals() {
    connect(ui->generateButton, &QPushButton::clicked, this, &MainWindow::onGenerate);
    connect(ui->exportPdfButton, &QPushButton::clicked, this, &MainWindow::onExportPdf);
    connect(ui->exportHtmlButton, &QPushButton::clicked, this, &MainWindow::onExportHtml);
    connect(ui->templateCombo, qOverload<int>(&QComboBox::currentIndexChanged), this, &MainWindow::onTemplateChanged);
    connect(ui->addEduButton, &QPushButton::clicked, this, &MainWindow::onAddEducation);
    connect(ui->removeEduButton, &QPushButton::clicked, this, &MainWindow::onRemoveEducation);
    connect(ui->addExpButton, &QPushButton::clicked, this, &MainWindow::onAddExperience);
    connect(ui->removeExpButton, &QPushButton::clicked, this, &MainWindow::onRemoveExperience);
    connect(ui->addSkillButton, &QPushButton::clicked, this, &MainWindow::onAddSkill);
    connect(ui->removeSkillButton, &QPushButton::clicked, this, &MainWindow::onRemoveSkill);
    connect(ui->browsePhotoButton, &QPushButton::clicked, this, &MainWindow::onBrowsePhoto);
}

QString MainWindow::assetsBaseDir() const {
    const QString appDir = QCoreApplication::applicationDirPath();
    QStringList candidates;
    candidates << QDir(appDir).absolutePath();
    candidates << QDir(appDir).absoluteFilePath("..");
    candidates << QDir(appDir).absoluteFilePath("../..");
    candidates << QDir::currentPath();

    for (const auto &c : candidates) {
        if (QDir(QDir(c).filePath("assets")).exists()) return c;
    }
    return QDir::currentPath();
}

void MainWindow::updateProfileFromForm() {
    m_profile = UserProfile();

    m_profile.personalInfo().setName(ui->nameEdit->text());
    m_profile.personalInfo().setEmail(ui->emailEdit->text());
    m_profile.personalInfo().setPhone(ui->phoneEdit->text());
    m_profile.personalInfo().setAddress(ui->addressEdit->text());
    m_profile.personalInfo().setSummary(ui->summaryEdit->toPlainText());
    m_profile.personalInfo().setPhotoPath(ui->photoPathEdit->text());

    for (int r = 0; r < ui->eduTable->rowCount(); ++r) {
        const QString school = ui->eduTable->item(r,0) ? ui->eduTable->item(r,0)->text() : QString();
        const QString degree = ui->eduTable->item(r,1) ? ui->eduTable->item(r,1)->text() : QString();
        const QString period = ui->eduTable->item(r,2) ? ui->eduTable->item(r,2)->text() : QString();
        const QString details = ui->eduTable->item(r,3) ? ui->eduTable->item(r,3)->text() : QString();
        if (!school.trimmed().isEmpty() || !degree.trimmed().isEmpty() || !period.trimmed().isEmpty() || !details.trimmed().isEmpty())
            m_profile.addEducation(Education(school, degree, period, details));
    }

    for (int r = 0; r < ui->expTable->rowCount(); ++r) {
        const QString role = ui->expTable->item(r,0) ? ui->expTable->item(r,0)->text() : QString();
        const QString company = ui->expTable->item(r,1) ? ui->expTable->item(r,1)->text() : QString();
        const QString period = ui->expTable->item(r,2) ? ui->expTable->item(r,2)->text() : QString();
        const QString details = ui->expTable->item(r,3) ? ui->expTable->item(r,3)->text() : QString();
        if (!role.trimmed().isEmpty() || !company.trimmed().isEmpty() || !period.trimmed().isEmpty() || !details.trimmed().isEmpty())
            m_profile.addExperience(Experience(role, company, period, details));
    }

    for (int r = 0; r < ui->skillTable->rowCount(); ++r) {
        const QString sk = ui->skillTable->item(r,0) ? ui->skillTable->item(r,0)->text() : QString();
        int level = -1;
        if (auto *it = ui->skillTable->item(r,1)) {
            bool ok=false; const int v = it->text().toInt(&ok);
            if (ok) level = std::clamp(v, 0, 100);
        }
        if (!sk.trimmed().isEmpty()) m_profile.addSkill(Skill(sk, level));
    }
}

void MainWindow::onBrowsePhoto() {
    const QString file = QFileDialog::getOpenFileName(this, "Choose Photo", QDir::homePath(),
                                                     "Images (*.png *.jpg *.jpeg *.bmp *.gif *.webp)");
    if (file.isEmpty()) return;
    ui->photoPathEdit->setText(file);
    onGenerate();
}

bool MainWindow::validateForm() {
    QString err;
    if (!m_profile.personalInfo().isValid(&err)) {
        QMessageBox::warning(this, "Validation", err);
        return false;
    }
    return true;
}

QString MainWindow::selectedTemplateKey() const {
    return ui->templateCombo->currentData().toString();
}

void MainWindow::showHtml(const QString &html, const QString &baseDir) {
    // Ensure relative assets (css/images) resolve
    if (m_preview && m_preview->document()) {
        m_preview->document()->setBaseUrl(QUrl::fromLocalFile(baseDir + "/"));
    }
    m_preview->setHtml(html);
}

void MainWindow::onGenerate() {
    updateProfileFromForm();
    if (!validateForm()) return;

    const QString baseDir = assetsBaseDir();

    QMap<QString, QString> ctx;
    ctx.insert("name", m_profile.personalInfo().name().toHtmlEscaped());
    ctx.insert("email", m_profile.personalInfo().email().toHtmlEscaped());
    ctx.insert("phone", m_profile.personalInfo().phone().toHtmlEscaped());
    ctx.insert("address", m_profile.personalInfo().address().toHtmlEscaped());
    ctx.insert("summary", m_profile.personalInfo().summary().toHtmlEscaped().replace("\n", "<br/>"));
    // photo: if set, prefer relative path to baseDir/assets or baseDir; else use file URL
    QString photoTag;
    const QString photoPath = m_profile.personalInfo().photoPath();
    if (!photoPath.trimmed().isEmpty()) {
        QString src;
        const QString baseDir = assetsBaseDir();
        const QString rel = QDir(baseDir).relativeFilePath(photoPath);
        if (!rel.startsWith("..")) {
            src = rel;
        } else {
            src = QUrl::fromLocalFile(photoPath).toString();
        }
        photoTag = QString("<img src=\"%1\" alt=\"Photo\" style=\"width:110px;height:110px;border-radius:50%%;object-fit:cover;float:right;margin:-10px 0 8px 12px;\">")
                       .arg(src.toHtmlEscaped());
    }
    ctx.insert("photo", photoTag);
    ctx.insert("education_section", m_profile.educationSectionHtml());
    ctx.insert("experience_section", m_profile.experienceSectionHtml());
    ctx.insert("skills_section", m_profile.skillsSectionHtml());
    ctx.insert("styles", QString("<link rel=\"stylesheet\" href=\"%1\">")
              .arg(QDir(baseDir).relativeFilePath(QDir(baseDir).filePath("assets/styles.css")).toHtmlEscaped()));

    const QString html = m_engine.render(selectedTemplateKey(), ctx, baseDir);
    showHtml(html, baseDir);
}

void MainWindow::onExportHtml() {
    onGenerate();
    const QString file = QFileDialog::getSaveFileName(this, "Export HTML", QDir::homePath() + "/resume.html", "HTML Files (*.html *.htm)");
    if (file.isEmpty()) return;

    const QString baseDir = assetsBaseDir();

    QMap<QString, QString> ctx;
    ctx.insert("name", m_profile.personalInfo().name().toHtmlEscaped());
    ctx.insert("email", m_profile.personalInfo().email().toHtmlEscaped());
    ctx.insert("phone", m_profile.personalInfo().phone().toHtmlEscaped());
    ctx.insert("address", m_profile.personalInfo().address().toHtmlEscaped());
    ctx.insert("summary", m_profile.personalInfo().summary().toHtmlEscaped().replace("\n", "<br/>"));
    // photo tag for export HTML
    {
        QString photoTag;
        const QString photoPath = m_profile.personalInfo().photoPath();
        if (!photoPath.trimmed().isEmpty()) {
            QString src;
            const QString baseDir2 = assetsBaseDir();
            const QString rel = QDir(baseDir2).relativeFilePath(photoPath);
            if (!rel.startsWith("..")) src = rel; else src = QUrl::fromLocalFile(photoPath).toString();
            photoTag = QString("<img src=\"%1\" alt=\"Photo\" style=\"width:110px;height:110px;border-radius:50%%;object-fit:cover;float:right;margin:-10px 0 8px 12px;\">").arg(src.toHtmlEscaped());
        }
        ctx.insert("photo", photoTag);
    }
    ctx.insert("education_section", m_profile.educationSectionHtml());
    ctx.insert("experience_section", m_profile.experienceSectionHtml());
    ctx.insert("skills_section", m_profile.skillsSectionHtml());
    ctx.insert("styles", QString("<link rel=\"stylesheet\" href=\"assets/styles.css\">"));

    const QString html = m_engine.render(selectedTemplateKey(), ctx, baseDir);

    QFile f(file);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Export", "Failed to write file.");
        return;
    }
    QTextStream out(&f);
    out << html;
    f.close();
    QMessageBox::information(this, "Export", "Exported HTML successfully.");
}

void MainWindow::onExportPdf() {
    onGenerate();

    const QString file = QFileDialog::getSaveFileName(this, "Export PDF", QDir::homePath() + "/resume.pdf", "PDF Files (*.pdf)");
    if (file.isEmpty()) return;

    const QString baseDir = assetsBaseDir();

    QMap<QString, QString> ctx;
    ctx.insert("name", m_profile.personalInfo().name().toHtmlEscaped());
    ctx.insert("email", m_profile.personalInfo().email().toHtmlEscaped());
    ctx.insert("phone", m_profile.personalInfo().phone().toHtmlEscaped());
    ctx.insert("address", m_profile.personalInfo().address().toHtmlEscaped());
    ctx.insert("summary", m_profile.personalInfo().summary().toHtmlEscaped().replace("\n", "<br/>"));
    ctx.insert("education_section", m_profile.educationSectionHtml());
    ctx.insert("experience_section", m_profile.experienceSectionHtml());
    ctx.insert("skills_section", m_profile.skillsSectionHtml());
    ctx.insert("styles", QString("<link rel=\"stylesheet\" href=\"assets/styles.css\">"));

    const QString html = m_engine.render(selectedTemplateKey(), ctx, baseDir);

    QString err;
    if (!PDFExporter::exportHtmlToPdf(html, file, baseDir, &err)) {
        QMessageBox::warning(this, "Export PDF", err.isEmpty() ? "Failed to export PDF." : err);
        return;
    }
    QMessageBox::information(this, "Export PDF", "Exported PDF successfully.");
}

void MainWindow::onTemplateChanged(int) {
    onGenerate();
}

void MainWindow::onAddEducation() {
    const int r = ui->eduTable->rowCount();
    ui->eduTable->insertRow(r);
}

void MainWindow::onRemoveEducation() {
    const int r = ui->eduTable->currentRow();
    if (r >= 0) ui->eduTable->removeRow(r);
}

void MainWindow::onAddExperience() {
    const int r = ui->expTable->rowCount();
    ui->expTable->insertRow(r);
}

void MainWindow::onRemoveExperience() {
    const int r = ui->expTable->currentRow();
    if (r >= 0) ui->expTable->removeRow(r);
}

void MainWindow::onAddSkill() {
    const int r = ui->skillTable->rowCount();
    ui->skillTable->insertRow(r);
}

void MainWindow::onRemoveSkill() {
    const int r = ui->skillTable->currentRow();
    if (r >= 0) ui->skillTable->removeRow(r);
}

}
