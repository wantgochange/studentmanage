#include "testqmldata.h"

TestQmlData::TestQmlData(QObject *parent) :
    QAbstractListModel(parent)
{
    m_listOneHistory.clear();
    m_listAllHistory.clear();
    m_listShowHistory.clear();

    m_hashRoles[id] = "id";
    m_hashRoles[name]="name";
    m_hashRoles[position]="position";
    m_hashRoles[historyType]="historytype";
    m_hashRoles[date]="date";
    m_hashRoles[time]="time";
    m_hashRoles[persistTime]="persistTime";
    m_hashRoles[flagimage]="flagimage";
    m_hashRoles[calledNumber]="calledNumber";
    m_hashRoles[calledNetwork]="calledNetwork";
    m_hashRoles[calledType]="calledType";
    m_hashRoles[callTarget]="callTarget";
    m_hashRoles[callInOrOut]="callInOrOut";
    m_hashRoles[callNet]="callNet";


    TagCalledRecord tag;
    tag.name = "班长";
    tag.time = "3月2日";
    tag.position = "连长";
    tag.flagimage = 0;
    tag.calledNumber = "12:20";


    TagCalledRecord tag1;
    tag1.name = "老";
    tag1.time = "3月2日";
    tag1.position = "连长";
    tag1.flagimage = 1;
    tag1.calledNumber = "12:20";


    TagCalledRecord tag2;
    tag2.name = "安一";
    tag2.time = "3月2日";
    tag2.position = "连长";
    tag2.flagimage = 2;
    tag2.calledNumber = "12:20";
    m_listAllHistory.append(tag2);



    emit beginInsertRows(QModelIndex(), 0, m_listAllHistory.count() - 1);
    m_listShowHistory = m_listAllHistory;
    emit endInsertRows();
}

int TestQmlData::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_listShowHistory.count();
}

QVariant TestQmlData::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= rowCount())
    {
        return QVariant();
    }
    TagCalledRecord person = m_listShowHistory[index.row()];
    switch(role)
    {
    case id:
        return person.id;
    case name:
        return person.name;
    case position:
        return person.position;
    case historyType:
        return person.historyType;
    case flagimage:
        return person.flagimage;
    case calledType:
        return person.calledType;
    case calledNetwork:
        return person.calledNetwork;
    case callInOrOut:
        return person.callInOrOut;
    case callTarget:
        return person.callTarget;
    case callNet:
        return person.callNet;
    case date:
    {
        person.time.replace(4,1,"年");
        person.time.replace(7,1,"月");
        person.time.replace(10,1,"日");
        return person.time.mid(0,11);
    }
    case time:
        return person.time.mid(11,18);
    case calledNumber:
        return person.calledNumber;
    case persistTime:
    {
        int min;
        int sec;
        min=person.persistTime/60;
        sec=person.persistTime%60;
        QString dt=QString::number(min)+":"+QString::number(sec);
        return dt;
    }
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> TestQmlData::roleNames() const
{
    return m_hashRoles;
}



