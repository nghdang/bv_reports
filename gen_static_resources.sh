#!/bin/bash
set -e

REPO_DIR=$(realpath $(dirname $0))
GRAPHIC_ID_HPP=${REPO_DIR}/application/GraphicId.hpp
GRAPHIC_ID_CPP=${REPO_DIR}/application/GraphicId.cpp

cat > $GRAPHIC_ID_HPP << EOF
#pragma once

#include <QObject>
#include <QUrl>

class GraphicId : public QObject
{
    Q_OBJECT

EOF

for fileName in $(ls ${REPO_DIR}/resources/graphics); do
    propertyName="ICNID_${fileName::-4}"
    cat >> $GRAPHIC_ID_HPP << EOF
    Q_PROPERTY(QUrl $propertyName READ $propertyName CONSTANT)

EOF
done

cat >> $GRAPHIC_ID_HPP << EOF
public:
    explicit GraphicId(QObject *parent = nullptr);
    virtual ~GraphicId() = default;

EOF

for fileName in $(ls ${REPO_DIR}/resources/graphics); do
    propertyName="ICNID_${fileName::-4}"
    cat >> $GRAPHIC_ID_HPP << EOF
    static QUrl $propertyName();

EOF
done

cat >> $GRAPHIC_ID_HPP << EOF
};

EOF

cat > $GRAPHIC_ID_CPP << EOF
#include "GraphicId.hpp"

GraphicId::GraphicId(QObject *parent) : QObject(parent)
{

}

EOF

for fileName in $(ls ${REPO_DIR}/resources/graphics); do
    propertyName="ICNID_${fileName::-4}"
    cat >> $GRAPHIC_ID_CPP << EOF
QUrl GraphicId::$propertyName()
{
    return QUrl("qrc:/graphics/$fileName");
}

EOF
done
