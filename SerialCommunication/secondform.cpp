#include "secondform.h"
#include "ui_secondform.h"
#include "mainwindow.h"

secondform::secondform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secondform)
{
    ui->setupUi(this);
}

secondform::~secondform()
{
    delete ui;
}
void secondform::setPort(QSerialPort* ReceivedPort)
{
    port = ReceivedPort;
    qDebug() << "Gelen Port: " << port->portName();
    connect(port,&QSerialPort::readyRead, this,&secondform::ReadSerialData);
}
void secondform::on_pushButton_clicked()
{
    port->close();

    MainWindow *mainfrm;
    mainfrm = new MainWindow();
    mainfrm->setAttribute(Qt::WA_DeleteOnClose);
    mainfrm->show();
    delete(port);
    this->close();
}
void secondform::ReadSerialData()
{
    if (!port->isOpen())
        port->open(QIODevice::ReadWrite);
    if (!port->isReadable())
    {
        qDebug() << "Port Okunamıyor!\n";
        return;
    }
    QByteArray data =port->readAll();
    ui->listWidget->addItem("Gelen: "+data);

}

void secondform::on_pushButton_2_clicked()
{
    if (!port->isOpen())
        port->open(QIODevice::ReadWrite);
    if (!port->isWritable())
    {
        qDebug() << "Seçilen Seri Porta Yazmaya İzin Verilmiyor !!\n";
        return;
    }
    QString data = ui->lineEdit->text();
    port->write(data.toUtf8());
    ui->listWidget->addItem("Gonderilen: "+data);
    ui->lineEdit->clear();
}
