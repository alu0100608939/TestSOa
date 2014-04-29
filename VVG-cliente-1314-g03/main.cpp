#include <QApplication>
#include <mysignalhandler.h>
#include <sys/socket.h>
#include <sys/signal.h>
#include <unistd.h>
#include <QSocketNotifier>
#include <QSettings>


//
// Configurar los manejadores de señal
//
int setupUnixSignalHandlers()
{
    struct ::sigaction hup, term, INT;

    hup.sa_handler = &MySignalHandler::hupSignalHandler;
    ::sigemptyset(&hup.sa_mask);
    hup.sa_flags = SA_RESTART;

    // Establecer manejador de la señal SIGHUP
    if (::sigaction(SIGHUP, &hup, 0) > 0)
    return 1;

    term.sa_handler = &MySignalHandler::termSignalHandler;
    ::sigemptyset(&term.sa_mask);
    term.sa_flags = SA_RESTART;

    // Establecer manejador de la señal SIGTERM
    if (::sigaction(SIGTERM, &term, 0) > 0)
    return 2;

    INT.sa_handler = &MySignalHandler::INTSignalHandler;
    ::sigemptyset(&INT.sa_mask);
    INT.sa_flags = SA_RESTART;

    // Establecer manejador de la señal SIGTERM
    if (::sigaction(SIGINT, &INT, 0) > 0)
    return 3;

    return 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("VVG-1314-g03");
    QCoreApplication::setApplicationName("Cliente");
    QApplication app(argc, argv,true);

    QSettings settings;
    QStringList args = app.arguments();
        for(int i = 0; i< args.size();i++){
            if(args[i] == "-i")
                settings.setValue("hostAdress", args[i+1]);
            else
                settings.setValue("hostAdress", "127.0.0.1");
            if(args[i] == "-p")
                settings.setValue("port", args[i+1]);
            else
                settings.setValue("port", "5000");
            if(args[i] == "-f")
                settings.setValue("mode", true);
            else
                settings.setValue("mode", false);
        }

    MySignalHandler MSHC(&app);
    setupUnixSignalHandlers();

    QObject::connect(&MSHC, SIGNAL(Exito()), &app,
        SLOT(quit()));

    return app.exec();

    //app.exit();
}

