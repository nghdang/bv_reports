#pragma once

#include <memory>

class HeaderBarModel;

class UserSettingsContext;

class ViewModelDependencies {
public:
    ViewModelDependencies(const std::shared_ptr<HeaderBarModel>& headerBarModel, const std::shared_ptr<UserSettingsContext>& userSettingsContext);
    virtual ~ViewModelDependencies() = default;

    const std::shared_ptr<HeaderBarModel>& m_headerBarModel;

    const std::shared_ptr<UserSettingsContext>& m_userSettingsContext;
};
