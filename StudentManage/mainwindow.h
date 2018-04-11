#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QTime>
#include <QTimer>
#include <QFont>

#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>

#include "comdata.h"

#include "./src/model/mpersonmodel.h"
#include "./src/model/mgroupmodel.h"
#include "./src/model/testqmldata.h"
#include "./src/model/mimmessage.h"
#include "./src/model/mteachermode.h"
#include "./src/model/mgroupmodel.h"

#define mysqldebug (qDebug() << "by sinux wang 打印输出：" << __FILE__<<__LINE__)


enum logindata{
    loginNum,
    password,
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    bool initLinkData();//初始化连接mysql数据库
    bool checkLogin(); //验证登录密码
    void time_5m();    //5秒计时器

    //sql  获取联系人数据
    QList<TagPersons> get_personModel();
    //修改联系人数据
    void change_personModel(TagPerson listPerson);
    //获取群组数据
    QList<CGroupInfos> get_groupModel();
    //获取教师数据
    QList<TagTeachers> get_teacherModel();

    void initModel();

    //教师表
    //根据教师id获取姓名
    QString get_teacherName(QString teacher_id);

private slots:
    void on_btn_cancel_clicked();

    void on_btn_login_clicked();

    void timerun();    //计时器功能

private:
    Ui::MainWindow *ui;
private:
    QQuickView*     m_pView;
    mPersonModel* personModel;
    MteacherMode* teacherModel;
    MGroupModel* groupModel;

};

#endif // MAINWINDOW_H
