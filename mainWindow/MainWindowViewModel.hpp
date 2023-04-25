#pragma once

#include <QObject>
#include "common/BaseViewModel.hpp"

class MainWindowViewModel : public BaseViewModel {
    Q_OBJECT

    Q_PROPERTY(HeaderBarModel* headerBarModel READ getHeaderBarModel NOTIFY headerBarModelChanged)

    Q_PROPERTY(QString activeViewName READ getActiveViewName NOTIFY activeViewNameChanged)
public:
    explicit MainWindowViewModel(std::shared_ptr<ViewModelDependencies> viewModelDependencies, QObject* parent = nullptr);
    virtual ~MainWindowViewModel() = default;

    HeaderBarModel* getHeaderBarModel();
    QString getActiveViewName();

public slots:
    void enterFirstUse();
    void enterUserSettings();

signals:
    void headerBarModelChanged();
    void activeViewNameChanged();

private:
    QString m_activeViewName;
};
