#pragma once
#include <QString>

namespace ResumeCraft {

class Skill {
public:
    Skill() = default;
    explicit Skill(QString name, int level = -1) : m_name(std::move(name)), m_level(level) {}

    const QString &name() const { return m_name; }
    int level() const { return m_level; } // 0-100 or -1 unknown

    void setName(const QString &n) { m_name = n; }
    void setLevel(int l) { m_level = l; }

    QString toHtml() const;

private:
    QString m_name;
    int m_level = -1;
};

}
