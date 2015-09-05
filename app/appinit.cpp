#include "appinit.h"
#include "myhelper.h"
/*
 * APP初始化化类
*/
AppInit::AppInit(QObject *parent) : QObject(parent)
{
    mousePressed = false;
    qApp->installEventFilter(this);
}

bool AppInit::eventFilter(QObject *obj, QEvent *evt)
{
    QWidget *w = (QWidget *)obj;
    if (!w->property("CanMove").toBool()) {
        return QObject::eventFilter(obj, evt);
    }

    QMouseEvent *event = static_cast<QMouseEvent *>(evt);
    if (event->type() == QEvent::MouseButtonPress) {
        if (event->button() == Qt::LeftButton) {
            mousePressed = true;
            mousePoint = event->globalPos() - w->pos();
            return true;
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
        mousePressed = false;
        return true;
    } else if (event->type() == QEvent::MouseMove) {
        if (mousePressed && (event->buttons() && Qt::LeftButton)) {
            w->move(event->globalPos() - mousePoint);
            return true;
        }
    }

    return QObject::eventFilter(obj, evt);
}

//加载
void AppInit::Load()
{
    MyHelper::SetUTF8Code();
    MyHelper::SetChinese();
    MyHelper::SetFont();

    App::AppPath = QApplication::applicationDirPath();
    App::ReadConfig();
    MyHelper::SetStyle(App::AppStyle);
}
