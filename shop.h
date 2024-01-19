#ifndef SHOP_H
#define SHOP_H

#include <QDialog>

namespace Ui {
class shop;
}

class shop : public QDialog
{
    Q_OBJECT

public:
    explicit shop(QWidget *parent = nullptr);
    ~shop();

private slots:


    void on_pushButton_clicked();

private:
    Ui::shop *ui;
};

#endif // SHOP_H
