#ifndef FRMCONFIG_H
#define FRMCONFIG_H

#include <QDialog>
#include "myhelper.h"

namespace Ui
{
    class FrmConfig;
}

class FrmConfig : public QDialog
{
    Q_OBJECT

public:
    explicit FrmConfig(QWidget *parent = 0);
    ~FrmConfig();

private slots:
    void SaveConfig();

    void button_clicked();

private:
    Ui::FrmConfig *ui;

    void InitStyle();   //初始化无边框窗体
    void InitForm();    //初始化窗体数据
};

#endif // FRMCONFIG_H
