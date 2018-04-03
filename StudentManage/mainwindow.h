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


private slots:
    void on_btn_cancel_clicked();

    void on_btn_login_clicked();

    void timerun();    //计时器功能

private:
    Ui::MainWindow *ui;
private:
    QQuickView*     m_pView;


};

#endif // MAINWINDOW_H
