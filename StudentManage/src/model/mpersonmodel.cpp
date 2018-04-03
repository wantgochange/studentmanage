#include "mpersonmodel.h"

void sortPerson(QList<TagPerson> &listPerson)
{
    //用于对人员按首字母排序
    for(int i = 0; i < listPerson.count(); i++)
    {
        for(int j = i + 1; j < listPerson.count(); j++)
        {
            if(listPerson[i].nameLetter > listPerson[j].nameLetter)
            {
                listPerson.swap(i,j);
            }
        }
    }
}

mPersonModel::mPersonModel(QObject *parent) : QAbstractListModel(parent)
{
    m_listAllPerson.clear();
    m_listShowPerson.clear();

    m_hashRoles[id] = "id";
    m_hashRoles[name] = "name";
    m_hashRoles[nameLetter] = "nameLetter";
    m_hashRoles[position] = "position";
    m_hashRoles[person_tiyu] = "person_tiyu";
    m_hashRoles[person_yuwen]="person_yuwen";
    m_hashRoles[person_math]="person_math";
    m_hashRoles[person_english]="person_english";
    m_hashRoles[tianTongId]="tianTongId";
    m_hashRoles[wifiIp]="wifiIp";
    m_hashRoles[picturePath]="picturePath";
    m_hashRoles[bossId]="bossId";
    m_hashRoles[netSort]="netSort";
    m_hashRoles[person_height]="person_height";
    m_hashRoles[person_weight]="person_weight";
    m_hashRoles[runclass]="runclass";
    m_hashRoles[baddata]="baddata";

    //模型数据
    {
        TagPerson person1;
        person1.id = "201";
        person1.firstName = "张";
        person1.lastName = "文";
        person1.position = "学生";
        person1.nameLetter = "ZW";
        person1.person_tiyu=2;
        person1.person_yuwen=11;
        person1.person_math=11;
        person1.person_english=11;
        person1.person_height=171;
        person1.person_weight=120;
        person1.runclass=1;
        person1.bossId="001";
        person1.baddata=1;

        TagPerson person2;
        person2.id = "202";
        person2.firstName = "陆";
        person2.lastName = "文";
        person2.position = "班长";
        person2.nameLetter = "LW";
        person2.person_tiyu=21;
        person2.person_yuwen=22;
        person2.person_math=22;
        person2.person_english=22;
        person2.person_height=173;
        person2.person_weight=122;
        person2.runclass=2;
        person2.bossId="002";
        person2.baddata=2;


        TagPerson person3;
        person3.id = "203";
        person3.firstName = "艾";
        person3.lastName = "文";
        person3.position = "班长";
        person3.nameLetter = "AW";
        person3.person_tiyu=2;
        person3.person_yuwen=33;
        person3.person_math=33;
        person3.person_english=33;
        person3.person_height=181;
        person3.person_weight=120;
        person3.runclass=33;
        person3.bossId="003";
        person3.baddata=22;


        TagPerson person4;
        person4.id = "204";
        person4.firstName = "毕";
        person4.lastName = "文";
        person4.position = "班长";
        person4.nameLetter = "BW";
        person4.person_tiyu=0;
        person4.person_yuwen=44;
        person4.person_math=44;
        person4.person_english=44;
        person4.person_height=161;
        person4.person_weight=110;
        person4.runclass=11;
        person4.bossId="006";
        person4.baddata=3;


        TagPerson person5;
        person5.id = "205";
        person5.firstName = "菜";
        person5.lastName = "文";
        person5.position = "班长";
        person5.nameLetter = "CW";
        person5.person_tiyu=4;
        person5.person_yuwen=55;
        person5.person_math=55;
        person5.person_english=44;
        person5.person_height=181;
        person5.person_weight=120;
        person5.runclass=11;
        person5.bossId="007";
        person5.baddata=3;


        TagPerson person6;
        person6.id = "206";
        person6.firstName = "戴";
        person6.lastName = "文";
        person6.position = "班长";
        person6.nameLetter = "DW";
        person6.person_tiyu=2;
        person6.person_yuwen=66;
        person6.person_math=66;
        person6.person_english=66;
        person6.person_height=183;
        person6.person_weight=120;
        person6.runclass=11;
        person6.bossId="011";
        person6.baddata=3;


        TagPerson person7;
        person7.id = "207";
        person7.firstName = "张";
        person7.lastName = "杰";
        person7.position = "数学课代表";
        person7.nameLetter = "ZW";
        person7.person_tiyu=0;
        person7.person_yuwen=77;
        person7.person_math=77;
        person7.person_english=77;
        person7.person_height=181;
        person7.person_weight=120;
        person7.runclass=11;
        person7.bossId="007";
        person7.baddata=3;


        TagPerson person8;
        person8.id = "208";
        person8.firstName = "高";
        person8.lastName = "杰";
        person8.position = "语文课代表";
        person8.nameLetter = "GW";
        person8.person_tiyu=0;
        person8.person_yuwen=88;
        person8.person_math=88;
        person8.person_english=888;
        person8.person_height=181;
        person8.person_weight=120;
        person8.runclass=11;
        person8.bossId="007";
        person8.baddata=3;


        TagPerson person9;
        person9.id = "209";
        person9.firstName = "啊";
        person9.lastName = "杰";
        person9.position = "英语课代表";
        person9.nameLetter = "AW";
        person9.person_tiyu=0;
        person9.person_yuwen=99;
        person9.person_math=99;
        person9.person_english=99;
        person9.person_height=181;
        person9.person_weight=120;
        person9.runclass=11;
        person9.bossId="007";
        person9.baddata=3;



        QList<TagPerson> listPerson;
        listPerson.append(person1);
        listPerson.append(person2);
        listPerson.append(person3);
        listPerson.append(person4);
        listPerson.append(person5);
        listPerson.append(person6);
        listPerson.append(person7);
        listPerson.append(person8);
        listPerson.append(person9);

        addPerson(listPerson);
    }
}


