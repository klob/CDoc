#ifndef APPLIVE_H
#define APPLIVE_H

#include <QObject>
#include <QUdpSocket>

class AppLive : public QObject
{
    Q_OBJECT
public:
    explicit AppLive(QObject *parent = 0);
    ~AppLive();

    void Start();

private slots:
    void ReadData();

private:
    QUdpSocket *udpServer;

signals:

public slots:
};

#endif // APPLIVE_H
