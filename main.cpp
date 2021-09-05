#include <qapplication.h>
#include "pianowidget.h"

int main(int argc, char *argv[])
{
    QApplication  a(argc, argv);
    CPianoWidget w;

    //a.setMainWidget(&w);
    w.show();
    return a.exec();
}
