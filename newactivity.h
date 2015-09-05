#ifndef NEWACTIVITY_H
#define NEWACTIVITY_H
#include <QDialog>
#include <CTIME>
#include"activitydao.h"
#include"userdao.h"
#include"myhelper.h"
#include"text.h"

namespace Ui {
class NewActivity;
}

class NewActivity : public QDialog
{
    Q_OBJECT

public:
    explicit NewActivity(QWidget *parent = 0);
    ~NewActivity();
    QString code_generate();
        void set_update(bool isUpdate,int id);

private slots:


    void on_btnOk_clicked();
    void init(int id);

    void on_btnCancel_clicked();

private:
    bool is_update;

    Activity activity;
    Ui::NewActivity *ui;
};

#endif // NEWACTIVITY_H
