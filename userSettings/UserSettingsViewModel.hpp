#pragma once

#include <memory>
#include <QObject>
#include <QSharedPointer>
#include "UserSettingsContext.hpp"
#include "UserSettingsItemModel.hpp"

class UserSettingsViewModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(QSharedPointer<UserSettingsItemModel> itemModel READ getItemModel NOTIFY itemModelChanged)
public:
    explicit UserSettingsViewModel(QObject* parent = nullptr);
    QSharedPointer<UserSettingsItemModel> getItemModel();

signals:
    void itemModelChanged();

public slots:
    void onSettingChanged(QString settingId, QString settingValue);

protected:
    std::shared_ptr<UserSettingsContext> m_userSettingsContext;

private:
    QSharedPointer<UserSettingsItemModel> m_itemModel;
    std::map<QString, QString> m_settings;
};
