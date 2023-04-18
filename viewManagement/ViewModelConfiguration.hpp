#pragma once

#include <QString>

class BaseViewModel;

struct ViewModelConfiguration {
    QString viewName;

    QString fsmStateName;

    QString propertyName;

    std::function<BaseViewModel*()> viewModelCreator;
};
