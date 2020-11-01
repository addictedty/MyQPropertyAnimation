#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->pushButton_return, SIGNAL(clicked()), this, SLOT(close()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_return_clicked()
{
    emit SetReturnWidget();
}
