#pragma once

#include "UserSettingsItem.hpp"

class UserSettingsContext {
public:
    UserSettingsContext();
    virtual ~UserSettingsContext() = default;

    QVector<UserSettingsItem> getMenus();

    void saveToJson(std::map<std::string, std::string> settings);

private:
    std::map<std::string, std::string> loadFromJson();

    void createMenus(std::map<std::string, std::string> settings);

    QVector<UserSettingsItem> m_menus;

    const std::string SETTINGS_FILENAME{"userSettings.json"};
};
