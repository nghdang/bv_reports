#include "HeaderBarModel.hpp"

HeaderBarModel::HeaderBarModel(QObject* parent)
    : QObject(parent)
{
}

QUrl HeaderBarModel::getSettingsIcon()
{
    return QUrl("qrc:/graphics/SETTINGS_MICON.png");
}
