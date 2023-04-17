#include "UserSettingsContext.hpp"

#include "UserSettingsItemModel.hpp"

UserSettingsContext::UserSettingsContext()
{
    UserSettingsItem leaderInfo;
    leaderInfo.settingId = "LeaderInfo";
    leaderInfo.settingLabel = "Leader Info";
    leaderInfo.valueModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> leaderInfoItems{{"LeaderInfo.FirstName", "First Name"}, {"LeaderInfo.BSHEmail", "BSH Email"}};
    leaderInfo.valueModel->setItems(leaderInfoItems);

    UserSettingsItem userInfo;
    userInfo.settingId = "UserInfo";
    userInfo.settingLabel = "User Info";
    userInfo.valueModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> userInfoItems{
        {"UserInfo.FirstName", "First Name"}, {"UserInfo.LastName", "Last Name"}, {"UserInfo.BSHEmail", "BSH Email"}};
    userInfo.valueModel->setItems(userInfoItems);

    UserSettingsItem projectInfo;
    projectInfo.settingId = "ProjectInfo";
    projectInfo.settingLabel = "Project Info";
    projectInfo.valueModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> projectInfoItems{{"ProjectInfo.FullName", "Full Name"},
                                               {"ProjectInfo.ShortName", "Short Name"},
                                               {"ProjectInfo.GitHubRepo", "GitHub Repo"},
                                               {"ProjectInfo.JiraProject", "Jira Project"}};
    projectInfo.valueModel->setItems(projectInfoItems);

    UserSettingsItem tokenInfo;
    tokenInfo.settingId = "TokenInfo";
    tokenInfo.settingLabel = "Token Info";
    tokenInfo.valueModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> tokenInfoItems{{"TokenInfo.GitHubToken", "GitHub Token"}, {"TokenInfo.JiraToken", "Jira Token"}};
    tokenInfo.valueModel->setItems(tokenInfoItems);

    m_menus = {leaderInfo, userInfo, projectInfo, tokenInfo};
}

QVector<UserSettingsItem> UserSettingsContext::getMenus()
{
    return m_menus;
}
