#include "UserSettingsContext.hpp"

#include "UserSettingsItemModel.hpp"

UserSettingsContext::UserSettingsContext()
{
    UserSettingsItem leaderInfo;
    leaderInfo.settingId = "Leader Info";
    leaderInfo.childrenModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> leaderInfoItems{{"First Name"}, {"BSH Email"}};
    leaderInfo.childrenModel->setItems(leaderInfoItems);

    UserSettingsItem userInfo;
    userInfo.settingId = "User Info";
    userInfo.childrenModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> userInfoItems{{"First Name"}, {"Last Name"}, {"BSH Email"}};
    userInfo.childrenModel->setItems(userInfoItems);

    UserSettingsItem projectInfo;
    projectInfo.settingId = "Project Info";
    projectInfo.childrenModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> projectInfoItems{{"Full Name"}, {"Short Name"}, {"GitHub Repo"}, {"Jira Project"}};
    projectInfo.childrenModel->setItems(projectInfoItems);

    UserSettingsItem tokenInfo;
    tokenInfo.settingId = "Token Info";
    tokenInfo.childrenModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> tokenInfoItems{{"GitHub Token"}, {"Jira Token"}};
    tokenInfo.childrenModel->setItems(tokenInfoItems);

    m_menus = {leaderInfo, userInfo, projectInfo, tokenInfo};
}

QVector<UserSettingsItem> UserSettingsContext::getMenus()
{
    return m_menus;
}
