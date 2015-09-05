#include "frmmessagebox.h"
#include "ui_frmmessagebox.h"
#include "app/myhelper.h"
/*
 * 自定义消息框
*/
FrmMessageBox::FrmMessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmMessageBox)
{
    ui->setupUi(this);
    this->InitStyle();
    MyHelper::FormInCenter(this);
}

FrmMessageBox::~FrmMessageBox()
{
    delete ui;
}

void FrmMessageBox::InitStyle()
{
    this->setProperty("Form", true);
    this->setProperty("CanMove", true);
    this->setWindowTitle(ui->lab_Title->text());
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    IconHelper::Instance()->SetIcoMain(ui->lab_Ico);
    IconHelper::Instance()->SetIcoClose(ui->btnMenu_Close);
    connect(ui->btnMenu_Close, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

void FrmMessageBox::SetMessage(QString msg, int type)
{
    if (type == 0) {
        ui->labIcoMain->setStyleSheet("border-image: url(:/image/msg_info.png);");
        ui->btnCancel->setVisible(false);
        ui->lab_Title->setText("提示");
    } else if (type == 1) {
        ui->labIcoMain->setStyleSheet("border-image: url(:/image/msg_question.png);");
        ui->lab_Title->setText("询问");
    } else if (type == 2) {
        ui->labIcoMain->setStyleSheet("border-image: url(:/image/msg_error.png);");
        ui->btnCancel->setVisible(false);
        ui->lab_Title->setText("错误");
    }

    ui->labInfo->setText(msg);
    this->setWindowTitle(ui->lab_Title->text());
}

void FrmMessageBox::on_btnOk_clicked()
{
    done(1);
    this->close();
}
