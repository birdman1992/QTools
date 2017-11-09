#include "dataconvert.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataConvert w;
    w.show();

    return a.exec();
}
