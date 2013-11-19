#include "colorclass.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    colorclass w;
    w.show();

    return a.exec();
}
