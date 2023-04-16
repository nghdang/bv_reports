#pragma once

#include "UserSettingsItemModel.hpp"
#include <QObject>
#include <QSharedPointer>

class UserSettingsViewModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(QSharedPointer<UserSettingsItemModel> itemModel READ getItemModel NOTIFY itemModelChanged)
public:
    explicit UserSettingsViewModel(QObject* parent = nullptr);
    QSharedPointer<UserSettingsItemModel> getItemModel();

signals:
    void itemModelChanged();

private:
    QSharedPointer<UserSettingsItemModel> m_itemModel;
};
