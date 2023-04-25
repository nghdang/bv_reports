#include "common/Constants.hpp"

namespace Constants {

Constants::QmlConstants::QmlConstants(QObject* parent)
    : QObject(parent)
{
}

QString QmlConstants::APPLICATION_TITLE()
{
    return Constants::APPLICATION_TITLE;
}

QString QmlConstants::VIEW_NAME_WELCOME()
{
    return Constants::VIEW_NAME_WELCOME;
}

QString QmlConstants::VIEW_NAME_USER_SETTINGS()
{
    return Constants::VIEW_NAME_USER_SETTINGS;
}
} // namespace Constants
