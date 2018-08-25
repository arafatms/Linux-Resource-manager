/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Graph
{
public:
    QCustomPlot *Memwidget;
    QLabel *label_6;
    QCustomPlot *widget;
    QLabel *label;
    QPushButton *RePaintButton;
    QLabel *label_2;
    QCustomPlot *Swapwidget;

    void setupUi(QWidget *Graph)
    {
        if (Graph->objectName().isEmpty())
            Graph->setObjectName(QStringLiteral("Graph"));
        Graph->resize(680, 555);
        Memwidget = new QCustomPlot(Graph);
        Memwidget->setObjectName(QStringLiteral("Memwidget"));
        Memwidget->setGeometry(QRect(30, 200, 600, 140));
        label_6 = new QLabel(Graph);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(310, 0, 69, 31));
        widget = new QCustomPlot(Graph);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 30, 600, 140));
        label = new QLabel(Graph);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 180, 81, 20));
        RePaintButton = new QPushButton(Graph);
        RePaintButton->setObjectName(QStringLiteral("RePaintButton"));
        RePaintButton->setGeometry(QRect(570, 520, 89, 25));
        label_2 = new QLabel(Graph);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 350, 80, 21));
        Swapwidget = new QCustomPlot(Graph);
        Swapwidget->setObjectName(QStringLiteral("Swapwidget"));
        Swapwidget->setGeometry(QRect(30, 370, 600, 140));

        retranslateUi(Graph);

        QMetaObject::connectSlotsByName(Graph);
    } // setupUi

    void retranslateUi(QWidget *Graph)
    {
        Graph->setWindowTitle(QApplication::translate("Graph", "Form", nullptr));
        label_6->setText(QApplication::translate("Graph", "cpu Graph", nullptr));
        label->setText(QApplication::translate("Graph", "Mem Graph", nullptr));
        RePaintButton->setText(QApplication::translate("Graph", "RePaint", nullptr));
        label_2->setText(QApplication::translate("Graph", "swap Graph", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graph: public Ui_Graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
