#pragma once

#include <QSharedPointer>
#include <QString>
#include <QVector>

class UserSettingsItemModel;

struct UserSettingsItem {

    QString settingId;

    QString settingLabel;

    QSharedPointer<UserSettingsItemModel> valueModel;
};
