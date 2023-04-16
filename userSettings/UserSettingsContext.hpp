#pragma once

#include "UserSettingsItem.hpp"

class UserSettingsContext {
public:
    UserSettingsContext();
    virtual ~UserSettingsContext() = default;

    QVector<UserSettingsItem> getMenus();

private:
    QVector<UserSettingsItem> m_menus;
};
