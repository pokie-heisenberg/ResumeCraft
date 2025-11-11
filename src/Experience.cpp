#include "../include/Experience.h"

namespace ResumeCraft {

QString Experience::toHtml() const {
    QString html;
    html += "<div class=\"exp-item\">";
    html += "<div class=\"row\"><span class=\"role\">" + m_role.toHtmlEscaped() + "</span>";
    html += "<span class=\"company\">" + m_company.toHtmlEscaped() + "</span>";
    html += "<span class=\"period\">" + m_period.toHtmlEscaped() + "</span></div>";
    if (!m_details.trimmed().isEmpty()) {
        html += "<div class=\"details\">" + m_details.toHtmlEscaped().replace("\n", "<br/>") + "</div>";
    }
    html += "</div>";
    return html;
}

}
