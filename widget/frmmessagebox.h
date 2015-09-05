#ifndef FRMMESSAGEBOX_H
#define FRMMESSAGEBOX_H

#include <QDialog>

namespace Ui
{
    class FrmMessageBox;
}

class FrmMessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit FrmMessageBox(QWidget *parent = 0);
    ~FrmMessageBox();

    void SetMessage(QString msg, int type);

private slots:
    void on_btnOk_clicked();

private:
    Ui::FrmMessageBox *ui;

    void InitStyle();   //初始化无边框窗体
};

#endif // FRMMESSAGEBOX_H
