#ifndef GUIWINDOW_HPP
#define GUIWINDOW_HPP

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

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

    private:
        Ui::GUIWindow *ui;
        void obj_connect();

        //Com
        QSerialPort *serialPort;
};

#endif // GUIWINDOW_HPP
