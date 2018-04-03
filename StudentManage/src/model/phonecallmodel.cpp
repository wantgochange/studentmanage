#include "phonecallmodel.h"
#include <QDateTime>
#include <QDebug>

PhoneCallModel::PhoneCallModel(QObject *parent) : QObject(parent)
{
    m_handlerList.clear();

}

void PhoneCallModel::atstartTime()
{

    handlerManager.startTime = QDateTime::currentDateTime();
}

QString PhoneCallModel::returnStartTime()
{

    QDateTime startTime;
    startTime = handlerManager.startTime;
    qDebug()<<startTime.toTime_t()<<QDateTime::currentDateTime().toTime_t();
    return timeToString(QDateTime::currentDateTime().toTime_t() - startTime.toTime_t());
}
QString PhoneCallModel::timeToString(int time)
{
    int minute;
    int second;
    int hour;
    QString minutes;
    QString seconds;
    QString timeString = "";
    if (time >= 3600)
    {
        hour = time / 3600;
        minute = time % 3600 / 60;
        second = time % 60;
        if (minute < 10)
            minutes = QString("0%1").arg(minute);
        else
            minutes = QString("%1").arg(minute);

        if (second < 10)
            seconds = QString("0%1").arg(second);
        else
            seconds = QString("%1").arg(second);
        timeString = QString("%1:%2:%3").arg(hour).arg(minutes).arg(seconds);
    }
    else if (time < 3600 && time > 0)
    {
        minute = time / 60;
        second = time % 60;
        if (minute < 10)
            minutes = QString("0%1").arg(minute);
        else
            minutes = QString("%1").arg(minute);

        if (second < 10)
            seconds = QString("0%1").arg(second);
        else
            seconds = QString("%1").arg(second);
        timeString = QString("%1:%2").arg(minutes).arg(seconds);
    }
    return timeString;
}
