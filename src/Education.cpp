#include "../include/Education.h"

namespace ResumeCraft {

QString Education::toHtml() const {
    QString html;
    html += "<div class=\"edu-item\">";
    html += "<div class=\"row\"><span class=\"degree\">" + m_degree.toHtmlEscaped() + "</span>";
    html += "<span class=\"school\">" + m_school.toHtmlEscaped() + "</span>";
    html += "<span class=\"period\">" + m_period.toHtmlEscaped() + "</span></div>";
    if (!m_details.trimmed().isEmpty()) {
        html += "<div class=\"details\">" + m_details.toHtmlEscaped().replace("\n", "<br/>") + "</div>";
    }
    html += "</div>";
    return html;
}

}
