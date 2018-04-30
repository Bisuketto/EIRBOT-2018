#include "guiwindow.hpp"
#include "ui_guiwindow.h"

GUIWindow::GUIWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUIWindow)
{
    ui->setupUi(this);

    QGraphicsScene *map_scene = new QGraphicsScene(this);
    QPixmap *table = new QPixmap("data/table.png");
    QGraphicsPixmapItem *item_table = map_scene->addPixmap(*table);
    item_table->setScale(((float) ui->mapView->size().height()-2)/((float) table->size().height()));
    ui->mapView->setScene(map_scene);

    /*QStandardItemModel *model = new QStandardItemModel(10, 3);
    QStringList tableHeader;
    tableHeader << "Type" << "Donnée 1" << "Donnée 2";
    model->setHorizontalHeaderLabels(tableHeader);
    ui->tableView->setModel(model);*/
    QStringList tableHeader;
    tableHeader << "Type" << "Data 1" << "Data 2";
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem());
        }
    }

    connectedCom = false;
    selectedPort = "";
    comGroup = new QActionGroup(this);
    comGroup->setExclusive(true);

    serialPort = new QSerialPort();

    consolePrint(tr("Welcome to Eirbot GUI !"));

    refresh_ports();
    obj_connect();
}

GUIWindow::~GUIWindow()
{
    delete ui;
}

void GUIWindow::obj_connect(){
    QObject::connect(comGroup, SIGNAL(triggered(QAction*)), this, SLOT(comSelect(QAction*)));
    QObject::connect(ui->actionRefresh, SIGNAL(triggered(bool)), this, SLOT(refresh_ports()));
    QObject::connect(ui->button_connect, SIGNAL(clicked()), this, SLOT(connexion()));
}
//CACA.wav bb.
void GUIWindow::refresh_ports(){
    QSerialPortInfo *infos = new QSerialPortInfo();
    qDebug() << "Availlable Ports : " << infos->availablePorts().size();
    qDebug() << "Items in menu Port : " << ui->menuPort_COM->actions().size();
    for(int i = 2; i < ui->menuPort_COM->actions().size(); i++){
        bool supp = true;
        qDebug() << "Checking for avaiable : " << ui->menuPort_COM->actions().at(i)->text();
        for(int j = 0; j < infos->availablePorts().size(); j++){
            if(infos->availablePorts().at(j).portName() == ui->menuPort_COM->actions().at(i)->text()){
                supp = false;
            }
        }
        if(supp){
            QAction *act_to_remove = ui->menuPort_COM->actions().at(i);
            comGroup->removeAction(act_to_remove);
            ui->menuPort_COM->removeAction(act_to_remove);
        }
    }
    for(int i = 0; i < infos->availablePorts().size(); i++){
        bool create = true;
        qDebug() << "Checking for existing : " << infos->availablePorts().at(i).portName();
        for(int j = 2; j < ui->menuPort_COM->actions().size(); j++){
            if(ui->menuPort_COM->actions().at(j)->text() == infos->availablePorts().at(i).portName())
                create = false;
        }
        if(create){
            QAction *new_act = ui->menuPort_COM->addAction(infos->availablePorts().at(i).portName());
            comGroup->addAction(new_act);
            new_act->setCheckable(true);
        }
    }
    delete infos;
}

