#pragma once

#include <QObject>
#include <QUrl>

class HeaderBarModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(QUrl SETTINGS_ICON READ getSettingsIcon NOTIFY settingIconsChanged)
public:
    explicit HeaderBarModel(QObject* parent = nullptr);
    virtual ~HeaderBarModel() = default;

    QUrl getSettingsIcon();

signals:
    void settingIconsChanged();
};

Q_DECLARE_METATYPE(HeaderBarModel*)
