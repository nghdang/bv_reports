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

int main(int argc, char* argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    auto windowIcon = QIcon(":" + GraphicId::ICNID_DRAGON_SYMBOL_LICON().path());
    app.setWindowIcon(windowIcon);

    QQmlApplicationEngine engine;

    qRegisterMetaType<HeaderBarModel*>("HeaderBarModel");

    GraphicId graphicId;
    engine.rootContext()->setContextProperty("GraphicId", &graphicId);

    auto headerBarModel = std::make_shared<HeaderBarModel>();
    auto viewModelDependencies = std::make_shared<ViewModelDependencies>(headerBarModel);

    MainWindowViewModel mainWindowViewModel(viewModelDependencies);
    engine.rootContext()->setContextProperty("mainWindowViewModel", &mainWindowViewModel);

    UserSettingsViewModel userSettingsViewModel;
    engine.rootContext()->setContextProperty("userSettingsViewModel", &userSettingsViewModel);

    const QUrl url(QStringLiteral("qrc:/views/main.qml"));
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
