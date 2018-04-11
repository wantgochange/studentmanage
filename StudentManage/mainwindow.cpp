#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./src/model/mpersonmodel.h"
#include "./src/model/mgroupmodel.h"
#include "./src/model/testqmldata.h"
#include "./src/model/mimmessage.h"
#include "./src/model/mteachermode.h"
#include "./src/model/mgroupmodel.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->edit_loginNum->setText("20150101");
    ui->edit_loginPassword->setText("123");
    ui->messageBox->clear();


    personModel=mPersonModel::getInstance();
    teacherModel=MteacherMode::getInstance();
    groupModel = MGroupModel::getInstance();

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::initLinkData()
{
    //初始化连接mysql数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setUserName("root");
    db.setPassword("root");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("student");
    db.setPort(3306);//端口
    if(db.open()){
        mysqldebug<<"open database success 数据已打开\n";
        return true;
    }
    else{
        mysqldebug<<"open faile!It is bad! 数据库关闭\n";
        ui->messageBox->setText("数据库关闭");
        time_5m();
        return false;
    }
}

bool MainWindow::checkLogin()
{
    int edittxt_loginNum = 0;
    int edittxt_password = 0;

    edittxt_loginNum = ui->edit_loginNum->text().toInt();
    edittxt_password = ui->edit_loginPassword->text().toInt();

    QSqlQuery query;
    query.prepare("select * from login");
    if(!query.exec())
        mysqldebug << query.lastError();
    //        qDebug() << query.lastError();
    else{
        while (query.next()) {
            if(query.value(loginNum) == edittxt_loginNum && query.value(password) == edittxt_password)
                return true;
        }
    }
    ui->messageBox->setText("学号或密码输入错误");
    time_5m();
    return false;
}

void MainWindow::time_5m()
{
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerun()));
    timer->setSingleShot(true);
    timer->start(1000);
}

QList<TagPersons> MainWindow::get_personModel()
{
    QList<TagPersons> list_person;
    mysqldebug << initLinkData();
    QSqlQuery query;
    query.prepare("select * from students");
    if(!query.exec()){
        mysqldebug << query.lastError();
    }
    else{
        while (query.next()) {
//            mysqldebug <<query.value(8)<< query.value(0) <<query.value(1) <<query.value(2) <<query.value(3) <<query.value(4) <<query.value(5) <<
//                          query.value(6) <<query.value(7)  <<query.value(9) <<query.value(10) <<
//                          query.value(11) <<query.value(12) <<query.value(13) <<query.value(14);
            TagPersons person;
            person.id = query.value(0).toString();person.picturePath = query.value(1).toString();
            person.firstName = query.value(2).toString();
            person.age = query.value(3).toInt();person.grade = query.value(4).toInt();person.person_yuwen = query.value(5).toInt();
            person.person_math = query.value(6).toInt();person.person_english = query.value(7).toInt();person.bossId = query.value(8).toString();
            person.person_height = query.value(9).toInt();person.person_weight = query.value(10).toInt();person.runclass = query.value(11).toInt();
            person.baddata = query.value(12).toInt();person.position = query.value(13).toString();person.person_tiyu = query.value(14).toInt();

            list_person.append(person);
        }
    }
    mysqldebug <<list_person.count()<<list_person[0].id<<list_person[1].id<<list_person[2].bossId<<"学生表";
    return list_person;
}

void MainWindow::change_personModel(TagPerson listPerson)
{
    mysqldebug << initLinkData();
    QSqlQuery query;
    query.prepare("UPDATE students SET Name = "+listPerson.firstName+","
"position ="+listPerson.position+","
"Yuwen ="+listPerson.person_yuwen+","
"Math="+listPerson.person_math+","
"English="+listPerson.person_english+","
"Tiyu="+listPerson.person_tiyu+ ", "
"Teacher="+listPerson.bossId+","
 "Height="+listPerson.person_height+","
"Weight="+listPerson.person_weight+","
 "Runclass="+listPerson.runclass+ ","
"BadData="+listPerson.baddata+" WHERE Num="+listPerson.id+";");
    if(!query.exec()){
        mysqldebug << query.lastError();
    }
    else{
        QSqlQuery query;
        query.prepare("select * from students");
        if(!query.exec()){
            mysqldebug << query.lastError();
        }
        else{
            while (query.next()) {
mysqldebug << query.value(0) <<query.value(1) <<query.value(2) <<query.value(3) <<query.value(4) <<query.value(5) <<
            query.value(6) <<query.value(7) <<query.value(8) <<query.value(9) <<query.value(10) <<
           query.value(11) <<query.value(12) <<query.value(13) <<query.value(14);
            }
        }
    }
}

