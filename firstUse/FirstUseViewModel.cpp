#include "FirstUseViewModel.hpp"
#include "application/HeaderBarModel.hpp"

FirstUseViewModel::FirstUseViewModel(std::shared_ptr<ViewModelDependencies> viewModelDependencies, QObject* parent)
    : BaseViewModel(viewModelDependencies, parent)
{
    m_headerBarModel->setIsSettingIconVisible(false);
}

HeaderBarModel* FirstUseViewModel::getHeaderBarModel()
{
    return m_headerBarModel.get();
}
