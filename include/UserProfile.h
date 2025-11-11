#pragma once
#include <QString>
#include <QVector>
#include "PersonalInfo.h"
#include "Education.h"
#include "Experience.h"
#include "Skill.h"

namespace ResumeCraft {

class UserProfile {
public:
    PersonalInfo &personalInfo() { return m_personal; }
    const PersonalInfo &personalInfo() const { return m_personal; }

    void addEducation(const Education &edu);
    void addExperience(const Experience &exp);
    void addSkill(const Skill &skill);

    const QVector<Education> &educations() const { return m_educations; }
    const QVector<Experience> &experiences() const { return m_experiences; }
    const QVector<Skill> &skills() const { return m_skills; }

    QString educationSectionHtml() const;
    QString experienceSectionHtml() const;
    QString skillsSectionHtml() const;

private:
    PersonalInfo m_personal;
    QVector<Education> m_educations;
    QVector<Experience> m_experiences;
    QVector<Skill> m_skills;
};

}
