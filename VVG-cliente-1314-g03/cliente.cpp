#include "cliente.h"
#include "protocol.pb.h"
#include "QSettings"

cliente::cliente(QObject *parent) :
    QObject(parent),
    camera_(NULL),
    timer_(new QTimer),
    TIMEOUT_TIMER(500),
    socket_(new QTcpSocket)
{
    QSettings settings;
    QString hostAdress = settings.value("hostAdress").toString();
    hostAdress_ = hostAdress;
    int port = settings.value("port").toInt();
    port_ = port;
    bool mode = settings.value("mode").toBool();
    mode_ = mode;

    devices_ = QCamera::availableDevices();
        qDebug() << "Dispositivo de Captura: "
                << QCamera::deviceDescription(devices_[0]);

    connect(timer_, SIGNAL(timeout()), this,
            SLOT(ConnectToHost()));
    timer_->start(5000);
}

void cliente::ConnectToHost()
{

    qDebug() << "Connecting To Host ("
                << hostAdress_<<":"
                << port_ << ")";

    connect(socket_, SIGNAL(connected()),
            this, SLOT(StreamVideo()));

    socket_->connectToHost("127.0.0.1",5000);
    if (socket_ -> waitForConnected(1000))
        qDebug() << "Connected";
        timer_->stop();

    disconnect(socket_, SIGNAL(connected()),
            this, SLOT(StreamVideo()));
}

void cliente::StreamVideo()
{
    if(!mode_){
        qDebug() << "Iniciando Streaming (WebCAM)...";

        camera_ = new QCamera(devices_[0]);
        captureBuffer_ = new CaptureBuffer();
        camera_->setViewfinder(captureBuffer_);
        camera_->start();

        connect(captureBuffer_,SIGNAL(s_image(QImage)),this,SLOT(image_s(QImage)));
    }else{
        qDebug() << "Iniciando Streaming (FILE)...";
        movie_ = new QMovie;
        movie_->setFileName("video-rpi.mjpeg");

        connect(movie_, SIGNAL(updated(const QRect&)),
                   this, SLOT(movie_updated(const QRect&)));
        movie_->start();
    }

}
void cliente::movie_updated(const QRect& rect) //rect?
{
        QPixmap pixmap = movie_->currentPixmap();

        QImage image2 = pixmap.toImage();
        startStream(image2);
}
void cliente::image_s(const QImage &image)
{

  QTime time2 = QTime::currentTime();
  QString timeString = time2.toString();

  QPixmap pixmap;

  pixmap = QPixmap::fromImage(image);
  QPainter paint(&pixmap);
  paint.setPen(Qt::red);
  paint.setFont(QFont("helvetica", 20));
  paint.drawText(0,0,pixmap.width(),pixmap.height(),Qt::AlignRight |Qt::AlignBottom ,timeString,0);

  QImage image2 = pixmap.toImage();
  startStream(image2);
}


//Streaming Casero
void cliente::startStream(const QImage &image2)
{
    if(socket_ ->state() == QAbstractSocket::ConnectedState){

                paquete pack;
                QByteArray ba;
                QBuffer buffer(&ba);
                buffer.open(QIODevice::ReadWrite);
                image2.save(&buffer, "jpeg");
                std::string img_string(buffer.buffer().data(), buffer.buffer().size());

                pack.set_protocol(PROTOCOL);
                pack.set_protocol_version(PROTOCOL_VERSION);
                pack.set_img(img_string);
                pack.set_devicename(devices_[0]);


                time_t t1 = 0;
                time_t* pt1 = &t1;
                time(pt1);
                pack.set_timestamp(t1);

                std::string pack_string = pack.SerializeAsString();


                int64_t size = pack_string.size();
                socket_->write((char*)&size,sizeof(int64_t));
                qDebug() << "Tamaño del paquete" << size;
                socket_->write(pack_string.c_str(),size);
                qDebug() << "Mensaje enviado";
          }
}

cliente::~cliente()
{
    camera_->stop();
    delete socket_;
    delete camera_;

}
