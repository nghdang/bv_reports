#include "ViewManager.hpp"

#include <QQmlContext>
#include "common/BaseViewModel.hpp"

ViewManager::ViewManager(QObject* parent)
    : QObject(parent)
{
}

ViewManager::~ViewManager()
{
    m_engine = nullptr;
}

void ViewManager::initialize()
{
    m_engine = new QQmlApplicationEngine();
}

QQmlApplicationEngine* ViewManager::getEngine()
{
    return m_engine;
}

void ViewManager::sendFsmEvent(const QString& event)
{
    m_stateMachine->submitEvent(event);
}

void ViewManager::initializeWindow(std::function<void(WindowConfiguration&)> windowConfigurator)
{
    WindowConfiguration windowConfiguration;
    windowConfigurator(windowConfiguration);

    auto windowInstance = windowConfiguration.windowViewModelCreator();
    m_engine->rootContext()->setContextProperty(windowConfiguration.propertyName, windowInstance);
}

void ViewManager::registerViewModel(std::function<void(ViewModelConfiguration&)> viewModelConfigurator)
{

    ViewModelConfiguration viewModelConfiguration;
    viewModelConfigurator(viewModelConfiguration);

    auto viewModelInstance = viewModelConfiguration.viewModelCreator();
    m_engine->rootContext()->setContextProperty(viewModelConfiguration.propertyName, viewModelInstance);
}
