#pragma once

#include "UserSettingsItem.hpp"

class UserSettingsContext {
public:
    UserSettingsContext();
    virtual ~UserSettingsContext() = default;

private:
    QVector<UserSettingsItem> m_menus;
};
