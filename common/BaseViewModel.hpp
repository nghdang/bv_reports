#pragma once

#include <QObject>
#include "ViewModelDependencies.hpp"

class HeaderBarModel;

class UserSettingsContext;

class BaseViewModel : public QObject {
    Q_OBJECT
public:
    explicit BaseViewModel(std::shared_ptr<ViewModelDependencies> viewModelDependencies, QObject* parent = nullptr);
    virtual ~BaseViewModel() = default;

protected:
    std::shared_ptr<HeaderBarModel> m_headerBarModel;

    std::shared_ptr<UserSettingsContext> m_userSettingsContext;
};
