#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "toolslibrary.h"
#include "loginwindow.h"
#include <QtCore>

static const char* WelcomeTemplate = "Добро пожаловать, %s!  "
                                     "Вы успешно авторизовались на нашем сервере";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QApplication::setStyle("Fusion");
    ui->setupUi(this);
    ui->button_logout->setVisible(false);
    ui->label_welcome->setVisible(false);
    ui->image->installEventFilter(this);
    updateUI();
    updateImage();
}

MainWindow::~MainWindow()
{
    delete ui;
    //удалить другие файлы и почистить за собой
}

void MainWindow::on_button_login_clicked()
{
    LoginWindow lw;
    lw.setModal(true);
    lw.setTitle("Авторизация"); //вынести в константы!!!
    lw.setWelcome("Авторизуйтесь, пожалуйста!");
    if (!lw.exec()) return;

    if ( dof.login(lw.login(), lw.password()) )
    {
        ui->button_login->setVisible(false);
        ui->button_register->setVisible(false);
        ui->button_logout->setVisible(true);
        ui->label_welcome->setVisible(true);
        QString welcome = QString::asprintf(WelcomeTemplate, lw.login().toUtf8().data());
        ui->label_welcome->setText(welcome);
    }
}

void MainWindow::on_button_register_clicked()
{
    LoginWindow lw;
    lw.setModal(true);
    lw.setTitle("Регистрация"); //вынести в константы!!!
    lw.setWelcome("Зарегистрируйтесь, пожалуйста!");
    if (!lw.exec()) return;

    if ( dof.createUser(lw.login(), lw.password()) )
    {
        dof.login(lw.login(), lw.password());
        ui->button_login->setVisible(false);
        ui->button_register->setVisible(false);
        ui->button_logout->setVisible(true);
        ui->label_welcome->setVisible(true);
        QString welcome = QString::asprintf(WelcomeTemplate, lw.login().toUtf8().data());
        ui->label_welcome->setText(welcome);
    }
}

void MainWindow::on_button_logout_clicked()
{
    dof.logout();
    ui->button_login->setVisible(true);
    ui->button_register->setVisible(true);
    ui->button_logout->setVisible(false);
    ui->label_welcome->setVisible(false);
}

void MainWindow::on_combo_strategy_currentIndexChanged(int index)
{
    dof.setStrategy(index);
    updateUI();
}

void MainWindow::on_combo_background_currentIndexChanged(int index)
{
    dof.setBackground(index);
    updateImage();
}

void MainWindow::on_combo_model_currentIndexChanged(int index)
{
    dof.setModel(index);
    updateImage();
}

void MainWindow::on_combo_crop_currentIndexChanged(int index)
{
    dof.setCrop(index);
    updateWidget(ui->spin_crop, dof.cropFactor());
    updateImage();
}

void MainWindow::on_spin_crop_valueChanged(double arg1)
{
    dof.setCropFactor(arg1);
    updateWidget(ui->combo_crop, dof.crop());
    updateImage();
}

void MainWindow::on_slider_model_distance_sliderMoved(int position)
{
    dof.setModelDistance(position);
    updateWidget(ui->spin_model_distance, dof.modelDistance());
    updateImage();
}

void MainWindow::on_spin_model_distance_valueChanged(double arg1)
{
    dof.setModelDistance(arg1);
    updateWidget(ui->slider_model_distance, dof.modelDistance());
    updateImage();
}

void MainWindow::on_slider_background_distance_sliderMoved(int position)
{
    dof.setBackgroundDistance(position);
    updateWidget(ui->spin_backgrond_distance, dof.backgroundDistance());
    updateImage();
}

void MainWindow::on_spin_backgrond_distance_valueChanged(double arg1)
{
    dof.setBackgroundDistance(arg1);
    updateWidget(ui->slider_background_distance, dof.backgroundDistance());
    updateImage();
}

void MainWindow::on_slider_focal_length_sliderMoved(int position)
{
    dof.setFocalLength(position);
    updateWidget(ui->spin_focal_length, dof.focalLength());
    updateImage();
}

void MainWindow::on_spin_focal_length_valueChanged(double arg1)
{
    dof.setFocalLength(arg1);
    updateWidget(ui->slider_focal_length, dof.focalLength());
    updateImage();
}

