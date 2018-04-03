#include "mgroupmodel.h"


void sortGroup(QList<CGroupInfo> &listGroup)
{
    //用于对人员按首字母排序
    for(int i = 0; i < listGroup.count(); i++)
    {
        for(int j = i + 1; j < listGroup.count(); j++)
        {
            if(listGroup[i].groupIdentity > listGroup[j].groupIdentity )
            {
                listGroup.swap(i,j);
            }
        }
    }

}
MGroupModel::MGroupModel(QObject *parent) : QAbstractListModel(parent),m_isEdit(false)
{
    m_listAllGroup.clear();
    m_listShowGroup.clear();

    m_hashRoles[id]="id";
    m_hashRoles[groupIdentity]="groupIdentity";
    m_hashRoles[name]="name";
    m_hashRoles[managerId]="managerId";
    m_hashRoles[createrId]="createrId";
    m_hashRoles[member]="member";
    m_hashRoles[netSort]="netSort";
    m_hashRoles[ttsIsOpen]="ttsIsOpen";
    m_hashRoles[openView]="openView";
    m_hashRoles[groupnum]="groupnum";
    m_hashRoles[groupLTEIp]="groupLTEIp";
    m_hashRoles[groupSelectAll]="groupSelectAll";
    m_hashRoles[groupSelectOne]="groupSelectOne";

    {
        CGroupInfo group1;
        group1.id = "101";
        group1.groupIdentity = 1;
        group1.name = "上";
        group1.managerId = "1";
        group1.createrId = "11";
        group1.member = "201,202,203";
        group1.netSort = "自组网,LTE";
        group1.ttsIsOpen = false;
        group1.openView =false;
        group1.groupnum = 3;
        group1.groupSelectAll = false;
        group1.groupSelectOne = "2,2,2";

        CGroupInfo group2;
        group2.id = "102";
        group2.groupIdentity = 2;
        group2.name = "下";
        group2.managerId = "2";
        group2.createrId = "22";
        group2.member = "205,204";
        group2.netSort = "自组网,LTE";
        group2.ttsIsOpen = false;
        group2.openView =false;
        group2.groupnum = 2;
        group2.groupSelectAll = false;
        group2.groupSelectOne = "2,2";

        CGroupInfo group3;
        group3.id = "103";
        group3.groupIdentity = 1;
        group3.name = "中";
        group3.managerId = "1";
        group3.createrId = "111";
        group3.member = "207";
        group3.netSort = "自组网,LTE";
        group3.ttsIsOpen = false;
        group3.openView =false;
        group3.groupnum = 1;
        group3.groupSelectAll = false;
        group3.groupSelectOne = "2,2";

        QList<CGroupInfo> listgroup;
        listgroup.append(group1);
        listgroup.append(group2);
        listgroup.append(group3);

        addGroup(listgroup);
    }

}

void MGroupModel::addGroup(QList<CGroupInfo> &listgroup)
{
    m_listAllGroup.append(listgroup);
    sortGroup(m_listAllGroup);
    updateModel();
}


int MGroupModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_listShowGroup.count();
}

QVariant MGroupModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= rowCount())
    {
        return QVariant();
    }
    CGroupInfo group=m_listShowGroup[index.row()];
    switch (role) {
    case id:
        return group.id;
    case groupIdentity:
        return group.groupIdentity;
    case name:
        return group.name;
    case managerId:
        return group.managerId;
    case createrId:
        return group.createrId;
    case member:
        return group.member;
    case ttsIsOpen:
        return group.ttsIsOpen;
    case netSort:
        return group.netSort;
    case openView:
        return group.openView;
    case groupnum:
        return group.groupnum;
    case groupLTEIp:
        return group.groupLTEIp;
    case groupTiantongIp:
        return group.groupTiantongIp;
    case groupAdhoocIp:
        return group.groupAdhoocIp;
    case groupWifiIp:
        return group.groupWifiIp;
    case groupSelectOne:
        return group.groupSelectOne;
    case groupSelectAll:
        return group.groupSelectAll;
    default:
        return QVariant();
    }
}

