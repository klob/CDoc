#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include"userdao.h"
#include"myhelper.h"
#include"text.h"
#include"activitydao.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);

    QString phone;
    QString passward;
    bool signin();
    ~Login();

private slots:


    void on_login_btn_clicked();

    void on_regiser_btn_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
