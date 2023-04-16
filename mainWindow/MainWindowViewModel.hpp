#pragma once

#include <QObject>
#include "common/BaseViewModel.hpp"

class MainWindowViewModel : public BaseViewModel {
    Q_OBJECT

    Q_PROPERTY(HeaderBarModel* headerBarModel READ getHeaderBarModel NOTIFY headerBarModelChanged)

    Q_PROPERTY(QString title READ getTitle NOTIFY titleChanged)
public:
    explicit MainWindowViewModel(std::shared_ptr<ViewModelDependencies> viewModelDependencies, QObject* parent = nullptr);
    virtual ~MainWindowViewModel() = default;

    HeaderBarModel* getHeaderBarModel();
    QString getTitle();

public slots:
    void enterUserSettings();

signals:
    void headerBarModelChanged();
    void titleChanged();
};
