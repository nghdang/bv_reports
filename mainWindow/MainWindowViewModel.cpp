#include "MainWindowViewModel.hpp"

#include <iostream>

MainWindowViewModel::MainWindowViewModel(std::shared_ptr<ViewModelDependencies> viewModelDependencies, QObject* parent)
    : BaseViewModel(viewModelDependencies, parent)
    , m_activeViewName("MainWindow")
{
}

HeaderBarModel* MainWindowViewModel::getHeaderBarModel()
{
    return m_headerBarModel.get();
}

QString MainWindowViewModel::getTitle()
{
    return QStringLiteral("BV-BSH Reports");
}

QString MainWindowViewModel::getActiveViewName()
{
    return m_activeViewName;
}

void MainWindowViewModel::enterUserSettings()
{
    m_activeViewName = "UserSettings";
    emit activeViewNameChanged();
}
