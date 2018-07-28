#include "mainwindow.h"
#include <QApplication>

#include "main_charBased.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

      int status = mainForCharBased();
      return status;

//    return a.exec();
}
