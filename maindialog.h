#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include"myhelper.h"
#include"text.h"
#include"activitydetail.h"
#include"editprofile.h"
#include"newactivity.h"
#include"frmconfig.h"
#include"myactivity.h"
namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();

private slots:

    void on_go_new_clicked();

    void on_join_activity_clicked();

    void on_go_look_clicked();

    void on_go_person_clicked();

    void on_go_set_clicked();

private:
    Ui::MainDialog *ui;
};

#endif // MAINDIALOG_H
