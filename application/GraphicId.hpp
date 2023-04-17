#pragma once

#include <QObject>
#include <QUrl>

class GraphicId : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl ICNID_DOWN_ARROW_LICON READ ICNID_DOWN_ARROW_LICON CONSTANT)

    Q_PROPERTY(QUrl ICNID_DOWN_ARROW_MICON READ ICNID_DOWN_ARROW_MICON CONSTANT)

    Q_PROPERTY(QUrl ICNID_DOWN_ARROW_SICON READ ICNID_DOWN_ARROW_SICON CONSTANT)

    Q_PROPERTY(QUrl ICNID_DRAGON_SYMBOL_LICON READ ICNID_DRAGON_SYMBOL_LICON CONSTANT)

    Q_PROPERTY(QUrl ICNID_DRAGON_SYMBOL_MICON READ ICNID_DRAGON_SYMBOL_MICON CONSTANT)

    Q_PROPERTY(QUrl ICNID_DRAGON_SYMBOL_SICON READ ICNID_DRAGON_SYMBOL_SICON CONSTANT)

    Q_PROPERTY(QUrl ICNID_RIGHT_ARROW_LICON READ ICNID_RIGHT_ARROW_LICON CONSTANT)

    Q_PROPERTY(QUrl ICNID_RIGHT_ARROW_MICON READ ICNID_RIGHT_ARROW_MICON CONSTANT)

    Q_PROPERTY(QUrl ICNID_RIGHT_ARROW_SICON READ ICNID_RIGHT_ARROW_SICON CONSTANT)

    Q_PROPERTY(QUrl ICNID_SETTINGS_LICON READ ICNID_SETTINGS_LICON CONSTANT)

    Q_PROPERTY(QUrl ICNID_SETTINGS_MICON READ ICNID_SETTINGS_MICON CONSTANT)

    Q_PROPERTY(QUrl ICNID_SETTINGS_SICON READ ICNID_SETTINGS_SICON CONSTANT)

public:
    explicit GraphicId(QObject *parent = nullptr);
    virtual ~GraphicId() = default;

    static QUrl ICNID_DOWN_ARROW_LICON();

    static QUrl ICNID_DOWN_ARROW_MICON();

    static QUrl ICNID_DOWN_ARROW_SICON();

    static QUrl ICNID_DRAGON_SYMBOL_LICON();

    static QUrl ICNID_DRAGON_SYMBOL_MICON();

    static QUrl ICNID_DRAGON_SYMBOL_SICON();

    static QUrl ICNID_RIGHT_ARROW_LICON();

    static QUrl ICNID_RIGHT_ARROW_MICON();

    static QUrl ICNID_RIGHT_ARROW_SICON();

    static QUrl ICNID_SETTINGS_LICON();

    static QUrl ICNID_SETTINGS_MICON();

    static QUrl ICNID_SETTINGS_SICON();

};

