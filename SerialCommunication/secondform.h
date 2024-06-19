#ifndef SECONDFORM_H
#define SECONDFORM_H

#include <QWidget>
#include <QSerialPort>

namespace Ui {
class secondform;
}

class secondform : public QWidget
{
    Q_OBJECT

public:
    explicit secondform(QWidget *parent = nullptr);
    ~secondform();
    void setPort(QSerialPort* ReceivedPort);

private slots:
    void on_pushButton_clicked();
    void ReadSerialData();

    void on_pushButton_2_clicked();

private:
    Ui::secondform *ui;
    QSerialPort* port;
};

#endif // SECONDFORM_H
