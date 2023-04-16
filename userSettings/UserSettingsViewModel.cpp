#include "UserSettingsViewModel.hpp"

UserSettingsViewModel::UserSettingsViewModel(QObject* parent) : QObject(parent)
{
    UserSettingsItem userInfo;
    userInfo.settingId = "User Info";
    userInfo.settingType = UserSettingsItem::SettingType::Menu;
    userInfo.childrenModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> userInfoItems{{"First Name", UserSettingsItem::SettingType::Value},
                                            {"Last Name", UserSettingsItem::SettingType::Value},
                                            {"BSH Email", UserSettingsItem::SettingType::Value}};
    userInfo.childrenModel->setItems(userInfoItems);

    UserSettingsItem projectInfo;
    projectInfo.settingId = "Project Info";
    projectInfo.settingType = UserSettingsItem::SettingType::Menu;
    projectInfo.childrenModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> projectInfoItems{{"Full Name", UserSettingsItem::SettingType::Value},
                                               {"Short Name", UserSettingsItem::SettingType::Value},
                                               {"GitHub Repo", UserSettingsItem::SettingType::Value},
                                               {"Jira Project", UserSettingsItem::SettingType::Value}};
    projectInfo.childrenModel->setItems(projectInfoItems);

    QVector<UserSettingsItem> items{userInfo, projectInfo};

    m_itemModel = QSharedPointer<UserSettingsItemModel>::create();
    m_itemModel->setItems(items);
}

QSharedPointer<UserSettingsItemModel> UserSettingsViewModel::getItemModel()
{
    return m_itemModel;
}
