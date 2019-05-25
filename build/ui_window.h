/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen;
    QAction *actionstart;
    QAction *actionsave;
    QAction *actionradius;
    QAction *actionstop;
    QAction *actionreset;
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QwtPlot *qwtPlot;
    QLabel *label_4;
    QwtPlot *qwtPlot_2;
    QLabel *label_5;
    QwtPlot *qwtPlot_3;
    QMenuBar *menubar;
    QMenu *menuopen;
    QMenu *menuoption;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 750);
        MainWindow->setMaximumSize(QSize(1200, 800));
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        actionstart = new QAction(MainWindow);
        actionstart->setObjectName(QStringLiteral("actionstart"));
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        actionradius = new QAction(MainWindow);
        actionradius->setObjectName(QStringLiteral("actionradius"));
        actionstop = new QAction(MainWindow);
        actionstop->setObjectName(QStringLiteral("actionstop"));
        actionreset = new QAction(MainWindow);
        actionreset->setObjectName(QStringLiteral("actionreset"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setMaximumSize(QSize(16777215, 700));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, 12, -1, -1);
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 460, 302));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        scrollArea_2 = new QScrollArea(groupBox);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 460, 302));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout->addWidget(scrollArea_2, 2, 0, 1, 1);

        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, 12, -1, -1);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setPointSize(14);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_3, 0, 0, 1, 2);

        qwtPlot = new QwtPlot(groupBox_2);
        qwtPlot->setObjectName(QStringLiteral("qwtPlot"));
        QBrush brush(QColor(239, 235, 231, 255));
        brush.setStyle(Qt::SolidPattern);
        qwtPlot->setCanvasBackground(brush);

        gridLayout_4->addWidget(qwtPlot, 0, 2, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_4, 1, 0, 1, 2);

        qwtPlot_2 = new QwtPlot(groupBox_2);
        qwtPlot_2->setObjectName(QStringLiteral("qwtPlot_2"));

        gridLayout_4->addWidget(qwtPlot_2, 1, 2, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_5, 2, 0, 1, 1);

        qwtPlot_3 = new QwtPlot(groupBox_2);
        qwtPlot_3->setObjectName(QStringLiteral("qwtPlot_3"));

        gridLayout_4->addWidget(qwtPlot_3, 2, 1, 1, 2);


        gridLayout_5->addWidget(groupBox_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 28));
        menuopen = new QMenu(menubar);
        menuopen->setObjectName(QStringLiteral("menuopen"));
        menuoption = new QMenu(menubar);
        menuoption->setObjectName(QStringLiteral("menuoption"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuopen->menuAction());
        menubar->addAction(menuoption->menuAction());
        menuopen->addAction(actionopen);
        menuopen->addAction(actionsave);
        menuoption->addAction(actionstart);
        menuoption->addAction(actionstop);
        menuoption->addAction(actionreset);
        menuoption->addAction(actionradius);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionopen->setText(QApplication::translate("MainWindow", "open", Q_NULLPTR));
        actionstart->setText(QApplication::translate("MainWindow", "start", Q_NULLPTR));
        actionsave->setText(QApplication::translate("MainWindow", "save", Q_NULLPTR));
        actionradius->setText(QApplication::translate("MainWindow", "radius", Q_NULLPTR));
        actionstop->setText(QApplication::translate("MainWindow", "stop", Q_NULLPTR));
        actionreset->setText(QApplication::translate("MainWindow", "reset", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Video", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "-: video :-", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "-: video :-", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "parameters", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "x", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "y", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "a", Q_NULLPTR));
        menuopen->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuoption->setTitle(QApplication::translate("MainWindow", "Setting", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
