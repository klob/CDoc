#include"activitydao.h"


ActivityDao * ActivityDao::m_instance=NULL;
QString TAG = "ActivityDao";

/*
 * Activity 数据库访问类  采用单例模式
*/

ActivityDao *  ActivityDao::get_instance()
{
    if(m_instance==NULL)
    {
        m_instance=new ActivityDao();
    }
    return m_instance;
}

ActivityDao::ActivityDao()
{

    
}

//增
bool ActivityDao::save(Activity activity){
    QString sql="insert into activity  " + activity.get_sql();
    return doSql(sql);
}

//删
bool ActivityDao::delete_activty(Activity activity){
    return   deleteById(activity.id);
}


bool ActivityDao::deleteById(int id){
    QString sql = " delete from activity where id =  " +L::wraper(id);
    return doSql(sql);
}

//查
QList<Activity> ActivityDao::query_all(){
    QList<QSqlRecord> list;
    QList<Activity> activity_list;
    QString sql= "select * from activity";
    doSql(sql);
    while(excutor.next())
    {
        list<<excutor.record();
    }
    foreach(QSqlRecord record,list)
    {
        activity_list<<parse(record);
    }

    return activity_list;
    
}

Activity ActivityDao::query_by_id(int id){
    Activity activity;
    QString sql ="select * from activity where id = " +L::wraper(id);
    doSql(sql);
    if(excutor.next()){
        activity=parse(excutor.record());
    }
    return activity;
    
}

QList<Activity> ActivityDao::query_by_managerid(int managerid){

    QString sql ="select * from activity where managerid = " +L::wraper(managerid);
    QList<QSqlRecord> list;
    QList<Activity> activity_list;
    doSql(sql);
    while(excutor.next())
    {
        list<<excutor.record();
    }
    foreach(QSqlRecord record,list)
    {
        activity_list<<parse(record);
    }

    return activity_list;


}

bool ActivityDao::doSql(QString sql)
{
    return BaseDao::doSql(sql);
}

Activity ActivityDao::query_by_code(QString code){
    QString sql ="select * from activity where code = " +L::w(code);
    doSql(sql);
    Activity ac;
    if(excutor.next()){
        ac=parse(excutor.record());
    }
    return ac;
}

QList<Activity> ActivityDao::query_by_relation(Relation relation)
{

    QList<Activity>acs;
    ActivityDao * dao = ActivityDao::get_instance();
    foreach (int id, relation.sql_to_ids()) {
        if(id!=0){
            acs.append(dao->query_by_id(id));
        }
    }
    return acs;
}

//改
bool ActivityDao::update(Activity activity){
    QString sql = "update activity set  " +activity.get_update_sql();
    return doSql(sql);
}

ActivityDao::~ActivityDao()
{
    db.close();
}

//sql语句解析成Activity model
Activity ActivityDao::parse(QSqlRecord record)
{
    Activity activity;

    activity.id=record.value(Activity::ID).toInt();

    activity.date=record.value(Activity::DATE).toDateTime();
    activity.title=record.value(Activity::TITLE).toString();
    activity.address=record.value(Activity::ADDRESS).toString();
    activity.managerid=record.value(Activity::MANAGERID).toInt();
    
    
    activity.detail=record.value(Activity::DETAIL).toString();
    activity.code=record.value(Activity::CODE).toString();
    activity.budget=record.value(Activity::BUDGET).toInt();

    activity.privacy=record.value(Activity::PRIVACY).toInt();
    activity.state=record.value(Activity::STATE).toInt();
    activity.userrelations.set_sql(record.value(Activity::USERRELATION).toString());


    return activity;
}


