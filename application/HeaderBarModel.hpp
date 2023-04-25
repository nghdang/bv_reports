#pragma once

#include <memory>
#include <QObject>
#include <QTimer>
#include <QUrl>

class HeaderBarModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString currentTime READ getCurrentTime NOTIFY currentTimeChanged)

    Q_PROPERTY(bool isSettingIconVisible READ getIsSettingIconVisible WRITE setIsSettingIconVisible NOTIFY isSettingIconVisibleChanged)
public:
    explicit HeaderBarModel(QObject* parent = nullptr);
    virtual ~HeaderBarModel() = default;

    QString getCurrentTime();

    bool getIsSettingIconVisible();
    void setIsSettingIconVisible(bool value);

signals:
    void currentTimeChanged();
    void isSettingIconVisibleChanged();

protected:
    QString m_currentTime;
    std::shared_ptr<QTimer> m_refreshSystemTimeTimer;
    bool m_isSettingIconVisible;
};
