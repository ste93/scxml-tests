#pragma once

#include <QScxmlCppDataModel>


class MyDataModel: public QScxmlCppDataModel
{
    Q_OBJECT
    Q_SCXML_DATAMODEL

private:
    bool isValid() const;
    QVariantMap eventData() const;

    QString topic;
};