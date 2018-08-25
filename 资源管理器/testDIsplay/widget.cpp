#include "widget.h"

#define LOOPCOUNT 8
DashboardProcess::DashboardProcess(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint)
    ,bPressFlag(false)
    , currentValue(0)
    , gap(0)
    , gapCount(LOOPCOUNT)
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    resize(159, 159);
    setAutoFillBackground(false);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0xFF,0xFF,0xFF,0xFF));
    setPalette(pal);
    pointPix.load(":/dashboard_pointer_bg.png");

    currentValueLabel = new QLabel(tr("0%"), this);
    currentValueLabel->setFont(QFont("Arial", 10, QFont::Normal));
    currentValueLabel->setAlignment(Qt::AlignCenter);
    currentValueLabel->setStyleSheet("color:#19649f");

    updateTimer = new QTimer(this);
    updateTimer->setInterval(8);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(slotUpdateTimer()));

    gapTimer = new QTimer(this);
    gapTimer->setInterval(10);
    connect(gapTimer, SIGNAL(timeout()), this, SLOT(slotGapTimer()));
}

DashboardProcess::~DashboardProcess()
{
    if (updateTimer->isActive()) {
        updateTimer->stop();
    }
    if (gapTimer->isActive()) {
        gapTimer->stop();
    }
}

void DashboardProcess::setUsedValue(int value)
{
    userdVaule = value;
}

void DashboardProcess::showEvent(QShowEvent *event)
{
    if (userdVaule > 0) {
        updateTimer->start();
    }
    gap = 0;
    gapCount = LOOPCOUNT;
    currentValue = 0;
}

void DashboardProcess::hideEvent(QHideEvent *event)
{
    if (updateTimer->isActive()) {
        updateTimer->stop();
    }
    if (gapTimer->isActive()) {
        gapTimer->stop();
    }
    currentValue = 0;
    gap = 0;
    gapCount = LOOPCOUNT;
}

void DashboardProcess::slotUpdateTimer()
{
    if (currentValue >= userdVaule) {
        currentValue = userdVaule;
        updateTimer->stop();
        --gapCount;
        gap = gapCount*4;
        gapTimer->start();
    }
    else {
        ++currentValue;
    }
    if (currentValue >= 0) {
        currentValueLabel->setText(QString("%1%").arg(currentValue));
    }
    update();
}

void DashboardProcess::slotGapTimer()
{
    if (gap < 0) {
        gapTimer->stop();
        --gapCount;
        if (gapCount > 0) {
            gapTimer->start();
            gap = gapCount * 4;
        }
        return;
    }
    --gap;
    update();
}

void DashboardProcess::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QColor usedColor(165, 220, 62);
    QColor freeColor(215, 215, 215);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    painter.save();
    painter.translate(width() / 2, height() / 2);
    painter.rotate(42);
    painter.setPen(QPen(usedColor, 2));
    for (int i = 0; i < currentValue ; ++i) {
        painter.drawLine(0, 60, 0, 70);
        painter.rotate(2.8);
    }
    painter.setPen(QPen(freeColor, 2));
    for (int i = currentValue; i < 100 ; ++i) {
        painter.drawLine(0, 60, 0, 70);
        painter.rotate(2.8);
    }
    painter.restore();

    painter.save();
    painter.translate(width() / 2, height() / 2);
    painter.rotate(-2);
    if (gapCount < LOOPCOUNT && gapCount >= 0) {
        if (gap >= gapCount * 3) {
            painter.rotate((qreal)(360 - 42 * 2)/100 * currentValue - 2 + gapCount * 4 - gap);
        }
        else if (gap >= gapCount * 2) {
            painter.rotate((qreal)(360 - 42 * 2)/100 * currentValue - 2 + gap - gapCount *2);
        }
        else if (gap >= gapCount) {
            painter.rotate((qreal)(360 - 42 * 2)/100 * currentValue - 2 - (gapCount *2 - gap));
        }
        else {
            painter.rotate((qreal)(360 - 42 * 2)/100 * currentValue - 2 - gap);
        }
    }
    else {
        if (currentValue >= 0) {
            painter.rotate((qreal)(360 - 42 * 2)/100 * currentValue - 2);
        }
    }
    painter.drawPixmap(QRect((- pointPix.width())/2 , (- pointPix.height())/2, pointPix.width(), pointPix.height()) , pointPix);
    painter.restore();
}

void DashboardProcess::resizeEvent(QResizeEvent *event)
{
    currentValueLabel->setGeometry(0, 122, width(), 20);
    move((QApplication::desktop()->width() - width())/2,  (QApplication::desktop()->height() - height())/2);
    QWidget::resizeEvent(event);
}

/****************move everywhere*******************/
void DashboardProcess::mousePressEvent(QMouseEvent *event)
{
    bPressFlag = true;
    beginDrag = event->pos();
    QWidget::mousePressEvent(event);
}

void DashboardProcess::mouseMoveEvent(QMouseEvent *event)
{
    if (bPressFlag) {
        QPoint relaPos(QCursor::pos() - beginDrag);
        move(relaPos);
    }
    QWidget::mouseMoveEvent(event);
}

void DashboardProcess::mouseReleaseEvent(QMouseEvent *event)
{
    bPressFlag = false;
    QWidget::mouseReleaseEvent(event);
}
