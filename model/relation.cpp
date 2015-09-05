#include"relation.h"

/*
 * Relation model  关系模型 管来User和Activity
*/
Relation::Relation()
{ 
    sql="";
    sql_to_list();

}

Relation::Relation(QString sql)
{
    this->sql=sql;
    sql_to_list();
}

void Relation::set_sql(QString sql)
{
    this->sql=sql;
    sql_to_list();
}

void Relation::sql_to_list()
{
    list.clear();
    list=sql.split(" ");
}

QString Relation::list_to_sql()
{
    sql=list.join(" ");
    return sql;
}

QString Relation::get_sql()
{

    return list_to_sql();
}

QList<int> Relation::sql_to_ids(){

    Relation::sql_to_list();
    QList<int>ids;
    for(int i=0;i<list.size();i++)
    {
        ids<<(list.at(i).toInt());

    }
    return ids;
}

//将关系变成sql语句
QString Relation::objs_to_sql(QList<int> ids){
    list.clear();
    for(int i=0;i<ids.size();i++)
    {
        list<<L::w(ids.at(i));
    }
    return Relation::list_to_sql();

}

//添加关系
bool Relation::add_obj(int id)
{
    if(!list.contains(L::w(id))){
        list<<L::w(id);
        return true;
    }
    return false;
}
