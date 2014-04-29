#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent, QTcpSocket* cliente) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    client_ = cliente;
    read_buffer_sz_ = 0;
    connect(client_,SIGNAL(readyRead()),this, SLOT(client_ready()));
    connect(client_,SIGNAL(disconnected()),this,SLOT(client_disco()));
    qDebug() << "Cliente creado desde el constructor";
}


client::~client()
{
    delete ui;
    delete client_;
}

void client::client_ready()
{

    if(read_buffer_sz_ == 0 && client_-> bytesAvailable() > sizeof(int64_t))
    {
        client_->read((char *)&read_buffer_sz_, sizeof(int64_t));

    }
    do{
        if(client_->bytesAvailable() > read_buffer_sz_ && read_buffer_sz_ != -1)
        {
          buffer_.resize(read_buffer_sz_);
          client_->read(const_cast<char*>(buffer_.c_str()), read_buffer_sz_);

          emit readytogo(buffer_);

          read_buffer_sz_ = 0;
        }

        if(read_buffer_sz_ == 0 && client_-> bytesAvailable() > sizeof(int64_t))
        {
          client_->read((char *)&read_buffer_sz_, sizeof(int64_t));
        }
     }while(read_buffer_sz_ < client_->bytesAvailable () && read_buffer_sz_ != 0);

}

void client::client_disco()
{
    client_->deleteLater();
    emit readydisconnect();
}

