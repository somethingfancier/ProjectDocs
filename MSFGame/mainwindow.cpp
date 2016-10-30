#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pbStart_clicked()
{
    Game *game = new Game();
    game->show();
    
    QMainWindow::close();
}

void MainWindow::on_pbLoad_clicked()
{

}

void MainWindow::on_pbControls_clicked()
{
    QMessageBox msg;
    msg.setText("Controls: \n\n*Move - arrow keys \n*Attack - spacebar \n*Pause - esc key");
    msg.exec();
}

void MainWindow::on_pbExit_clicked()
{
    QApplication::quit();
}
