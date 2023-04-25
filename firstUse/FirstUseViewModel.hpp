#pragma once

#include <QObject>
#include "common/BaseViewModel.hpp"

class FirstUseViewModel : public BaseViewModel {
    Q_OBJECT

    Q_PROPERTY(HeaderBarModel* headerBarModel READ getHeaderBarModel NOTIFY headerBarModelChanged)

public:
    explicit FirstUseViewModel(std::shared_ptr<ViewModelDependencies> viewModelDependencies, QObject* parent = nullptr);
    virtual ~FirstUseViewModel() = default;

    HeaderBarModel* getHeaderBarModel();

signals:
    void headerBarModelChanged();
};
