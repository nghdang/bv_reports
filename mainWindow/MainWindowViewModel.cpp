#include "MainWindowViewModel.hpp"

#include <iostream>

MainWindowViewModel::MainWindowViewModel(std::shared_ptr<ViewModelDependencies> viewModelDependencies, QObject* parent)
    : BaseViewModel(viewModelDependencies, parent)
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

void MainWindowViewModel::enterUserSettings()
{
    std::cout << __FUNCTION__ << "():" << std::endl;
}
