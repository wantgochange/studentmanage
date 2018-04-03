#ifndef PHONECALLMODEL_H
#define PHONECALLMODEL_H
#include <QDateTime>
#include <QObject>


struct HandlerManager
{
    QString handlerId;               ///< user ID
    QString dialNumber;              ///< 所拨打的电话号码
    int network;                     ///< 网络类型  取自 common.h::NetworkType
    int state;                       ///< 通话业务的状态  取自 common.h::DialTransStatus
    bool isIncoming;                 ///< ture : 当前通话是呼入电话; false : 当前是呼出电话
    bool isMultiparty;               ///< ture : 当前通话是电话会议; false : 当前通话不是电话会议
    bool isMuted;                    ///< true : 当前是静音 ;       false : 当前不是静音
    bool isHandsfree ;               ///< true : 当前是免提 ;       false : 当前不是免提
    bool isRecord ;                  ///< true : 当前是录音 ;       false : 当前不是录音
    QDateTime startTime;                //电话开始计时
    bool isAudio;                       //语音
    bool isOnline;                       //是否在线


    HandlerManager()
    {
        handlerId.clear();dialNumber.clear();network = 0; state = 0;
        isIncoming = false; isMultiparty = false; isMuted = false;
        isHandsfree = false; isRecord = false;
        startTime = QDateTime::currentDateTime();
        isAudio = true;
        isOnline = true;
    }
    HandlerManager(const HandlerManager& info)
    {
        handlerId = info.handlerId;
        dialNumber = info.dialNumber;
        network = info.network;
        state = info.state;
        isIncoming = info.isIncoming;
        isMultiparty = info.isMultiparty;
        isMuted = info.isMuted;
        isHandsfree = info.isHandsfree;
        isRecord = info.isRecord;
        startTime = info.startTime;
        isAudio = info.isAudio;
        isOnline = info.isOnline;
    }

    void operator=(const HandlerManager& info)
    {
        handlerId = info.handlerId;
        dialNumber = info.dialNumber;
        network = info.network;
        state = info.state;
        isIncoming = info.isIncoming;
        isMultiparty = info.isMultiparty;
        isMuted = info.isMuted;
        isHandsfree = info.isHandsfree;
        isRecord = info.isRecord;
        startTime = info.startTime;
        isAudio = info.isAudio;
        isOnline = info.isOnline;
    }
};



class PhoneCallModel : public QObject
{
    Q_OBJECT
public:
    enum PhoneCallRoles{
        handlerId,
        dialNumber,
        network,
        state,
        isIncoming,
        isMultiparty,
        isMuted,
        isHandsfree,
        isRecord,
        startTime,
        isAudio,
        isOnline
    };

public:
    explicit PhoneCallModel(QObject *parent = 0);
    QList<HandlerManager> m_handlerList;

    Q_INVOKABLE void atstartTime();
    Q_INVOKABLE QString returnStartTime();

signals:

public slots:

private:
     HandlerManager handlerManager;
    QString timeToString(int time);

};

#endif // PHONECALLMODEL_H
