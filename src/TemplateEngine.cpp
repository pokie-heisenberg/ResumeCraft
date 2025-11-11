#include "../include/TemplateEngine.h"
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>

namespace ResumeCraft {

TemplateEngine::TemplateEngine(QString baseDir)
    : m_baseDir(baseDir.isEmpty() ? resolveTemplatesDir() : baseDir) {}

QString TemplateEngine::resolveTemplatesDir(const QString &hint) {
    if (!hint.isEmpty()) return hint;

    QStringList candidates;
    const QString appDir = QCoreApplication::applicationDirPath();
    candidates << (appDir + "/ui/templates");
    candidates << (appDir + "/../ui/templates");
    candidates << (appDir + "/../../ui/templates");

    // Also consider running from source
    candidates << (QDir::currentPath() + "/ui/templates");

    for (const auto &c : candidates) {
        if (QDir(c).exists()) return c;
    }
    return QDir::currentPath();
}

QString TemplateEngine::loadTemplate(const QString &templateName) const {
    const QString path = QDir(m_baseDir).filePath(templateName + ".html");
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return QString("<html><body><p>Failed to load template: %1</p></body></html>").arg(path.toHtmlEscaped());
    }
    QTextStream in(&f);
    return in.readAll();
}

QString TemplateEngine::render(const QString &templateName, const QMap<QString, QString> &context, const QString & /*baseUrlDir*/) const {
    QString html = loadTemplate(templateName);
    for (auto it = context.constBegin(); it != context.constEnd(); ++it) {
        const QString placeholder = QString("{{%1}}").arg(it.key());
        html.replace(placeholder, it.value());
    }
    return html;
}

}
