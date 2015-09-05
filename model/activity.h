#ifndef ACTIVITY_H
#define ACTIVITY_H

#include"tool/text.h"
#include"relation.h"
#include<QString>
class Activity
{
public:
    Activity();
    long long int id;
    QString title;
    QDateTime  date;
    QString address;
    long long int managerid;


    QString detail;
    QString code;
    int budget;
    int privacy;
    int state;


    Relation  userrelations;

    QString get_sql();
    QString get_update_sql();

    static QString ID;
    static QString TITLE;
    static QString DATE;
    static QString ADDRESS;
    static QString MANAGERID;

    static QString USERRELATION;
    static QString DETAIL;
    static QString CODE;
    static QString BUDGET;
    static QString PRIVACY;
    static QString STATE;
    static QString FORMAT;

};

#endif // ACTIVITY_H
