#ifndef USERDAO_H
#define USERDAO_H

#include"../model/user.h"
#include"basedao.h"


class UserDao : public BaseDao
{
private:
      UserDao();

      static UserDao *  m_instance;
      static User    current_user;
public:

    ~UserDao();
   static  UserDao *  get_instance();
   static  User    get_currentUser();
   static  void set_currentUser(User  user);
   QList<User> query_by_relation(Relation relation);

    QList<User> query_all();
    User  query_by_id(int id);
    User  query_by_phone(QString phone);

    bool  delete_user(User user);
    bool  delete_by_id(int id);
    bool  delete_by_phone(QString phone);

    bool  save(User user);
    bool  update(User t);
    
    bool  doSql(QString sql);
    
    void  close();
    bool  signup(User user);
    bool  signin(User user);
    
    
    User  parse(QSqlRecord record);

};

#endif // USERDAO_H
