#include <iostream>
#include <QGuiApplication>
#include <QIcon>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "application/GraphicId.hpp"
#include "application/HeaderBarModel.hpp"
#include "common/ViewModelDependencies.hpp"
#include "mainWindow/MainWindowViewModel.hpp"
#include "userSettings/UserSettingsContext.hpp"
#include "userSettings/UserSettingsViewModel.hpp"

int main(int argc, char* argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    auto windowIcon = QIcon(":" + GraphicId::ICNID_DRAGON_SYMBOL_LICON().path());
    app.setWindowIcon(windowIcon);

    qRegisterMetaType<HeaderBarModel*>("HeaderBarModel");

    GraphicId graphicId;

    auto headerBarModel = std::make_shared<HeaderBarModel>();
    auto userSettingsContext = std::make_shared<UserSettingsContext>();
    auto viewModelDependencies = std::make_shared<ViewModelDependencies>(headerBarModel, userSettingsContext);

    MainWindowViewModel mainWindowViewModel(viewModelDependencies);
    UserSettingsViewModel userSettingsViewModel(viewModelDependencies);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("GraphicId", &graphicId);
    engine.rootContext()->setContextProperty("mainWindowViewModel", &mainWindowViewModel);
    engine.rootContext()->setContextProperty("userSettingsViewModel", &userSettingsViewModel);

    const QUrl url(QStringLiteral("qrc:/views/MainWindow.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
