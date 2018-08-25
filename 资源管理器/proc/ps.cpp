#include "ps.h"
#include "ui_ps.h"
#include <stdlib.h>
#include<fstream>
#include<QDebug>
#include<QTableWidget>
#include<QHeaderView>
#include <QScrollBar>

#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include<QMessageBox>
#include<QLineEdit>

using namespace std;
ps::ps(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ps)
{
        ui->setupUi(this);
        this->setLayout(ui->verticalLayout);




        //chushihua liebiao
         ui->tableWidget->setColumnCount(5); //设置列数
         rowcounter_old=100;
         ui->tableWidget->setRowCount(rowcounter_old);


          ui->tableWidget->horizontalHeader()->resizeSection(0,250);
          ui->tableWidget->horizontalHeader()->resizeSection(1,100);

          //hide horizontalScrollBar
          ui->tableWidget->horizontalScrollBar()->hide();

          //设置表头内容
          QStringList header;
          header<<tr("name")<<tr("pid")<<tr("ppid")<<tr("Rss")<<tr("pri");
          ui->tableWidget->setHorizontalHeaderLabels(header);



          //设置表头字体加粗

          QFont font = ui->tableWidget->horizontalHeader()->font();
          font.setBold(true);
          ui->tableWidget->horizontalHeader()->setFont(font);\

          ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

          ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  // 选中一行




          timerUpdate();

          //update
          connect(&timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
          timer.start(1000);


          connect(ui->KillpushButton,SIGNAL(clicked(bool)),this,SLOT(clickedKillPushButton()));
          connect(ui->infopushButton,SIGNAL(clicked(bool)),this,SLOT(clickedInfoPushButton()));
          connect(ui->searchpushButton,SIGNAL(clicked(bool)),this,SLOT(clickedSearchPushButton()));




}

ps::~ps()
{
    delete ui;
}


int ps::Get_ps_file(){

    //system ("ps -x >>psdata.txt");
    return 1;
}


//get file name
vector<string> ps::getFiles(string cate_dir)
{
    vector<string> files;//存放文件名

    DIR *dir;
    struct dirent *ptr;
    char base[1000];

    if ((dir=opendir(cate_dir.c_str())) == NULL)
        {
        perror("Open dir error...");
                exit(1);
        }

    while ((ptr=readdir(dir)) != NULL)
    {
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
                continue;
        else if(ptr->d_type == 8)    ///file
            //printf("d_name:%s/%s\n",basePath,ptr->d_name);
            files.push_back(ptr->d_name);
        else if(ptr->d_type == 10)    ///link file
            //printf("d_name:%s/%s\n",basePath,ptr->d_name);
            continue;
        else if(ptr->d_type == 4)    ///dir
        {
            files.push_back(ptr->d_name);
        }
    }
    closedir(dir);

    //排序，按从小到大排序
    sort(files.begin(), files.end());
    return files;
}
//update psdata
void ps::timerUpdate(){
    FILE *fp;
    char name[25],scan_temp[25];

    string basePath="/proc";
    vector<string> files=getFiles(basePath);
//    for (int i=0; i<files.size(); i++)
//    {
//        cout<<files[i]<<endl;
//    }

//    cout<<"end..."<<endl<<endl;


    //set rowCount of table widget
    ui->tableWidget->setRowCount(files.size());
    int rowcounter=0;

    for(int i=0;i<files.size();i++){


        int pid,priority,rss,ppid;
        string temp="/proc/"+files[i]+"/stat";
        fp=fopen(temp.data(),"r");
        if(fp == NULL)   //when pros by kill
        {
            continue;
        }
        else rowcounter++;


        if(rowcounter>rowcounter_old) {
            ui->tableWidget->setRowCount(files.size());
            rowcounter_old=files.size();
        }

//        fgets(buf,sizeof(buf),fp);
//        qDebug()<<buf;
        for(int j=0;j<25;j++){
            if(j==0) fscanf(fp,"%d",&pid);
            else if(j==1) fscanf(fp,"%s",name);
            else if(j==3) fscanf(fp,"%d",&ppid);
            else if(j==17) fscanf(fp,"%d",&priority);
            //else if(j==23) fscanf(fp,"%d",&rss);
            else fscanf(fp,"%s",scan_temp);
        }
        fclose(fp);
        temp=temp+"m";
        fp=fopen(temp.data(),"r");
        if(fp == NULL)   //when pros by kill
        {
            continue;
        }

        fscanf(fp,"%s%d",scan_temp,&rss);
        rss=rss*4;
        fclose(fp);
        //qDebug()<<name<<pid<<ppid<<priority<<rss;


        //insert in listWidget
          QTableWidgetItem *item = new QTableWidgetItem();
          QTableWidgetItem *item1 = new QTableWidgetItem();
          QTableWidgetItem *item2 = new QTableWidgetItem();
          QTableWidgetItem *item3 = new QTableWidgetItem();
          QTableWidgetItem *item4 = new QTableWidgetItem();
          item->setText(QString(name).remove("(").remove(")"));

          item1->setText(QString::number(pid,10));
          item2->setText(QString::number(ppid,10));
          item3->setText(QString::number(rss,10));
          item4->setText(QString::number(priority,10));

          ui->tableWidget->setItem(i, 0, item);
          ui->tableWidget->setItem(i, 1, item1);
            ui->tableWidget->setItem(i, 2, item2);
            ui->tableWidget->setItem(i, 3, item3);
            ui->tableWidget->setItem(i, 4, item4);

    }
    ui->tableWidget->setRowCount(rowcounter);
    rowcounter_old=rowcounter;


}

void ps::clickedKillPushButton()
{
    if(ui->tableWidget->selectedItems().isEmpty()) return;
    QMessageBox::StandardButton rb = QMessageBox::question(NULL, "Warning", "this maybe  will broke your system,are you sure to continue?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {
        QList<QTableWidgetItem*> items = ui->tableWidget->selectedItems();
        QTableWidgetItem *item = items.at(1);
        int pid=item->text().toInt();
        kill(pid,SIGKILL);  //kill ps
    }


}

void ps::clickedInfoPushButton()
{
    if(ui->tableWidget->selectedItems().isEmpty()) return;
    QList<QTableWidgetItem*> items = ui->tableWidget->selectedItems();
    QTableWidgetItem *item = items.at(1);
    int pid=item->text().toInt();
    char datapath[30];
    sprintf(datapath,"/proc/%d/status",pid);
    //qDebug()<<datapath;
    FILE *fp;
    fp=fopen(datapath,"r");
    QString infoStr;
    char buf[128];
    while(!feof(fp)){
    fgets(buf,sizeof(buf),fp);
    infoStr+=buf;
    }
    QMessageBox::information(this,"information",infoStr);
}

void ps::clickedSearchPushButton()
{
    QString text=ui->searchlineEdit->text();
    if(text.isEmpty()) return;
    for(int i=0;i<rowcounter_old;i++){
        if(ui->tableWidget->item(i,0)->text()==text||ui->tableWidget->item(i,1)->text()==text){
            ui->tableWidget->selectRow(i);
            break;
        }
    }
}
