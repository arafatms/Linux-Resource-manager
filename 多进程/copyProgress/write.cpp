#include "write.h"
#include "ui_write.h"

Write::Write(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Write)
{
    ui->setupUi(this);
}

Write::~Write()
{
    delete ui;
}
