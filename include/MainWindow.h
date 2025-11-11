#pragma once
#include <QMainWindow>
#include <QScopedPointer>
#include <QMap>
#include <QTextBrowser>
#include <QTableWidget>
#include <QComboBox>
#include "UserProfile.h"
#include "TemplateEngine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace ResumeCraft {

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onGenerate();
    void onExportPdf();
    void onExportHtml();
    void onTemplateChanged(int index);
    void onAddEducation();
    void onRemoveEducation();
    void onAddExperience();
    void onRemoveExperience();
    void onAddSkill();
    void onRemoveSkill();
    void onBrowsePhoto();

private:
    void bindSignals();
    void updateProfileFromForm();
    bool validateForm();
    void showHtml(const QString &html, const QString &baseDir);
    QString selectedTemplateKey() const;
    QString assetsBaseDir() const;

private:
    Ui::MainWindow *ui;
    QTextBrowser *m_preview;
    TemplateEngine m_engine;
    UserProfile m_profile;
};

}