mPersonModel* mPersonModel::personModel = NULL;
mPersonModel *mPersonModel::getInstance()
{
    if(!personModel)
    {
        personModel = new mPersonModel();
    }
    return personModel;
}

void mPersonModel::addPerson(QList<TagPerson> &listPerson)
{
    m_listAllPerson.append(listPerson);
    sortPerson(m_listAllPerson);
    updateModel();
}

QVariant mPersonModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= rowCount())
    {
        return QVariant();
    }
    TagPerson person = m_listShowPerson[index.row()];
    switch(role)
    {
    case id:
        return person.id;
    case name:
        return   person.firstName +person.lastName;
    case nameLetter:
        return person.nameLetter.left(1);
    case position:
        return person.position;
    case person_tiyu:
        return person.person_tiyu;
    case person_yuwen:
        return person.person_yuwen;
    case person_math:
        return person.person_math;
    case person_english:
        return person.person_english;
    case tianTongId:
        return person.tianTongId;
    case wifiIp:
        return person.wifiIp;
    case picturePath:
        return person.picturePath;
    case bossId:
        return person.bossId;
    case netSort:
        return person.netSort;
    case person_height:
        return person.person_height;
    case person_weight:
        return person.person_weight;
    case runclass:
        return person.runclass;
    case baddata:
        return person.baddata;
    default:
        return QVariant();
    }
}

int mPersonModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_listShowPerson.count();
}

QString mPersonModel::getNameLetter(int index)
{
    if(index < 0 || index >= rowCount())
        return "1";
    return m_listShowPerson[index].nameLetter.left(1);
}

void mPersonModel::setFilter(QString filter)
{
    if(!filter.isEmpty())
    {
        if(filter.at(0) >= 'a' && filter.at(0)<= 'z')
        {
            if(filter.count()>1)
            {
                char a ;
                a=filter.at(0).toLatin1();
                a -= 32;
                filter += a;
            }
            else{
                char a ;
                a=filter.at(0).toLatin1();
                a -= 32;
                filter = a;
            }
        }
    }
    m_strFilter = filter;
    updateModel();
}

QString mPersonModel::getName(QString id)
{
    for(int i=0;i<m_listAllPerson.count();i++)
    {
        if(id==m_listAllPerson[i].id)
        {
            return m_listAllPerson[i].firstName+m_listAllPerson[i].lastName;
        }
    }
    return id;
}

QString mPersonModel::getLTEnum(QString personId)
{
    for(int i=0;i<m_listAllPerson.count();i++)
    {
        if(m_listAllPerson[i].id==personId)
        {
            return m_listAllPerson[i].person_math+"  "+m_listAllPerson[i].firstName+m_listAllPerson[i].lastName;
        }
    }
    return "";
}

int mPersonModel::getData(QString personID,int atindex)
{
    for(int i = 0 ;i<m_listAllPerson.count();i++){
        if(m_listAllPerson[i].id == personID){
            switch (atindex) {
            case 0:
                return m_listAllPerson[i].person_yuwen;
            case 1:
                return m_listAllPerson[i].person_math;
            case 2:
                return m_listAllPerson[i].person_english;
            case 3:
                return m_listAllPerson[i].person_tiyu;
            case 4:
                return 101;
            case 5:
                return m_listAllPerson[i].person_height;
            case 6:
                return m_listAllPerson[i].person_weight;
            case 7:
                return m_listAllPerson[i].runclass;
            case 8:
                return m_listAllPerson[i].baddata;
            case 9:
                return 102;

            default:
                return 103;
            }
        }
    }
    return 0;
}

QString mPersonModel::getTeacher(QString personID)
{
    for(int i=0;i<m_listAllPerson.count();i++){
        if(personID == m_listAllPerson[i].id){
            return m_listAllPerson[i].bossId;
        }
    }
    return "";
}

QString mPersonModel::getPosition(QString personID)
{
    for(int i=0;i<m_listAllPerson.count();i++){
        if(personID == m_listAllPerson[i].id){
            return m_listAllPerson[i].position;
        }
    }
    return "";
}



QHash<int, QByteArray> mPersonModel::roleNames() const
{
    return m_hashRoles;
}

void mPersonModel::updateModel()
{
    //根据m_strFilter更新模型
    if(rowCount()>0){
        emit beginRemoveRows(QModelIndex(), 0, rowCount() - 1);
        m_listShowPerson.clear();
        emit endRemoveRows();
    }

    if(m_strFilter.isEmpty() && m_listAllPerson.count() > 0)
    {
        emit beginInsertRows(QModelIndex(), 0, m_listAllPerson.count() - 1);
        m_listShowPerson = m_listAllPerson;
        emit endInsertRows();
    }
    else
    {
        for(int i=0;i<m_listAllPerson.count();i++)
        {
            if(m_listAllPerson[i].nameLetter.left(1).contains(m_strFilter) || \
                    m_listAllPerson[i].wifiIp.contains(m_strFilter)||\
                    m_listAllPerson[i].tianTongId.contains(m_strFilter)
                    )
            {
                emit beginInsertRows(QModelIndex(),m_listShowPerson.count(),m_listShowPerson.count());
                m_listShowPerson.append(m_listAllPerson[i]);
                emit endInsertRows();
            }
        }
    }
}
