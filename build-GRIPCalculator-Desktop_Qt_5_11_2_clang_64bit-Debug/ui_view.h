/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QSlider *horizontalSlider;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QSlider *horizontalSlider_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QSlider *horizontalSlider_3;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_7;
    QSlider *horizontalSlider_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName(QStringLiteral("View"));
        View->resize(1063, 954);
        View->setWindowTitle(QStringLiteral("GRIP Calculator"));
        centralWidget = new QWidget(View);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 10, 816, 636));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(500, 500));
        graphicsView->setBaseSize(QSize(500, 500));

        verticalLayout->addWidget(graphicsView);

        tableView = new QTableView(widget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setMinimumSize(QSize(0, 80));
        tableView->setMaximumSize(QSize(16777215, 122));

        verticalLayout->addWidget(tableView);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(250, 0));

        verticalLayout_2->addWidget(comboBox);


        verticalLayout_9->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(250, 0));

        verticalLayout_3->addWidget(comboBox_2);


        verticalLayout_9->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_4->addWidget(label_3);

        comboBox_3 = new QComboBox(widget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setMinimumSize(QSize(250, 0));

        verticalLayout_4->addWidget(comboBox_3);


        verticalLayout_9->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_5->addWidget(label_4);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(300, 0));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider);


        verticalLayout_9->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_6->addWidget(label_5);

        horizontalSlider_2 = new QSlider(widget);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMinimumSize(QSize(300, 0));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(horizontalSlider_2);


        verticalLayout_9->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_7->addWidget(label_6);

        horizontalSlider_3 = new QSlider(widget);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setMinimumSize(QSize(300, 0));
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout_7->addWidget(horizontalSlider_3);


        verticalLayout_9->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_8->addWidget(label_7);

        horizontalSlider_4 = new QSlider(widget);
        horizontalSlider_4->setObjectName(QStringLiteral("horizontalSlider_4"));
        horizontalSlider_4->setMinimumSize(QSize(300, 0));
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        verticalLayout_8->addWidget(horizontalSlider_4);


        verticalLayout_9->addLayout(verticalLayout_8);


        horizontalLayout->addLayout(verticalLayout_9);

        View->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(View);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1063, 22));
        View->setMenuBar(menuBar);
        mainToolBar = new QToolBar(View);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        View->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(View);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        View->setStatusBar(statusBar);

        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        label->setText(QApplication::translate("View", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("View", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("View", "TextLabel", nullptr));
        label_4->setText(QApplication::translate("View", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("View", "TextLabel", nullptr));
        label_6->setText(QApplication::translate("View", "TextLabel", nullptr));
        label_7->setText(QApplication::translate("View", "TextLabel", nullptr));
        Q_UNUSED(View);
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
