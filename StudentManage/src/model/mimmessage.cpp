#include "mimmessage.h"
#include <QDateTime>
#include <QDebug>

MImMessage::MImMessage(QObject *parent) :
    QAbstractListModel(parent)
{
    m_listShowIM.clear();

    m_hashRoles[id]="id";
    m_hashRoles[content]="content";
    m_hashRoles[type]="type";      //数据类型,与枚举通讯消息类型对应
    m_hashRoles[time]="time";
    m_hashRoles[senderId]="senderId";
    m_hashRoles[receiverId]="receiverId";
    m_hashRoles[netType]="netType";
    m_hashRoles[isTransmissionOk]="isTransmissionOk";
    m_hashRoles[isLook]="isLook";
    m_hashRoles[remark]="remark";
    m_hashRoles[isSendFalse]="isSendFalse";
    m_hashRoles[isGetimOK]="isGetimOK";

    {
        TagImdate Im1;
//        Im1.id=QUuid::createUuid().toString();
        Im1.id="1";
        Im1.content="txtssssssssssssssssssssssssss.txt";
//        Im1.type=MESSAGE_FILE;
        Im1.type=1;
        Im1.time="2017-09-21 23:43:15";
        Im1.netType="LTE";
        Im1.isTransmissionOk=true;
        Im1.isLook=false;
        Im1.senderId="1";
//        Im1.receiverId="202";


        TagImdate Im2;
//        Im2.id=QUuid::createUuid().toString();
        Im2.id="2";
        Im2.content="mp3ssssssssssssssssssssssssssssssssssssss.mp3";
//        Im2.type=MESSAGE_FILE;
        Im2.type=2;
        Im2.time="2017-09-22 08:43:15";
        Im2.netType="LTE";
        Im2.isTransmissionOk=false;
        Im2.isLook=false;
        Im2.senderId="2";

        TagImdate Im3;
//        Im3.id=QUuid::createUuid().toString();
        Im3.id="1";
        Im3.content="今天早上要下雨吗今天早上要下雨吗今天早上要下雨吗";
//        Im3.type=MESSAGE_TEXT;
        Im3.type=1;
        Im3.time="2017-09-22 09:43:15";
        Im3.netType="ADHOC";
        Im3.isTransmissionOk=true;
        Im3.isLook=false;
        Im3.senderId="1";

        TagImdate Im4;
//        Im4.id=QUuid::createUuid().toString();
        Im4.id="1";
        Im4.content="今天早上不下雨，明天早上下雨,今天早上不下雨，明天早上下雨,今天早上不下雨，明天早上下雨,今天早上不下雨，明天早上下雨,今天早上不下雨，明天早上下雨,今天早上不下雨，明天早上下雨";
//        Im4.type=MESSAGE_TEXT;
        Im4.type=1;
        Im4.time="2017-09-22 10:43:15";
        Im4.netType="WIFI";
        Im4.isTransmissionOk=false;
        Im4.isLook=false;
        Im4.senderId="2";

        TagImdate Im5;
//        Im5.id=QUuid::createUuid().toString();
        Im5.id="2";
        Im5.content="./../images/contact/contact_spec.png";
        Im5.type=3;
        Im5.time="2017-09-22 11:43:15";
        Im5.netType="TIANTONG";
        Im5.isTransmissionOk=true;
        Im5.isLook=false;
        Im5.senderId="1";

        TagImdate Im6;
//        Im6.id=QUuid::createUuid().toString();
        Im6.id="1";
        Im6.content="./../images/contact/contact_spec.png";
        Im6.type=3;
        Im6.time="2017-09-22 12:43:15";
        Im6.netType="TIANTONG";
        Im6.isTransmissionOk=false;
        Im6.isLook=false;
        Im6.senderId="2";

        TagImdate Im7;
//        Im7.id=QUuid::createUuid().toString();
        Im7.id="2";
        Im7.content="";
        Im7.type=2;
        Im7.time="2017-09-22 13:43:15";
        Im7.netType="TIANTONG";
        Im7.isTransmissionOk=true;
        Im7.isLook=false;
        Im7.senderId="2";

        TagImdate Im8;
//        Im8.id=QUuid::createUuid().toString();
        Im8.id="2";
        Im8.content="";
        Im8.type=4;
        Im8.time="2017-09-22 14:43:15";
        Im8.netType="TIANTONG";
        Im8.isTransmissionOk=true;
        Im8.isLook=false;
        Im8.senderId="1";

        TagImdate Im9;
//        Im9.id=QUuid::createUuid().toString();
        Im9.id="1";
        Im9.content="";
        Im9.type=4;
        Im9.time="2017-09-11 14:43:15";
        Im9.netType="ADHOC";
        Im9.isTransmissionOk=true;
        Im9.isLook=false;
        Im9.senderId="2";

        TagImdate Im10;
//        Im10.id=QUuid::createUuid().toString();
        Im10.id="1";
        Im10.content="";
        Im10.type=2;
        Im10.time="2017-09-12 14:43:15";
        Im10.netType="ADHOC";
        Im10.isTransmissionOk=true;
        Im10.isLook=false;
        Im10.senderId="1";

        QList<TagImdate> listIm;
        listIm.append(Im1);
        listIm.append(Im2);
        listIm.append(Im3);
        listIm.append(Im4);
        listIm.append(Im5);
        listIm.append(Im6);
        listIm.append(Im7);
        listIm.append(Im8);
        listIm.append(Im9);
        listIm.append(Im10);

        addContactRecord(listIm);
    }
}

