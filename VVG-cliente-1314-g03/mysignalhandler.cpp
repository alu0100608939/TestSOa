#include "mysignalhandler.h"
#include "sys/socket.h"
#include "sys/signal.h"
#include <unistd.h>
#include "QDebug"

int MySignalHandler::sigHupSd[2];
int MySignalHandler::sigTermSd[2];
int MySignalHandler::sigINTSd[2];

MySignalHandler::MySignalHandler(QObject *parent) : QObject(parent)
{
    qDebug() << "Satan es la cumbia";
    client = new cliente;

    // Crear las parejas de sockets UNIX
    if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sigHupSd))
        qFatal("Couldn't create HUP socketpair");
    if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sigTermSd))
        qFatal("Couldn't create TERM socketpair");
    if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sigINTSd))
        qFatal("Couldn't create INT socketpair");

    // Crear los objetos para monitorizar uno de los socket
    // de cada pareja.
    sigHupNotifier = new QSocketNotifier(sigHupSd[1],
        QSocketNotifier::Read, this);
    sigTermNotifier = new QSocketNotifier(sigTermSd[1],
        QSocketNotifier::Read, this);
    sigINTNotifier = new QSocketNotifier(sigINTSd[1],
        QSocketNotifier::Read, this);

    // Conectar la señal activated() de cada objeto
    // QSocketNotifier con el slot correspondiente. Esta señal
    // será emitida cuando hayan datos para ser leidos en el
    // socket monitorizado.
    connect(sigHupNotifier, SIGNAL(activated(int)), this,
        SLOT(handleSigHup()));
    connect(sigTermNotifier, SIGNAL(activated(int)), this,
        SLOT(handleSigTerm()));
    connect(sigINTNotifier, SIGNAL(activated(int)), this,
        SLOT(handleSigINT()));
}


MySignalHandler::~MySignalHandler()
{
    sigHupNotifier->deleteLater();
    sigTermNotifier->deleteLater();
    sigINTNotifier->deleteLater();
    client->deleteLater();
}

//
// Manejador de la señal SIGHUP
//
void MySignalHandler::hupSignalHandler(int)
{
    char a = 1;
    ::write(sigHupSd[0], &a, sizeof(a));
}

//
// Manejador de la señal SIGTERM
//
void MySignalHandler::termSignalHandler(int)
{

    char a = 1;
    ::write(sigTermSd[0], &a, sizeof(a));
}

void MySignalHandler::INTSignalHandler(int)
{

    char a = 1;
    ::write(sigINTSd[0], &a, sizeof(a));
}


void MySignalHandler::handleSigHup()
{
    sigHupNotifier->setEnabled(false);
    char tmp;
    ::read(sigHupSd[1], &tmp, sizeof(tmp));

    // do Qt stuff
     qDebug() << "handleSigHup";
    sigHupNotifier->setEnabled(true);
}

void MySignalHandler::handleSigTerm()
{
    sigTermNotifier->setEnabled(false);
    char tmp;
    ::read(sigTermSd[1], &tmp, sizeof(tmp));

    // do Qt stuff
    while(1)
     qDebug() << "handleSigTerm";
    sigTermNotifier->setEnabled(true);
}

void MySignalHandler::handleSigINT()
{
    sigINTNotifier->setEnabled(false);
    char tmp;
    ::read(sigINTSd[1], &tmp, sizeof(tmp));

    // do Qt stuff
     qDebug() << "Aplicación detenida por el usuario";

     emit Exito();
    sigINTNotifier->setEnabled(true);
}
