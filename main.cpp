#include <QApplication>
#include"maindialog.h"
#include"login.h"
#include "app/appinit.h"
#include"basedao.h"

/*
 * 程序入口
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //初始化APP
    AppInit *init = new AppInit;
    init->Load();
    //直接进去登录页面
    //BaseDao::set_driver("QMYSQL");
    Login w;

    if(w.exec()==QDialog::Accepted)
    {
        //登录成功进入主页面
        MainDialog mainwindow;
        return  mainwindow.exec();
    }

    return a.exec();


}
