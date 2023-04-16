#pragma once

#include <memory>
#include <QObject>
#include <QTimer>
#include <QUrl>

class HeaderBarModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(QUrl LOGO_ICON READ getLogoIcon NOTIFY logoIconChanged)

    Q_PROPERTY(QUrl SETTINGS_ICON READ getSettingsIcon NOTIFY settingIconChanged)

    Q_PROPERTY(QString currentTime READ getCurrentTime NOTIFY currentTimeChanged)
public:
    explicit HeaderBarModel(QObject* parent = nullptr);
    virtual ~HeaderBarModel() = default;

    QUrl getLogoIcon();
    QUrl getSettingsIcon();
    QString getCurrentTime();

signals:
    void logoIconChanged();
    void settingIconChanged();
    void currentTimeChanged();

protected:
    QString m_currentTime;
    std::shared_ptr<QTimer> m_refreshSystemTimeTimer;
};

// Q_DECLARE_METATYPE(HeaderBarModel*)
