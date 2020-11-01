#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QLayout>
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_show_clicked();

    void ReturnWidget();

    void AnimationFinish();

private:
    Dialog *dialog;

    QLabel *label;

    QPropertyAnimation *animal1;

    bool m_showFlag;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
