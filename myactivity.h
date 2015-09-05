#ifndef MYACTIVITY_H
#define MYACTIVITY_H

#include <QDialog>
#include<QStandardItem>
#include<QStandardItemModel>

#include"userdao.h"
#include"activitydao.h"
#include"iconhelper.h"
#include"activitydetail.h"

namespace Ui {
class MyActivity;
}

class MyActivity : public QDialog
{
    Q_OBJECT

public:
    explicit MyActivity(QWidget *parent = 0);
    ~MyActivity();
    void init_my_activity();
    void init_manager_activity();
private slots:

    void on_my_activity_tab_clicked(const QModelIndex &index);

    void on_manager_activity_tab_clicked(const QModelIndex &index);

private:
    QList<Activity> activities;
    QList<Activity> manageractivities;
    Activity click_activity;
    Ui::MyActivity *ui;
};

#endif // MYACTIVITY_H
