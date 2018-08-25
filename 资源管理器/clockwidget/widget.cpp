#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <qmath.h>
#include <QTime>
#include <QPainter>

clockWidget::clockWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clockWidget)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));
        timer->start(1000);

}

clockWidget::~clockWidget()
{
    delete ui;
}

QRectF clockWidget::textRectF(double radius, int pointSize, double angle)
{
    QRectF rectF;
    rectF.setX(radius*qCos(angle*3.14/180.0) - pointSize*2);
    rectF.setY(radius*qSin(angle*3.14/180.0) - pointSize/2.0);
    rectF.setWidth(pointSize*4);
    rectF.setHeight(pointSize);
    return rectF;
}


void clockWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    // 时针、分针、秒针位置 - 多边形
    static const QPoint hourHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -30)
    };
    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -65)
    };

    static const QPoint secondHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -80)
    };

    // 时针、分针、秒针颜色
    QColor hourColor(200, 100, 0, 200);
    QColor minuteColor(0, 127, 127, 150);
    QColor secondColor(0, 160, 230, 150);

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    // 平移坐标系原点至中心点
    painter.translate(width() / 2, height() / 2);
    // 缩放
    painter.scale(side / 200.0, side / 200.0);

    // 绘制时针
    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);

    painter.save();
    // 每圈360° = 12h 即：旋转角度 = 小时数 * 30°
    painter.restore();

    painter.setPen(hourColor);

    // 绘制小时线 （360度 / 12 = 30度）
    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    int radius = 100;
    QFont font = painter.font();
    font.setBold(true);
    painter.setFont(font);
    int pointSize = font.pointSize();

    // 绘制小时文本
    int nHour = 0;
    for (int i = 0; i < 11; ++i) {
        nHour = i ;
//        if (nHour > 10)
//            nHour -= 10;
        painter.drawText(textRectF(radius*0.8, pointSize, (i+4) * 30), Qt::AlignCenter, QString::number(nHour));
    }

    // 绘制分针
    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);

    painter.save();
    // 每圈360° = 60m 即：旋转角度 = 分钟数 * 6°
    painter.restore();

    painter.setPen(minuteColor);

    // 绘制分钟线 （360度 / 60 = 6度）
    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }

    // 绘制秒针
    painter.setPen(Qt::NoPen);
    painter.setBrush(secondColor);

    painter.save();
    // 每圈360° = 60s 即：旋转角度 = 秒数 * 6°
    painter.rotate(6.0 * 10);         //input how %
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();
}
