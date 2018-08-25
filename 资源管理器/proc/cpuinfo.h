#ifndef CPUINFO_H
#define CPUINFO_H

#include <QWidget>

namespace Ui {
class CPUInfo;
}

class CPUInfo : public QWidget
{
    Q_OBJECT

public:
    explicit CPUInfo(QWidget *parent = 0);
    ~CPUInfo();

private:
    Ui::CPUInfo *ui;
};

#endif // CPUINFO_H
