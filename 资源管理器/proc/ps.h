#ifndef PS_H
#define PS_H

#include <QWidget>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <QTimer>

using std::string;
using std::vector;

namespace Ui {
class ps;
}

class ps : public QWidget
{
    Q_OBJECT

public:
    explicit ps(QWidget *parent = 0);
    ~ps();
    int Get_ps_file();
    vector<string> getFiles(string cate_dir);

private:
    Ui::ps *ui;
    QTimer timer;
    int rowcounter_old;
public slots:
    void timerUpdate(void);
    void clickedKillPushButton();
    void clickedInfoPushButton();
    void clickedSearchPushButton();
};

#endif // PS_H
