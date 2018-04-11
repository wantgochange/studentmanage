#ifndef COMDATA_H
#define COMDATA_H

#include <QString>
#include <QDebug>
#include <QStringList>
#include <QList>
#include <QDataStream>
#include <QMetaType>
#include <QByteArray>
#include <QMap>
struct CGroupInfos{
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
    CGroupInfos()
    {
        id.clear();groupIdentity=0;name.clear();managerId.clear();createrId.clear();
        member.clear();netSort.clear();ttsIsOpen=false;
        openView=false;groupnum=0;groupLTEIp.clear();
        groupWifiIp.clear();
        groupAdhoocIp.clear();
        groupTiantongIp.clear();
        groupSelectAll=false;
        groupSelectOne.clear();teacherMember.clear();
    }

    CGroupInfos(const CGroupInfos& otherGroupInfo)
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
        groupSelectOne=otherGroupInfo.groupSelectOne;teacherMember = otherGroupInfo.teacherMember;
    }

    void operator = (const CGroupInfos& otherGroupInfo)
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
        groupSelectOne=otherGroupInfo.groupSelectOne;teacherMember = otherGroupInfo.teacherMember;
    }
};
typedef QList<CGroupInfos> ListContactGroup;


struct TagPersons
{
    QString id;
    QString firstName;
    QString lastName;


    QString nameLetter;
    int person_yuwen;
    int person_math;

    int person_english;

    QString wifiIp;
    QString tianTongId;
    QString picturePath;

    QString netSort;        // this is new add data ,网络首选排序
    int person_tiyu;
    bool ttsOpen;
    QList<int> listNetworkSequence;


    int age;
    QString teacher;
    int grade;
    QString bossId; //班主任ID
    int person_height;
    int person_weight;
    int runclass;
    int baddata;
    QString position;//班级职位
    QString atGroupid;//所在班组id

    TagPersons()
    {
        id.clear();firstName.clear();lastName.clear();nameLetter.clear();
        position.clear();person_yuwen = 0;person_math = 0;wifiIp.clear();
        person_english= 0;tianTongId.clear();
        person_tiyu = 0; ttsOpen = false;picturePath.clear();
        bossId.clear();netSort.clear();atGroupid.clear();
        person_height =0 ;person_weight =0 ;runclass=0;baddata=0;
    }
    TagPersons(const TagPersons& otherPerson)
    {
        id = otherPerson.id; firstName = otherPerson.firstName;
        nameLetter = otherPerson.nameLetter; position = otherPerson.position;
        lastName = otherPerson.lastName; person_yuwen = otherPerson.person_yuwen;
        person_math = otherPerson.person_math; wifiIp = otherPerson.wifiIp;
        person_english = otherPerson.person_english; tianTongId = otherPerson.tianTongId;
        person_tiyu = otherPerson.person_tiyu;
        listNetworkSequence = otherPerson.listNetworkSequence;
        picturePath=otherPerson.picturePath;
        bossId=otherPerson.bossId;netSort=otherPerson.netSort;
        person_height=otherPerson.person_height;person_weight=otherPerson.person_weight;
        runclass=otherPerson.runclass;
        baddata=otherPerson.baddata;atGroupid=otherPerson.atGroupid;
    }

    void operator=(const TagPersons& otherPerson)
    {
        id = otherPerson.id; firstName = otherPerson.firstName;
        nameLetter = otherPerson.nameLetter; position = otherPerson.position;
        lastName = otherPerson.lastName; person_yuwen = otherPerson.person_yuwen;
        person_math = otherPerson.person_math; wifiIp = otherPerson.wifiIp;
        person_english = otherPerson.person_english; tianTongId = otherPerson.tianTongId;
        person_tiyu = otherPerson.person_tiyu;
        listNetworkSequence = otherPerson.listNetworkSequence;
        picturePath=otherPerson.picturePath;
        bossId=otherPerson.bossId;netSort=otherPerson.netSort;
        person_height=otherPerson.person_height;person_weight=otherPerson.person_weight;
        runclass=otherPerson.runclass;
        baddata=otherPerson.baddata;atGroupid=otherPerson.atGroupid;
    }
};
typedef QList<TagPersons> ListContactPerson ;

struct TagTeachers{
    QString id;
    QString teacherName;
    QString position;
    QString atClass;

    TagTeachers(){
        id.clear();teacherName.clear();position.clear();atClass.clear();
    }
    TagTeachers(const TagTeachers& otherTeacher){
        id =otherTeacher.id;
        teacherName = otherTeacher.teacherName;
        position = otherTeacher.position;
        atClass = otherTeacher.atClass;
    }
    void operator=(const TagTeachers& otherTeacher)
    {
        id =otherTeacher.id;
        teacherName = otherTeacher.teacherName;
        position = otherTeacher.position;
        atClass = otherTeacher.atClass;
    }
};
typedef QList<TagTeachers> ListContactTeacher ;


#endif // COMDATA_H
