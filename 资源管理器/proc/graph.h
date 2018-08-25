#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include "qcustomplot.h"

struct MemInfoStruct
{
    float Mem_usage;
    float swap_usage;
};

namespace Ui {
class Graph;
}

class Graph : public QWidget
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = 0);
    ~Graph();
    double num1[100];
        double num2[100];
            int n;
            void Graph_Show(QCustomPlot *CustomPlot,QVector<double> data);
            void Graph_Show(double cpu_usage,MemInfoStruct str);

private:
    Ui::Graph *ui;

    QVector<double> CPUusage;
    QVector<double> Memusage;
    QVector<double> Swapusage;
private slots:
    void RePaint();

};

#endif // GRAPH_H
