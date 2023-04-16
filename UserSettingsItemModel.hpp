#pragma once

#include "UserSettingsItem.hpp"
#include <QAbstractListModel>

class UserSettingsItemModel : public QAbstractListModel {
    Q_OBJECT

    Q_PROPERTY(QVector<UserSettingsItem> items READ getItems WRITE setItems)

public:
    enum entryRoles {
        SettingIdRole,
        SettingTypeRole,
        ValueModelRole
    };

    explicit UserSettingsItemModel(QObject* parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    // QAbstractItemModel interface
    QHash<int, QByteArray> roleNames() const override;

    QVector<UserSettingsItem> getItems();
    void setItems(const QVector<UserSettingsItem>& items);

private:
    QVector<UserSettingsItem> m_items;
};
