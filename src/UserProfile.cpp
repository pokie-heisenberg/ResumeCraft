#include "../include/UserProfile.h"

namespace ResumeCraft {

void UserProfile::addEducation(const Education &edu) { m_educations.push_back(edu); }
void UserProfile::addExperience(const Experience &exp) { m_experiences.push_back(exp); }
void UserProfile::addSkill(const Skill &skill) { m_skills.push_back(skill); }

QString UserProfile::educationSectionHtml() const {
    QString html;
    if (m_educations.isEmpty()) return html;
    html += "<section id=\"education\"><h2>Education</h2>";
    for (const auto &e : m_educations) html += e.toHtml();
    html += "</section>";
    return html;
}

QString UserProfile::experienceSectionHtml() const {
    QString html;
    if (m_experiences.isEmpty()) return html;
    html += "<section id=\"experience\"><h2>Experience</h2>";
    for (const auto &e : m_experiences) html += e.toHtml();
    html += "</section>";
    return html;
}

QString UserProfile::skillsSectionHtml() const {
    QString html;
    if (m_skills.isEmpty()) return html;
    html += "<section id=\"skills\"><h2>Skills</h2><div class=\"skills\">";
    for (const auto &s : m_skills) html += s.toHtml();
    html += "</div></section>";
    return html;
}

}
