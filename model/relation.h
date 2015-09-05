#ifndef RELATION
#define RELATION
#include"tool/text.h"
#include"QStringList"

class Relation
{
public  :
    Relation();
    Relation(QString);
    void sql_to_list();
    QString list_to_sql();
    QString get_sql();
    QList<int> sql_to_ids();

    QString objs_to_sql(QList<int> ids);
    bool add_obj(int id);
    void set_sql(QString sql);

protected :
    QString sql;
    QStringList list;

};
#endif // RELATION




