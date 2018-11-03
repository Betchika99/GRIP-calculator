/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *frame_control;
    QSlider *slider_focallen;
    QSlider *slider_distance;
    QDoubleSpinBox *spin_distance;
    QLabel *label_background;
    QLabel *label_crop;
    QLabel *label_focallen;
    QLabel *label_aperture;
    QSlider *slider_aperture;
    QComboBox *combo_model;
    QDoubleSpinBox *spin_crop;
    QDoubleSpinBox *spin_focallen;
    QLabel *label_model;
    QComboBox *combo_sensor;
    QLabel *label_sensor;
    QLabel *label_distance;
    QComboBox *combo_background;
    QComboBox *combo_aperture;
    QTableWidget *table_dof;
    QLabel *image;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(686, 434);
        MainWindow->setMinimumSize(QSize(686, 434));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(10);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame_control = new QFrame(centralWidget);
        frame_control->setObjectName(QStringLiteral("frame_control"));
        frame_control->setMinimumSize(QSize(242, 0));
        frame_control->setMaximumSize(QSize(242, 16777215));
        frame_control->setFrameShape(QFrame::StyledPanel);
        frame_control->setFrameShadow(QFrame::Plain);
        slider_focallen = new QSlider(frame_control);
        slider_focallen->setObjectName(QStringLiteral("slider_focallen"));
        slider_focallen->setGeometry(QRect(10, 238, 140, 19));
        slider_focallen->setMinimum(1);
        slider_focallen->setMaximum(1000);
        slider_focallen->setSingleStep(10);
        slider_focallen->setPageStep(100);
        slider_focallen->setOrientation(Qt::Horizontal);
        slider_distance = new QSlider(frame_control);
        slider_distance->setObjectName(QStringLiteral("slider_distance"));
        slider_distance->setGeometry(QRect(10, 188, 140, 19));
        slider_distance->setMinimum(1);
        slider_distance->setMaximum(100);
        slider_distance->setOrientation(Qt::Horizontal);
        slider_distance->setTickPosition(QSlider::NoTicks);
        spin_distance = new QDoubleSpinBox(frame_control);
        spin_distance->setObjectName(QStringLiteral("spin_distance"));
        spin_distance->setGeometry(QRect(160, 178, 70, 22));
        spin_distance->setDecimals(1);
        spin_distance->setMinimum(1);
        spin_distance->setMaximum(100);
        label_background = new QLabel(frame_control);
        label_background->setObjectName(QStringLiteral("label_background"));
        label_background->setGeometry(QRect(10, 8, 71, 16));
        label_crop = new QLabel(frame_control);
        label_crop->setObjectName(QStringLiteral("label_crop"));
        label_crop->setGeometry(QRect(161, 110, 70, 13));
        label_focallen = new QLabel(frame_control);
        label_focallen->setObjectName(QStringLiteral("label_focallen"));
        label_focallen->setGeometry(QRect(10, 218, 141, 16));
        label_aperture = new QLabel(frame_control);
        label_aperture->setObjectName(QStringLiteral("label_aperture"));
        label_aperture->setGeometry(QRect(10, 268, 141, 16));
        slider_aperture = new QSlider(frame_control);
        slider_aperture->setObjectName(QStringLiteral("slider_aperture"));
        slider_aperture->setGeometry(QRect(10, 288, 140, 19));
        slider_aperture->setMinimum(0);
        slider_aperture->setMaximum(10);
        slider_aperture->setOrientation(Qt::Horizontal);
        combo_model = new QComboBox(frame_control);
        combo_model->setObjectName(QStringLiteral("combo_model"));
        combo_model->setGeometry(QRect(10, 78, 220, 22));
        spin_crop = new QDoubleSpinBox(frame_control);
        spin_crop->setObjectName(QStringLiteral("spin_crop"));
        spin_crop->setGeometry(QRect(160, 128, 70, 22));
        spin_crop->setMinimum(0.1);
        spin_crop->setSingleStep(0.1);
        spin_focallen = new QDoubleSpinBox(frame_control);
        spin_focallen->setObjectName(QStringLiteral("spin_focallen"));
        spin_focallen->setGeometry(QRect(160, 228, 70, 22));
        spin_focallen->setDecimals(1);
        spin_focallen->setMinimum(1);
        spin_focallen->setMaximum(1000);
        label_model = new QLabel(frame_control);
        label_model->setObjectName(QStringLiteral("label_model"));
        label_model->setGeometry(QRect(10, 58, 71, 16));
        combo_sensor = new QComboBox(frame_control);
        combo_sensor->setObjectName(QStringLiteral("combo_sensor"));
        combo_sensor->setGeometry(QRect(10, 128, 140, 22));
        label_sensor = new QLabel(frame_control);
        label_sensor->setObjectName(QStringLiteral("label_sensor"));
        label_sensor->setGeometry(QRect(10, 108, 71, 16));
        label_distance = new QLabel(frame_control);
        label_distance->setObjectName(QStringLiteral("label_distance"));
        label_distance->setGeometry(QRect(10, 168, 141, 16));
        combo_background = new QComboBox(frame_control);
        combo_background->setObjectName(QStringLiteral("combo_background"));
        combo_background->setGeometry(QRect(10, 28, 220, 22));
        combo_aperture = new QComboBox(frame_control);
        combo_aperture->setObjectName(QStringLiteral("combo_aperture"));
        combo_aperture->setGeometry(QRect(160, 280, 70, 22));

        gridLayout->addWidget(frame_control, 0, 1, 1, 1);

        table_dof = new QTableWidget(centralWidget);
        if (table_dof->columnCount() < 1)
            table_dof->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_dof->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (table_dof->rowCount() < 4)
            table_dof->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_dof->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_dof->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_dof->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_dof->setVerticalHeaderItem(3, __qtablewidgetitem4);
        table_dof->setObjectName(QStringLiteral("table_dof"));
        table_dof->setMinimumSize(QSize(242, 85));
        table_dof->setMaximumSize(QSize(242, 85));
        table_dof->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table_dof->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table_dof->setAutoScroll(false);
        table_dof->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_dof->setSelectionMode(QAbstractItemView::NoSelection);
        table_dof->horizontalHeader()->setVisible(false);
        table_dof->horizontalHeader()->setStretchLastSection(true);
        table_dof->verticalHeader()->setDefaultSectionSize(21);
        table_dof->verticalHeader()->setHighlightSections(false);
        table_dof->verticalHeader()->setMinimumSectionSize(21);
        table_dof->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(table_dof, 1, 1, 1, 1);

        image = new QLabel(centralWidget);
        image->setObjectName(QStringLiteral("image"));
        image->setFrameShape(QFrame::StyledPanel);
        image->setScaledContents(false);
        image->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(image, 0, 0, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(combo_background, combo_model);
        QWidget::setTabOrder(combo_model, combo_sensor);
        QWidget::setTabOrder(combo_sensor, spin_crop);
        QWidget::setTabOrder(spin_crop, slider_distance);
        QWidget::setTabOrder(slider_distance, spin_distance);
        QWidget::setTabOrder(spin_distance, slider_focallen);
        QWidget::setTabOrder(slider_focallen, spin_focallen);
        QWidget::setTabOrder(spin_focallen, slider_aperture);
        QWidget::setTabOrder(slider_aperture, combo_aperture);
        QWidget::setTabOrder(combo_aperture, table_dof);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DOF Calculator", nullptr));
        spin_distance->setSuffix(QApplication::translate("MainWindow", " \320\274", nullptr));
        label_background->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\275\320\270\320\271 \320\277\320\273\320\260\320\275", nullptr));
        label_crop->setText(QApplication::translate("MainWindow", "\320\232\321\200\320\276\320\277-\321\204\320\260\320\272\321\202\320\276\321\200", nullptr));
        label_focallen->setText(QApplication::translate("MainWindow", "\320\244\320\276\320\272\321\203\321\201\320\275\320\276\320\265 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265", nullptr));
        label_aperture->setText(QApplication::translate("MainWindow", "\320\224\320\270\320\260\321\204\321\200\320\260\320\263\320\274\320\260\320\263\320\274\320\265\320\275\320\275\320\276\320\265 \321\207\320\270\321\201\320\273\320\276", nullptr));
        spin_focallen->setSuffix(QApplication::translate("MainWindow", " \320\274\320\274", nullptr));
        label_model->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        label_sensor->setText(QApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\272\320\260\320\264\321\200\320\260", nullptr));
        label_distance->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\264\320\276 \320\274\320\276\320\264\320\265\320\273\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_dof->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_dof->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\223\320\273\321\203\320\261\320\270\320\275\320\260 \321\200\320\265\320\267\320\272\320\276\321\201\321\202\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_dof->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\264\320\275\320\270\320\271 \321\204\321\200\320\276\320\275\321\202 \320\223\320\240\320\230\320\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_dof->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\275\320\270\320\271 \321\204\321\200\320\276\320\275\321\202 \320\223\320\240\320\230\320\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_dof->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\223\320\270\320\277\320\265\321\200\321\204\320\276\320\272\320\260\320\273\321\214\320\275\320\276\320\265 \321\200\320\260\321\201\321\201\321\202", nullptr));
        image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
