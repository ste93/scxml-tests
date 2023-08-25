#include "MyDataModel.h"

#include <QScxmlEvent>


bool MyDataModel::isValid() const 
{
    QString topicName = eventData().value(QStringLiteral("topic")).toString();
    return topicName.size() > 0;
}

QVariantMap MyDataModel::eventData() const
{
    return scxmlEvent().data().value<QVariantMap>();
}
