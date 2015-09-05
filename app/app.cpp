#include "app.h"
#include "myhelper.h"

QString App::AppPath = "";

#ifdef Q_OS_WIN
int App::AppFontSize = 10;
QString App::AppFontName = "Microsoft YaHei";
#endif

#ifdef Q_OS_LINUX
#ifdef __arm__
int App::AppFontSize = 11;
QString App::AppFontName = "WenQuanYi Micro Hei";
#else
int App::AppFontSize = 11;
QString App::AppFontName = "WenQuanYi";
#endif
#endif

#ifdef Q_OS_MAC
int App::AppFontSize = 11;
QString App::AppFontName = "Heiti SC";
#endif

QString App::AppStyle = ":/qss/brown.css";

int App::IcoMain = 0xf015;
int App::IcoMin = 0xf068;
int App::IcoClose = 0xf00d;
int App::IcoMax = 0xf079;
int App::IcoNormal = 0xf096;

/*
 * APP配置读取
*/

void App::ReadConfig()
{
    QString fileName = App::AppPath + "/GAS_Config.ini";
    //如果配置文件不存在,则以初始值继续运行,并生成配置文件
    if (!MyHelper::FileIsExist(fileName)) {
        WriteConfig();
        return;
    }

    QSettings *set = new QSettings(fileName, QSettings::IniFormat);
    set->beginGroup("AppConfig");

    App::AppStyle = set->value("AppStyle").toString();

    set->endGroup();
}

/*
 * APP配置保存
*/

void App::WriteConfig()
{
    QString fileName = App::AppPath + "/GAS_Config.ini";
    QSettings *set = new QSettings(fileName, QSettings::IniFormat);
    set->beginGroup("AppConfig");

    set->setValue("AppStyle", App::AppStyle);

    set->endGroup();
}