void MainWindow::on_slider_diaphragm_sliderMoved(int position)
{
    dof.setDiaphragm(position);
    updateWidget(ui->spin_diaphragm, dof.diaphragm());
    updateImage();
}

void MainWindow::on_spin_diaphragm_valueChanged(double arg1)
{
    dof.setDiaphragm(arg1);
    updateWidget(ui->slider_diaphragm, dof.diaphragm());
    updateImage();
}

void MainWindow::on_combo_favorite_currentIndexChanged(int index)
{
    if (dof.loadFavorite(ui->combo_favorite->itemText(index)))
    {
        updateUI();
        updateImage();
    }
    ui->button_delete->setEnabled(true);
}

void MainWindow::on_combo_favorite_editTextChanged(const QString &arg1)
{
    ui->button_save->setEnabled(!arg1.isEmpty());
    ui->button_delete->setEnabled(false);
}

void MainWindow::on_button_save_clicked()
{
    if (dof.saveFavorite(ui->combo_favorite->currentText()))
    {
        updateWidget(ui->combo_favorite, dof.favorite());
        ui->button_save->setEnabled(false);
        ui->button_delete->setEnabled(true);

    }
}

void MainWindow::on_button_delete_clicked()
{
    dof.deleteFavorite(ui->combo_favorite->currentText());
    updateWidget(ui->combo_favorite, dof.favorite());
    ui->button_save->setEnabled(false);
    ui->button_delete->setEnabled(false);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->image && event->type() == QEvent::Resize) updateImage();
    return QObject::eventFilter(obj, event);
}

template<class T>
void MainWindow::updateWidget(QComboBox *wg, const PropertySwitch<T> &p)
{
    wg->blockSignals(true);
    wg->clear();
    wg->addItems(p.titleList());
    wg->setCurrentIndex(p.index());
    wg->blockSignals(false);
}

template<class T>
void MainWindow::updateWidget(QDoubleSpinBox *wg, const PropertyValue<T> &p)
{
    wg->blockSignals(true);
    wg->setRange(p.min(), p.max());
    wg->setValue(p.value());
    wg->blockSignals(false);
}

template<class T>
void MainWindow::updateWidget(QSlider *wg, const PropertyValue<T> &p)
{
    wg->blockSignals(true);
    wg->setRange(qRound(p.min()), qRound(p.max()));
    wg->setValue(qRound(p.value()));
    wg->blockSignals(false);
}

void MainWindow::updateUI()
{
    updateWidget(ui->combo_strategy, dof.strategy());
    updateWidget(ui->combo_background, dof.background());
    updateWidget(ui->combo_model, dof.model());
    updateWidget(ui->combo_crop, dof.crop());
    updateWidget(ui->spin_crop, dof.cropFactor());
    updateWidget(ui->slider_model_distance, dof.modelDistance());
    updateWidget(ui->spin_model_distance, dof.modelDistance());
    updateWidget(ui->slider_background_distance, dof.backgroundDistance());
    updateWidget(ui->spin_backgrond_distance, dof.backgroundDistance());
    updateWidget(ui->slider_focal_length, dof.focalLength());
    updateWidget(ui->spin_focal_length, dof.focalLength());
    updateWidget(ui->slider_diaphragm, dof.diaphragm());
    updateWidget(ui->spin_diaphragm, dof.diaphragm());
    updateWidget(ui->combo_favorite, dof.favorite());
}

void MainWindow::updateImage()
{
    dof.performImageProcessing();
    ui->table_dof->item(0, 0)->setText(QString::asprintf("%1.2f м", dof.getGRIP()));
    ui->table_dof->item(1, 0)->setText(QString::asprintf("%1.2f м", dof.getNearestPointOfSharpness()));
    ui->table_dof->item(2, 0)->setText(QString::asprintf("%1.2f м", dof.getFarestPointOfSharpness()));
    ui->table_dof->item(3, 0)->setText(QString::asprintf("%1.2f м", dof.getHyperFocal()));
    ui->image->setPixmap(dof.getResultImage().scale(ui->image->size()).asQPixmap());
}
