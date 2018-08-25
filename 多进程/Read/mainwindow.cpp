#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>

extern QString buff;
extern bool signal_pthread;
double value;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //create();
    value=0;
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::create()
{

}

void MainWindow::update()
{
    if(!buff.isEmpty()) {
    ui->textEdit->append(buff);
    buff.clear();
    }
    ui->progressBar->setValue(value=value+0.05);
    if(signal_pthread) {
        ui->progressBar->setValue(100);
        timer->stop();
        return;
    }
}
