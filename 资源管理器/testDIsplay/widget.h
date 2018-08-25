#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <QTextCodec>
class DashboardProcess : public QWidget
{
    Q_OBJECT

public:
    DashboardProcess(QWidget *parent = 0);
    ~DashboardProcess();
    void setUsedValue(int value);
    void setSize(int width, int height);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent (QResizeEvent * event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

private slots:
    void slotUpdateTimer();
    void slotGapTimer();

private:
    QPoint beginDrag;
    bool bPressFlag;
    int typeDisplay;

    QPixmap pointPix;
    int userdVaule;
    int currentValue;
    QLabel *currentValueLabel;

    QTimer *updateTimer;
    QTimer *gapTimer;
    int gap;
    int gapCount;
};

#endif // WIDGET_H
