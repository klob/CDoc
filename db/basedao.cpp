#include "basedao.h"

static const QString TAG= "Basedao";
QSqlDatabase BaseDao::db;
QSqlQuery BaseDao::excutor=QSqlQuery(BaseDao::db);
bool BaseDao::is_open=false;
QString BaseDao::db_driver="QSQLITE";

/*
 * 数据基础类
*/

BaseDao::BaseDao()
{

}

BaseDao::~BaseDao()
{
    close();
}

void BaseDao::set_driver(QString dbdriver)
{
    db_driver = dbdriver;
}
//初始化
bool BaseDao::init (){
    if( BaseDao::is_open==false){

        if(db_driver=="QMYSQL")
        {
            db=QSqlDatabase::addDatabase("QMYSQL");
         //  db.setHostName("138.128.200.28");
            db.setHostName("localhost");
            db.setDatabaseName("cdoc");
            db.setUserName("klob");
            db.setPassword("liuping");
        }
        else
        {
            db=QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("cdoc.db");
        }
    }
    if(BaseDao::is_open==false){
        if (BaseDao::db.open())
        {
            excutor =QSqlQuery(BaseDao::db);
            create_table();
            L::i(TAG,"connect success");
            BaseDao::is_open=true;
        }
        else
        {
            L::i(TAG,"connect failed");
        }
        return true;
    }
    else
    {
        excutor =QSqlQuery(BaseDao::db);
        L::i("db","user cache db");
        BaseDao::is_open=true;
        return true;
    }

}

//执行sql语句
bool BaseDao::doSql(QString sql){
    L::i(TAG,sql);
    return excutor.exec(sql);
}

void BaseDao::close(){
    db.close();
}

//建表
bool BaseDao::create_table()
{
    bool flag1,flag2;
    QString mysqlac="CREATE TABLE activity(id INTEGER PRIMARY KEY AUTO_INCREMENT ,title VARCHAR( 100 ) DEFAULT  '0' NOT NULL ,DATE DATE DEFAULT  '0' NOT NULL ,address NVARCHAR( 100 ) DEFAULT  '0' NOT NULL ,managerid INTEGER NOT NULL ,detail NVARCHAR( 200 ) DEFAULT  '0' NULL ,userrelation NVARCHAR( 200 ) DEFAULT  '0' NULL ,budget INTEGER NULL ,privacy INTEGER DEFAULT  '0' NULL ,code NVARCHAR( 100 ) NULL ,state INTEGER DEFAULT  '0' NULL)";
    QString myluser="CREATE TABLE USER( "
                    "id INTEGER PRIMARY KEY AUTO_INCREMENT NOT NULL , "
                    "username VARCHAR( 20 ) DEFAULT  '0' NULL , "
                    "passward VARCHAR( 20 ) DEFAULT  '0' NULL , "
                    "phone VARCHAR( 40 ) DEFAULT '0' UNIQUE NULL , "
                    "qq VARCHAR( 20 ) DEFAULT  '0' NULL ,  "
                    "activityrelation NVARCHAR(200) DEFAULT '0' NULL,"
                    "signature NVARCHAR( 140 ) DEFAULT  '0' NULL , TYPE INTEGER DEFAULT  '0' NOT NULL )";

    QString sqlite1 = "CREATE TABLE [user] ("
                      "[id] INTEGER DEFAULT '1' PRIMARY KEY AUTOINCREMENT NOT NULL,"
                      "[username] varchar(20) DEFAULT '0' NULL,"
                      "[passward] varchar(20) DEFAULT '0' NULL,"
                      "[phone] VARCHAR(40) DEFAULT '0' UNIQUE NULL,"
                      "[qq] VARCHAR(20) DEFAULT '0' NULL,"
                      "[activityrelation] NVARCHAR(200) DEFAULT '0' NULL,"
                      "[signature] NVARCHAR(140) DEFAULT '0' NULL,"
                      "[type] INTEGER DEFAULT '0' NOT NULL)";

    QString sqlite2 = "CREATE TABLE "
                      "[activity] ("
                      "[id] INTEGER DEFAULT '1' NOT NULL PRIMARY KEY AUTOINCREMENT,"
                      "[title] VARCHAR(100) DEFAULT '0' NOT NULL,"
                      "[date] DATE DEFAULT CURRENT_TIME NOT NULL,"
                      "[address] NVARCHAR(100) DEFAULT '0' NOT NULL,"
                      "[managerid] INTEGER  NOT NULL,"
                      "[detail] NVARCHAR(200) DEFAULT '0' NULL,"
                      "[userrelation] NVARCHAR(200) DEFAULT '0' NULL,"
                      "[budget] INTEGER  NULL,[privacy] INTEGER DEFAULT '0' NULL,"
                      "[code] NVARCHAR(100)  NULL,"
                      "[state] INTEGER DEFAULT '0' NULL)";
    if(db_driver=="QMYSQL")
    {
        excutor.clear();
        flag1= excutor.exec(mysqlac);

        excutor.clear();
        flag2=  excutor.exec(myluser);
    }
    else
    {
        excutor.clear();
        flag1= excutor.exec(sqlite1);

        excutor.clear();
        flag2=  excutor.exec(sqlite2);
    }

    return flag1&&flag2;

}
