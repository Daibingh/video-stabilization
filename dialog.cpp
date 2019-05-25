#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    p = (MainWindow*)parent;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    int radius = ui->lineEdit->text().toInt();
    cout<<"radius: "<<radius<<endl;
    p->player->radius = radius;
}
