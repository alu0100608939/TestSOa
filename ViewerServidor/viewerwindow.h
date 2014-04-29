#ifndef VIEWERWINDOW_H
#define VIEWERWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QCamera>
#include <QCameraViewfinder>
#include <QAbstractVideoSurface>
#include <capturebuffer.h>

#include "QFileDialog"
#include "QFile"
#include "QImageReader"
#include "QWaitCondition"
#include "QMutex"
#include "QMovie"
#include "QMessageBox"
#include "QSettings"
#include "QDebug"
#include "about.h"
#include "QTime"
#include "QPainter"
#include "QTcpServer"
#include "protocol.pb.h"
#include "QDir"
#include "client.h"
#include "QList"
namespace Ui {
class ViewerWindow;
}

class ViewerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewerWindow(QWidget *parent = 0);
    ~ViewerWindow();

signals:
    void received(const std::string &);


private slots:
    void on_pushButton_clicked();

    void on_actionSalir_triggered();

    void on_actionAcerca_de_triggered();

    void on_pushButton_4_clicked();

    //void receiveMessage();

    void newSocket();

    void deleteLater(client* newclient);

    void Stream(const std::string &);

private:
    Ui::ViewerWindow *ui;
    QString m_sSettingsFile;

    QTcpServer *tcpServer_;
    //QTcpSocket *tcpSocket_;
    QHostAddress hostAdress_;
    quint16 port_;
    int64_t read_buffer_sz_;

    std::string buffer_;

    void saveSettings();
    void loadSettings();

    void connectionToHost();

    qint32 imgcounter_;
    client* newclient_;
    QList<client*> clients_;

};

#endif // VIEWERWINDOW_H
