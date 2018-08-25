/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actioninfo;
    QAction *actioncpu;
    QAction *action_Graph;
    QAction *NewProgressaction;
    QAction *PowerOffaction;
    QAction *actionshow_ps;
    QWidget *centralWidget;
    QFrame *procframe;
    QFrame *stateframe;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *hostnamelabel;
    QLabel *activateTimelabel;
    QLabel *RunTimelabel;
    QLabel *CurrentTimelabel;
    QLabel *label;
    QLabel *Label2;
    QLabel *cpuphereLabel;
    QLabel *memphereLabel;
    QLabel *Oslabel;
    QMenuBar *menuBar;
    QMenu *menuproc;
    QMenu *menucpu;
    QMenu *menuswap;
    QMenu *menuother;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(937, 649);
        actioninfo = new QAction(MainWindow);
        actioninfo->setObjectName(QStringLiteral("actioninfo"));
        actioncpu = new QAction(MainWindow);
        actioncpu->setObjectName(QStringLiteral("actioncpu"));
        action_Graph = new QAction(MainWindow);
        action_Graph->setObjectName(QStringLiteral("action_Graph"));
        NewProgressaction = new QAction(MainWindow);
        NewProgressaction->setObjectName(QStringLiteral("NewProgressaction"));
        PowerOffaction = new QAction(MainWindow);
        PowerOffaction->setObjectName(QStringLiteral("PowerOffaction"));
        actionshow_ps = new QAction(MainWindow);
        actionshow_ps->setObjectName(QStringLiteral("actionshow_ps"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        procframe = new QFrame(centralWidget);
        procframe->setObjectName(QStringLiteral("procframe"));
        procframe->setGeometry(QRect(10, 0, 680, 561));
        procframe->setFrameShape(QFrame::StyledPanel);
        procframe->setFrameShadow(QFrame::Raised);
        stateframe = new QFrame(centralWidget);
        stateframe->setObjectName(QStringLiteral("stateframe"));
        stateframe->setGeometry(QRect(700, 0, 231, 561));
        stateframe->setFrameShape(QFrame::StyledPanel);
        stateframe->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(stateframe);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 430, 211, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        hostnamelabel = new QLabel(verticalLayoutWidget);
        hostnamelabel->setObjectName(QStringLiteral("hostnamelabel"));

        verticalLayout->addWidget(hostnamelabel);

        activateTimelabel = new QLabel(verticalLayoutWidget);
        activateTimelabel->setObjectName(QStringLiteral("activateTimelabel"));

        verticalLayout->addWidget(activateTimelabel);

        RunTimelabel = new QLabel(verticalLayoutWidget);
        RunTimelabel->setObjectName(QStringLiteral("RunTimelabel"));

        verticalLayout->addWidget(RunTimelabel);

        CurrentTimelabel = new QLabel(verticalLayoutWidget);
        CurrentTimelabel->setObjectName(QStringLiteral("CurrentTimelabel"));

        verticalLayout->addWidget(CurrentTimelabel);

        label = new QLabel(stateframe);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 10, 41, 17));
        Label2 = new QLabel(stateframe);
        Label2->setObjectName(QStringLiteral("Label2"));
        Label2->setGeometry(QRect(100, 230, 41, 17));
        cpuphereLabel = new QLabel(stateframe);
        cpuphereLabel->setObjectName(QStringLiteral("cpuphereLabel"));
        cpuphereLabel->setGeometry(QRect(80, 130, 67, 17));
        memphereLabel = new QLabel(stateframe);
        memphereLabel->setObjectName(QStringLiteral("memphereLabel"));
        memphereLabel->setGeometry(QRect(80, 350, 67, 17));
        Oslabel = new QLabel(centralWidget);
        Oslabel->setObjectName(QStringLiteral("Oslabel"));
        Oslabel->setGeometry(QRect(20, 570, 341, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 937, 22));
        menuproc = new QMenu(menuBar);
        menuproc->setObjectName(QStringLiteral("menuproc"));
        menucpu = new QMenu(menuBar);
        menucpu->setObjectName(QStringLiteral("menucpu"));
        menuswap = new QMenu(menuBar);
        menuswap->setObjectName(QStringLiteral("menuswap"));
        menuother = new QMenu(menuBar);
        menuother->setObjectName(QStringLiteral("menuother"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuproc->menuAction());
        menuBar->addAction(menucpu->menuAction());
        menuBar->addAction(menuswap->menuAction());
        menuBar->addAction(menuother->menuAction());
        menuproc->addAction(actionshow_ps);
        menucpu->addAction(actioninfo);
        menuswap->addAction(action_Graph);
        menuother->addAction(NewProgressaction);
        menuother->addAction(PowerOffaction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actioninfo->setText(QApplication::translate("MainWindow", "info", nullptr));
        actioncpu->setText(QApplication::translate("MainWindow", "cpu\344\275\277\347\224\250\347\216\207\347\232\204\345\233\276\345\275\242\345\214\226\346\230\276\347\244\272", nullptr));
        action_Graph->setText(QApplication::translate("MainWindow", "\344\275\277\347\224\250\347\216\207\347\232\204\345\233\276\345\275\242\345\214\226\346\230\276\347\244\272", nullptr));
        NewProgressaction->setText(QApplication::translate("MainWindow", "\347\224\250\346\226\260\350\277\233\347\250\213\350\277\220\350\241\214\344\270\200\344\270\252\345\205\266\344\273\226\347\250\213\345\272\217", nullptr));
        PowerOffaction->setText(QApplication::translate("MainWindow", "\345\205\263\346\234\272\345\212\237\350\203\275", nullptr));
        actionshow_ps->setText(QApplication::translate("MainWindow", "show ps", nullptr));
        hostnamelabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        activateTimelabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        RunTimelabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        CurrentTimelabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QApplication::translate("MainWindow", "CPU", nullptr));
        Label2->setText(QApplication::translate("MainWindow", "MEM", nullptr));
        cpuphereLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        memphereLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        Oslabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        menuproc->setTitle(QApplication::translate("MainWindow", "proc", nullptr));
        menucpu->setTitle(QApplication::translate("MainWindow", "cpu", nullptr));
        menuswap->setTitle(QApplication::translate("MainWindow", "Graph", nullptr));
        menuother->setTitle(QApplication::translate("MainWindow", "other", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
