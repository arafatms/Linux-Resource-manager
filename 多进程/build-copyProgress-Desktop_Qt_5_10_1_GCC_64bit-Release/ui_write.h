/********************************************************************************
** Form generated from reading UI file 'write.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRITE_H
#define UI_WRITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Write
{
public:

    void setupUi(QWidget *Write)
    {
        if (Write->objectName().isEmpty())
            Write->setObjectName(QStringLiteral("Write"));
        Write->resize(400, 300);

        retranslateUi(Write);

        QMetaObject::connectSlotsByName(Write);
    } // setupUi

    void retranslateUi(QWidget *Write)
    {
        Write->setWindowTitle(QApplication::translate("Write", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Write: public Ui_Write {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRITE_H
