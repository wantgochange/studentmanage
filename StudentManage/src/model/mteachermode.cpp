#include "mteachermode.h"
#include <QDebug>
#include "./../../mainwindow.h"
MteacherMode::MteacherMode(QObject *parent) : QAbstractListModel(parent)
{
    m_listAllTeacher.clear();
    m_listShowTeacher.clear();

    m_hashRoles[id] = "id";
    m_hashRoles[position] = "position";
    m_hashRoles[teacherName] = "teacherName";
    m_hashRoles[atClass] = "atClass";


    TagTeacher teacher1;
    teacher1.id = "011";
    teacher1.position = "语文";
    teacher1.teacherName = "李浩";
    teacher1.atClass = "001,002";


    TagTeacher teacher2;
    teacher2.id = "012";
    teacher2.position = "数学";
    teacher2.teacherName = "朱军";
    teacher2.atClass = "003";

    QList<TagTeacher> listTeacher;
    listTeacher.append(teacher1);
    listTeacher.append(teacher2);
//    addTeacher(listTeacher);
}
MteacherMode* MteacherMode::teacherModel = NULL;
MteacherMode *MteacherMode::getInstance()
{
    if(!teacherModel)
    {
        teacherModel = new MteacherMode();
    }
    return teacherModel;
}

void MteacherMode::addTeacher(QList<TagTeacher> &listTeacher)
{
    m_listAllTeacher.append(listTeacher);
    updateModel();
}

QVariant MteacherMode::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= rowCount())
    {
        return QVariant();
    }
    TagTeacher teacher = m_listShowTeacher[index.row()];
    switch(role)
    {
    case id:
        return teacher.id;
    case teacherName:
        return teacher.teacherName;
    case position:
        return teacher.position;
    case atClass:
        return teacher.atClass;
    default:
        return QVariant();
    }
}

int MteacherMode::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_listAllTeacher.count();
}

void MteacherMode::initTeacherModel()
{
    //获取从数据库下拉的数据
    QList<TagTeachers> list_teacher;
    MainWindow* main =new MainWindow();
    list_teacher = main->get_teacherModel();
    QList<TagTeacher> listTeacher;
    for(int i=0;i<list_teacher.count();i++){
        TagTeacher teacher;
        teacher.id = list_teacher[i].id;
        teacher.teacherName = list_teacher[i].teacherName;
        teacher.position = list_teacher[i].position;
        teacher.atClass = list_teacher[i].atClass;

        listTeacher.append(teacher);
    }
    addTeacher(listTeacher);
}

QString MteacherMode::getTeacherGroup(QString teacherId)
{
    for(int i=0;i<m_listAllTeacher.count();i++){
        if(m_listAllTeacher[i].id == teacherId){
            return m_listAllTeacher[i].atClass;
        }
    }
    return "";
}

int MteacherMode::getTeacherGroupcount(QString teacherId)
{
    for(int i=0;i<m_listAllTeacher.count();i++){
        if(m_listAllTeacher[i].id == teacherId){
            qDebug()<<m_listAllTeacher[i].atClass.split(",").count();
            return m_listAllTeacher[i].atClass.split(",").count();
        }
    }
    return 0;
}

QString MteacherMode::get_TeacherGroup(int atindex,QString teacherId)
{
    QStringList teacher_groupId = teacherId.split(",");
    return MGroupModel::getInstance()->getGroupName(teacher_groupId[atindex]);
}

QString MteacherMode::get_teacherName(QString teacherId)
{
    qDebug() << "m_listAllTeacher[i].teacherName"<<teacherId<<m_listAllTeacher.count();
    for(int i=0;i<m_listAllTeacher.count();i++){
        if(m_listAllTeacher[i].id == teacherId){
            qDebug() << m_listAllTeacher[i].teacherName;
            return m_listAllTeacher[i].teacherName;
        }
    }
    qDebug() << "m_listAllTeacher[i].teacherName"<<teacherId;
    return "";
}

QString MteacherMode::get_teacherPosition(QString teacherId)
{
    for(int i=0;i<m_listAllTeacher.count();i++){
        if(m_listAllTeacher[i].id == teacherId){
            return m_listAllTeacher[i].position;
        }
    }
    return "";
}

void MteacherMode::change_TeacherInfo(QString teacher_Id,QString teacher_name, QString teacher_position)
{
    qDebug() <<teacher_Id<<teacher_name<<teacher_position<<"修改教师信息" ;
    for(int i=0;i<m_listAllTeacher.count();i++){
        if(m_listAllTeacher[i].id == teacher_Id){
            m_listAllTeacher[i].teacherName = teacher_name;
            m_listAllTeacher[i].position = teacher_position;
            emit dataChanged(index(i),index(i));
        }
    }
}

QHash<int, QByteArray> MteacherMode::roleNames() const
{
    return m_hashRoles;
}

void MteacherMode::updateModel()
{
    //根据m_strFilter更新模型
    if(rowCount()>0){
        emit beginRemoveRows(QModelIndex(), 0, rowCount() - 1);
        m_listShowTeacher.clear();
        emit endRemoveRows();
    }
    emit beginInsertRows(QModelIndex(), 0, m_listAllTeacher.count() - 1);
    m_listShowTeacher = m_listAllTeacher;
    emit endInsertRows();
}
