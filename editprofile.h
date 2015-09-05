#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include<QDialog>
#include"userdao.h"
#include"myhelper.h"
#include"text.h"

namespace Ui {
class EditProfile;
}

class EditProfile : public QDialog
{
    Q_OBJECT

public:
    explicit EditProfile(QWidget *parent = 0);
    ~EditProfile();
    void init();

private slots:


    void on_btnOk_clicked();

    void on_btnCancel_clicked();

private:
    Ui::EditProfile *ui;
    User  user;
};

#endif // EDITPROFILE_H
