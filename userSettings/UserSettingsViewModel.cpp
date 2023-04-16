#include "UserSettingsViewModel.hpp"

UserSettingsViewModel::UserSettingsViewModel(QObject* parent) : QObject(parent)
{
    m_userSettingsContext = std::make_shared<UserSettingsContext>();

    m_itemModel = QSharedPointer<UserSettingsItemModel>::create();
    m_itemModel->setItems(m_userSettingsContext->getMenus());
}

QSharedPointer<UserSettingsItemModel> UserSettingsViewModel::getItemModel()
{
    return m_itemModel;
}