int MGroupModel::getgroupIdentity(QString groupId)
{
    for(int i=0;i<m_listShowGroup.count();i++)
    {
        if(groupId==m_listShowGroup[i].id)
        {
            return m_listShowGroup[i].groupIdentity;
        }
    }
    return 0;
}

QString MGroupModel::getMemberName(int row, int index)
{
    QString Id= getMemberId(row,index);
    MPhonebook* phonebookmodel=MPhonebook::getInstance();
    mPersonModel* personModel = phonebookmodel->getpersonModel();

    return personModel->getName(Id);
}

QString MGroupModel::getMemberId(int row, int index)
{
    if(row < 0 || row >= rowCount())
    {
        return 0;
    }
    if(!m_listShowGroup[row].member.isEmpty())
    {
        QStringList strList=m_listShowGroup[row].member.split(",");
        if(index < 0 || index >= strList.count())
        {
            return 0;
        }
        return strList[index];
    }
    return 0;
}

int MGroupModel::m_listShowGroupforIndex(int atindex)
{
//    qDebug() << "ffffffffffffffffffffffffffff: " << atindex <<m_listAllGroup[atindex].groupIdentity;


    return m_listAllGroup[atindex].groupIdentity;
}

void MGroupModel::changeopenView(QString groupid,bool isAll)
{
    if(isAll){//将下拉关闭
        for(int i=0;i<m_listAllGroup.count();i++)
        {
            if(m_listAllGroup[i].openView==true)
            {
                m_listAllGroup[i].openView=false;
            }
        }
        for(int i=0;i<m_listShowGroup.count();i++)
        {
            if(m_listShowGroup[i].openView==true)
            {
                m_listShowGroup[i].openView=false;
                emit dataChanged(index(i),index(i));

            }
        }
    }
    else{
        for(int i=0;i<m_listAllGroup.count();i++)
        {
            if(groupid==m_listAllGroup[i].id&&m_listAllGroup[i].openView==false)
            {
                m_listAllGroup[i].openView=true;
            }
            else if(groupid==m_listAllGroup[i].id&&m_listAllGroup[i].openView!=false){
                m_listAllGroup[i].openView=false;
            }
        }
        for(int i=0;i<m_listShowGroup.count();i++)
        {
            if(groupid==m_listShowGroup[i].id)
            {
                m_listShowGroup[i].openView = !(m_listShowGroup[i].openView);
                emit dataChanged(index(i),index(i));                
            }
        }
    }
}

void MGroupModel::change_SelectAll_openView(QString groupid)
{
    for(int i=0;i<m_listAllGroup.count();i++)
    {
        if(groupid==m_listAllGroup[i].id&&m_listAllGroup[i].groupSelectAll==false)
        {
            changeSuccess_SelectAll_openView(i,true);
            m_listAllGroup[i].groupSelectAll=true;

        }
        else if(groupid==m_listAllGroup[i].id&&m_listAllGroup[i].groupSelectAll!=false){
            changeSuccess_SelectAll_openView(i,false);
            m_listAllGroup[i].groupSelectAll=false;

        }
    }
    for(int i=0;i<m_listShowGroup.count();i++)
    {
        if(groupid==m_listShowGroup[i].id)
        {
            m_listShowGroup[i].groupSelectAll = !(m_listShowGroup[i].groupSelectAll);
            emit dataChanged(index(i),index(i));
            break;
        }
    }
}

void MGroupModel::changeSuccess_SelectAll_openView(int atindex,bool openclass)
{
    QStringList strList=m_listAllGroup[atindex].groupSelectOne.split(",");
    for(int i=0;i<strList.count();i++)
    {
        if(openclass){
            if(strList[i] == "2" )
            {
                strList[i] = "1";
            }
        }
        else{
            if(strList[i] == "1" )
            {
                strList[i] = "2";
            }
        }

    }
    QString openview_backString1;
    for(int j=0;j<strList.count();j++)
    {
        if(j==0)
        {
            openview_backString1 = strList[j];
        }
        else{
            openview_backString1 += "," + strList[j];
        }
    }
    m_listAllGroup[atindex].groupSelectOne=openview_backString1;
    updateModel();
}

