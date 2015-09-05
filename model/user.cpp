#include "user.h"

QString User::ID="id";
QString User::TYPE="type";
QString User::USERNAME="username";
QString User::PASSWARD="passward";
QString User::PHONE="phone";

QString User::QQ="qq";
QString User::SIGNATURE="signature";
QString User::ACTIVITYRELATION="activityrelation";

/*
 * User model 用模型
*/
User::User():type(0)
{

}

//得到新建sql语句
QString User::get_sql()
{
    return "(username,passward,phone,qq,signature,type,activityrelation) "
           "values ( '" +  username +"','"+ passward+"','"+ phone+"','"+ qq+"','"+signature+"',"+L::wd(type)+L::w(activityrelations.get_sql())+")";
}

//得到更新sql语句
QString User::get_update_sql()
{

    return "username = "+L::wraper(username)+
            ",passward = "+L::wraper(passward)+
            ",phone = "+L::wraper(phone)+
            ",qq = "+L::wraper(qq)+
            ",signature = "+L::wraper(signature) +
            ",type = "+L::wraper(type)+
            ",activityrelation = "+ L::w(activityrelations.get_sql())+"where id = "+ L::wraper(id) ;
}

//是否为管理员
bool User::is_manager()
{
    return type==MANAGER;
}

//设置管理员
void User::set_manager(bool is_manager)
{
    if(is_manager)
    {
        type=MANAGER;
    }
    else
    {
        type=DEFAULT;
    }
}
