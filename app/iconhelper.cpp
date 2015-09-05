#include "iconhelper.h"
#include "app.h"

IconHelper *IconHelper::_instance = 0;
/*
 * 图标帮助
*/
IconHelper::IconHelper(QObject *):
    QObject(qApp)
{
    int fontId = QFontDatabase::addApplicationFont(":/image/fontawesome-webfont.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    iconFont = QFont(fontName);
}

void IconHelper::SetIcon(QLabel *lab, QChar c)
{
    SetIcon(lab, c, App::AppFontSize);
}

void IconHelper::SetIcon(QPushButton *btn, QChar c)
{
    SetIcon(btn, c, App::AppFontSize);
}

void IconHelper::SetIcon(QLabel *lab, QChar c, int size)
{
    iconFont.setPointSize(size);
    lab->setFont(iconFont);
    lab->setText(c);
}

void IconHelper::SetIcon(QPushButton *btn, QChar c, int size)
{
    iconFont.setPointSize(size);
    btn->setFont(iconFont);
    btn->setText(c);
}

void IconHelper::SetIcoMain(QLabel *labMain)
{
    SetIcoMain(labMain, App::AppFontSize);
}

void IconHelper::SetIcoMin(QPushButton *btnMin)
{
    SetIcoMin(btnMin, App::AppFontSize);
}

void IconHelper::SetIcoClose(QPushButton *btnClose)
{
    SetIcoClose(btnClose, App::AppFontSize);
}

void IconHelper::SetIcoMax(QPushButton *btnMax)
{
    SetIcoMax(btnMax, App::AppFontSize);
}

void IconHelper::SetIcoNormal(QPushButton *btnNormal)
{
    SetIcoNormal(btnNormal, App::AppFontSize);
}

void IconHelper::SetIcoMain(QLabel *labMain, int size)
{
    iconFont.setPointSize(size);
    labMain->setFont(iconFont);
    labMain->setText(QChar(App::IcoMain));
}

void IconHelper::SetIcoMin(QPushButton *btnMin, int size)
{
    iconFont.setPointSize(size);
    btnMin->setFont(iconFont);
    btnMin->setText(QChar(App::IcoMin));
}

void IconHelper::SetIcoClose(QPushButton *btnClose, int size)
{
    iconFont.setPointSize(size);
    btnClose->setFont(iconFont);
    btnClose->setText(QChar(App::IcoClose));
}

void IconHelper::SetIcoMax(QPushButton *btnMax, int size)
{
    iconFont.setPointSize(size);
    btnMax->setFont(iconFont);
    btnMax->setText(QChar(App::IcoMax));
}

void IconHelper::SetIcoNormal(QPushButton *btnNormal, int size)
{
    iconFont.setPointSize(size);
    btnNormal->setFont(iconFont);
    btnNormal->setText(QChar(App::IcoNormal));
}
