#ifndef CLIENTE_H
#define CLIENTE_H

#include <QObject>
#include <QTcpSocket>
#include <QCamera>
#include <QMovie>
#include <QTimer>
#include <QTime>
#include <QPixmap>
#include <QBuffer>
#include <QPainter>

#include "capturebuffer.h"

#define PROTOCOL "VVG"
#define PROTOCOL_VERSION "0.1"

class cliente : public QObject
{
    Q_OBJECT
private:
    QList<QByteArray> devices_;
    int selectedDevice_;
    CaptureBuffer *captureBuffer_;
    QMovie *movie_;
    QCamera *camera_;

    QTimer *timer_;
    const int TIMEOUT_TIMER;
    QTcpSocket *socket_;
    QString hostAdress_;
    bool mode_;
    qint16 port_;

    void startStream(const QImage &image2);

public:
    explicit cliente(QObject *parent = 0);
    ~cliente();


signals:


public slots:
        void movie_updated(const QRect& rect);
        void image_s(const QImage &image);
        void ConnectToHost();
        void StreamVideo();

};

#endif // CLIENTE_H
