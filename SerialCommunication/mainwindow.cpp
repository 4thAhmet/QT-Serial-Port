#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , frm(nullptr)
{
    ui->setupUi(this);
    doldur();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doldur()
{
    ui->comboBox->clear();
    const auto ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : ports) {
        ui->comboBox->addItem(info.portName());
    }
}

void MainWindow::on_pushButton_clicked()
{
    port = new QSerialPort();
    port->setPortName(ui->comboBox->currentText());
    port->setBaudRate(QSerialPort::Baud9600);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);
try{
    if (!port->open(QIODevice::ReadWrite)){
        QMessageBox::warning(this,"Hata","Seri Port Açılamıyor..");
        return;
    }else {
        QMessageBox::information(this,"Success","Port Açıldı!");
    }
    if(!frm){
        frm = new secondform();
        frm->setAttribute(Qt::WA_DeleteOnClose);
    }
    frm->show();
    frm->setPort(port);
    //this->hide();
    this->close();
    }
    catch(QException e)
    {
        QMessageBox::warning(this,"Hata","Hata");
    }
}
