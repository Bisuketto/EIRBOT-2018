#ifndef GUIWINDOW_HPP
#define GUIWINDOW_HPP

#include <iostream>
#include <QActionGroup>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <QStandardItemModel>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <TELEM_CODE.hpp>

namespace Ui {
class GUIWindow;
}

class GUIWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit GUIWindow(QWidget *parent = 0);
        ~GUIWindow();

    public slots:
        void refresh_ports();
        void connexion();
        void comSelect(QAction*_act);
        void readCom();

    private:
        Ui::GUIWindow *ui;
        void obj_connect();
        void consolePrint(QString _text);
        /*
            Write a converted float in 4 chars (big-endian) to a char array beginning on the specified character
        */
        void float_to_hex(float _fin, char *_str, int _start = 0);
        /*
            Write a converted int in 4 chars (big-endian) to a char array beginning on the specified character
        */
        void int_to_hex(int _iin, char *_str, int _start = 0);
        /*
            Return a converted float from 4 chars (big-endian) beginning on the specified character
        */
        float hex_to_float(char *_str, int _start = 0);
        /*
            Return a converted int from 4 chars (big-endian) beginning on the specified character
        */
        int hex_to_int(char *_str, int _start = 0);

        //Com
        bool connectedCom;
        QActionGroup *comGroup;
        QString selectedPort;
        QSerialPort *serialPort;
};

#endif // GUIWINDOW_HPP
