#pragma once

#include <QString>

class BaseViewModel;

struct WindowConfiguration {
    QString viewName;

    QString fsmStateName;

    QString propertyName;

    std::function<BaseViewModel*()> windowViewModelCreator;
};