void GUIWindow::connexion(){
    if((!connectedCom) && selectedPort != "")
    {
        serialPort->setPortName(selectedPort);
        if(serialPort->open(QIODevice::ReadWrite))
        {
            connectedCom = true;
            consolePrint(tr("Connected to : ") + selectedPort);
            serialPort->setBaudRate(QSerialPort::Baud115200);//(QSerialPort::Baud57600);
            serialPort->setParity(QSerialPort::NoParity);
            serialPort->setFlowControl(QSerialPort::NoFlowControl);
            serialPort->setDataBits(QSerialPort::Data8);
            serialPort->setStopBits(QSerialPort::OneStop);
            serialPort->setDataTerminalReady(false);
            serialPort->setDataTerminalReady(true);
            QObject::connect(serialPort, SIGNAL(readyRead()), this, SLOT(readCom()));
        }
        else
        {
            consolePrint(tr("Failed to connect"));
        }
        if(connectedCom)
        {
            comGroup->setEnabled(false);
            //commande->setEnabled(true);
            //send->setEnabled(true);
            //zero->setEnabled(true);
            //stop->setEnabled(true);
            //joyActiv->setEnabled(true);
            //itemRobot->show();
            ui->button_connect->setText(tr("Disconnect"));
            ui->actionRefresh->setEnabled(false);
            //sendCom(); //Handshake **
        }
    }
    else if(connectedCom)
    {
        serialPort->close();
        QObject::disconnect(serialPort, SIGNAL(readyRead()), this, SLOT(readCom()));
        //commande->setEnabled(false);
        //send->setEnabled(false);
        //zero->setEnabled(false);
        //stop->setEnabled(false);
        //joyActiv->setEnabled(false);
        //itemRobot->hide();
        connectedCom = false;
        ui->button_connect->setText(tr("Connect"));
        comGroup->setEnabled(true);
        ui->actionRefresh->setEnabled(true);
        consolePrint(tr("Disconnected"));
    }
}

void GUIWindow::comSelect(QAction* _act){
    qDebug() << "Selecting : " << _act->text();
    selectedPort = _act->text();
}

void GUIWindow::consolePrint(QString _text){
    ui->console->append(_text);
    ui->console->ensureCursorVisible();
}

