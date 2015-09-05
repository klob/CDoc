#include "frmconfig.h"
#include "ui_frmconfig.h"

/*
 * 设置页
 */

FrmConfig::FrmConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmConfig)
{
    ui->setupUi(this);
    this->InitStyle();
    this->InitForm();
    MyHelper::FormInCenter(this);
}

FrmConfig::~FrmConfig()
{
    delete ui;
}

void FrmConfig::InitStyle()
{
    this->setProperty("Form", true);
    this->setProperty("CanMove", true);
    this->setWindowTitle(ui->lab_Title->text());
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    IconHelper::Instance()->SetIcoMain(ui->lab_Ico);
    IconHelper::Instance()->SetIcoClose(ui->btnMenu_Close);
    connect(ui->btnMenu_Close, SIGNAL(clicked()), this, SLOT(close()));
}

//选择皮肤
void FrmConfig::InitForm()
{
    QStringList qssName;
    qssName << "黑色" << "灰黑色" << "灰色" << "浅灰色" << "深灰色" << "银色" << "淡蓝色" << "蓝色";
    ui->cboxAppStyle->addItems(qssName);
    if (App::AppStyle == ":/qss/black.css") {
        ui->cboxAppStyle->setCurrentIndex(0);
    } else if (App::AppStyle == ":/qss/brown.css") {
        ui->cboxAppStyle->setCurrentIndex(1);
    } else if (App::AppStyle == ":/qss/gray.css") {
        ui->cboxAppStyle->setCurrentIndex(2);
    } else if (App::AppStyle == ":/qss/lightgray.css") {
        ui->cboxAppStyle->setCurrentIndex(3);
    } else if (App::AppStyle == ":/qss/darkgray.css") {
        ui->cboxAppStyle->setCurrentIndex(4);
    } else if (App::AppStyle == ":/qss/silvery.css") {
        ui->cboxAppStyle->setCurrentIndex(5);
    } else if (App::AppStyle == ":/qss/blue.css") {
        ui->cboxAppStyle->setCurrentIndex(6);
    } else if (App::AppStyle == ":/qss/dev.css") {
        ui->cboxAppStyle->setCurrentIndex(7);
    }

    connect(ui->cboxAppStyle, SIGNAL(currentIndexChanged(int)), this, SLOT(SaveConfig()));

    QList<QPushButton *> btns = ui->widget_left->findChildren<QPushButton *>();
    foreach (QPushButton * btn, btns) {
        connect(btn, SIGNAL(clicked()), this, SLOT(button_clicked()));
    }

 }



void FrmConfig::button_clicked()
{
    QPushButton *btn = (QPushButton *)sender();
    QString name = btn->text();

    QList<QPushButton *> btns = ui->widget_left->findChildren<QPushButton *>();
    foreach (QPushButton * b, btns) {
        b->setChecked(false);
    }
    btn->setChecked(true);

}

//确认保存皮肤
void FrmConfig::SaveConfig()
{
    QString style = ui->cboxAppStyle->currentText();
    if (style == "黑色") {
        App::AppStyle = ":/qss/black.css";
    } else if (style == "灰黑色") {
        App::AppStyle = ":/qss/brown.css";
    } else if (style == "灰色") {
        App::AppStyle = ":/qss/gray.css";
    } else if (style == "浅灰色") {
        App::AppStyle = ":/qss/lightgray.css";
    } else if (style == "深灰色") {
        App::AppStyle = ":/qss/darkgray.css";
    } else if (style == "银色") {
        App::AppStyle = ":/qss/silvery.css";
    } else if (style == "淡蓝色") {
        App::AppStyle = ":/qss/blue.css";
    } else if (style == "蓝色") {
        App::AppStyle = ":/qss/dev.css";
    }

    App::WriteConfig();
    MyHelper::SetStyle(App::AppStyle);
}
