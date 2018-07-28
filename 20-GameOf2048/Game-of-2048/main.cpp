//#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "main_charBased.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

      freopen("in.txt", "r", stdin);

      int status = mainForCharBased();
      return status;

//    return a.exec();
}
