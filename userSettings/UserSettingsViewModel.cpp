#include "UserSettingsViewModel.hpp"

#include <iostream>

UserSettingsViewModel::UserSettingsViewModel(QObject* parent)
    : QObject(parent)
{
    m_userSettingsContext = std::make_shared<UserSettingsContext>();

    m_itemModel = QSharedPointer<UserSettingsItemModel>::create();
    m_itemModel->setItems(m_userSettingsContext->getMenus());

    for (const auto& menu : m_userSettingsContext->getMenus())
    {
        for (const auto& value : menu.childrenModel->getItems())
            ;
    }
}

QSharedPointer<UserSettingsItemModel> UserSettingsViewModel::getItemModel()
{
    return m_itemModel;
}

void UserSettingsViewModel::onSettingChanged(QString settingId, QString settingValue)
{
    std::cout << __FUNCTION__ << ": settingId = " << settingId.toStdString() << " settingValue = " << settingValue.toStdString() << std::endl;
}
