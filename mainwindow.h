#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QString aboutText;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void connectToServer();
    void startServer();

private slots:
    void on_aboutQt_triggered();
    void on_aboutApp_triggered();

    void on_connectToClient_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
