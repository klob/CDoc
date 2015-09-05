#include "maindialog.h"
#include "ui_maindialog.h"

/**
 * 主页
 */

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
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
}

MainDialog::~MainDialog()
{
    delete ui;
}

//进入发起活动页
void MainDialog::on_go_new_clicked()
{
    User user=UserDao::get_currentUser();
    if(user.phone==""||user.username==""||user.qq=="")
    {
        MyHelper::ShowMessageBoxInfo("信息不完整，无法发起活动");
        return ;
    }
    NewActivity newac;
    newac.exec();
}

//参与活动
void MainDialog::on_join_activity_clicked()
{
    bool ok;
    QString value;
    User user=UserDao::get_currentUser();
    if(user.phone==""||user.username==""||user.qq=="")
    {
        MyHelper::ShowMessageBoxInfo("信息不完整，无法参加活动");
        return ;
    }
    value = MyHelper::ShowInputBox("请输入活动邀请码:", ok);
    if (ok) {
        Activity activity=   ActivityDao::get_instance()->query_by_code(value);
        if(activity.id==-1)
        {
            MyHelper::ShowMessageBoxInfo("邀请码无效");
            return ;
        }
        bool flag=  activity.userrelations.add_obj(UserDao::get_currentUser().id);
        if(!flag)
        {
            MyHelper::ShowMessageBoxInfo("已参与活动");
        }
        else if(ActivityDao::get_instance()->update(activity)){
            user.activityrelations.add_obj(activity.id);
            bool isOk=  UserDao::get_instance()->update(user);
            if(isOk)
            {
                MyHelper::ShowMessageBoxInfo("成功参与活动，请前往我的活动查看");
            }
            else
            {
                MyHelper::ShowMessageBoxInfo("邀请码无效");
            }
        }
    }
}

//进入查看活动
void MainDialog::on_go_look_clicked()
{
    MyActivity myactivity;
    myactivity.exec();
}

//进入个人资料页
void MainDialog::on_go_person_clicked()
{
    EditProfile edit;
    edit.exec();
}

//进入设置页
void MainDialog::on_go_set_clicked()
{
    FrmConfig config;
          config.exec();
}
