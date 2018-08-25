#include "cpuinfo.h"
#include "ui_cpuinfo.h"
#include <fstream>
#include <QDebug>

CPUInfo::CPUInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CPUInfo)
{
    ui->setupUi(this);


    FILE *fp;
    char buf[256];

    fp=fopen("/proc/cpuinfo","r");
    if(fp == NULL)   //when pros by kill
    {
        exit(-1);
    }
    qDebug()<<"cpu info";
    while(!feof(fp)){
        fgets(buf,sizeof(buf),fp);
        //qDebug()<<buf;
        ui->textEdit->append(buf);
    }
    fclose(fp);

}

CPUInfo::~CPUInfo()
{
    delete ui;
}
