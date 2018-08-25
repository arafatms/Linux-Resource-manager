#ifndef READ_H
#define READ_H

#include <QWidget>

namespace Ui {
class Read;
}

class Read : public QWidget
{
    Q_OBJECT

public:
    explicit Read(QWidget *parent = 0);
    ~Read();

private:
    Ui::Read *ui;
};

#endif // READ_H
