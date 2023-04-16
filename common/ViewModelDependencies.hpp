#pragma once

#include <memory>

class HeaderBarModel;

class ViewModelDependencies {
public:
    ViewModelDependencies(const std::shared_ptr<HeaderBarModel>& headerBarModel);
    virtual ~ViewModelDependencies() = default;

    const std::shared_ptr<HeaderBarModel>& m_headerBarModel;
};
