#ifndef ICONHELPER_H
#define ICONHELPER_H

#include <QObject>
#include <QFont>
#include <QFontDatabase>
#include <QMutex>
#include <QLabel>
#include <QPushButton>
#include <QApplication>

class IconHelper : public QObject
{
private:
    explicit IconHelper(QObject *parent = 0);
    QFont iconFont;
    static IconHelper *_instance;

public:
    static IconHelper *Instance() {
        static QMutex mutex;
        if (!_instance) {
            QMutexLocker locker(&mutex);
            if (!_instance) {
                _instance = new IconHelper;
            }
        }
        return _instance;
    }

    void SetIcon(QLabel *lab, QChar c);
    void SetIcon(QPushButton *btn, QChar c);
    void SetIcon(QLabel *lab, QChar c, int size);
    void SetIcon(QPushButton *btn, QChar c, int size);

    void SetIcoMain(QLabel *labMain);
    void SetIcoMin(QPushButton *btnMin);
    void SetIcoClose(QPushButton *btnClose);
    void SetIcoMax(QPushButton *btnMax);
    void SetIcoNormal(QPushButton *btnNormal);

    void SetIcoMain(QLabel *labMain, int size);
    void SetIcoMin(QPushButton *btnMin, int size);
    void SetIcoClose(QPushButton *btnClose, int size);
    void SetIcoMax(QPushButton *btnMax, int size);
    void SetIcoNormal(QPushButton *btnNormal, int size);

};

#endif // ICONHELPER_H
