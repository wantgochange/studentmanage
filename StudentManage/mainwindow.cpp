#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./src/model/mpersonmodel.h"
#include "./src/model/mgroupmodel.h"
#include "./src/model/testqmldata.h"
#include "./src/model/mimmessage.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->edit_loginNum->setText("20150101");
    ui->edit_loginPassword->setText("123");
    ui->messageBox->clear();


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
            mPersonModel* personModel=mPersonModel::getInstance();
            m_view->rootContext()->setContextProperty("personModel",personModel);
            m_view->setSource(QUrl("qrc:/qml/SelectGo.qml"));



    }
    else{
        on_btn_cancel_clicked();
        mysqldebug << "登录失败";
    }
}
