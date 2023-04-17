#include "UserSettingsItemModel.hpp"

UserSettingsItemModel::UserSettingsItemModel(QObject* parent)
    : QAbstractListModel(parent)
{
}

int UserSettingsItemModel::rowCount(const QModelIndex& parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return m_items.size();
}

QVariant UserSettingsItemModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    const auto& item = m_items.at(index.row());

    switch (role)
    {
    case SettingIdRole:
        return QVariant(item.settingId);
    case SettingLabelRole:
        return QVariant(item.settingLabel);
    case SettingValueRole:
        return QVariant(item.settingValue);
    case ValueModelRole:
        return QVariant::fromValue(item.valueModel);
    }

    return QVariant();
}

QHash<int, QByteArray> UserSettingsItemModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[SettingIdRole] = "settingId";
    roles[SettingLabelRole] = "settingLabel";
    roles[SettingValueRole] = "settingValue";
    roles[ValueModelRole] = "valueModel";

    return roles;
}

QVector<UserSettingsItem> UserSettingsItemModel::getItems()
{
    return m_items;
}

void UserSettingsItemModel::setItems(const QVector<UserSettingsItem>& items)
{
    beginResetModel();
    m_items = items;
    endResetModel();
}
