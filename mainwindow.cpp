#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "shop.h"
QString login;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Вход");

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString log = ui->login->text();

    if (log == "")
    {
        QMessageBox::warning(this, "Ошибка!", "Пожалуйста, введите логин");
    }
    else
    {
        bool checker = 1;
        for (int i = 0; i< log.size();i++)
        {
            if (log[i] == ' ')
            {
                QMessageBox::warning(this, "Ошибка!", "Пожалуйста, введите логин без пробелов");
                i =  log.size();
                checker = 0;
            }

        }
        if (checker == 1)
        {
         MainWindow::setLogin(log);
         hide();
         shop Shop;
         Shop.setModal(true);
         Shop.exec();

        }
    }
}
