#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // define serial port variable
    serial = new QSerialPort(this);

    // connect readyRead signal of serial with readData function
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));

    // Show available COM-Ports
    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        ui->cmbSerialPort->addItem(port.portName());
    }

    // set serial parameters
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    // initialize plot
    ui->widget->addGraph();
    ui->widget->xAxis->setLabel("Wavelength");
    ui->widget->yAxis->setLabel("Pixel");
    ui->widget->xAxis->setRange(0, 288);
    ui->widget->yAxis->setRange(0, 65535);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_cmdConnect_clicked()
{
    // if serial is not connected, connect
    if (ui->cmdConnect->text() == "Connect") {
        // set selected COM Port
        serial->setPortName(ui->cmbSerialPort->currentText());
        // connect to serial port
        if (serial->open(QIODevice::ReadWrite)) {
            // if the connection attempt was successful, change text of button to "disconnect"
            ui->cmdConnect->setText("Disconnect");
        }
    } else {
        // if serial is already connected, close serial connection
        serial->close();
        // change text of button to "connect"
        ui->cmdConnect->setText("Connect");
    }
}

// this function is triggered by SIGNAL readyRead of QSerialPort
void MainWindow::readData() {
    // first, read in a line
    QByteArray data;
    data = serial->readLine();
    // convert QByteArray to String
    QString bytestring = tr(data);

    // check if string is "!spek!\n" what means, that there is a new spectrum
    if (bytestring == "!spek!\n") {

        // if there is a new spectrum, get 2x288 = 576 byte values from serial
        char bytes[576];

        // make sure, that all data bytes are ready to read, otherwise, do not read in yet
        if (serial->bytesAvailable() >= 576) {
            for (int i=0;i<576;i++) {
                char dataByte = 0;
                serial->read(&dataByte, 1);
                bytes[i] = dataByte;
            }
            int counter=0;
            int arraycounter = 0;
            uint16_t spektrum[288];

            // build a spectrum from data (2 byte values per pixel have to be converted to one 16 bit value per pixel)
            for (int i=0;i<288;i++) {
               uint8_t highbyte = bytes[counter];
               uint8_t lowbyte = bytes[counter+1];
               uint16_t value = highbyte<<8 | lowbyte;
               counter = counter + 2;
               spektrum[arraycounter] = value;
               arraycounter++;
            }

            // define two QVectors for the plot
            QVector<double> x(288), y(288);

            // write the right values into the QVectors
            for (int i=0;i<288;i++) {
                x[i] = i;
                y[i] = spektrum[i];
            }

            // plot the QVectors, which contain the pixel count and the pixel number
            ui->widget->graph(0)->setData(x, y);
            ui->widget->replot();
        }
    }
}

// this function is triggered if the users clicks on the button "set"
void MainWindow::on_pushButton_clicked()
{
    char bytes[6];
    // read in the wanted integration time
    int n = ui->spbIntegrationTime->value();
    // calculate the right amount of timer periods
    int longInt = round((n-192)/0.033);
    // control byte
    bytes[0] = 0x1F;
    // data bytes
    bytes[1] = (longInt >> 24) & 0xFF;
    bytes[2] = (longInt >> 16) & 0xFF;
    bytes[3] = (longInt >> 8) & 0xFF;
    bytes[4] = longInt & 0xFF;
    // do not forget to write "\r" / 0x0D to serial, otherwise the spectrometer will not get the data
    bytes[5] = 0x0D;
    serial->write(bytes, 6);
}

void MainWindow::on_actionClose_triggered()
{
    // quit application
    qApp->exit();
}
