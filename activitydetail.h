#ifndef ACTIVITYDETAIL_H
#define ACTIVITYDETAIL_H

#include<QDialog>
#include<QStandardItemModel>
#include<QFileDialog>
#include<QMessageBox>
#include"myhelper.h"
#include"text.h"
#include"userdao.h"
#include"activitydao.h"
#include"exportexcelobject.h"
#include"newactivity.h"

namespace Ui {
class ActivityDetail;
}

class ActivityDetail : public QDialog
{
    Q_OBJECT

public:
    explicit ActivityDetail(QWidget *parent = 0);

    void init(int id);
    void init_user();
    ~ActivityDetail();

private slots:
    void on_export_excel_clicked();

    void on_edit_clicked();

private:
    Activity activity;
    bool is_manager;
    Ui::ActivityDetail *ui;
};

#endif // ACTIVITYDETAIL_H
