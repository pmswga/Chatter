#include "mainwindow.h"
#include "clientwindow.h"
#include "serverwindow.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("fusion"));

    a.setOrganizationName("pmswga/soft");
    a.setApplicationName("Chatter");
    a.setApplicationVersion("2020.1");

    MainWindow w;
    w.setWindowTitle("Chatter");
    w.show();

    ServerWindow s;
    s.setWindowTitle("Chatter | Server");

    ClientWindow c;
    c.setWindowTitle("Chatter | Client");

    QObject::connect(&w, &MainWindow::startServer, &s, &ServerWindow::show);
    QObject::connect(&w, &MainWindow::connectToServer, &c, &ClientWindow::show);

    QObject::connect(&w, &MainWindow::startServer, &w, &MainWindow::close);
    QObject::connect(&w, &MainWindow::connectToServer, &w, &MainWindow::close);

    QObject::connect(&c, &ClientWindow::wantNewConnection, &w, &MainWindow::show);
    QObject::connect(&c, &ClientWindow::disconnectFromServer, &w, &MainWindow::show);

    return a.exec();
}
