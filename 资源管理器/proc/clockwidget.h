#ifndef CLOCKWIDGET_H
#define CLOCKWIDGET_H

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
    void set_usage(float usage);

private:
    Ui::clockWidget *ui;
    float usage_value;
};

#endif // CLOCKWIDGET_H
