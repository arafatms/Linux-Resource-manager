#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QString>
#include<QDebug>
#include<QDateTime>
#include "clockwidget.h"
#include"ps.h"
#include"cpuinfo.h"
#include "graph.h"


namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString openFIleReturnString(QString filename);
    float CPU_usage();
    MemInfoStruct Mem_usage();
    const QString ret_osinfo();

private:
    Ui::MainWindow *ui;
    clockWidget *CPU_clock_show;
    clockWidget *Mem_clock_show;
    bool flag_memtotal_read;
    CPUInfo *cpuinfo;
    ps *ps1;
    Graph *graph;

public slots:
    void timerUpdate(void);
    void show_cpuinfo();
    void show_proc();
    void show_graph();
    void clicked_PowerOffAction();
    void clicked_NewProgressAction();

};

#endif // MAINWINDOW_H
