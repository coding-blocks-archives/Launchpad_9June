//#include "mainwindow.h"
//#include <QCoreApplication>
#include <iostream>
#include "main_charBased.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

      std::cout << "Hi";
      int status = mainForCharBased();
      return status;

//    return a.exec();
}
