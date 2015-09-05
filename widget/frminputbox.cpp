#include "frminputbox.h"
#include "ui_frminputbox.h"
#include "app/myhelper.h"

/*
 * 自定义输入消息框
*/
FrmInputBox::FrmInputBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmInputBox)
{
    ui->setupUi(this);
    this->InitStyle();
    MyHelper::FormInCenter(this);
}

FrmInputBox::~FrmInputBox()
{
    delete ui;
}

/*
 * 初始化窗体
*/
void FrmInputBox::InitStyle()
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

void FrmInputBox::SetMessage(QString title)
{
    ui->labInfo->setText(title);
}

void FrmInputBox::on_btnOk_clicked()
{
    value = ui->txtValue->text();
    done(1);
    this->close();
}
