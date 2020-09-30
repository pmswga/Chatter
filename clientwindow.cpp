#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);

}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::on_connectToServer_triggered()
{
    this->close();
    emit wantNewConnection();
}

void ClientWindow::on_disconnectFromServer_triggered()
{
    this->close();
    emit disconnectFromServer();
}
