#include "myactivity.h"
#include "ui_myactivity.h"

/*
 *我的活动页
 */

MyActivity::MyActivity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyActivity)
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

    QStringList headers;
    headers << "主题" << "时间"<<"地点";
    ui->my_activity_tab->setHeaderLabels(headers);
    ui->manager_activity_tab->setHeaderLabels(headers);
    init_my_activity();
    init_manager_activity();

}

//初始化我参与的活动
void MyActivity::init_my_activity()
{

    User user=UserDao::get_currentUser();
    QList<QTreeWidgetItem *> rootList;
    activities=ActivityDao::get_instance()->query_by_relation(user.activityrelations);


    for(int i =0;i<activities.size();i++)
    {
        QStringList rootTextList;
        rootTextList << activities.at(i).title << activities.at(i).date.toString(Activity::FORMAT) <<activities.at(i).address ;
        QTreeWidgetItem *root = new QTreeWidgetItem(ui->my_activity_tab, rootTextList);
        rootList << root;
    }
    ui->my_activity_tab->setColumnWidth(0,200);
    ui->my_activity_tab->setColumnWidth(1,200);
    ui->my_activity_tab->insertTopLevelItems(0, rootList);
    ui->my_activity_tab->show();


}
//初始化我管理的活动
void MyActivity::init_manager_activity()
{
    User user=UserDao::get_currentUser();

    QList<QTreeWidgetItem *> rootmList;
    manageractivities=ActivityDao::get_instance()->query_by_managerid(user.id);

    for(int i =0;i<manageractivities.size();i++)
    {
        QStringList rootTextList;
        rootTextList << manageractivities.at(i).title << manageractivities.at(i).date.toString(Activity::FORMAT) <<manageractivities.at(i).address ;
        QTreeWidgetItem *root = new QTreeWidgetItem(ui->manager_activity_tab, rootTextList);
        rootmList << root;
    }
    ui->manager_activity_tab->setColumnWidth(0,200);
    ui->manager_activity_tab->setColumnWidth(1,200);
    ui->manager_activity_tab->insertTopLevelItems(0, rootmList);
    ui->manager_activity_tab->show();
}

MyActivity::~MyActivity()
{
    delete ui;
}

//参与的活动点击查看详情
void MyActivity::on_my_activity_tab_clicked(const QModelIndex &index)
{
    ActivityDetail detail;
    detail.init(activities.at(index.row()).id);
    detail.exec();
}

//管理的活动点击查看详情
void MyActivity::on_manager_activity_tab_clicked(const QModelIndex &index)
{

    ActivityDetail detail;
    detail.init(manageractivities.at(index.row()).id);
    detail.exec();
}
