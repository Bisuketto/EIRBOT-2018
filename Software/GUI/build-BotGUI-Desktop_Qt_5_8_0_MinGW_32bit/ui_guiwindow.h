/********************************************************************************
** Form generated from reading UI file 'guiwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIWINDOW_H
#define UI_GUIWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIWindow
{
public:
    QAction *actionBlup;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *mapView;
    QListView *listView;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *button_connect;
    QSpacerItem *verticalSpacer;
    QTextEdit *console;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QMenu *menuPort_COM;

    void setupUi(QMainWindow *GUIWindow)
    {
        if (GUIWindow->objectName().isEmpty())
            GUIWindow->setObjectName(QStringLiteral("GUIWindow"));
        GUIWindow->resize(981, 518);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GUIWindow->sizePolicy().hasHeightForWidth());
        GUIWindow->setSizePolicy(sizePolicy);
        GUIWindow->setMinimumSize(QSize(981, 518));
        GUIWindow->setMaximumSize(QSize(981, 518));
        actionBlup = new QAction(GUIWindow);
        actionBlup->setObjectName(QStringLiteral("actionBlup"));
        centralWidget = new QWidget(GUIWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 10, 961, 461));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        mapView = new QGraphicsView(horizontalLayoutWidget);
        mapView->setObjectName(QStringLiteral("mapView"));
        mapView->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mapView->sizePolicy().hasHeightForWidth());
        mapView->setSizePolicy(sizePolicy1);
        mapView->setMinimumSize(QSize(300, 300));
        mapView->setBaseSize(QSize(0, 0));

        verticalLayout_2->addWidget(mapView);

        listView = new QListView(horizontalLayoutWidget);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout_2->addWidget(listView);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        button_connect = new QPushButton(horizontalLayoutWidget);
        button_connect->setObjectName(QStringLiteral("button_connect"));
        button_connect->setMinimumSize(QSize(150, 0));
        button_connect->setCheckable(true);

        verticalLayout->addWidget(button_connect);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        console = new QTextEdit(horizontalLayoutWidget);
        console->setObjectName(QStringLiteral("console"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(console->sizePolicy().hasHeightForWidth());
        console->setSizePolicy(sizePolicy2);
        console->setBaseSize(QSize(0, 0));

        verticalLayout->addWidget(console);


        horizontalLayout->addLayout(verticalLayout);

        GUIWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GUIWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GUIWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(GUIWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 981, 20));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuPort_COM = new QMenu(menuOptions);
        menuPort_COM->setObjectName(QStringLiteral("menuPort_COM"));
        GUIWindow->setMenuBar(menuBar);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(menuPort_COM->menuAction());

        retranslateUi(GUIWindow);

        QMetaObject::connectSlotsByName(GUIWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GUIWindow)
    {
        GUIWindow->setWindowTitle(QApplication::translate("GUIWindow", "GUIBot", Q_NULLPTR));
        actionBlup->setText(QApplication::translate("GUIWindow", "Blup", Q_NULLPTR));
        button_connect->setText(QApplication::translate("GUIWindow", "Connect", Q_NULLPTR));
        menuOptions->setTitle(QApplication::translate("GUIWindow", "Options", Q_NULLPTR));
        menuPort_COM->setTitle(QApplication::translate("GUIWindow", "Port COM", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GUIWindow: public Ui_GUIWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIWINDOW_H
