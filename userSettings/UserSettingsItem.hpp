#pragma once

#include <QSharedPointer>
#include <QString>
#include <QVector>

class UserSettingsItemModel;

struct UserSettingsItem {

    QString settingId;

    QSharedPointer<UserSettingsItemModel> childrenModel;
};
