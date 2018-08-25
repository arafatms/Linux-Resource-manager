#include "graph.h"
#include "ui_graph.h"
#include <QVector>

#include <QTime>
#include <QTimer>
#include <time.h>

Graph::Graph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);

    QLinearGradient plotGradient;
    //lotGradient.setStart(0, 0);
    //plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    //plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->widget->setBackground(plotGradient);

   //设置坐标颜色/坐标名称颜色
    ui->widget->xAxis->setLabelColor(Qt::white);//文字颜色
    ui->widget->yAxis->setLabelColor(Qt::white);
    ui->widget->xAxis->setTickLabelColor(Qt::white);//坐标轴数字颜色
    ui->widget->yAxis->setTickLabelColor(Qt::white);
    ui->widget->xAxis->setBasePen(QPen(Qt::white, 1));//坐标轴颜色及宽度
    ui->widget->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->widget->xAxis->setTickPen(QPen(Qt::white, 1));//主刻度
    ui->widget->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->widget->xAxis->setSubTickPen(QPen(Qt::white, 1));//副刻度
    ui->widget->yAxis->setSubTickPen(QPen(Qt::white, 1));


    //设置属性可缩放，移动等
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                         QCP::iSelectLegend | QCP::iSelectPlottables);


    ui->Memwidget->setBackground(plotGradient);

   //设置坐标颜色/坐标名称颜色
    ui->Memwidget->xAxis->setLabelColor(Qt::white);//文字颜色
    ui->Memwidget->yAxis->setLabelColor(Qt::white);
    ui->Memwidget->xAxis->setTickLabelColor(Qt::white);//坐标轴数字颜色
    ui->Memwidget->yAxis->setTickLabelColor(Qt::white);
    ui->Memwidget->xAxis->setBasePen(QPen(Qt::white, 1));//坐标轴颜色及宽度
    ui->Memwidget->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->Memwidget->xAxis->setTickPen(QPen(Qt::white, 1));//主刻度
    ui->Memwidget->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->Memwidget->xAxis->setSubTickPen(QPen(Qt::white, 1));//副刻度
    ui->Memwidget->yAxis->setSubTickPen(QPen(Qt::white, 1));


    //设置属性可缩放，移动等
    ui->Memwidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                         QCP::iSelectLegend | QCP::iSelectPlottables);


    ui->Swapwidget->setBackground(plotGradient);
    ui->Swapwidget->xAxis->setLabelColor(Qt::white);//文字颜色
    ui->Swapwidget->yAxis->setLabelColor(Qt::white);
    ui->Swapwidget->xAxis->setTickLabelColor(Qt::white);//坐标轴数字颜色
    ui->Swapwidget->yAxis->setTickLabelColor(Qt::white);
    ui->Swapwidget->xAxis->setBasePen(QPen(Qt::white, 1));//坐标轴颜色及宽度
    ui->Swapwidget->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->Swapwidget->xAxis->setTickPen(QPen(Qt::white, 1));//主刻度
    ui->Swapwidget->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->Swapwidget->xAxis->setSubTickPen(QPen(Qt::white, 1));//副刻度
    ui->Swapwidget->yAxis->setSubTickPen(QPen(Qt::white, 1));


    //设置属性可缩放，移动等
    ui->Swapwidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                         QCP::iSelectLegend | QCP::iSelectPlottables);

    connect(ui->RePaintButton,SIGNAL(clicked(bool)),this,SLOT(RePaint()));
}

Graph::~Graph()
{
    delete ui;
}

void Graph::Graph_Show(QCustomPlot *CustomPlot,QVector<double> data)
{
        QVector<double> temp(20);
        for(int i=0;i<20;i++) temp[i]=i;
       //设置画布颜色



        CustomPlot->addGraph();//添加一条曲线
        CustomPlot->graph(0)->setPen(QPen(Qt::green)); //0是曲线序号，添加的第一条是0，设置曲线颜色
        CustomPlot->graph(0)->setData(temp,data); //输出各点的图像，x和y都是QVector类


        CustomPlot->xAxis->setRange(0,20);//x轴范围
        CustomPlot->yAxis->setRange(0,100);//y轴范围
        CustomPlot->replot();//重绘
}

void Graph::Graph_Show(double cpu_usage,MemInfoStruct str)
{
     CPUusage.append(cpu_usage);
     if(CPUusage.size()>20) CPUusage.removeFirst();
     Graph_Show(ui->widget,CPUusage);

     Memusage.append(str.Mem_usage);
     if(Memusage.size()>20) Memusage.removeFirst();
     Graph_Show(ui->Memwidget,Memusage);

     Swapusage.append(str.swap_usage);
     if(Swapusage.size()>20) Swapusage.removeFirst();
     Graph_Show(ui->Swapwidget,Swapusage);
}

void Graph::RePaint()
{
    CPUusage.clear();
    Memusage.clear();
    Swapusage.clear();
}
