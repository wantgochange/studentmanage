#ifndef MIMMESSAGE_H
#define MIMMESSAGE_H

#include <QObject>
#include <QAbstractListModel>

struct TagImdate
{
    QString id;                 //唯一标识
    int     type;               //数据类型,与枚举通讯消息类型对应
    QString content;            //内容。文本-传输文本内容，其他-文件的绝对路径（包含文件名）
//    long time;               //发送时间
    QString time;
    QString senderId;           //发送者ID
    QString receiverId;         //接收者ID
    QString netType;            //网络类型,与枚举网络类型对应
    QString remark;             //备注。消息为语音和视频文件时保存时长，其他消息类型的保留字段
    bool    isTransmissionOk;   //是否收发送数据成功
    bool   isLook;              //是否未读
    int    isMy;                //发送类型
    bool  isSendFalse;          //是否在发送中  true ->发送完成  fasle ->发送中
    int  isGetimOK;            //是否在接收中    1 ->接收失败 0 ->接收中

    TagImdate()
    {
        id.clear();content.clear();/*time = 0;*/senderId.clear();
        time.clear();
        receiverId.clear();remark.clear();
        type=0;netType.clear();isTransmissionOk=true;isLook=true;isMy=0;
        isSendFalse=false;isGetimOK=0;
    }
    TagImdate(const TagImdate&  otherTagImdate)
    {
        id=otherTagImdate.id;content=otherTagImdate.content;
        time=otherTagImdate.time;senderId=otherTagImdate.senderId;
        receiverId=otherTagImdate.receiverId;remark=otherTagImdate.remark;
        type=otherTagImdate.type;netType=otherTagImdate.netType;
        isTransmissionOk=otherTagImdate.isTransmissionOk;isLook=otherTagImdate.isLook;
        isMy=otherTagImdate.isMy;isSendFalse=otherTagImdate.isSendFalse;
        isGetimOK=otherTagImdate.isGetimOK;
    }

    void operator = (const TagImdate& otherTagImdate)
    {
        id = otherTagImdate.id; type = otherTagImdate.type;
        content = otherTagImdate.content; time = otherTagImdate.time;
        senderId = otherTagImdate.senderId; receiverId  = otherTagImdate.receiverId;
        netType = otherTagImdate.netType; remark = otherTagImdate.remark;
        isTransmissionOk = otherTagImdate.isTransmissionOk;isLook=otherTagImdate.isLook;
        isMy=otherTagImdate.isMy;isSendFalse=otherTagImdate.isSendFalse;
        isGetimOK=otherTagImdate.isGetimOK;
    }
};


class MImMessage : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ContactRoles{
        id=Qt::UserRole +1,
        type,
        content,
        time,
        senderId,
        receiverId,
        netType,
        remark,
        isTransmissionOk,
        isLook,
        isMy,
        isSendFalse,
        isGetimOK
    };

public:
    explicit MImMessage(QObject *parent = 0);
    void addContactRecord(QList<TagImdate> & listIm);
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    Q_INVOKABLE void sendMessage(QString sendtext,QString sendTime,int sendtype,QString sendid); //发送信息
    Q_INVOKABLE void setContactId(QString strId); //设置联系人id
    Q_INVOKABLE void getpIMModel(QString pIMid);//获取对应联系人的model

private:
    QString m_strreceiverid;
    QList<TagImdate>  m_listAllIM;
    QList<TagImdate>  m_listShowIM;
    QHash<int,QByteArray>   m_hashRoles;
    void updateModel();

protected:
    QHash<int,QByteArray> roleNames() const;

signals:

public slots:
};

#endif // MIMMESSAGE_H
