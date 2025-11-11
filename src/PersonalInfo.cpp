#include "../include/PersonalInfo.h"
#include <QRegularExpression>

namespace ResumeCraft {

void PersonalInfo::setName(const QString &name) { m_name = name.trimmed(); }
void PersonalInfo::setEmail(const QString &email) { m_email = email.trimmed(); }
void PersonalInfo::setPhone(const QString &phone) { m_phone = phone.trimmed(); }
void PersonalInfo::setAddress(const QString &address) { m_address = address.trimmed(); }
void PersonalInfo::setSummary(const QString &summary) { m_summary = summary.trimmed(); }
void PersonalInfo::setPhotoPath(const QString &path) { m_photoPath = path.trimmed(); }

bool PersonalInfo::isValid(QString *errorMessage) const {
    if (m_name.isEmpty()) {
        if (errorMessage) *errorMessage = "Name is required.";
        return false;
    }
    if (m_email.isEmpty()) {
        if (errorMessage) *errorMessage = "Email is required.";
        return false;
    }
    QRegularExpression re("^[^@\n]+@[^@\n]+\\.[^@\n]+$");
    if (!re.match(m_email).hasMatch()) {
        if (errorMessage) *errorMessage = "Email format is invalid.";
        return false;
    }
    return true;
}

}
