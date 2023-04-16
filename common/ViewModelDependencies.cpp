#include "ViewModelDependencies.hpp"

ViewModelDependencies::ViewModelDependencies(const std::shared_ptr<HeaderBarModel>& headerBarModel)
    : m_headerBarModel{std::move(headerBarModel)}
{
}
