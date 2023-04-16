#pragma once

#include <QSharedPointer>
#include <QString>
#include <QVector>

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
