#pragma once
#include <QString>
#include <QMap>

namespace ResumeCraft {

class TemplateEngine {
public:
    explicit TemplateEngine(QString baseDir = QString());

    QString loadTemplate(const QString &templateName) const; // e.g., "classic", "modern", "minimal"
    QString render(const QString &templateName, const QMap<QString, QString> &context, const QString &baseUrlDir = QString()) const;

    static QString resolveTemplatesDir(const QString &hint = QString());

private:
    QString m_baseDir;
};

}
