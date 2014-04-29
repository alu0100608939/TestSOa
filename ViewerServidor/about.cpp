#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(accept()));

    QPixmap pixmap("about.png");
    ui->label_2->setPixmap(pixmap);

}

About::~About()
{
    delete ui;
}
