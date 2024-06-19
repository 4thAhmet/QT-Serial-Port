#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "form2.h"
#include "secondform.h"
#include <QMainWindow>
#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    //void readSerialData();
    void doldur();

private:
    Ui::MainWindow *ui;
    QSerialPort *port;
    secondform *frm;
};
#endif // MAINWINDOW_H
