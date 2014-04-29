#include "viewerwindow.h"
#include "ui_viewerwindow.h"

ViewerWindow::ViewerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewerWindow),
    tcpServer_(new QTcpServer),
    //tcpSocket_(new QTcpSocket),
    read_buffer_sz_(0)
{
    QCoreApplication::setOrganizationName("AngelFumeroRevetti");
    QCoreApplication::setApplicationName("StreamServidor");
    ui->setupUi(this);
    QSettings settings;
    imgcounter_ = settings.value("imgcounter").toInt();
    loadSettings();

}

ViewerWindow::~ViewerWindow()
{
    delete tcpServer_;
   // delete tcpSocket_;
    delete newclient_;
    delete ui;

}

void ViewerWindow::on_pushButton_clicked()
{
    saveSettings();
    qApp->quit();
}

void ViewerWindow::on_actionSalir_triggered()
{
    saveSettings();
    qApp->quit();
}

void ViewerWindow::on_pushButton_4_clicked()
{
    connectionToHost();

}

//Streaming Casero
void ViewerWindow::connectionToHost()
{
   // hostAdress_ = QHostAddress(QHostAddress::LocalHost).toString();
    tcpServer_->listen(hostAdress_, port_);

    if (!tcpServer_->isListening()){
        qDebug() << "No se pudo iniciar el servidor";
        return;
    }else{
        connect(tcpServer_, SIGNAL(newConnection()), this, SLOT(newSocket()));
        qDebug() << "Servidor iniciado";
    }
}

void ViewerWindow::newSocket()
{
   // QTcpSocket clientConnection();
    //QTcpSocket clientconection(tcpServer_->nextPendingConnection());
    newclient_ = new client(this, tcpServer_->nextPendingConnection());

    if(!clients_.contains(newclient_)){
     clients_.append(newclient_);
    }

    connect(newclient_, SIGNAL(readytogo(std::string)),this,SLOT(Stream(std::string)));
    connect(newclient_, SIGNAL(readydisconnect()),this, SLOT(deleteLater(newclient_)));
}

void ViewerWindow::deleteLater(client* newclient)
{
    clients_.removeOne(newclient);

  //  tcpSocket_ = dynamic_cast<QTcpSocket *>(QObject::sender());
  //  tcpSocket_ -> deleteLater();

    //   read_buffer_sz_ = 0;
    //   buffer_.resize(0);
}

/*
void ViewerWindow::receiveMessage()
{

    tcpSocket_ = dynamic_cast<QTcpSocket *>(QObject::sender());
    if(read_buffer_sz_ == 0 && tcpSocket_-> bytesAvailable() > sizeof(int64_t))
    {
        tcpSocket_->read((char *)&read_buffer_sz_, sizeof(int64_t));

    }
    do{
        if(tcpSocket_->bytesAvailable() > read_buffer_sz_ && read_buffer_sz_ != -1)
        {
          buffer_.resize(read_buffer_sz_);
          tcpSocket_->read(const_cast<char*>(buffer_.c_str()), read_buffer_sz_);

          Stream(buffer_);

          read_buffer_sz_ = 0;
        }

        if(read_buffer_sz_ == 0 && tcpSocket_-> bytesAvailable() > sizeof(int64_t))
        {
          tcpSocket_->read((char *)&read_buffer_sz_, sizeof(int64_t));
        }
     }while(read_buffer_sz_ < tcpSocket_->bytesAvailable () && read_buffer_sz_ != 0);
}
*/
void ViewerWindow::Stream(const std::string &packed)
{
    paquete msg;
    msg.ParseFromString(packed);

    QImage imagen;
    imagen.loadFromData((const uchar *)msg.img().c_str(), msg.img().size(), "jpeg");

    qDebug() << "Nombre de Camara: "
             << msg.devicename().c_str();
    qDebug() << "Timestapm: "
             << msg.timestamp();
    qDebug() << "Protocolo: "
             << msg.protocol().c_str();
    qDebug() << "Protocol Version: "
             << msg.protocol_version().c_str();

    QPixmap pixmap;
    pixmap.convertFromImage(imagen);
    ui->label->setPixmap(pixmap);

    QSettings settings;
    imgcounter_ = imgcounter_ + 1;
    settings.setValue("imgcounter",imgcounter_);

    QString img_name(settings.value("imgcounter").toString());
    img_name = img_name.rightJustified(15,'0');

    QString directory;
    directory.append(img_name.left(4));
    directory.append("/");

    QString subdirectory;
    subdirectory.append(directory);
    subdirectory.append(img_name.mid(5,4));
    subdirectory.append("/");

    if(!QDir(directory).exists()){
        QDir().mkdir(directory);
    }
    if(!QDir(subdirectory).exists()){
        QDir().mkdir(subdirectory);
    }
    QString image;
    image.append(subdirectory);
    image.append(img_name.right(6));
    imagen.save(image,"jpg",-1);

}

//Carga de datos
void ViewerWindow::saveSettings()
{
   /* QSettings settings;

    bool aArranque = ui->checkBox->isChecked();
    int device = ui->comboBox->currentIndex();
        settings.setValue("AutoArranque", aArranque);
        settings.setValue("selectedDevice", device);
   */
}

void ViewerWindow::loadSettings()
{
    QSettings settings;

    QString hostAdress = settings.value("hostAdress").toString();
        hostAdress_ = hostAdress;

    int port = settings.value("port").toInt();
        port_ = port;

}

void ViewerWindow::on_actionAcerca_de_triggered()
{
    About about;
    about.exec();
}


