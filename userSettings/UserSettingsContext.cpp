#include "UserSettingsContext.hpp"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <sys/stat.h>
#include "UserSettingsItemModel.hpp"

UserSettingsContext::UserSettingsContext()
{
    auto persistentSettings = loadFromJson();
    createMenus(persistentSettings);
}

QVector<UserSettingsItem> UserSettingsContext::getMenus()
{
    return m_menus;
}

bool UserSettingsContext::hasSettingsSaved()
{
    struct stat buffer;
    return stat(SETTINGS_FILENAME.c_str(), &buffer) == 0;
}

void UserSettingsContext::saveToJson(std::map<std::string, std::string> persistentSettings)
{
    nlohmann::json settingsJson;

    for (const auto& setting : persistentSettings)
    {
        settingsJson[setting.first] = setting.second;
    }

    std::ofstream ofs(SETTINGS_FILENAME);
    ofs << std::setw(4) << settingsJson << std::endl;

    ofs.close();
}

std::map<std::string, std::string> UserSettingsContext::loadFromJson()
{
    std::map<std::string, std::string> persistentSettings;
    if (hasSettingsSaved())
    {
        std::ifstream ifs(SETTINGS_FILENAME);
        auto settingsJson = nlohmann::json::parse(ifs);

        for (const auto& setting : settingsJson.items())
        {
            persistentSettings.emplace(setting.key(), setting.value());
        }
    }
    return persistentSettings;
}

void UserSettingsContext::createMenus(std::map<std::string, std::string> persistentSettings)
{
    UserSettingsItem leaderFirstName;
    leaderFirstName.settingId = "LeaderInfo.FirstName";
    leaderFirstName.settingLabel = "First Name";
    auto setting = persistentSettings.find(leaderFirstName.settingId.toStdString());
    leaderFirstName.settingValue = setting != persistentSettings.end() ? QString::fromStdString(setting->second) : "";

    UserSettingsItem leaderBSHEmail;
    leaderBSHEmail.settingId = "LeaderInfo.BSHEmail";
    leaderBSHEmail.settingLabel = "BSH Email";
    setting = persistentSettings.find(leaderBSHEmail.settingId.toStdString());
    leaderBSHEmail.settingValue = setting != persistentSettings.end() ? QString::fromStdString(setting->second) : "";

    UserSettingsItem leaderInfo;
    leaderInfo.settingId = "LeaderInfo";
    leaderInfo.settingLabel = "Leader Info";
    leaderInfo.valueModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> leaderInfoItems{leaderFirstName, leaderBSHEmail};
    leaderInfo.valueModel->setItems(leaderInfoItems);

    UserSettingsItem userFirstName;
    userFirstName.settingId = "UserInfo.FirstName";
    userFirstName.settingLabel = "First Name";
    setting = persistentSettings.find(userFirstName.settingId.toStdString());
    userFirstName.settingValue = setting != persistentSettings.end() ? QString::fromStdString(setting->second) : "";

    UserSettingsItem userLastName;
    userLastName.settingId = "UserInfo.LastName";
    userLastName.settingLabel = "Last Name";
    setting = persistentSettings.find(userLastName.settingId.toStdString());
    userLastName.settingValue = setting != persistentSettings.end() ? QString::fromStdString(setting->second) : "";

    UserSettingsItem userBSHEmail;
    userBSHEmail.settingId = "UserInfo.BSHEmail";
    userBSHEmail.settingLabel = "BSH Email";
    setting = persistentSettings.find(userBSHEmail.settingId.toStdString());
    userBSHEmail.settingValue = setting != persistentSettings.end() ? QString::fromStdString(setting->second) : "";

    UserSettingsItem userInfo;
    userInfo.settingId = "UserInfo";
    userInfo.settingLabel = "User Info";
    userInfo.valueModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> userInfoItems{userFirstName, userLastName, userBSHEmail};
    userInfo.valueModel->setItems(userInfoItems);

    UserSettingsItem projectFullName;
    projectFullName.settingId = "ProjectInfo.FullName";
    projectFullName.settingLabel = "Full Name";
    setting = persistentSettings.find(projectFullName.settingId.toStdString());
    projectFullName.settingValue = setting != persistentSettings.end() ? QString::fromStdString(setting->second) : "";

    UserSettingsItem projectShortName;
    projectShortName.settingId = "ProjectInfo.ShortName";
    projectShortName.settingLabel = "Short Name";
    setting = persistentSettings.find(projectShortName.settingId.toStdString());
    projectShortName.settingValue = setting != persistentSettings.end() ? QString::fromStdString(setting->second) : "";

    UserSettingsItem projectGitHubRepo;
    projectGitHubRepo.settingId = "ProjectInfo.GitHubRepo";
    projectGitHubRepo.settingLabel = "GitHub Repo";
    setting = persistentSettings.find(projectGitHubRepo.settingId.toStdString());
    projectGitHubRepo.settingValue = setting != persistentSettings.end() ? QString::fromStdString(setting->second) : "";

    UserSettingsItem projectJiraProject;
    projectJiraProject.settingId = "ProjectInfo.JiraProject";
    projectJiraProject.settingLabel = "Jira Project";
    setting = persistentSettings.find(projectJiraProject.settingId.toStdString());
    projectJiraProject.settingValue = setting != persistentSettings.end() ? QString::fromStdString(setting->second) : "";

    UserSettingsItem projectInfo;
    projectInfo.settingId = "ProjectInfo";
    projectInfo.settingLabel = "Project Info";
    projectInfo.valueModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> projectInfoItems{projectFullName, projectShortName, projectGitHubRepo, projectJiraProject};
    projectInfo.valueModel->setItems(projectInfoItems);

    UserSettingsItem tokenGitHubToken;
    tokenGitHubToken.settingId = "TokenInfo.GitHubToken";
    tokenGitHubToken.settingLabel = "GitHub Token";
    setting = persistentSettings.find(tokenGitHubToken.settingId.toStdString());
    tokenGitHubToken.settingValue = setting != persistentSettings.end() ? QString::fromStdString(setting->second) : "";

    UserSettingsItem tokenJiraToken;
    tokenJiraToken.settingId = "TokenInfo.JiraToken";
    tokenJiraToken.settingLabel = "Jira Token";
    setting = persistentSettings.find(tokenJiraToken.settingId.toStdString());
    tokenJiraToken.settingValue = setting != persistentSettings.end() ? QString::fromStdString(setting->second) : "";

    UserSettingsItem tokenInfo;
    tokenInfo.settingId = "TokenInfo";
    tokenInfo.settingLabel = "Token Info";
    tokenInfo.valueModel = QSharedPointer<UserSettingsItemModel>::create();
    QVector<UserSettingsItem> tokenInfoItems{tokenGitHubToken, tokenJiraToken};
    tokenInfo.valueModel->setItems(tokenInfoItems);

    m_menus = {leaderInfo, userInfo, projectInfo, tokenInfo};
}
