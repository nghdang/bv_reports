#pragma once

#include <QObject>
#include <QString>

namespace Constants {

// Window title
const QString APPLICATION_TITLE = "BV-BSH Reports";

// View names
const QString VIEW_NAME_WELCOME = "Welcome";
const QString VIEW_NAME_FIRST_USE = "FirstUse";
const QString VIEW_NAME_USER_SETTINGS = "UserSettings";

const QString CURRENT_TIME_FORMAT{"dd-MMM-yyyy hh:mm"};

const int MINUTE_IN_MSEC{60 * 1000};

class QmlConstants : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString APPLICATION_TITLE READ APPLICATION_TITLE CONSTANT)

    Q_PROPERTY(QString VIEW_NAME_WELCOME READ VIEW_NAME_WELCOME CONSTANT)

    Q_PROPERTY(QString VIEW_NAME_USER_SETTINGS READ VIEW_NAME_USER_SETTINGS CONSTANT)
public:
    explicit QmlConstants(QObject* parent = nullptr);
    virtual ~QmlConstants() = default;

    QString APPLICATION_TITLE();

    QString VIEW_NAME_WELCOME();

    QString VIEW_NAME_USER_SETTINGS();
};

} // namespace Constants
