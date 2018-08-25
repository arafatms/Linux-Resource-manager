/********************************************************************************
** Form generated from reading UI file 'read.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READ_H
#define UI_READ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Read
{
public:

    void setupUi(QWidget *Read)
    {
        if (Read->objectName().isEmpty())
            Read->setObjectName(QStringLiteral("Read"));
        Read->resize(400, 300);

        retranslateUi(Read);

        QMetaObject::connectSlotsByName(Read);
    } // setupUi

    void retranslateUi(QWidget *Read)
    {
        Read->setWindowTitle(QApplication::translate("Read", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Read: public Ui_Read {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READ_H
