#pragma once

#include <memory>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QScxmlStateMachine>
#include "viewManagement/ViewModelConfiguration.hpp"
#include "viewManagement/WindowConfiguration.hpp"

class ViewManager : public QObject {
    Q_OBJECT
public:
    explicit ViewManager(QObject* parent = nullptr);
    virtual ~ViewManager();

    void initialize();
    QQmlApplicationEngine* getEngine();

    void sendFsmEvent(const QString& event);

    void initializeWindow(std::function<void(WindowConfiguration&)> windowConfigurator);
    void registerViewModel(std::function<void(ViewModelConfiguration&)> viewModelConfigurator);

private:
    QQmlApplicationEngine* m_engine;
    std::unique_ptr<QScxmlStateMachine> m_stateMachine;
};