void MGroupModel::change_SelectOne_openView(int atrow, int atindex)
{
    if(atrow < 0 || atrow >= rowCount())
    {
        return;
    }
    if(!m_listAllGroup[atrow].groupSelectOne.isEmpty())
    {
        qDebug()<<m_listAllGroup[atrow].groupSelectOne;
        QStringList strList=m_listAllGroup[atrow].groupSelectOne.split(",");
        if(atindex < 0 || atindex >= strList.count())
        {
            return;
        }
        if(strList[atindex] == "2")
        {
            strList[atindex] = "1";
        }
        else{
            strList[atindex] = "2";
        }



        int selectState = 0;
        QString openview_backString1;
        for(int j=0;j<strList.count();j++)
        {
            if(strList[j] == "1"){
                selectState++;
            }
            if(j==0)
            {
                openview_backString1 = strList[j];
            }
            else{
                openview_backString1 += "," + strList[j];
            }
        }
        //检查是否所有的子项都被勾选，是则勾中全选
        if(selectState == strList.count()){
//            qDebug()<<selectState <<strList.count();
            m_listAllGroup[atrow].groupSelectAll = true;
        }
        else{
            m_listAllGroup[atrow].groupSelectAll = false;
        }

        m_listAllGroup[atrow].groupSelectOne=openview_backString1;

        qDebug()<<m_listAllGroup[atrow].groupSelectOne;
        updateModel();
    }


//    if(!m_listShowGroup[atrow].groupSelectOne.isEmpty())
//    {
//        qDebug()<<m_listShowGroup[atrow].groupSelectOne;
//        QStringList strList=m_listShowGroup[atrow].groupSelectOne.split(",");
//        if(atindex < 0 || atindex >= strList.count())
//        {
//            return;
//        }
//        if(strList[atindex] == "2")
//        {
//            strList[atindex] = "1";
//        }
//        else{
//            strList[atindex] = "2";
//        }

//        QString openview_backString;
//        for(int j=0;j<strList.count();j++)
//        {
//            if(j==0)
//            {
//                openview_backString = strList[j];
//            }
//            else{
//                openview_backString += "," + strList[j];
//            }
//        }

//        m_listShowGroup[atrow].groupSelectOne=openview_backString;
//        qDebug()<<m_listShowGroup[atrow].groupSelectOne;
//        emit dataChanged(index(atrow),index(atrow));

//    }
}

QString MGroupModel::get_SelectOne_openView(int atrow, int atindex)
{
    // 0 异常 1开 2关
    if(atrow < 0 || atrow >= rowCount())
    {
        return 0;
    }
    if(!m_listShowGroup[atrow].groupSelectOne.isEmpty())
    {
        QStringList strList=m_listShowGroup[atrow].groupSelectOne.split(",");
        if(atindex < 0 || atindex >= strList.count())
        {
            return 0;
        }
        return strList[atindex];
    }
    return 0;
}

void MGroupModel::cancel_openView()
{
    for(int i=0;i<m_listAllGroup.count();i++){
        m_listAllGroup[i].openView = false;
    }
    updateModel();
}

void MGroupModel::cancel_Selec_openView()
{
    for(int x=0; x<m_listAllGroup.count();x++) {
        QStringList strList=m_listAllGroup[x].groupSelectOne.split(",");
        for(int i=0;i<strList.count();i++){
            if(strList[i] == "1"){
                strList[i] = "2";
            }
        }
        QString openview_backString;
        for(int j=0;j<strList.count();j++)
        {
            if(j==0)
            {
                openview_backString = strList[j];
            }
            else{
                openview_backString += "," + strList[j];
            }
        }
        qDebug()<<m_listAllGroup[x].groupSelectOne;
        m_listAllGroup[x].groupSelectOne = openview_backString;
        m_listAllGroup[x].groupSelectAll = false;
        qDebug()<<m_listAllGroup[x].groupSelectOne;
        updateModel();
    }
}

