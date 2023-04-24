#pragma once

#include <memory>
#include <QObject>
#include <QSharedPointer>
#include "common/BaseViewModel.hpp"
#include "UserSettingsContext.hpp"
#include "UserSettingsItemModel.hpp"

class UserSettingsViewModel : public BaseViewModel {
    Q_OBJECT

    Q_PROPERTY(QSharedPointer<UserSettingsItemModel> itemModel READ getItemModel NOTIFY itemModelChanged)
public:
    explicit UserSettingsViewModel(std::shared_ptr<ViewModelDependencies> viewModelDependencies, QObject* parent = nullptr);
    QSharedPointer<UserSettingsItemModel> getItemModel();

signals:
    void itemModelChanged();

public slots:
    void onSettingChanged(QString settingId, QString settingValue);
    void onSave();

private:
    QSharedPointer<UserSettingsItemModel> m_itemModel;
    std::map<std::string, std::string> m_settings;
};
