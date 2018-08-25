#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTimer"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cpuinfo=NULL; ps1=NULL; graph=NULL;
    flag_memtotal_read=false;
    //hostnamelabelload
    QString myText =openFIleReturnString("/proc/sys/kernel/hostname");
    myText="hostName:"+myText.remove(myText.size()-1,1);
    qDebug() << myText;
    ui->hostnamelabel->setText(myText);


    CPU_clock_show=new clockWidget(ui->stateframe);
    CPU_clock_show->setGeometry(30,30,170,170);
    CPU_clock_show->show();


    Mem_clock_show=new clockWidget(ui->stateframe);
    Mem_clock_show->setGeometry(30,250,170,170);
    Mem_clock_show->show();


    //showTime
    timerUpdate();

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);


    //showOsLabel
    ui->Oslabel->setText("OSType:"+ret_osinfo());

    ps1=new ps(ui->procframe);
    ps1->setGeometry(0,0,680,555);
    ps1->show();

    connect(ui->actioninfo,SIGNAL(triggered(bool)),this,SLOT(show_cpuinfo()));
    connect(ui->actionshow_ps,SIGNAL(triggered(bool)),this,SLOT(show_proc()));
    connect(ui->PowerOffaction,SIGNAL(triggered(bool)),this,SLOT(clicked_PowerOffAction()));
    connect(ui->NewProgressaction,SIGNAL(triggered(bool)),this,SLOT(clicked_NewProgressAction()));
    connect(ui->action_Graph,SIGNAL(triggered(bool)),this,SLOT(show_graph()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::openFIleReturnString(QString filename){
        QFile file(filename);
        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            qDebug() << " Could not open the file for reading";
            return "null";
        }
        QTextStream in(&file);
        QString myText = in.readAll();
        file.close();
        return myText;
}


void MainWindow::timerUpdate(void)
{
    //activate Time&Run Time
    QString myText =openFIleReturnString("/proc/uptime");
    QString tempText=myText;
    myText="activate Time:"+myText.remove(myText.indexOf(" ",0),10);
    ui->activateTimelabel->setText(myText);
    tempText="Run Time:"+tempText.remove(0,myText.indexOf(" ",0));
    tempText=tempText.remove(tempText.size()-1,1);

    ui->RunTimelabel->setText(tempText);

    //current Time
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
    ui->CurrentTimelabel->setText(current_date);

    //cup_usage update
    float usage_CPU=CPU_usage();
    CPU_clock_show->set_usage(usage_CPU);
    ui->cpuphereLabel->setText(QString("%1%").arg(usage_CPU));

    //mem_usage update
    MemInfoStruct usage_Mem=Mem_usage();
    Mem_clock_show->set_usage(usage_Mem.Mem_usage);
    ui->memphereLabel->setText(QString("%1%").arg(usage_Mem.Mem_usage));

    if(graph!=NULL) graph->Graph_Show(usage_CPU,usage_Mem);

}

void MainWindow::show_cpuinfo()
{

    if(cpuinfo) return;
    //close other widget
    if(ps1) {
        delete ps1;
        ps1=NULL;
    }
    if(graph){
        delete graph;
        graph=NULL;
    }

    //create widget of cpuinfo
    cpuinfo=new CPUInfo(ui->procframe);
    cpuinfo->setGeometry(0,0,680,555);

    cpuinfo->show();
}

void MainWindow::show_proc()
{
    if(ps1) return;

    //close other widget
    if(cpuinfo) {
        delete cpuinfo;
        cpuinfo=NULL;
    }
    if(graph){
        delete graph;
        graph=NULL;
    }

    //create widget of proc
    ps1=new ps(ui->procframe);
    ps1->setGeometry(0,0,680,555);
    ps1->show();
}

void MainWindow::show_graph()
{
    if(graph) return;

    //close other widget
    if(cpuinfo) {
        delete cpuinfo;
        cpuinfo=NULL;
    }
    if(ps1) {
        delete ps1;
        ps1=NULL;
    }

    //create widget of proc
    graph=new Graph(ui->procframe);
    graph->setGeometry(0,0,680,555);
    graph->show();
}

void MainWindow::clicked_PowerOffAction()
{
    QMessageBox::StandardButton rb = QMessageBox::question(NULL, "Warning", "this will let your system power off,are you sure to continue?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {
        system("poweroff");
    }
}

void MainWindow::clicked_NewProgressAction()
{
    QString file_name = QFileDialog::getOpenFileName(NULL,"Open New Progress",".","*");
    file_name="cd / \n"+file_name+" &";
    qDebug()<<file_name;
    QByteArray ba = file_name.toLatin1(); // must
    system(ba.data());

}


float MainWindow::CPU_usage(){
            FILE *fp;
            char buf[128];
            char cpu[5];
            static long int static_all=0;
            static long int static_idle=0;
            long int user,nice,sys,idle,iowait,irq,softirq;

            long int all1,idle1;
            float usage;

                    fp = fopen("/proc/stat","r");
                    if(fp == NULL)
                    {
                            perror("fopen:");
                            exit (0);
                    }


                    fgets(buf,sizeof(buf),fp);
                    sscanf(buf,"%s%d%d%d%d%d%d%d",cpu,&user,&nice,&sys,&idle,&iowait,&irq,&softirq);
                    /*
    #if __DEBUG__
    printf("%s,%d,%d,%d,%d,%d,%d,%d\n",cpu,user,nice,sys,idle,iowait,irq,softirq);
    #endif
    */
                    all1 = user+nice+sys+idle+iowait+irq+softirq;
                    idle1 = idle;

                    usage = (float)(all1-static_all-(idle1-static_idle)) / (all1-static_all)*100 ;

                    static_all=all1;
                    static_idle=idle1;

                    fclose(fp);
             return usage;
}

MemInfoStruct MainWindow::Mem_usage(){
            FILE *fp;
            char buf[128];
            char titlename[10];
            char kb[3];
            long int memtotal,memactive,SwapTotal,SwapFree;

            MemInfoStruct str;
            float usage,SwapUsage;

                    fp = fopen("/proc/meminfo","r");
                    if(fp == NULL)
                    {
                            perror("fopen:");
                            exit (0);
                    }
                    for(int i=0;i<16;i++){
                        fgets(buf,sizeof(buf),fp);
                        qDebug()<<buf<<"end";
                        if(i==0){   //get memtotal
                            sscanf(buf,"%s%ld%s",titlename,&memtotal,kb);

                        }

                        else if(i==6){   //get memactive
                            sscanf(buf,"%s%ld%s",titlename,&memactive,kb);

                        }
                        else if(i==14){   //get memactive
                            sscanf(buf,"%s%ld%s",titlename,&SwapTotal,kb);

                        }
                        else if(i==15){   //get memactive
                            sscanf(buf,"%s%ld%s",titlename,&SwapFree,kb);

                        }
                    }
                    usage=(float)memactive/memtotal*100;
                    SwapUsage=(float)(SwapTotal-SwapFree)/SwapTotal;
                    str.Mem_usage=usage;
                    str.swap_usage=SwapUsage;
             return str;
}

const QString MainWindow::ret_osinfo(){
    FILE *fp;
    fp = fopen("/proc/sys/kernel/ostype","r");
    char buf_type[10],buf_release[20];
    if(fp==NULL){
        perror("fopen:");
        exit(0);
    }
    fgets(buf_type,sizeof(buf_type),fp);
    fclose(fp);
    fp=fopen("/proc/sys/kernel/osrelease","r");
    if(fp==NULL){
        perror("fopen:");
        exit(0);
    }
    fgets(buf_release,sizeof(buf_release),fp);
    QString ret_str=QString("%1 %2").arg(buf_type,buf_release);
    ret_str.replace("\n","");
    return ret_str;
}
