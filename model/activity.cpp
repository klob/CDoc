#include "activity.h"


QString Activity::ID="id";
QString Activity::TITLE="title";
QString Activity::DATE="date";
QString Activity::ADDRESS="address";
QString Activity::MANAGERID="managerid";
QString Activity::USERRELATION="userrelation";
QString Activity::DETAIL="detail";
QString Activity::CODE="code";
QString Activity::BUDGET="budget";
QString Activity::PRIVACY="privacy";
QString Activity::STATE="state";
QString  Activity::FORMAT="yyyy-MM-dd hh:mm";

/*
 * Activity model 活动模型
*/

Activity::Activity()
{

    date=QDateTime::currentDateTime();
    id=-1;
    title="";
    privacy=0;
    state=0;

}

//得到新建sql语句
QString Activity::get_sql()
{
    return "( title,date,address,managerid,userrelation,detail,code,budget,privacy,state )"
           " values ( "
            +  L::wd(title) +"'" +date.toString(FORMAT)+"',"+ L::wd(address)+ L::wd(managerid)+
            L::wd(userrelations.get_sql())+ L::wd(detail)+L::wd(code)+ L::wd(budget)+L::wd(privacy)+L::w(state)
            +  ")";
}

//得到更新sql语句
QString Activity::get_update_sql()
{
    return
            "title = " + L::wd(title)+
            "date = '" + date.toString(FORMAT)+"',"+
            "address = " + L::wd(address) +
            "managerid = " +L::wd(managerid) +
            "detail = " + L::wd(detail) +
            "userrelation = " +L::wd(userrelations.get_sql())  +
            "code = " + L::wd(code) +
            "budget = "+L::wd(budget) +
            "privacy = " + L::wd(privacy) +
            "state = " +L::w(state)
            +" where id = " + L::wraper(id);

}

