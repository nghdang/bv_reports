#pragma once

#include <QString>
#include <QVector>
#include <QSharedPointer>

class UserSettingsItemModel;

struct UserSettingsItem {

    enum SettingType {
        Menu,
        Value
    };

    QString settingId;

    SettingType settingType;

    QSharedPointer<UserSettingsItemModel> childrenModel;
};
