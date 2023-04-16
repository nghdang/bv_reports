#pragma once

#include <QObject>
#include <QUrl>

class HeaderBarModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(QUrl LOGO_ICON READ getLogoIcon NOTIFY logoIconChanged)

    Q_PROPERTY(QUrl SETTINGS_ICON READ getSettingsIcon NOTIFY settingIconChanged)
public:
    explicit HeaderBarModel(QObject* parent = nullptr);
    virtual ~HeaderBarModel() = default;

    QUrl getLogoIcon();
    QUrl getSettingsIcon();

signals:
    void logoIconChanged();
    void settingIconChanged();
};

// Q_DECLARE_METATYPE(HeaderBarModel*)
