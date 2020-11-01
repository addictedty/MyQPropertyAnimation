#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_showFlag = false;

    label = new QLabel(this);
    dialog = new Dialog(this);
    dialog->setGeometry(pos().x(), pos().y(), width(), height());
    dialog->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);


    animal1= new QPropertyAnimation(label,"pos");

    connect(dialog, SIGNAL(SetReturnWidget()), this, SLOT(ReturnWidget()));
    connect(animal1, SIGNAL(finished()), this, SLOT(AnimationFinish()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_show_clicked()
{
    QRect rect = geometry();

    dialog->setGeometry(rect.x(), rect.y(), rect.width(), rect.height() - 100);
    label->setGeometry(rect.x(), -rect.x(), rect.width(), rect.height() - 100);
    label->setPixmap(dialog->grab());

    animal1->setDuration(500);
    animal1->setStartValue(QPoint(0, -dialog->height()));  //startx的值是原点横坐标-部件长度
    animal1->setEndValue(QPoint(0, 0));
    animal1->start();

    m_showFlag = true;
}

void MainWindow::ReturnWidget()
{
    animal1->setDuration(500);
    animal1->setStartValue(QPoint(0, 0));  //startx的值是原点横坐标-部件长度
    animal1->setEndValue(QPoint(0, -dialog->height()));
    animal1->start();

    m_showFlag = false;
}

void MainWindow::AnimationFinish()
{
    if(m_showFlag)
    {
        dialog->exec();
    }
}
