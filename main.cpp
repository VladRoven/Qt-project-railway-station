#include "mainwindow.h"

#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "UTF-8");
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    w.show();
    return a.exec();
}
