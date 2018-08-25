#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class clockWidget;
}

class clockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit clockWidget(QWidget *parent = 0);
    ~clockWidget();
    QRectF textRectF(double radius, int pointSize, double angle);
    void paintEvent(QPaintEvent *event);

private:
    Ui::clockWidget *ui;
};

#endif // WIDGET_H
