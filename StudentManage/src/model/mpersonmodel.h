#ifndef MPERSONMODEL_H
#define MPERSONMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <QQuickView>
#include <QQmlContext>

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

    TagPerson()
    {
        id.clear();firstName.clear();lastName.clear();nameLetter.clear();
        position.clear();person_yuwen = 0;person_math = 0;wifiIp.clear();
        person_english= 0;tianTongId.clear();
        person_tiyu = 0; ttsOpen = false;picturePath.clear();
        bossId.clear();netSort.clear();
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
        baddata=otherPerson.baddata;
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
        baddata=otherPerson.baddata;
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
        baddata
    };

public:
    explicit mPersonModel(QObject *parent = 0);
    static mPersonModel *getInstance();


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
