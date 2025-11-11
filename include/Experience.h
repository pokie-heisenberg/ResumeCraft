#pragma once
#include <QString>

namespace ResumeCraft {

class Experience {
public:
    Experience() = default;
    Experience(QString role, QString company, QString period, QString details)
        : m_role(std::move(role)), m_company(std::move(company)), m_period(std::move(period)), m_details(std::move(details)) {}

    const QString &role() const { return m_role; }
    const QString &company() const { return m_company; }
    const QString &period() const { return m_period; }
    const QString &details() const { return m_details; }

    void setRole(const QString &r) { m_role = r; }
    void setCompany(const QString &c) { m_company = c; }
    void setPeriod(const QString &p) { m_period = p; }
    void setDetails(const QString &d) { m_details = d; }

    QString toHtml() const;

private:
    QString m_role;
    QString m_company;
    QString m_period;
    QString m_details;
};

}
