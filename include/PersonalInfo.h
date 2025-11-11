#pragma once
#include <QString>

namespace ResumeCraft {

class PersonalInfo {
public:
    PersonalInfo() = default;

    const QString &name() const { return m_name; }
    const QString &email() const { return m_email; }
    const QString &phone() const { return m_phone; }
    const QString &address() const { return m_address; }
    const QString &summary() const { return m_summary; }
    const QString &photoPath() const { return m_photoPath; }

    void setName(const QString &name);
    void setEmail(const QString &email);
    void setPhone(const QString &phone);
    void setAddress(const QString &address);
    void setSummary(const QString &summary);
    void setPhotoPath(const QString &path);

    bool isValid(QString *errorMessage = nullptr) const;

private:
    QString m_name;
    QString m_email;
    QString m_phone;
    QString m_address;
    QString m_summary;
    QString m_photoPath;
};

}
