#pragma once

#include <memory>
#include <QObject>
#include <QTimer>
#include <QUrl>

class HeaderBarModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString currentTime READ getCurrentTime NOTIFY currentTimeChanged)
public:
    explicit HeaderBarModel(QObject* parent = nullptr);
    virtual ~HeaderBarModel() = default;

    QString getCurrentTime();

signals:
    void currentTimeChanged();

protected:
    QString m_currentTime;
    std::shared_ptr<QTimer> m_refreshSystemTimeTimer;
};