QList<CGroupInfos> MainWindow::get_groupModel()
{
    QList<CGroupInfos> list_group;
    mysqldebug << initLinkData();
    QSqlQuery query;
    query.prepare("select * from class");
    if(!query.exec()){
        mysqldebug << query.lastError();
    }
    else{
        while (query.next()) {
//            mysqldebug << query.value(0) <<query.value(1)<<query.value(2)<<query.value(3)<<query.value(4)<<query.value(5);
            CGroupInfos group;
            group.id = query.value(0).toString();
            group.managerId = query.value(1).toString();
            group.member = query.value(2).toString();
            group.teacherMember = query.value(3).toString();
            group.groupIdentity = query.value(4).toInt();
            group.name = query.value(5).toString();
            list_group.append(group);
        }
    }
    mysqldebug <<list_group.count()<<list_group[0].id<<list_group[1].id<<"群组id";
    return list_group;
}

QList<TagTeachers> MainWindow::get_teacherModel()
{
    QList<TagTeachers> list_teacher;
    mysqldebug << initLinkData();
    QSqlQuery query;
    query.prepare("select * from teacher");
    if(!query.exec()){
        mysqldebug << query.lastError();
    }
    else{
        while (query.next()) {
            //            mysqldebug << query.value(0) <<query.value(1) <<query.value(2) <<query.value(3) <<query.value(4) <<query.value(5) <<
            //                          query.value(6) <<query.value(7) <<query.value(8) <<query.value(9) <<query.value(10) <<
            //                          query.value(11) <<query.value(12) <<query.value(13) <<query.value(14);
            TagTeachers teacher;
            teacher.id = query.value(0).toString();teacher.teacherName = query.value(1).toString();
            teacher.position = query.value(2).toString();
            teacher.atClass = query.value(3).toInt();
            list_teacher.append(teacher);
        }
    }
    mysqldebug <<list_teacher.count()<<list_teacher[0].id<<list_teacher[1].id<<list_teacher[2].id<<"教师表===";
    return list_teacher;
}


void MainWindow::initModel()
{
    personModel->initPersonModel();
    groupModel->initGroupModel();
    teacherModel->initTeacherModel();
}

QString MainWindow::get_teacherName(QString teacher_id)
{
    return teacherModel->get_teacherName(teacher_id);
}

void MainWindow::timerun()
{
    ui->messageBox->clear();
}

void MainWindow::on_btn_cancel_clicked()
{
    ui->edit_loginNum->clear();
    ui->edit_loginPassword->clear();
}

void MainWindow::on_btn_login_clicked()
{
    if(ui->edit_loginNum->text().isEmpty() || ui->edit_loginPassword->text().isEmpty()){
        ui->messageBox->setText("请输入正确的学号和密码");
        time_5m();
        return;
    }
    mysqldebug << initLinkData();
    mysqldebug << checkLogin();
    if(checkLogin()){
        mysqldebug << "2.10 登录完成";
        this->hide();


        QQuickView* m_view ;
        m_view= new QQuickView();
        m_view->setSource(QUrl("qrc:/qml/SelectGo.qml"));

        m_view->rootContext()->setContextProperty("personModel",personModel);
        m_view->rootContext()->setContextProperty("teacherModel",teacherModel);
        m_view->rootContext()->setContextProperty("groupModel",groupModel);
        initModel();
    }
    else{
        on_btn_cancel_clicked();
        mysqldebug << "登录失败";
    }
}
