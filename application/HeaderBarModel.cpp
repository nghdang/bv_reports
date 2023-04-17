#include "HeaderBarModel.hpp"

#include <QDateTime>
#include "common/Constants.hpp"

HeaderBarModel::HeaderBarModel(QObject* parent)
    : QObject(parent)
{
    m_currentTime = QDateTime::currentDateTime().toString(Constants::CURRENT_TIME_FORMAT);

    m_refreshSystemTimeTimer = std::make_shared<QTimer>();
    m_refreshSystemTimeTimer->setInterval(Constants::MINUTE_IN_MSEC);
    connect(m_refreshSystemTimeTimer.get(), &QTimer::timeout, this, [&]() {
        m_currentTime = QDateTime::currentDateTime().toString(Constants::CURRENT_TIME_FORMAT);
        emit currentTimeChanged();
    });
    m_refreshSystemTimeTimer->start();
}

QString HeaderBarModel::getCurrentTime()
{
    return m_currentTime;
}
