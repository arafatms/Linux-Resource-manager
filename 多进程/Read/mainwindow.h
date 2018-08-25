#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int create();
    QTimer *timer;

private:
    Ui::MainWindow *ui;
private slots:
    void update();
};

#endif // MAINWINDOW_H
