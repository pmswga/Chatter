#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    aboutText = "<b>Chatter</b> - многофункциональный чат нового поколения <br>"
                "Версия: " + QApplication::applicationVersion();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_aboutQt_triggered()
{
    QMessageBox::aboutQt(this, "О Qt");
}

void MainWindow::on_aboutApp_triggered()
{
    QMessageBox::about(this, "О приложении", aboutText);
}

void MainWindow::on_connectToClient_clicked()
{

    emit connectToServer();
}
