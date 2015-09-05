#ifndef BASEDAO_H
#define BASEDAO_H
#include"tool/text.h"
#include"sql.h"

class BaseDao
{
public:


    BaseDao();
    ~BaseDao();
    bool init();
    bool doSql(QString sql);
    void close();
    bool create_table();
    void static set_driver(QString dbdriver);

protected:

    static QSqlDatabase  db;
    static QSqlQuery excutor;
private:
    static QString  db_driver;
    static bool is_open;
private:


};

#endif // BASEDAO_H
