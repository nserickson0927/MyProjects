#include <QtGui/QApplication>
#include "HW01.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    HW01 hw01;
    hw01.show();
    return app.exec();
}
