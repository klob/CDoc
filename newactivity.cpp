#include "newactivity.h"
#include "ui_newactivity.h"

const int SIZE_CHAR = 15;
const char CCH[] = "_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";

/*
 * 发起活动页
*/

NewActivity::NewActivity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewActivity)
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

    is_update=false;

}

NewActivity::~NewActivity()
{
    delete ui;
}

//是否修改
void NewActivity::set_update(bool isUpdate,int id)
{
    is_update=isUpdate;
    init(id);

}

//初始化活动详情
void NewActivity::init(int id)
{
    activity=ActivityDao::get_instance()->query_by_id(id);
    ui->title->setText(activity.title);
    ui->date->setDateTime(activity.date);
    ui->address->setText(activity.address);
    ui->budget->setText(L::w(activity.budget));
    ui->detail->setText(activity.detail);
}

//确认发起活动
void NewActivity::on_btnOk_clicked()
{
    activity.title=ui->title->text();
    activity.date=ui->date->dateTime();
    activity.address=ui->address->text();
    activity.budget=ui->budget->text().toInt();
    activity.detail=ui->detail->toPlainText();

    if(activity.title=="")
    {
        MyHelper::ShowMessageBoxInfo("主题不能为空");
        return ;
    }

    if(activity.address=="")
    {
        MyHelper::ShowMessageBoxInfo("地点不能为空");
        return ;
    }

    if(!is_update){
        activity.managerid=UserDao::get_currentUser().id;
        activity.userrelations.add_obj(UserDao::get_currentUser().id);
        activity.code=code_generate();

        if(ActivityDao::get_instance()->save(activity))
        {
            int id=ActivityDao::get_instance()->query_by_code(activity.code).id;
            User user=UserDao::get_currentUser();
            user.activityrelations.add_obj(id);
            UserDao::get_instance()->update(user);
            MyHelper::ShowMessageBoxInfo("发起活动成功");
            accept();
        }
        else
        {
            MyHelper::ShowMessageBoxInfo("发起活动失败");

        }
    }
    else
    {
        if(ActivityDao::get_instance()->update(activity))
        {
              MyHelper::ShowMessageBoxInfo("更新活动成功");
                 accept();
        }
        else
        {
            MyHelper::ShowMessageBoxInfo("更新活动失败");

        }
    }

}

//取消
void NewActivity::on_btnCancel_clicked()
{
    accept();
}

//邀请码生成
QString NewActivity::code_generate()
{
    srand((unsigned)time(NULL));
    char ch[SIZE_CHAR + 1] = {0};
    for (int i = 0; i < SIZE_CHAR; ++i)
    {
        int x = rand() / (RAND_MAX / (sizeof(CCH) - 1));
        ch[i] = CCH[x];
    }
    return QString(ch);
}
