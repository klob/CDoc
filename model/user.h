#ifndef USER_H
#define USER_H
#include"text.h"
#include"relation.h"

class User
{

public:
    static const int DEFAULT=0;
    static const int MANAGER=1;
    User();
    QString get_sql();
    QString get_update_sql();
    bool is_manager();
    void set_manager(bool is_manager);


    QString username;
    QString passward;
    QString phone;
    QString qq;
    QString signature;

    long long int id;
    int type;

    Relation  activityrelations;


    static QString ID;
    static QString TYPE;
    static QString USERNAME;
    static QString PASSWARD;
    static QString PHONE;

    static QString QQ;
    static QString SIGNATURE;
    static QString ACTIVITYRELATION;

};

#endif // USER_H
