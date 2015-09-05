#include "activitydetail.h"
#include "ui_activitydetail.h"

/*
 *  活动详情页
 *  管理员可以修改和导出表格
 *  普通参与人员则不行
 */

ActivityDetail::ActivityDetail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivityDetail)
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

//初始化人员列表
void ActivityDetail::init_user()
{

    QStandardItemModel *student_model = new QStandardItemModel();
    student_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("姓名")));
    student_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("手机")));
    student_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("QQ")));
    student_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("备注")));
    QList<User> users=UserDao::get_instance()->query_by_relation(activity.userrelations);
    for(int i=0;i<users.size();i++)
    {
        student_model->setItem(i, 0, new QStandardItem(users.at(i).username));
        student_model->setItem(i, 1, new QStandardItem(users.at(i).phone));
        student_model->setItem(i, 2, new QStandardItem(users.at(i).qq));
    }

    ui->tableView->setModel(student_model);

}

//初始化活动详情
void ActivityDetail::init(int id)
{

    activity=ActivityDao::get_instance()->query_by_id(id);

    is_manager=(activity.managerid==UserDao::get_currentUser().id);
    ui->title->setText(activity.title);
    ui->date->setText(activity.date.toString(Activity::FORMAT));
    ui->address->setText(activity.address);
    ui->budget->setText(L::w(activity.budget));
    ui->code->setText(activity.code);
    ui->detail->setText(activity.detail);
    ui->detail->setWordWrap(true);
    ui->detail->setAlignment(Qt::AlignTop);
    init_user();
    if(!is_manager)
    {

        ui->edit->hide();
        ui->export_excel->hide();
    }
    else{

        ui->edit->show();
        ui->export_excel->show();
    }

}

ActivityDetail::~ActivityDetail()
{
    delete ui;
}

//导出excel表格
void ActivityDetail::on_export_excel_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tableView);


    obj.addField(0, "姓名", "char(20)");
    obj.addField(1, "手机", "char(20)");
    obj.addField(2, "QQ", "char(20)");
    obj.addField(3, "备注", "char(20)");

    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),QString(tr("%1 records exported!")).arg(retVal));
    }
}

//进入修改详情页
void ActivityDetail::on_edit_clicked()
{
    NewActivity newac;
    newac.set_update(true,activity.id);
    int i =newac.exec();
    L::i("activitydetail",L::w(activity.id));
    if(i)
    {
        init(activity.id);
    }

}