void MGroupModel::insert_AllMember(QString selectMemberID,QString selectgroupId,int getclass)
{//勾选的成员id list 群组id  给予的属性
    qDebug()<< selectMemberID;
    QStringList select_MemberList=selectMemberID.split(",");
    //删除原成员
    for(int i =0;i<m_listAllGroup.count();i++){
        QStringList strList=m_listAllGroup[i].member.split(",");
        QString tempMemberList; //临时替换的群组成员 变量
        for(int j=0;j<strList.count();j++){//遍历找群组内某ID的位置,进行删除
            for(int x=0;x<select_MemberList.count();x++){
                if(select_MemberList[x] == strList[j]){
                    strList.removeAt(j);
                    m_listAllGroup[i].groupnum--;
                }
            }
        }

        //修改数据
        for(int r =0;r<strList.count();r++){
            if(r ==0 ){
                tempMemberList.append(strList[r]);
            }
            else{
                tempMemberList.append(","+strList[r]);
            }
        }
        m_listAllGroup[i].member = tempMemberList;
        m_listShowGroup[i].member = tempMemberList;
        qDebug()<<tempMemberList<<m_listShowGroup[i].member;
        emit dataChanged(index(i),index(i));
    }
    //添加群成员
    for(int a=0;a<m_listAllGroup.count();a++){
        QString add_member;
        if(selectgroupId == m_listAllGroup[a].id){

            QStringList add_strList=m_listShowGroup[a].member.split(",");
            for(int y=0;y<select_MemberList.count();y++){
                QString tempID=select_MemberList[y];
                if(getclass == 1){//指定为班长
                    add_strList.insert(0,tempID);
                    m_listAllGroup[a].groupnum++;
                }
                else{
                    if(add_strList.count() >0){
                        add_strList.append(","+tempID);
                        m_listAllGroup[a].groupnum++;

                    }
                    else{
                        add_strList.append(tempID);
                        m_listAllGroup[a].groupnum++;

                    }
                }
            }
            for(int z=0;z<add_strList.count();z++){
                if(getclass == 1){
                    if(z ==0 ){

                        add_member.append(add_strList[z]);
                    }
                    else{
                        add_member.append(","+add_strList[z]);
                    }
                }
                else{
                    add_member.append(add_strList[z]);
                }

            }
            m_listAllGroup[a].member = add_member;
            m_listShowGroup[a].member = add_member;

            qDebug()<<add_member<<m_listShowGroup[a].member;
            emit dataChanged(index(a),index(a));
        }
    }
    updateModel();

}

QString MGroupModel::get_SelectMember_ID()
{
    int atIndex = 0;
    QString MoveMemeber_list;
    for(int j =0; j<m_listShowGroup.count();j++){
        QStringList strList=m_listShowGroup[j].groupSelectOne.split(",");
        for(int i = 0;i<strList.count();i++){
            if(strList[i] == "1"){
                QStringList Member_strList=m_listShowGroup[j].member.split(",");
                qDebug()<< Member_strList[i]<<MoveMemeber_list;
                if(atIndex ==0){
                    MoveMemeber_list.append( Member_strList[i]);
                    atIndex++;
                }
                else{
                    MoveMemeber_list.append(","+Member_strList[i]);
                }
            }
        }
    }
    qDebug() <<MoveMemeber_list;
    return MoveMemeber_list;
}

void MGroupModel::delete_Group()
{

}

void MGroupModel::add_Group()
{

}



int MGroupModel::get_Select_openView()
{
    int temp_num = 0;
    for(int j =0; j<m_listShowGroup.count();j++){
        QStringList strList=m_listShowGroup[j].groupSelectOne.split(",");
        for(int i = 0;i<strList.count();i++){
            if(strList[i] == "1"){
                temp_num++;
            }
        }
    }
    return temp_num;
}

QHash<int, QByteArray> MGroupModel::roleNames() const
{
    return m_hashRoles;
}

void MGroupModel::updateModel()
{
    if(rowCount() > 0)
    {
         beginRemoveRows(QModelIndex(),0,rowCount() -1);
        m_listShowGroup.clear();
         endRemoveRows();
     }
     beginInsertRows(QModelIndex(), 0, m_listAllGroup.count() - 1);
    m_listShowGroup = m_listAllGroup;
     endInsertRows();
    emit updataToQml();
}
