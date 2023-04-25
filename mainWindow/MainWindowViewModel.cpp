#include "MainWindowViewModel.hpp"

#include <iostream>
#include "common/Constants.hpp"
#include "userSettings/UserSettingsContext.hpp"

MainWindowViewModel::MainWindowViewModel(std::shared_ptr<ViewModelDependencies> viewModelDependencies, QObject* parent)
    : BaseViewModel(viewModelDependencies, parent)
{
    m_activeViewName = m_userSettingsContext->hasSettingsSaved() ? Constants::VIEW_NAME_USER_SETTINGS : Constants::VIEW_NAME_WELCOME;
}

HeaderBarModel* MainWindowViewModel::getHeaderBarModel()
{
    return m_headerBarModel.get();
}

QString MainWindowViewModel::getActiveViewName()
{
    return m_activeViewName;
}

void MainWindowViewModel::enterFirstUse()
{
    m_activeViewName = Constants::VIEW_NAME_FIRST_USE;
    emit activeViewNameChanged();
}

void MainWindowViewModel::enterUserSettings()
{
    m_activeViewName = Constants::VIEW_NAME_USER_SETTINGS;
    emit activeViewNameChanged();
}
