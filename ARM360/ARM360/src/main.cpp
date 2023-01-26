#include "stdafx.h"
#include "arm360.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ARM360 w;
    w.show();
    return a.exec();
}
