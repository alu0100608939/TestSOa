#ifndef MYSIGNALHANDLER_H
#define MYSIGNALHANDLER_H

#include "QSocketNotifier"
#include "QCoreApplication"
#include "cliente.h"

class MySignalHandler: public QObject
{
    Q_OBJECT

    public:
        MySignalHandler(QObject *parent = 0);
        ~MySignalHandler();
        // Manejadores de señal POSIX
        static void hupSignalHandler(int unused);
        static void termSignalHandler(int unused);
        static void INTSignalHandler(int unused);

    public slots:
        // Slots Qt donde atender las señales POSIX
        void handleSigHup();
        void handleSigTerm();
        void handleSigINT();

    signals:
        void Exito();

    private:
        // Pares de sockets. Un par por señal a manejar
        static int sigHupSd[2];
        static int sigTermSd[2];
        static int sigINTSd[2];

        // Objetos para monitorizar los pares de sockets
        QSocketNotifier *sigHupNotifier;
        QSocketNotifier *sigTermNotifier;
        QSocketNotifier *sigINTNotifier;

        cliente * client;

};
#endif // MYSIGNALHANDLER_H
