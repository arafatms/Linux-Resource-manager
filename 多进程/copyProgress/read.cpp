#include "read.h"
#include "ui_read.h"

Read::Read(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Read)
{
    ui->setupUi(this);
}

Read::~Read()
{
    delete ui;
}
