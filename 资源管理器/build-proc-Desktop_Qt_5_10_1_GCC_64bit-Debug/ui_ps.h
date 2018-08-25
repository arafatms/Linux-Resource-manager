/********************************************************************************
** Form generated from reading UI file 'ps.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PS_H
#define UI_PS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ps
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *searchlineEdit;
    QPushButton *searchpushButton;
    QPushButton *KillpushButton;
    QPushButton *infopushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ps)
    {
        if (ps->objectName().isEmpty())
            ps->setObjectName(QStringLiteral("ps"));
        ps->resize(550, 458);
        ps->setLayoutDirection(Qt::LeftToRight);
        ps->setAutoFillBackground(false);
        verticalLayoutWidget = new QWidget(ps);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 551, 461));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(verticalLayoutWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        searchlineEdit = new QLineEdit(verticalLayoutWidget);
        searchlineEdit->setObjectName(QStringLiteral("searchlineEdit"));

        horizontalLayout->addWidget(searchlineEdit);

        searchpushButton = new QPushButton(verticalLayoutWidget);
        searchpushButton->setObjectName(QStringLiteral("searchpushButton"));

        horizontalLayout->addWidget(searchpushButton);

        KillpushButton = new QPushButton(verticalLayoutWidget);
        KillpushButton->setObjectName(QStringLiteral("KillpushButton"));

        horizontalLayout->addWidget(KillpushButton);

        infopushButton = new QPushButton(verticalLayoutWidget);
        infopushButton->setObjectName(QStringLiteral("infopushButton"));

        horizontalLayout->addWidget(infopushButton);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ps);

        QMetaObject::connectSlotsByName(ps);
    } // setupUi

    void retranslateUi(QWidget *ps)
    {
        ps->setWindowTitle(QApplication::translate("ps", "Form", nullptr));
        searchpushButton->setText(QApplication::translate("ps", "search", nullptr));
        KillpushButton->setText(QApplication::translate("ps", "Kill", nullptr));
        infopushButton->setText(QApplication::translate("ps", "information", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ps: public Ui_ps {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PS_H
