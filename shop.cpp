#include "shop.h"
#include "ui_shop.h"
#include "QFile"
#include "QDebug"
#include"QSpinBox"
#include "QMessageBox"
#include "mainwindow.h"
#include "QTextStream"
int arrInt[3];
int arrPrice[3];
QString arrName[3];
QSpinBox* arrSpin[3];
int converting(QString str, QString arr[3], int a)
{
  QStringList fields = str.split("|");
  if (fields.size() == 3) {
    arr[0] = fields[0];
    a = fields[1].toInt();
    arr[1] = fields[1];
    arr[2] = fields[2];
    arr[2].resize( arr[2].size()-2);
  }
  return a;
}
int converting(QString str, QString arr[3], int a);
shop::shop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shop)
{
    ui->setupUi(this);
    ui->label->setText("hello, "+login);
    QFile file("C:/Users/User/Desktop/final/products.txt");
    file.open(QIODevice::ReadOnly);
int c=0;


    while (!file.atEnd())
    {
        QString str = file.readLine();
        QString conArr[3];
        arrInt[c] = converting(str,conArr,arrInt[c]);
        ui->MyCuteBase->insertRow( ui->MyCuteBase->rowCount() );//добавляет строку
    for(int row = c; row < ui->MyCuteBase->rowCount(); row++)
      for(int column = 0; column < ui->MyCuteBase->columnCount(); column++)
      {
           QTableWidgetItem *item = new QTableWidgetItem(); // выделяем память под ячейку
           switch (column)
               {

               case 0:
               item->setText(QString(conArr[0])); // вставляем текст
               arrName[c] = conArr[0];
               ui->MyCuteBase->setItem(row, column, item); // вставляем ячейку
                   break;
               case 1:
               item->setText(QString(conArr[1])); // вставляем текст
               ui->MyCuteBase->setItem(row, column, item); // вставляем ячейку
                    break;
               case 2:
               arrPrice[c]= conArr[2].toInt();
               item->setText(QString(conArr[2])); // вставляем текст
               ui->MyCuteBase->setItem(row, column, item); // вставляем ячейку
                    break;
               case 3:
                QSpinBox *spin = new QSpinBox;
                arrSpin[c] = spin;
                spin->setMaximum(arrInt[c]);
                ui->MyCuteBase->setCellWidget(row,column,  spin);
                }

      }
    c++;
    }
    ui->MyCuteBase->setEditTriggers(0);
    for(int row = 0; row < ui->MyCuteBase->rowCount(); row++)
    {
     arrSpin[row]->value();
    }

}

shop::~shop()
{
    delete ui;
}



void shop::on_pushButton_clicked()
{
    if (arrSpin[0]->value()==0 and arrSpin[1]->value()==0 and arrSpin[2]->value()==0 )
         {
              QMessageBox::warning(this, "error","Пожалуйста, выберите товары!");
         }
        else
    {

        QFile output("C:/Users/User/Desktop/final/check.txt");
         QTextStream out(&output);
        output.open(QIODevice::WriteOnly);
        out <<"Login: "<< login << "\n";
        int sum = 0;
        for (int I=0; I<3;I++)
        if (arrSpin[I]->value()!=0)
        {
             int price = arrPrice[I]*(arrSpin[I]->value());
             sum+=price;
             out<<arrName[I]<<" - "<<arrSpin[I]->value()<<" "<<price <<"\n";
        }
        out<<"Check: "<<sum<<"\n";
    close();

    }

}
