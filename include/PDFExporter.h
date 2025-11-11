#pragma once
#include <QString>

namespace ResumeCraft {

class PDFExporter {
public:
    static bool exportHtmlToPdf(const QString &html, const QString &outputFile, const QString &baseUrlDir = QString(), QString *error = nullptr);
};

}
