#pragma once
#include <QString>

namespace ResumeCraft {

class Education {
public:
    Education() = default;
    Education(QString school, QString degree, QString period, QString details)
        : m_school(std::move(school)), m_degree(std::move(degree)), m_period(std::move(period)), m_details(std::move(details)) {}

    const QString &school() const { return m_school; }
    const QString &degree() const { return m_degree; }
    const QString &period() const { return m_period; }
    const QString &details() const { return m_details; }

    void setSchool(const QString &s) { m_school = s; }
    void setDegree(const QString &d) { m_degree = d; }
    void setPeriod(const QString &p) { m_period = p; }
    void setDetails(const QString &d) { m_details = d; }

    QString toHtml() const;

private:
    QString m_school;
    QString m_degree;
    QString m_period;
    QString m_details;
};

}
