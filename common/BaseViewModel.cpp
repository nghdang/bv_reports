#include "BaseViewModel.hpp"

BaseViewModel::BaseViewModel(std::shared_ptr<ViewModelDependencies> viewModelDependencies, QObject* parent)
    : m_headerBarModel{viewModelDependencies->m_headerBarModel}
    , m_userSettingsContext{viewModelDependencies->m_userSettingsContext}
    , QObject(parent)
{
}
