#include "UserSettingsViewModel.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

UserSettingsViewModel::UserSettingsViewModel(QObject* parent)
    : QObject(parent)
{
    m_userSettingsContext = std::make_shared<UserSettingsContext>();

    m_itemModel = QSharedPointer<UserSettingsItemModel>::create();
    m_itemModel->setItems(m_userSettingsContext->getMenus());

    for (auto& menu : m_userSettingsContext->getMenus())
    {
        for (auto& value : menu.valueModel->getItems())
        {
            m_settings.emplace(value.settingId.toStdString(), "");
        }
    }
}

QSharedPointer<UserSettingsItemModel> UserSettingsViewModel::getItemModel()
{
    return m_itemModel;
}

void UserSettingsViewModel::onSettingChanged(QString settingId, QString settingValue)
{
    std::cout << __FUNCTION__ << ": settingId = " << settingId.toStdString() << " settingValue = " << settingValue.toStdString() << std::endl;
    m_settings.emplace(settingId.toStdString(), settingValue.toStdString());
}

void UserSettingsViewModel::onSave()
{
    int ncols = 100;
    int lcols = 30;
    int rcols = ncols - lcols - 5;

    json userSettings;

    std::cout << std::string(ncols, '-') << std::endl;
    std::cout << "|" << std::setw(lcols) << "Setting Id"
              << " |" << std::setw(rcols) << "Setting Value"
              << " |" << std::endl;
    std::cout << std::string(ncols, '-') << std::endl;
    for (const auto& setting : m_settings)
    {
        userSettings[setting.first] = setting.second;
        std::cout << "|" << std::setw(lcols) << setting.first << " |" << std::setw(rcols) << setting.second << " |" << std::endl;
        std::cout << std::string(ncols, '-') << std::endl;
    }

    std::ofstream ofs(SETTINGS_FILENAME, std::ofstream::out);
    ofs << std::setw(4) << userSettings << std::endl;

    ofs.close();
}
