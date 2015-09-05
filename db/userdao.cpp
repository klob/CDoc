#include"userdao.h"


UserDao * UserDao::m_instance=NULL;
User  UserDao::current_user;

/*
 * User 数据库访问类  采用单例模式
*/

UserDao *  UserDao::get_instance()
{
    if(m_instance==NULL)
    {
        L::i("userdao ","instacnce");
        current_user.id=-1;
        m_instance=new UserDao();
    }
    return m_instance;
}
UserDao::UserDao()
{
   L::i("userdao ","userdao");
   BaseDao::init();

}

//得到当前用户
User   UserDao::get_currentUser(){
    L::i("userdao",current_user.get_update_sql());
    return current_user;
}

//设置当期用户
void UserDao::set_currentUser(User user){
    current_user =user;
}

UserDao::~UserDao(){
    db.close();
}

//注册
bool  UserDao::signup(User user)
{

    return save(user);
}

//登录
bool UserDao::signin(User user)
{

    current_user= query_by_phone(user.phone);
    if(current_user.id<0)
    {
        L::i("USERDAO","账户不存在");
        return false;
    }
    else if(user.passward==current_user.passward)
    {
        set_currentUser(current_user);

     //   L::i(TAG,);
        return true;
    }

    else return false;
}

//增
bool UserDao::save(User user){

    QString sql="insert into user  " + user.get_sql();

    return doSql(sql);
}

//删
bool UserDao::delete_user(User user){
    return   delete_by_id(user.id);
}
bool UserDao::delete_by_id(int id){
    QString sql = " delete from user where id =  " +L::wraper(id);
    return doSql(sql);
}

bool UserDao::delete_by_phone(QString phone){
    QString sql = " delete from user where phone =  '" +phone+"'";
    return doSql(sql);
}

//查
QList<User> UserDao::query_all(){
    QList<QSqlRecord> list;
    QList<User> user_list;
    QString sql= "select * from user";
    doSql(sql);
    while(excutor.next())
    {
        list<<excutor.record();
    }
    foreach(QSqlRecord record,list)
    {
        user_list<<parse(record);
    }


    return user_list;

}

User UserDao::query_by_id(int id){
    QString sql ="select * from user where id = " +L::wraper(id);
    doSql(sql);
    excutor.next();
    User user =parse(excutor.record());
    return user;

}

User UserDao::query_by_phone(QString phone){
    QString sql ="select * from user where phone = " +L::wraper(phone);
    doSql(sql);
    excutor.next();
    User user =parse(excutor.record());
    return user;
}

QList<User> UserDao::query_by_relation(Relation relation)
{

    QList<User>acs;
    UserDao * dao = UserDao::get_instance();
    foreach (int id, relation.sql_to_ids()) {
        if(id!=0){
           acs.append(dao->query_by_id(id));
        }
    }
    return acs;
}
//改
bool UserDao::update(User user){
    current_user=user;
    QString sql = "update user set  " +user.get_update_sql();
    return doSql(sql);
}

bool UserDao::doSql(QString sql)
{
    return BaseDao::doSql(sql);
}

void UserDao::close(){
    db.close();
}

//User model
User UserDao::parse(QSqlRecord record)
{

    User user;
    user.id=record.value("id").toInt();
    user.username=record.value("username").toString();
    user.passward=record.value("passward").toString();
    user.phone=record.value("phone").toString();
    user.qq=record.value("qq").toString();
    user.signature=record.value("signature").toString();
    L::i("userdao",record.value(User::ACTIVITYRELATION).toString());
    user.activityrelations.set_sql(record.value(User::ACTIVITYRELATION).toString());
    return user;
}
