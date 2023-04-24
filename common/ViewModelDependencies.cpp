#include "ViewModelDependencies.hpp"

ViewModelDependencies::ViewModelDependencies(const std::shared_ptr<HeaderBarModel>& headerBarModel,
                                             const std::shared_ptr<UserSettingsContext>& userSettingsContext)
    : m_headerBarModel{std::move(headerBarModel)}
    , m_userSettingsContext{std::move(userSettingsContext)}
{
}
