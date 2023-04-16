#include "UserSettingsContext.hpp"

#include "UserSettingsItemModel.hpp"

UserSettingsContext::UserSettingsContext()
{
    UserSettingsItem leaderInfo;
    leaderInfo.settingId = "Leader Info";
    leaderInfo.settingType = UserSettingsItem::SettingType::Menu;
    leaderInfo.childrenModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> leaderInfoItems{{"First Name", UserSettingsItem::SettingType::Value},
                                              {"BSH Email", UserSettingsItem::SettingType::Value}};
    leaderInfo.childrenModel->setItems(leaderInfoItems);

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

    UserSettingsItem tokenInfo;
    tokenInfo.settingId = "Token Info";
    tokenInfo.settingType = UserSettingsItem::SettingType::Menu;
    tokenInfo.childrenModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> tokenInfoItems{{"GitHub Token", UserSettingsItem::SettingType::Value},
                                             {"Jira Token", UserSettingsItem::SettingType::Value}};
    tokenInfo.childrenModel->setItems(tokenInfoItems);

    m_menus = {leaderInfo, userInfo, projectInfo, tokenInfo};
}

QVector<UserSettingsItem> UserSettingsContext::getMenus()
{
    return m_menus;
}
