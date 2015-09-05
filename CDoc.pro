#-------------------------------------------------
#
# Project created by QtCreator 2015-06-15T14:34:50
#
#-------------------------------------------------

QT       += core gui network sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = CDoc
TEMPLATE = app

FORMS    += \
    widget/frmmessagebox.ui \
    widget/frminputbox.ui \
    frmconfig.ui \
    login.ui \
    newactivity.ui \
    editprofile.ui \
    activitydetail.ui \
    myactivity.ui \
    maindialog.ui \
    basedialog.ui

RESOURCES += \
    other/rc.qrc


INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/usercontrol
INCLUDEPATH += $$PWD/api
INCLUDEPATH += $$PWD/sql

DESTDIR         = bin


DISTFILES += \
    other/image/add.png \
    other/image/bg_main.png \
    other/image/join.png \
    other/image/look.png \
    other/image/title.png \
    other/image/icon.png

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/widget
INCLUDEPATH += $$PWD/db
INCLUDEPATH += $$PWD/model
INCLUDEPATH += $$PWD/tool
INCLUDEPATH += $$PWD/app

HEADERS += \
    app/app.h \
    app/appinit.h \
    app/applive.h \
    app/applog.h \
    app/iconhelper.h \
    app/myhelper.h \
    db/activitydao.h \
    db/basedao.h \
    db/userdao.h \
    model/activity.h \
    model/relation.h \
    model/user.h \
    tool/exportexcelobject.h \
    tool/l.h \
    tool/sql.h \
    tool/text.h \
    widget/frminputbox.h \
    widget/frmmessagebox.h \
    activitydetail.h \
    editprofile.h \
    frmconfig.h \
    login.h \
    maindialog.h \
    myactivity.h \
    newactivity.h \
    basedialog.h

SOURCES += \
    app/app.cpp \
    app/appinit.cpp \
    app/applive.cpp \
    app/applog.cpp \
    app/iconhelper.cpp \
    db/activitydao.cpp \
    db/basedao.cpp \
    db/userdao.cpp \
    model/activity.cpp \
    model/relation.cpp \
    model/user.cpp \
    tool/exportexcelobject.cpp \
    tool/l.cpp \
    widget/frminputbox.cpp \
    widget/frmmessagebox.cpp \
    activitydetail.cpp \
    editprofile.cpp \
    frmconfig.cpp \
    login.cpp \
    main.cpp \
    maindialog.cpp \
    myactivity.cpp \
    newactivity.cpp \
    basedialog.cpp
