#ifndef ACTIVITYDAO_H
#define ACTIVITYDAO_H

#include"../model/activity.h"
#include"basedao.h"
#include"../model/relation.h"
class ActivityDao : public BaseDao
{
private:
    ActivityDao();
    ~ActivityDao();
    static ActivityDao *  m_instance;
public:
    static ActivityDao * get_instance();

    bool save(Activity);

    bool deleteById(int id);
    bool delete_activty(Activity activity);

    bool update(Activity activity);

    QList<Activity> query_all();
    Activity query_by_id(int id);
    Activity query_by_code(QString code);
    QList<Activity> query_by_managerid(int managerid);
    QList<Activity> query_by_relation(Relation relation);

    bool doSql(QString sql);

    Activity parse(QSqlRecord record);
};

#endif // ACTIVITYDAO_H
