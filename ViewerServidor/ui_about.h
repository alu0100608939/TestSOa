/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->setEnabled(true);
        About->resize(400, 300);
        About->setSizeGripEnabled(false);
        About->setModal(false);
        gridLayout = new QGridLayout(About);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(About);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 2);

        pushButton = new QPushButton(About);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 2, 1, 1);

        label_2 = new QLabel(About);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);


        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About", 0));
#ifndef QT_NO_TOOLTIP
        About->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        About->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        label->setText(QApplication::translate("About", "<html><head/><body><p><span style=\" font-weight:600;\">Angel Fumero Revetti</span></p><p><br/></p><p><br/></p><p><br/></p><p><span style=\" font-style:italic;\">Esta aplicaci\303\263n tiene un poquito de m\303\255 </span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("About", "Ok", 0));
        label_2->setText(QApplication::translate("About", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
