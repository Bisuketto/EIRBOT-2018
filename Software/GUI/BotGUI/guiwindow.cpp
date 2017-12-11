#include "guiwindow.hpp"
#include "ui_guiwindow.h"

GUIWindow::GUIWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUIWindow)
{
    refresh_ports();
    ui->setupUi(this);
}

GUIWindow::~GUIWindow()
{
    delete ui;
}

void GUIWindow::obj_connect(){
    QObject::connect(ui->menuPort_COM, SIGNAL(hovered()), this, SLOT(refresh_ports()));
}

void GUIWindow::refresh_ports(){
    for(int i = 0; i < ui->menuPort_COM->actions().size(); i++){
        QAction *act_to_remove = ui->menuPort_COM->actions.at(i);
        ui->menuPort_COM->removeAction(act_to_remove);
    }
    QSerialPortInfo *infos = new QSerialPortInfo();
    for(int i = 0; i < infos->availablePorts().size(); i++){
        ui->menuPort_COM->addAction(infos->availablePorts().at(i).portName());
    }
}
