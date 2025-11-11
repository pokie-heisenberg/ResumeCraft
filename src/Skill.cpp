#include "../include/Skill.h"

namespace ResumeCraft {

QString Skill::toHtml() const {
    if (m_level >= 0) {
        return QString("<div class=\"skill\"><span class=\"name\">%1</span><div class=\"bar\"><div class=\"fill\" style=\"width:%2%%\"></div></div></div>")
            .arg(m_name.toHtmlEscaped()).arg(m_level);
    }
    return QString("<div class=\"skill\"><span class=\"name\">%1</span></div>").arg(m_name.toHtmlEscaped());
}

}
