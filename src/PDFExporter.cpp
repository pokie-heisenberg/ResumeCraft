#include "../include/PDFExporter.h"
#include <QPrinter>
#include <QTextDocument>
#include <QFileInfo>
#include <QUrl>
#include <QMarginsF>

namespace ResumeCraft {

bool PDFExporter::exportHtmlToPdf(const QString &html, const QString &outputFile, const QString &baseUrlDir, QString *error) {
    QPrinter printer; // Qt 6: use default constructor
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(outputFile);
    printer.setPageMargins(QMarginsF(10, 10, 10, 10));

    QTextDocument doc;
    if (!baseUrlDir.isEmpty()) {
        doc.setBaseUrl(QUrl::fromLocalFile(baseUrlDir + "/"));
    }
    doc.setHtml(html);

    try {
        doc.print(&printer);
    } catch (...) {
        if (error) *error = QStringLiteral("Failed to render PDF.");
        return false;
    }

    return QFileInfo::exists(outputFile);
}

}