void GUIWindow::readCom(){
    if(serialPort->bytesAvailable() >= 9){
        char op[1] = "";
        char data[10] = "";
        serialPort->read(op, 1);
        QString optxt;
        optxt.append(op[0] + '0');
        char telem_code = op[0];
        qDebug("Telemetry code : %X", telem_code);
        switch(telem_code){
            case TELEM_CODE_PING :
                break;
            case TELEM_CODE_PONG :
                break;
            case TELEM_CODE_PWM  :
                serialPort->read(data, 8);
                qDebug() << "Line Received : " << data;
                qDebug() << "PWM L" << hex_to_float(data, 0);
                qDebug() << "PWM R" << hex_to_float(data, 4);
                ui->tableWidget->item(0,0)->setText("Pwm (L , R)");
                ui->tableWidget->item(0, 1)->setText(QString::number(hex_to_float(data, 0)));
                ui->tableWidget->item(0, 2)->setText(QString::number(hex_to_float(data, 4)));
                break;
            case TELEM_CODE_COORD:
                serialPort->read(data, 8);
                qDebug() << "Line Received : " << data;
                consolePrint(data);
                consolePrint("COORD Received");
                qDebug() << "x" << hex_to_float(data, 0);
                qDebug() << "y" << hex_to_float(data, 4);
                ui->tableWidget->item(1,0)->setText("Coordonates (x , y)");
                ui->tableWidget->item(1, 1)->setText(QString::number(hex_to_float(data, 0)));
                ui->tableWidget->item(1, 2)->setText(QString::number(hex_to_float(data, 4)));
                break;
            case TELEM_CODE_VOLT :
                serialPort->read(data, 8);
                qDebug() << "Line Received : " << data;
                consolePrint(data);
                consolePrint("VOLT Received");
                qDebug() << "18V" << hex_to_float(data, 0);
                qDebug() << "9V" << hex_to_float(data, 4);
                ui->tableWidget->item(2,0)->setText("Voltage (18V , 9V)");
                ui->tableWidget->item(2, 1)->setText(QString::number(hex_to_float(data, 0)));
                ui->tableWidget->item(2, 2)->setText(QString::number(hex_to_float(data, 4)));
                break;
            case TELEM_CODE_CURR :
                break;
            case TELEM_CODE_TEXT :
                break;
            case TELEM_CODE_GOTO :
                break;
            case TELEM_CODE_DIST :
                break;
            case TELEM_CODE_ANG  :
                serialPort->read(data, 4);
                qDebug() << "Line Received : " << data;
                consolePrint(data);
                consolePrint("ANG Received");
                qDebug() << "Angle" << hex_to_float(data, 0);
                ui->tableWidget->item(3,0)->setText("Angle ([rad] , [deg])");
                ui->tableWidget->item(3, 1)->setText(QString::number(hex_to_float(data, 0)));
                ui->tableWidget->item(3, 2)->setText(QString::number(180*hex_to_float(data, 4)/3.1415));
                break;
            case TELEM_CODE_ACK  :
                serialPort->read(data, 1);
                qDebug() << "Line Received : " << data;
                consolePrint(data);
                consolePrint("ACK Received");
                qDebug() << "ACK CODE" << data;
                break;
            case TELEM_CODE_ERR  :
                serialPort->read(data, 8);
                qDebug() << "Line Received : " << data;
                consolePrint(data);
                consolePrint("ERR Received");
                qDebug() << "Err L" << hex_to_float(data, 0);
                qDebug() << "Err R" << hex_to_float(data, 4);
                ui->tableWidget->item(4,0)->setText("Error (dist , ang)");
                ui->tableWidget->item(4, 1)->setText(QString::number(hex_to_float(data, 0)));
                ui->tableWidget->item(4, 2)->setText(QString::number(hex_to_float(data, 4)));
                break;
            case TELEM_CODE_ENC  :
                serialPort->read(data, 8);
                qDebug() << "Line Received : " << data;
                consolePrint(data);
                consolePrint("ENC Received");
                qDebug() << "ENC L" << hex_to_int(data, 0);
                qDebug() << "ENC R" << hex_to_int(data, 4);
                ui->tableWidget->item(5,0)->setText("Encoders (l , r)");
                ui->tableWidget->item(5, 1)->setText(QString::number(hex_to_float(data, 0)));
                ui->tableWidget->item(5, 2)->setText(QString::number(hex_to_float(data, 4)));
                break;
            case TELEM_CODE_TIME :
                serialPort->read(data, 4);
                qDebug() << "Line Received : " << data;
                consolePrint(data);
                consolePrint("TIME Received");
                qDebug() << "Time" << hex_to_float(data, 0);
                ui->tableWidget->item(6,0)->setText("Time (s , mins)");
                ui->tableWidget->item(6, 1)->setText(QString::number(hex_to_float(data, 0)));
                ui->tableWidget->item(6, 2)->setText(QString::number(hex_to_float(data, 4)/60));
                break;
            case TELEM_CODE_STAT :
                break;
            default :
                consolePrint("Wrong op received");
                serialPort->read(data, 1);
        }
    }
}

void GUIWindow::float_to_hex(float _fin, char *_str, int _start) {
    union { float f_val; unsigned int b_val; };
    f_val = _fin;
    unsigned int mask = 0x000000FF;
    for (int i = 0; i < 4; i++) {
        _str[3 - i + _start] = (b_val >> (8 * i)) & mask;
    }
}

void GUIWindow::int_to_hex(int _iin, char *_str, int _start) {
    int mask = 0x000000FF;
    for (int i = 0; i < 4; i++) {
        _str[3 - i + _start] = (_iin >> (8 * i)) & mask;
    }
}

float GUIWindow::hex_to_float(char *_str, int _start) {
    union {unsigned int b_val; float f_val; };
    b_val = 0;
    for (int i = 0; i < 4; i++) {
        unsigned int mask = 0x000000FF << (8 * i);
        unsigned int value = mask & ((_str[3 - i + _start]) << (8 * i));
        b_val |= value;
    }
    return f_val;
}

int GUIWindow::hex_to_int(char *_str, int _start) {
    int i_val = 0;
    for (int i = 0; i < 4; i++) {
        int mask = 0x000000FF << (8 * i);
        int value = mask & ((_str[3 - i + _start]) << (8 * i));
        i_val |= value;
    }
    return i_val;
}
