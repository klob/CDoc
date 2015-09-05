#ifndef FRMINPUTBOX_H
#define FRMINPUTBOX_H

#include <QDialog>

namespace Ui
{
    class FrmInputBox;
}

class FrmInputBox : public QDialog
{
    Q_OBJECT

public:
    explicit FrmInputBox(QWidget *parent = 0);
    ~FrmInputBox();

    void SetMessage(QString title);
    QString GetValue()const {
        return value;
    }

private slots:
    void on_btnOk_clicked();

private:
    Ui::FrmInputBox *ui;

    void InitStyle();   //初始化无边框窗体

    QString value;
};

#endif // FRMINPUTBOX_H
