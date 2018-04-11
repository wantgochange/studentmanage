#ifndef MPERSONMODEL_H
#define MPERSONMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <QQuickView>
#include <QQmlContext>
#include "./../../comdata.h"

struct TagPerson
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
    int grade;
    QString bossId; //班主任ID
    int person_height;
    int person_weight;
    int runclass;
    int baddata;
    QString position;//班级职位
    QString atGroupid;//所在班组id

    TagPerson()
    {
        id.clear();firstName.clear();lastName.clear();nameLetter.clear();
        position.clear();person_yuwen = 0;person_math = 0;wifiIp.clear();
        person_english= 0;tianTongId.clear();
        person_tiyu = 0; ttsOpen = false;picturePath.clear();
        bossId.clear();netSort.clear();atGroupid.clear();
        person_height =0 ;person_weight =0 ;runclass=0;baddata=0;
    }
    TagPerson(const TagPerson& otherPerson)
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

    void operator=(const TagPerson& otherPerson)
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


class mPersonModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum PersonRoles{
        name = Qt::UserRole +1,
        nameLetter,
        position,
        person_tiyu,
        person_yuwen,
        person_math,
        id,
        person_english,
        wifiIp,
        tianTongId,
        picturePath,
        bossId,
        netSort,
        person_height,
        person_weight,
        runclass,
        baddata,
        atGroupid
    };

public:
    explicit mPersonModel(QObject *parent = 0);
    static mPersonModel *getInstance();

    void initPersonModel();   //初始化学生列表

    void addPerson(QList<TagPerson>& listPerson);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    Q_INVOKABLE QString getNameLetter(int index);

     Q_INVOKABLE void setFilter(QString filter);//搜索查找
    Q_INVOKABLE QString getName(QString id);//获取姓名
    //获取IP
    Q_INVOKABLE QString getLTEnum(QString personId);
    //查询数据
    Q_INVOKABLE int getData(QString personID,int atindex);
    //获取班主任信息 ID
    Q_INVOKABLE QString getTeacher(QString personID);
    //获取职位信息
    Q_INVOKABLE QString getPosition(QString personID);
    //获取所在群组信息
    Q_INVOKABLE QString getAtgroupInfo(QString personID);
    //修改个人信息
    Q_INVOKABLE void changePersonInfo(QString pId,QString input_name,QString input_position,
                                      int input_yuwen, int input_math, int input_english,
                                      int input_tiyu, QString input_teacher, int input_height,
                                      int input_width, int input_runclass, int input_beddata);


signals:

public slots:

protected:
    QHash<int,QByteArray> roleNames() const;
private:
    void updateModel();

    QList<TagPerson>        m_listAllPerson;
    QList<TagPerson>        m_listShowPerson;
    QHash<int,QByteArray>   m_hashRoles;
    QString                 m_strFilter;
    static mPersonModel* personModel;

};

#endif // MPERSONMODEL_H
