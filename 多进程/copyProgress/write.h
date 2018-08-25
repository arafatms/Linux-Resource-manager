#ifndef WRITE_H
#define WRITE_H

#include <QWidget>

namespace Ui {
class Write;
}

class Write : public QWidget
{
    Q_OBJECT

public:
    explicit Write(QWidget *parent = 0);
    ~Write();

private:
    Ui::Write *ui;
};

#endif // WRITE_H
