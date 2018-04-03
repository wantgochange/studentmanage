#ifndef TESTQMLDATA_H
#define TESTQMLDATA_H

#include <QObject>
#include <QHash>
#include <QModelIndex>
#include <QAbstractListModel>


struct TagCalledRecord
{
    int calledType;//通话类型 没用
    int calledNetwork;
    int historyType;//通话记录类型  语音
    int flagimage;//通话类型
    int  persistTime; //拨打时长,单位秒    0 已接 1 未接  2 已拨
    int     callNet;        //通话网络，与枚举网络类型对应
    QString id;   //通话记录id
    QString name;
    QString time;
    QString firstName;
    QString position;
    QString lastName;//meiyong
    QString calledDuration;
    QString calledNumber;
    QList<QString> listperson;
    QString callTarget;         //接听，拨打对象的id   //如果查无此人，就返回拨打号码
    int     callInOrOut;    // 0-->call in, 1-->call out, 2-->未接


    //构造函数
    TagCalledRecord()
    {
        calledType=0;calledNetwork=0;flagimage=0;persistTime=0;
        firstName.clear();lastName.clear();
        calledDuration.clear();calledNumber.clear();time.clear();historyType=0;
        position.clear();id.clear();callTarget.clear();callInOrOut=0;callNet=0;
        name.clear();
    }

    //拷贝构造函数
    TagCalledRecord(const TagCalledRecord&  otherCalledRecord)
    {
        calledType=otherCalledRecord.calledType;position=otherCalledRecord.position;
        calledNetwork=otherCalledRecord.calledNetwork;firstName=otherCalledRecord.firstName;
        lastName=otherCalledRecord.lastName;calledDuration=otherCalledRecord.calledDuration;
        calledNumber=otherCalledRecord.calledNumber;time=otherCalledRecord.time;
        listperson=otherCalledRecord.listperson;historyType=otherCalledRecord.historyType;
        flagimage=otherCalledRecord.flagimage;id=otherCalledRecord.id;persistTime=otherCalledRecord.persistTime;
        callTarget=otherCalledRecord.callTarget;callInOrOut=otherCalledRecord.callInOrOut;
        callNet=otherCalledRecord.callNet;name=otherCalledRecord.name;

    }
    //赋值
    void operator=(const TagCalledRecord& otherCalledRecord)
    {
        calledType=otherCalledRecord.calledType;position=otherCalledRecord.position;
        calledNetwork=otherCalledRecord.calledNetwork;firstName=otherCalledRecord.firstName;
        lastName=otherCalledRecord.lastName;calledDuration=otherCalledRecord.calledDuration;
        calledNumber=otherCalledRecord.calledNumber;time=otherCalledRecord.time;
        listperson=otherCalledRecord.listperson;historyType=otherCalledRecord.historyType;
        flagimage=otherCalledRecord.flagimage;id=otherCalledRecord.id;persistTime=otherCalledRecord.persistTime;
        callInOrOut=otherCalledRecord.callInOrOut;callTarget=otherCalledRecord.callTarget;
        callNet=otherCalledRecord.callNet;
        name=otherCalledRecord.name;

    }
};


class TestQmlData: public QAbstractListModel
{
    Q_OBJECT

    enum CallRecordRoles
    {
        name = Qt::UserRole + 1,
        position,
        historyType,
        date,
        time,
        flagimage,
        calledNumber,
        id,
        persistTime,
        calledNetwork,
        calledType,
        callTarget,
        callInOrOut,
        callNet

    };

public:
    explicit TestQmlData(QObject *parent = 0);
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role=Qt::DisplayRole) const;
protected:
    QHash<int,QByteArray> roleNames() const;
private:
    QList<TagCalledRecord>  m_listAllHistory;


    QList<TagCalledRecord>  m_listShowHistory;
    QHash<int, QByteArray>   m_hashRoles;
    QList<TagCalledRecord> m_listOneHistory;


};

#endif // TESTQMLDATA_H






