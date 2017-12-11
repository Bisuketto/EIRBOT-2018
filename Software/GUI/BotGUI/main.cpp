#include "guiwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUIWindow w;
    w.show();

    return a.exec();
}