void MImMessage::addContactRecord(QList<TagImdate> &listIm)
{
    m_listShowIM.append(listIm);
}

int MImMessage::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_listShowIM.count();
}

QVariant MImMessage::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= rowCount())
    {
        return QVariant();
    }
    TagImdate IM=m_listShowIM[index.row()];
    switch (role) {
    case id:
        return IM.id;
    case content:
        return IM.content;
    case type:
        return IM.type;
    case time:
//        return QString::number(IM.time);
        return IM.time;
    case netType:
        return IM.netType;
    case isTransmissionOk:
        return IM.isTransmissionOk;
    case isLook:
        return IM.isLook;
    case senderId:
        return IM.senderId;
    case isSendFalse:
        return IM.isSendFalse;
    case remark:
        return IM.remark;
    case isGetimOK:
        return IM.isGetimOK;
    default:
        return QVariant();
    }
}

void MImMessage::sendMessage(QString sendtext, QString sendTime, int sendtype, QString sendid)
{

    TagImdate IM;
//    IM.id=QUuid::createUuid().toString().remove("{").remove("}").replace("-", "");
    IM.id = "1";
    IM.content=sendtext;
    IM.type=sendtype;
    IM.time= sendTime;
    IM.netType = "adhoc";
    IM.senderId=sendid;
    IM.receiverId=m_strreceiverid;
    IM.isTransmissionOk=false;//是否发送成功
    IM.isSendFalse=false;//发送中
    IM.remark="";
    IM.isLook=true;

    emit beginInsertRows(QModelIndex(), m_listShowIM.count(), m_listShowIM.count());
    m_listShowIM.append(IM);
    emit endInsertRows();

    qDebug()<<m_listShowIM.count()<<IM.content;
}

void MImMessage::setContactId(QString strId)
{
    m_strreceiverid = strId;


}

void MImMessage::getpIMModel(QString pIMid)
{
//    if(rowCount()>0)
//    {
//        emit beginRemoveRows(QModelIndex(), 0, rowCount() - 1);
//        m_listShowIM.clear();
//        emit endRemoveRows();
//    }
//    ListImHistoryData listImHistoryData = CBridgeService::getInstance()->getImData(pIMid);//从数据库获取相应人的聊天model
//    if(listImHistoryData.count() > 0)
//    {
//        emit beginInsertRows(QModelIndex(), 0, listImHistoryData.count()-1);
//        for(int i=0;i<listImHistoryData.count();i++)
//        {
//            TagImdate tagImdate;
//            tagImdate.id=listImHistoryData[i].id;
//            tagImdate.type=listImHistoryData[i].type;
//            tagImdate.content=listImHistoryData[i].content;
//            tagImdate.time=listImHistoryData[i].time;
//            tagImdate.senderId=listImHistoryData[i].senderId;
//            tagImdate.receiverId=listImHistoryData[i].receiverId;
//            if(tagImdate.type == 3)
//            {
//                tagImdate.content.remove("file://");
//                tagImdate.content.insert(0,"file://");
//            }


//            QStringList templist=exchangeNet(listImHistoryData[i].netType).split(",");
//            QString tempstring;
//            for(int i=0;i<templist.count();i++)
//            {
//                if( i == 0)
//                {
//                    tempstring.append(netToString(templist[i].toInt()));
//                }
//                else{
//                    tempstring.append(","+netToString(templist[i].toInt()));
//                }
//                DEBUG_OUT << tempstring;
//            }
//            tagImdate.netType= tempstring;
//            tagImdate.remark=listImHistoryData[i].remark;
//            tagImdate.isTransmissionOk=listImHistoryData[i].isTransmissionOk;
//            tagImdate.isLook=listImHistoryData[i].isRead;
//            tagImdate.isSendFalse=true;
//            qDebug() <<listImHistoryData[i].netType<< "iiiiiiiiiii--:" ;
//            m_listShowIM.append(tagImdate);
//        }
//        emit endInsertRows();
//    }
}

void MImMessage::updateModel()
{

}

QHash<int, QByteArray> MImMessage::roleNames() const
{
    return m_hashRoles;
}
