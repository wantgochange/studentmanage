#ifndef MTEACHERMODE_H
#define MTEACHERMODE_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <QQuickView>
#include <QQmlContext>
#include "mgroupmodel.h"
struct TagTeacher{
    QString id;
    QString teacherName;
    QString position;
    QString atClass;

    TagTeacher(){
        id.clear();teacherName.clear();position.clear();atClass.clear();
    }
    TagTeacher(const TagTeacher& otherTeacher){
        id =otherTeacher.id;
        teacherName = otherTeacher.teacherName;
        position = otherTeacher.position;
        atClass = otherTeacher.atClass;
    }
    void operator=(const TagTeacher& otherTeacher)
    {
        id =otherTeacher.id;
        teacherName = otherTeacher.teacherName;
        position = otherTeacher.position;
        atClass = otherTeacher.atClass;
    }
};

class MteacherMode : public QAbstractListModel
{
    Q_OBJECT
public:
    enum TeacherRoles{
        id = Qt::UserRole +1,
        teacherName,
        position,
        atClass
    };

public:
    explicit MteacherMode(QObject *parent = 0);
    static MteacherMode *getInstance();
    void addTeacher(QList<TagTeacher>& listTeacher);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex& parent = QModelIndex()) const;

    void initTeacherModel();    //初始化教师表s

    //获取所管辖班级的id
    Q_INVOKABLE QString getTeacherGroup(QString teacherId);
    //获取所管辖班级的个数
    Q_INVOKABLE int getTeacherGroupcount(QString teacherId);
    //获取所管辖班级
    Q_INVOKABLE QString get_TeacherGroup(int atindex,QString teacherId);
    //获取教师姓名
    Q_INVOKABLE QString get_teacherName(QString teacherId);
    //获取教师职位
    Q_INVOKABLE QString get_teacherPosition(QString teacherId);

    //修改教师信息
    Q_INVOKABLE void change_TeacherInfo(QString ,QString ,QString);



signals:

public slots:
protected:
    QHash<int,QByteArray> roleNames() const;

private:
    void updateModel();

    QList<TagTeacher>        m_listAllTeacher;
    QList<TagTeacher>        m_listShowTeacher;
    QHash<int,QByteArray>   m_hashRoles;
    static MteacherMode* teacherModel;
};

#endif // MTEACHERMODE_H
