/********************************************************************************
** Form generated from reading UI file 'viewerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWERWINDOW_H
#define UI_VIEWERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewerWindow
{
public:
    QAction *actionAbrir;
    QAction *actionSalir;
    QAction *actionAcerca_de;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ViewerWindow)
    {
        if (ViewerWindow->objectName().isEmpty())
            ViewerWindow->setObjectName(QStringLiteral("ViewerWindow"));
        ViewerWindow->resize(536, 384);
        actionAbrir = new QAction(ViewerWindow);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        actionSalir = new QAction(ViewerWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionAcerca_de = new QAction(ViewerWindow);
        actionAcerca_de->setObjectName(QStringLiteral("actionAcerca_de"));
        centralWidget = new QWidget(ViewerWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setScaledContents(true);

        gridLayout->addWidget(label, 0, 0, 1, 4);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 2, 1, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        ViewerWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ViewerWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 536, 25));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        ViewerWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ViewerWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ViewerWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ViewerWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ViewerWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);
        menuAbout->addAction(actionAcerca_de);

        retranslateUi(ViewerWindow);

        QMetaObject::connectSlotsByName(ViewerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ViewerWindow)
    {
        ViewerWindow->setWindowTitle(QApplication::translate("ViewerWindow", "ViewerWindow", 0));
        actionAbrir->setText(QApplication::translate("ViewerWindow", "Abrir", 0));
        actionSalir->setText(QApplication::translate("ViewerWindow", "Salir", 0));
        actionAcerca_de->setText(QApplication::translate("ViewerWindow", "Acerca de..", 0));
        label->setText(QString());
        pushButton_4->setText(QApplication::translate("ViewerWindow", "Capturar", 0));
        pushButton->setText(QApplication::translate("ViewerWindow", "Salir", 0));
        menuArchivo->setTitle(QApplication::translate("ViewerWindow", "Archivo", 0));
        menuAbout->setTitle(QApplication::translate("ViewerWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewerWindow: public Ui_ViewerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWERWINDOW_H
