#include "editprofile.h"
#include "ui_editprofile.h"

/*
 * 编辑个人资料页
*/

EditProfile::EditProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProfile)
{
    //初始化UI
    ui->setupUi(this);
    this->setProperty("Form", true);
    this->setProperty("CanMove", false);
    this->setWindowIcon(QIcon(":/image/icon"));
    this->setWindowTitle("云Doc信息管理系统");
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    ui->lab_Title->installEventFilter(this);
    IconHelper::Instance()->SetIcon(ui->btnMenu_Close, QChar(0xf00d));
    IconHelper::Instance()->SetIcon(ui->btnMenu_Min, QChar(0xf068));
    connect(ui->btnMenu_Close, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnMenu_Min, SIGNAL(clicked()), this, SLOT(showMinimized()));

    user=UserDao::get_currentUser();
    QRegExp regx("[1-9][0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->phone );
    ui->phone->setValidator(validator);
    init();
}

EditProfile::~EditProfile()
{
    delete ui;
}

//初始化个人资料
void EditProfile::init()
{

    ui->id->setEnabled(false);
    if(user.id!=-1){
        ui->id->setText(L::w(user.id));
        ui->username->setText(user.username);
        ui->phone->setText(user.phone);
        ui->qq->setText(user.qq);
    }

}

//确认修改
void EditProfile::on_btnOk_clicked()
{
    user.username= ui->username->text();
    user.phone= ui->phone->text();
    user.qq= ui->qq->text();
    UserDao::get_instance()->update(user);
    accept();

}

//取消修改
void EditProfile::on_btnCancel_clicked()
{
    accept();
}
