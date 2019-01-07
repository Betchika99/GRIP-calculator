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
#include <QtWidgets/QPushButton>
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
    QSlider *slider_focal_length;
    QSlider *slider_model_distance;
    QDoubleSpinBox *spin_model_distance;
    QLabel *label_background;
    QLabel *label_crop_factor;
    QLabel *label_focal_length;
    QLabel *label_diaphragm;
    QSlider *slider_diaphragm;
    QComboBox *combo_model;
    QDoubleSpinBox *spin_crop;
    QDoubleSpinBox *spin_focal_length;
    QLabel *label_model;
    QComboBox *combo_crop;
    QLabel *label_crop;
    QLabel *label_model_distance;
    QComboBox *combo_background;
    QSlider *slider_background_distance;
    QDoubleSpinBox *spin_backgrond_distance;
    QLabel *label_background_distance;
    QDoubleSpinBox *spin_diaphragm;
    QLabel *diaphragm_letter;
    QComboBox *combo_strategy;
    QLabel *label_strategy;
    QFrame *frame_favorite;
    QLabel *label_favorite;
    QComboBox *combo_favorite;
    QPushButton *button_save;
    QPushButton *button_delete;
    QLabel *image;
    QTableWidget *table_dof;
    QFrame *frame_logon;
    QPushButton *button_login;
    QPushButton *button_register;
    QLabel *label_welcome;
    QPushButton *button_logout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1149, 655);
        MainWindow->setMinimumSize(QSize(888, 655));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(10);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame_control = new QFrame(centralWidget);
        frame_control->setObjectName(QStringLiteral("frame_control"));
        frame_control->setMinimumSize(QSize(240, 422));
        frame_control->setMaximumSize(QSize(240, 16777215));
        frame_control->setFrameShape(QFrame::StyledPanel);
        frame_control->setFrameShadow(QFrame::Plain);
        slider_focal_length = new QSlider(frame_control);
        slider_focal_length->setObjectName(QStringLiteral("slider_focal_length"));
        slider_focal_length->setGeometry(QRect(10, 338, 140, 19));
        slider_focal_length->setLayoutDirection(Qt::LeftToRight);
        slider_focal_length->setMinimum(1);
        slider_focal_length->setMaximum(1000);
        slider_focal_length->setSingleStep(10);
        slider_focal_length->setPageStep(100);
        slider_focal_length->setOrientation(Qt::Horizontal);
        slider_focal_length->setInvertedAppearance(false);
        slider_focal_length->setInvertedControls(false);
        slider_focal_length->setTickPosition(QSlider::NoTicks);
        slider_focal_length->setTickInterval(70);
        slider_model_distance = new QSlider(frame_control);
        slider_model_distance->setObjectName(QStringLiteral("slider_model_distance"));
        slider_model_distance->setGeometry(QRect(10, 238, 140, 19));
        slider_model_distance->setMinimum(1);
        slider_model_distance->setMaximum(50);
        slider_model_distance->setOrientation(Qt::Horizontal);
        slider_model_distance->setTickPosition(QSlider::NoTicks);
        spin_model_distance = new QDoubleSpinBox(frame_control);
        spin_model_distance->setObjectName(QStringLiteral("spin_model_distance"));
        spin_model_distance->setGeometry(QRect(160, 238, 70, 22));
        spin_model_distance->setDecimals(1);
        spin_model_distance->setMinimum(1);
        spin_model_distance->setMaximum(50);
        spin_model_distance->setSingleStep(0.5);
        label_background = new QLabel(frame_control);
        label_background->setObjectName(QStringLiteral("label_background"));
        label_background->setGeometry(QRect(10, 58, 81, 16));
        label_crop_factor = new QLabel(frame_control);
        label_crop_factor->setObjectName(QStringLiteral("label_crop_factor"));
        label_crop_factor->setGeometry(QRect(161, 160, 70, 13));
        label_focal_length = new QLabel(frame_control);
        label_focal_length->setObjectName(QStringLiteral("label_focal_length"));
        label_focal_length->setGeometry(QRect(10, 318, 241, 16));
        label_diaphragm = new QLabel(frame_control);
        label_diaphragm->setObjectName(QStringLiteral("label_diaphragm"));
        label_diaphragm->setGeometry(QRect(10, 368, 171, 16));
        slider_diaphragm = new QSlider(frame_control);
        slider_diaphragm->setObjectName(QStringLiteral("slider_diaphragm"));
        slider_diaphragm->setGeometry(QRect(10, 388, 140, 19));
        slider_diaphragm->setToolTipDuration(-1);
        slider_diaphragm->setMinimum(0);
        slider_diaphragm->setMaximum(32);
        slider_diaphragm->setPageStep(0);
        slider_diaphragm->setValue(1);
        slider_diaphragm->setOrientation(Qt::Horizontal);
        slider_diaphragm->setTickPosition(QSlider::NoTicks);
        combo_model = new QComboBox(frame_control);
        combo_model->setObjectName(QStringLiteral("combo_model"));
        combo_model->setGeometry(QRect(10, 128, 220, 22));
        spin_crop = new QDoubleSpinBox(frame_control);
        spin_crop->setObjectName(QStringLiteral("spin_crop"));
        spin_crop->setGeometry(QRect(160, 178, 70, 22));
        spin_crop->setMinimum(0.5);
        spin_crop->setMaximum(10);
        spin_crop->setSingleStep(0.1);
        spin_crop->setValue(1);
        spin_focal_length = new QDoubleSpinBox(frame_control);
        spin_focal_length->setObjectName(QStringLiteral("spin_focal_length"));
        spin_focal_length->setGeometry(QRect(160, 338, 70, 22));
        spin_focal_length->setDecimals(1);
        spin_focal_length->setMinimum(1);
        spin_focal_length->setMaximum(1000);
        label_model = new QLabel(frame_control);
        label_model->setObjectName(QStringLiteral("label_model"));
        label_model->setGeometry(QRect(10, 108, 71, 16));
        combo_crop = new QComboBox(frame_control);
        combo_crop->setObjectName(QStringLiteral("combo_crop"));
        combo_crop->setGeometry(QRect(10, 178, 140, 22));
        label_crop = new QLabel(frame_control);
        label_crop->setObjectName(QStringLiteral("label_crop"));
        label_crop->setGeometry(QRect(10, 158, 91, 16));
        label_model_distance = new QLabel(frame_control);
        label_model_distance->setObjectName(QStringLiteral("label_model_distance"));
        label_model_distance->setGeometry(QRect(10, 218, 141, 10));
        combo_background = new QComboBox(frame_control);
        combo_background->setObjectName(QStringLiteral("combo_background"));
        combo_background->setGeometry(QRect(10, 78, 220, 22));
        slider_background_distance = new QSlider(frame_control);
        slider_background_distance->setObjectName(QStringLiteral("slider_background_distance"));
        slider_background_distance->setGeometry(QRect(10, 288, 141, 22));
        slider_background_distance->setMinimum(1);
        slider_background_distance->setMaximum(500);
        slider_background_distance->setSingleStep(1);
        slider_background_distance->setValue(1);
        slider_background_distance->setOrientation(Qt::Horizontal);
        spin_backgrond_distance = new QDoubleSpinBox(frame_control);
        spin_backgrond_distance->setObjectName(QStringLiteral("spin_backgrond_distance"));
        spin_backgrond_distance->setGeometry(QRect(160, 288, 70, 22));
        spin_backgrond_distance->setDecimals(1);
        spin_backgrond_distance->setMinimum(1);
        spin_backgrond_distance->setMaximum(500);
        spin_backgrond_distance->setSingleStep(1);
        spin_backgrond_distance->setValue(1);
        label_background_distance = new QLabel(frame_control);
        label_background_distance->setObjectName(QStringLiteral("label_background_distance"));
        label_background_distance->setGeometry(QRect(10, 268, 181, 16));
        spin_diaphragm = new QDoubleSpinBox(frame_control);
        spin_diaphragm->setObjectName(QStringLiteral("spin_diaphragm"));
        spin_diaphragm->setGeometry(QRect(171, 388, 58, 22));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spin_diaphragm->sizePolicy().hasHeightForWidth());
        spin_diaphragm->setSizePolicy(sizePolicy);
        spin_diaphragm->setDecimals(1);
        spin_diaphragm->setMinimum(1);
        spin_diaphragm->setMaximum(32);
        spin_diaphragm->setSingleStep(0.1);
        diaphragm_letter = new QLabel(frame_control);
        diaphragm_letter->setObjectName(QStringLiteral("diaphragm_letter"));
        diaphragm_letter->setGeometry(QRect(160, 391, 31, 16));
        combo_strategy = new QComboBox(frame_control);
        combo_strategy->setObjectName(QStringLiteral("combo_strategy"));
        combo_strategy->setGeometry(QRect(10, 28, 220, 22));
        label_strategy = new QLabel(frame_control);
        label_strategy->setObjectName(QStringLiteral("label_strategy"));
        label_strategy->setGeometry(QRect(10, 8, 91, 16));

        gridLayout->addWidget(frame_control, 0, 1, 3, 1);

        frame_favorite = new QFrame(centralWidget);
        frame_favorite->setObjectName(QStringLiteral("frame_favorite"));
        frame_favorite->setMinimumSize(QSize(240, 0));
        frame_favorite->setMaximumSize(QSize(240, 96));
        frame_favorite->setFrameShape(QFrame::StyledPanel);
        frame_favorite->setFrameShadow(QFrame::Plain);
        label_favorite = new QLabel(frame_favorite);
        label_favorite->setObjectName(QStringLiteral("label_favorite"));
        label_favorite->setGeometry(QRect(10, 8, 181, 16));
        combo_favorite = new QComboBox(frame_favorite);
        combo_favorite->setObjectName(QStringLiteral("combo_favorite"));
        combo_favorite->setGeometry(QRect(10, 28, 220, 22));
        combo_favorite->setEditable(true);
        combo_favorite->setInsertPolicy(QComboBox::InsertAtBottom);
        button_save = new QPushButton(frame_favorite);
        button_save->setObjectName(QStringLiteral("button_save"));
        button_save->setEnabled(false);
        button_save->setGeometry(QRect(10, 60, 75, 23));
        button_delete = new QPushButton(frame_favorite);
        button_delete->setObjectName(QStringLiteral("button_delete"));
        button_delete->setEnabled(false);
        button_delete->setGeometry(QRect(100, 60, 75, 23));

        gridLayout->addWidget(frame_favorite, 3, 1, 1, 1);

        image = new QLabel(centralWidget);
        image->setObjectName(QStringLiteral("image"));
        image->setFrameShape(QFrame::StyledPanel);
        image->setScaledContents(false);
        image->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(image, 1, 0, 4, 1);

        table_dof = new QTableWidget(centralWidget);
        if (table_dof->columnCount() < 1)
            table_dof->setColumnCount(1);
        if (table_dof->rowCount() < 4)
            table_dof->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_dof->setVerticalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_dof->setVerticalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_dof->setVerticalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_dof->setVerticalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem4->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        table_dof->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem5->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        table_dof->setItem(1, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem6->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        table_dof->setItem(2, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem7->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        table_dof->setItem(3, 0, __qtablewidgetitem7);
        table_dof->setObjectName(QStringLiteral("table_dof"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(table_dof->sizePolicy().hasHeightForWidth());
        table_dof->setSizePolicy(sizePolicy1);
        table_dof->setMinimumSize(QSize(240, 96));
        table_dof->setMaximumSize(QSize(240, 96));
        table_dof->setFrameShape(QFrame::HLine);
        table_dof->setFrameShadow(QFrame::Raised);
        table_dof->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table_dof->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table_dof->setAutoScroll(false);
        table_dof->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_dof->setSelectionMode(QAbstractItemView::NoSelection);
        table_dof->setRowCount(4);
        table_dof->setColumnCount(1);
        table_dof->horizontalHeader()->setVisible(false);
        table_dof->horizontalHeader()->setStretchLastSection(true);
        table_dof->verticalHeader()->setDefaultSectionSize(23);
        table_dof->verticalHeader()->setHighlightSections(false);
        table_dof->verticalHeader()->setMinimumSectionSize(21);
        table_dof->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(table_dof, 4, 1, 1, 1);

        frame_logon = new QFrame(centralWidget);
        frame_logon->setObjectName(QStringLiteral("frame_logon"));
        frame_logon->setMinimumSize(QSize(615, 44));
        frame_logon->setMaximumSize(QSize(16777215, 44));
        frame_logon->setFrameShape(QFrame::StyledPanel);
        frame_logon->setFrameShadow(QFrame::Plain);
        button_login = new QPushButton(frame_logon);
        button_login->setObjectName(QStringLiteral("button_login"));
        button_login->setEnabled(true);
        button_login->setGeometry(QRect(30, 10, 75, 23));
        button_register = new QPushButton(frame_logon);
        button_register->setObjectName(QStringLiteral("button_register"));
        button_register->setEnabled(true);
        button_register->setGeometry(QRect(130, 10, 101, 23));
        label_welcome = new QLabel(frame_logon);
        label_welcome->setObjectName(QStringLiteral("label_welcome"));
        label_welcome->setGeometry(QRect(30, 10, 401, 16));
        button_logout = new QPushButton(frame_logon);
        button_logout->setObjectName(QStringLiteral("button_logout"));
        button_logout->setEnabled(true);
        button_logout->setGeometry(QRect(440, 10, 93, 28));
        label_welcome->raise();
        button_login->raise();
        button_register->raise();
        button_logout->raise();

        gridLayout->addWidget(frame_logon, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(combo_background, combo_model);
        QWidget::setTabOrder(combo_model, combo_crop);
        QWidget::setTabOrder(combo_crop, spin_crop);
        QWidget::setTabOrder(spin_crop, slider_model_distance);
        QWidget::setTabOrder(slider_model_distance, spin_model_distance);
        QWidget::setTabOrder(spin_model_distance, slider_focal_length);
        QWidget::setTabOrder(slider_focal_length, spin_focal_length);
        QWidget::setTabOrder(spin_focal_length, slider_diaphragm);
        QWidget::setTabOrder(slider_diaphragm, table_dof);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DOF Calculator", nullptr));
        spin_model_distance->setSuffix(QApplication::translate("MainWindow", " \320\274", nullptr));
        label_background->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\275\320\270\320\271 \320\277\320\273\320\260\320\275", nullptr));
        label_crop_factor->setText(QApplication::translate("MainWindow", "\320\232\321\200\320\276\320\277-\321\204\320\260\320\272\321\202\320\276\321\200", nullptr));
        label_focal_length->setText(QApplication::translate("MainWindow", "\320\255\320\272\320\262\320\270\320\262\320\260\320\273\320\265\320\275\321\202\320\275\320\276\320\265 \321\204\320\276\320\272\321\203\321\201\320\275\320\276\320\265 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265 ", nullptr));
        label_diaphragm->setText(QApplication::translate("MainWindow", "\320\224\320\270\320\260\321\204\321\200\320\260\320\263\320\274\320\260\320\263\320\274\320\265\320\275\320\275\320\276\320\265 \321\207\320\270\321\201\320\273\320\276", nullptr));
        spin_focal_length->setSuffix(QApplication::translate("MainWindow", " \320\274\320\274", nullptr));
        label_model->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        label_crop->setText(QApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\272\320\260\320\264\321\200\320\260", nullptr));
        label_model_distance->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\264\320\276 \320\274\320\276\320\264\320\265\320\273\320\270", nullptr));
        spin_backgrond_distance->setSuffix(QApplication::translate("MainWindow", " \320\274", nullptr));
        label_background_distance->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\264\320\276 \321\204\320\276\320\275\320\260", nullptr));
        diaphragm_letter->setText(QApplication::translate("MainWindow", "f/", nullptr));
        label_strategy->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 \321\201\321\212\320\265\320\274\320\272\320\270", nullptr));
        label_favorite->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265 \320\275\320\260\320\261\320\276\321\200\320\260 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\276\320\262", nullptr));
        button_save->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        button_delete->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        image->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table_dof->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\223\320\273\321\203\320\261\320\270\320\275\320\260 \321\200\320\265\320\267\320\272\320\276\321\201\321\202\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_dof->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\264\320\275\320\270\320\271 \321\204\321\200\320\276\320\275\321\202 \320\223\320\240\320\230\320\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_dof->verticalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\275\320\270\320\271 \321\204\321\200\320\276\320\275\321\202 \320\223\320\240\320\230\320\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_dof->verticalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\223\320\270\320\277\320\265\321\200\321\204\320\276\320\272\320\260\320\273\321\214\320\275\320\276\320\265 \321\200\320\260\321\201\321\201\321\202", nullptr));

        const bool __sortingEnabled = table_dof->isSortingEnabled();
        table_dof->setSortingEnabled(false);
        table_dof->setSortingEnabled(__sortingEnabled);

        button_login->setText(QApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        button_register->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label_welcome->setText(QString());
        button_logout->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
