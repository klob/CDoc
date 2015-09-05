#include "applive.h"

AppLive::AppLive(QObject *parent) : QObject(parent)
{
    udpServer  = new QUdpSocket(this);
}

AppLive::~AppLive()
{

}

void AppLive::Start()
{
    udpServer->bind(6008);
    connect(udpServer, SIGNAL(readyRead()), this, SLOT(ReadData()));
}

void AppLive::ReadData()
{
    QByteArray tempData;
    do {
        tempData.resize(udpServer->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        udpServer->readDatagram(tempData.data(), tempData.size(), &sender, &senderPort);
        QString data = QLatin1String(tempData);
        if (data == "hello") {
            udpServer->writeDatagram("GASOK", sender, senderPort);
        }
    } while (udpServer->hasPendingDatagrams());
}
