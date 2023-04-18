#include <iostream>
#include <QGuiApplication>
#include <QIcon>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "application/GraphicId.hpp"
#include "application/HeaderBarModel.hpp"
#include "common/ViewModelDependencies.hpp"
#include "mainWindow/MainWindowViewModel.hpp"
#include "userSettings/UserSettingsViewModel.hpp"
#include "viewManagement/ViewManager.hpp"

int main(int argc, char* argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    auto windowIcon = QIcon(":" + GraphicId::ICNID_DRAGON_SYMBOL_LICON().path());
    app.setWindowIcon(windowIcon);

    ViewManager viewManager;
    viewManager.initialize();

    qRegisterMetaType<HeaderBarModel*>("HeaderBarModel");

    GraphicId graphicId;
    viewManager.getEngine()->rootContext()->setContextProperty("GraphicId", &graphicId);

    auto headerBarModel = std::make_shared<HeaderBarModel>();
    auto viewModelDependencies = std::make_shared<ViewModelDependencies>(headerBarModel);

    viewManager.initializeWindow([&](WindowConfiguration& windowConfiguration) {
        windowConfiguration.viewName = QStringLiteral("MainWindow");
        windowConfiguration.fsmStateName = QStringLiteral("MainWindow");
        windowConfiguration.propertyName = QStringLiteral("mainWindowViewModel");
        windowConfiguration.windowViewModelCreator = [&]() -> BaseViewModel* { return new MainWindowViewModel(viewModelDependencies); };
    });

    viewManager.registerViewModel([&](ViewModelConfiguration& viewModelConfiguration) {
        viewModelConfiguration.viewName = QStringLiteral("UserSettingsViewModel");
        viewModelConfiguration.fsmStateName = QStringLiteral("UserSettingsViewModel");
        viewModelConfiguration.propertyName = QStringLiteral("userSettingsViewModel");
        viewModelConfiguration.viewModelCreator = [&]() -> BaseViewModel* { return new UserSettingsViewModel(viewModelDependencies); };
    });

    auto engine = viewManager.getEngine();
    const QUrl url(QStringLiteral("qrc:/views/main.qml"));
    QObject::connect(
        engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine->load(url);

    return app.exec();
}
