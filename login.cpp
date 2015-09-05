#include"login.h"
#include "ui_login.h"

/**
 * 登录注册页
 */

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
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

    QRegExp regx("[1-9][0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->lineEdit );
    ui->lineEdit->setValidator(validator);

}

Login::~Login()
{
    delete ui;
}

//登录函数
bool Login::signin( )
{

    phone = ui->lineEdit->text();
    passward=ui->lineEdit_2->text();
    User user;
    user.phone=phone;
    user.passward=passward;
    bool flag =UserDao::get_instance()->signin(user);
    return flag;
}

//登录
void Login::on_login_btn_clicked()
{
    if(signin())
    {
        accept();
    }
    else
    {
        MyHelper::ShowMessageBoxInfo("用户名或密码错误");
    }
}

//注册然后登录
void Login::on_regiser_btn_clicked()
{
    phone = ui->lineEdit->text();
    passward=ui->lineEdit_2->text();
    User user;
    user.phone=phone;
    user.passward=passward;

    bool flag =UserDao::get_instance()->signup(user);

    if(flag) {
        MyHelper::ShowMessageBoxInfo("欢迎使用");
        signin();
        accept();
    }
    else
    {
        MyHelper::ShowMessageBoxInfo("用户已存在");
    }
}
