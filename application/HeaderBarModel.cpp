#include "HeaderBarModel.hpp"

HeaderBarModel::HeaderBarModel(QObject* parent)
    : QObject(parent)
{
}

QUrl HeaderBarModel::getLogoIcon()
{
    return QUrl("qrc:/graphics/DRAGON_SYMBOL_MICON.png");
}

QUrl HeaderBarModel::getSettingsIcon()
{
    return QUrl("qrc:/graphics/SETTINGS_MICON.png");
}
