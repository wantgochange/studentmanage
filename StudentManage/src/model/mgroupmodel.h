#ifndef MGROUPMODEL_H
#define MGROUPMODEL_H

#include <QObject>
#include<QAbstractListModel>

#include "mpersonmodel.h"

//#include "./../cbridgeservice.h"
//#include "./../../datatype/define.h"
//#include "./../../datatype/comdata.h"
#include <QDebug>
#include "./../../comdata.h"

struct CGroupInfo{
//    GroupInfo groupInfo;
    QString id;             //群组唯一识别ID
    int     groupIdentity;  //群组性质。0-建制,1-战时 2-固定群组  1/班  2、组
    QString name;           //群名字
    QString managerId;      //管理员ID
    QString createrId;      //创建者ID
    QString member;         //群成员(字符串)，数据格式为连续的群成员id，成员id之间用','隔开
    QString netSort;
    bool ttsIsOpen;
    bool openView;          //群组成员是否打开
    int groupnum;           //群组成员数目
    QString groupLTEIp;        //群组Ip 组播地址
    QString groupAdhoocIp;
    QString groupWifiIp;
    QString groupTiantongIp;

    bool groupSelectAll;    //群组全选按钮开关
    QString groupSelectOne;    //群组成员按钮开关 1 开  2关

    QString teacherMember; //教师列

    CGroupInfo()
    {
        id.clear();groupIdentity=0;name.clear();managerId.clear();createrId.clear();
        member.clear();netSort.clear();ttsIsOpen=false;
        openView=false;groupnum=0;groupLTEIp.clear();
        groupWifiIp.clear();
        groupAdhoocIp.clear();
        groupTiantongIp.clear();
        groupSelectAll=false;
        groupSelectOne.clear();
        teacherMember.clear();
    }

    CGroupInfo(const CGroupInfo& otherGroupInfo)
    {
        id=otherGroupInfo.id;groupIdentity=otherGroupInfo.groupIdentity;name=otherGroupInfo.name;
        managerId=otherGroupInfo.managerId;createrId=otherGroupInfo.createrId;
        member=otherGroupInfo.member;ttsIsOpen=otherGroupInfo.ttsIsOpen;
        netSort=otherGroupInfo.netSort;openView=otherGroupInfo.openView;
        groupnum=otherGroupInfo.groupnum;groupLTEIp=otherGroupInfo.groupLTEIp;
        groupWifiIp=otherGroupInfo.groupWifiIp;
        groupAdhoocIp=otherGroupInfo.groupAdhoocIp;
        groupTiantongIp=otherGroupInfo.groupTiantongIp;
        groupSelectAll=otherGroupInfo.groupSelectAll;
        groupSelectOne=otherGroupInfo.groupSelectOne;
        teacherMember = otherGroupInfo.teacherMember;
    }

    void operator = (const CGroupInfo& otherGroupInfo)
    {
        id = otherGroupInfo.id; groupIdentity = otherGroupInfo.groupIdentity;
        name = otherGroupInfo.name; managerId = otherGroupInfo.managerId;
        createrId = otherGroupInfo.createrId; member = otherGroupInfo.member;ttsIsOpen=otherGroupInfo.ttsIsOpen;
        netSort=otherGroupInfo.netSort;openView=otherGroupInfo.openView;
        groupnum=otherGroupInfo.groupnum;groupLTEIp=otherGroupInfo.groupLTEIp;
        groupWifiIp=otherGroupInfo.groupWifiIp;
        groupAdhoocIp=otherGroupInfo.groupAdhoocIp;
        groupTiantongIp=otherGroupInfo.groupTiantongIp;
        groupSelectAll=otherGroupInfo.groupSelectAll;
        groupSelectOne=otherGroupInfo.groupSelectOne;
        teacherMember=otherGroupInfo.teacherMember;
    }
};
class MGroupModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum GroupRoles{
        id=Qt::UserRole +1,
        groupIdentity,
        name,
        managerId,
        createrId,
        member,
        ttsIsOpen,
        netSort,
        openView,
        groupnum,
        groupLTEIp,
        groupWifiIp,
        groupAdhoocIp,
        groupTiantongIp,
        groupSelectAll,
        groupSelectOne,
        teacherMember

    };

public:
    //备注  每次 成员变更时，需要更改他的勾选状态
    explicit MGroupModel(QObject *parent = 0);
    static MGroupModel *getInstance();
    void addGroup(QList<CGroupInfo> & listgroup);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;

    void initGroupModel();

    Q_INVOKABLE int getgroupIdentity(QString groupId);//获取群组性质
    Q_INVOKABLE int getMemberNum(QString groupId); //获取群组成员数目
    Q_INVOKABLE QString getGroupName(QString groupId);//获取群名字
    Q_INVOKABLE int getGroupIndex(QString groupId); //获取群组行数
    Q_INVOKABLE QString getMemberName(int row, int index);//获取成员姓名
    Q_INVOKABLE QString getMemberId(int row,int index); //获取成员ID
    Q_INVOKABLE int get_Select_openView();               //获取群组成员勾选状态个数
    Q_INVOKABLE QString get_SelectOne_openView(int atrow, int atindex);       //获取群组成员勾选状态
    Q_INVOKABLE QString get_SelectMember_ID();        //获取被勾选的成员id list
    Q_INVOKABLE int m_listShowGroupforIndex(int atindex); //根据index获取群组性质

    Q_INVOKABLE void changeopenView(QString groupid,bool isAll);           //修改群组打开状态,或将下拉框关闭
    Q_INVOKABLE void change_SelectAll_openView(QString groupid);           //修改群组全选状态
    Q_INVOKABLE void changeSuccess_SelectAll_openView(int atindex,bool openclass);    //完成群组全选状态
    Q_INVOKABLE void change_SelectOne_openView(int atrow, int atindex);    //修改群组勾选状态

    Q_INVOKABLE void cancel_openView();       //取消群组打开状态
    Q_INVOKABLE void cancel_Selec_openView();       //取消群组勾选状态
    //多个勾选移动
    Q_INVOKABLE void insert_AllMember(QString selectMemberID,QString selectgroupId,int getclass);
    Q_INVOKABLE void delete_Group();            //删除群组
    Q_INVOKABLE void add_Group(QString g_groupName,int g_groupIdentity);               //添加群组
    Q_INVOKABLE void delete_Member(QString at_groupId);              //删除成员

    //比较群组成员id
    Q_INVOKABLE bool comper_groupMember(QString groupID,QString memberId);
    //添加群组成员
    Q_INVOKABLE void append_groupMember(QString groupID,QString memberId);

protected:
    QHash<int,QByteArray> roleNames() const;
private:
    void updateModel();

    bool                    m_isEdit;
    QList<CGroupInfo>        m_listAllGroup;
    QList<CGroupInfo>        m_listShowGroup;
    QHash<int,QByteArray>   m_hashRoles;

     static MGroupModel* groupModel;
signals:
    void updataToQml();
//    void signalSendSyncCallManager(ListSyncCallManager list,int sync);

public slots:
};

#endif // MGROUPMODEL_H
