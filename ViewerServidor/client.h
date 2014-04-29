#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>
#include "protocol.pb.h"

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT
    
public:
    explicit client(QWidget *parent, QTcpSocket* cliente);
    ~client();

signals:

    void readytogo(std::string buffer);
    void readydisconnect();

private slots:

    void client_ready();
    void client_disco();

private:
    Ui::client *ui;
    QTcpSocket *client_;
    int64_t read_buffer_sz_;
    std::string buffer_;
};

#endif // CLIENT_H
