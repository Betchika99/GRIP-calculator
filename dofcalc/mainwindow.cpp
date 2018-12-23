#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logger.h"
#include <QDir>
#include <QPainter>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    InitLog();

    QApplication::setStyle("Fusion");
    ui->setupUi(this);
    ui->image->installEventFilter(this);

    QDir dirBrowser(QApplication::applicationDirPath(), "*.dat", QDir::Time|QDir::Reversed);
    ui->combo_favorite->blockSignals(true);
    for (int i = 0; i < dirBrowser.entryList().count(); i++)
    {
        QFileInfo fi(dirBrowser.entryList()[i]);
        ui->combo_favorite->addItem(fi.baseName());
    }
    ui->combo_favorite->setCurrentIndex(-1);
    ui->combo_favorite->blockSignals(false);

    dof = new DOFManager();
    updateUI();
    updateImage();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dof;
    CloseLog();
}

void MainWindow::on_button_login_clicked()
{
    //todo
}

void MainWindow::on_button_register_clicked()
{
    //todo
}

void MainWindow::on_combo_strategy_currentIndexChanged(int index)
{
    dof->setStrategyIndex(index);
    updateUI();
}

void MainWindow::on_combo_background_currentIndexChanged(int index)
{
    dof->setBackgroundIndex(index);
    updateImage();
}

void MainWindow::on_combo_model_currentIndexChanged(int index)
{
    dof->setModelIndex(index);
    updateImage();
}

void MainWindow::on_combo_crop_currentIndexChanged(int index)
{
    dof->setSensorIndex(index);
    ui->spin_crop->setValue(dof->getCropFactor());
    updateImage();
}

void MainWindow::on_spin_crop_valueChanged(double arg1)
{
    dof->setCropFactor(arg1);
    ui->combo_crop->setCurrentIndex(dof->getSensorIndex());
    updateImage();
}

void MainWindow::on_slider_model_distance_sliderMoved(int position)
{
    dof->setModelDistance(position);
    ui->spin_model_distance->setValue(dof->getModelDistance());
    updateImage();
}

void MainWindow::on_spin_model_distance_valueChanged(double arg1)
{
    dof->setModelDistance(arg1);
    ui->slider_model_distance->setValue(static_cast<int>(dof->getModelDistance()));
    updateImage();
}

void MainWindow::on_slider_background_distance_sliderMoved(int position)
{
    dof->setBackgroundDistance(position);
    ui->spin_backgrond_distance->setValue(dof->getBackgroundDistance());
    updateImage();
}

void MainWindow::on_spin_backgrond_distance_valueChanged(double arg1)
{
    dof->setBackgroundDistance(arg1);
    ui->slider_background_distance->setValue(static_cast<int>(dof->getBackgroundDistance()));
    updateImage();
}

void MainWindow::on_slider_focal_length_sliderMoved(int position)
{
    dof->setFocalLength(position);
    ui->spin_focal_length->setValue(dof->getFocalLength());
    updateImage();
}

void MainWindow::on_spin_focal_length_valueChanged(double arg1)
{
    dof->setFocalLength(arg1);
    ui->slider_focal_length->setValue(static_cast<int>(dof->getFocalLength()));
    updateImage();
}

void MainWindow::on_slider_diaphragm_sliderMoved(int position)
{
    dof->setAperture(position);
    ui->spin_diaphragm->setValue(dof->getAperture());
    updateImage();
}

void MainWindow::on_spin_diaphragm_valueChanged(double arg1)
{
    dof->setAperture(arg1);
    ui->slider_diaphragm->setValue(static_cast<int>(dof->getAperture()));
    updateImage();
}

void MainWindow::on_combo_favorite_currentIndexChanged(int index)
{
    QString fileName = QApplication::applicationDirPath() + "/" + ui->combo_favorite->itemText(index) + ".dat";
    if (QFileInfo(fileName).exists())
    {
        dof->loadFromFile(fileName);
        updateUI();
        updateImage();
        ui->button_delete->setEnabled(true);
    }
}

void MainWindow::on_combo_favorite_editTextChanged(const QString &arg1)
{
    ui->button_save->setEnabled(!arg1.isEmpty());
    ui->button_delete->setEnabled(false);
}

void MainWindow::on_button_save_clicked()
{
    QString fileName = QApplication::applicationDirPath() + "/" + ui->combo_favorite->currentText() + ".dat";
    dof->saveToFile(fileName);
    if (ui->combo_favorite->findText(ui->combo_favorite->currentText()) < 0)
    {
        ui->combo_favorite->blockSignals(true);
        ui->combo_favorite->addItem(ui->combo_favorite->currentText());
        ui->combo_favorite->blockSignals(false);
    }
    ui->button_save->setEnabled(false);
    ui->button_delete->setEnabled(true);
}

void MainWindow::on_button_delete_clicked()
{
    QString fileName = QApplication::applicationDirPath() + "/" + ui->combo_favorite->currentText() + ".dat";
    QFile file(fileName);
    if (file.exists()) file.remove();
    int index = ui->combo_favorite->findText(ui->combo_favorite->currentText());
    if (index >= 0)
    {
        ui->combo_favorite->blockSignals(true);
        ui->combo_favorite->removeItem(index);
        ui->combo_favorite->setCurrentIndex(-1);
        ui->combo_favorite->blockSignals(false);
    }
    ui->button_save->setEnabled(false);
    ui->button_delete->setEnabled(false);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)   //todo
{
    if (obj == ui->image && event->type() == QEvent::Resize) updateImage();
    return QObject::eventFilter(obj, event);
}

void MainWindow::updateImage()
{
    dof->PerformImageProcessing();

    ui->table_dof->item(0, 0)->setText(QString::asprintf("%1.2f м", dof->getGRIP()));
    ui->table_dof->item(1, 0)->setText(QString::asprintf("%1.2f м", dof->getNearestPointOfSharpness()));
    ui->table_dof->item(2, 0)->setText(QString::asprintf("%1.2f м", dof->getFarestPointOfSharpness()));
    ui->table_dof->item(3, 0)->setText(QString::asprintf("%1.2f м", dof->getHyperFocal()));

    ui->image->setPixmap(dof->getResultImage().scale(ui->image->size()).asQPixmap());   //можно класс Image переписать с использование неявного преобразования типа
}

void MainWindow::updateUI()
{
    Strategy &strategy = dof->getStrategy();

    ui->combo_strategy->blockSignals(true);
    ui->combo_strategy->clear();
    ui->combo_strategy->addItems(dof->getStrategyList());
    ui->combo_strategy->setCurrentIndex(dof->getStrategyIndex());
    ui->combo_strategy->blockSignals(false);

    ui->combo_background->blockSignals(true);
    ui->combo_background->clear();
    ui->combo_background->addItems(dof->getBackgroundsList());
    ui->combo_background->setCurrentIndex(dof->getBackgroundIndex());
    ui->combo_background->blockSignals(false);

    ui->combo_model->blockSignals(true);
    ui->combo_model->clear();
    ui->combo_model->addItems(dof->getModelsList());
    ui->combo_model->setCurrentIndex(dof->getModelIndex());
    ui->combo_model->blockSignals(false);

    ui->combo_crop->blockSignals(true);
    ui->spin_crop->blockSignals(true);
    ui->combo_crop->clear();
    ui->combo_crop->addItems(dof->getSensorsList());
    ui->combo_crop->setCurrentIndex(dof->getSensorIndex());
    ui->spin_crop->setValue(dof->getCropFactor());
    ui->combo_crop->blockSignals(false);
    ui->spin_crop->blockSignals(false);

    ui->slider_model_distance->blockSignals(true);
    ui->spin_model_distance->blockSignals(true);
    ui->slider_model_distance->setRange(
        static_cast<int>(strategy.ModelDistance().min),
        static_cast<int>(strategy.ModelDistance().max));
    ui->spin_model_distance->setRange(strategy.ModelDistance().min, strategy.ModelDistance().max);
    ui->slider_model_distance->setValue(static_cast<int>(dof->getModelDistance()));
    ui->spin_model_distance->setValue(dof->getModelDistance());
    ui->slider_model_distance->blockSignals(false);
    ui->spin_model_distance->blockSignals(false);

    ui->slider_background_distance->blockSignals(true);
    ui->spin_backgrond_distance->blockSignals(true);
    ui->slider_background_distance->setRange(
        static_cast<int>(strategy.BackgroundDistance().min),
        static_cast<int>(strategy.BackgroundDistance().max));
    ui->spin_backgrond_distance->setRange(strategy.BackgroundDistance().min, strategy.BackgroundDistance().max);
    ui->slider_background_distance->setValue(static_cast<int>(dof->getBackgroundDistance()));
    ui->spin_backgrond_distance->setValue(dof->getBackgroundDistance());
    ui->slider_background_distance->blockSignals(false);
    ui->spin_backgrond_distance->blockSignals(false);

    ui->slider_focal_length->blockSignals(true);
    ui->spin_focal_length->blockSignals(true);
    ui->slider_focal_length->setRange(
        static_cast<int>(strategy.FocalLenght().min),
        static_cast<int>(strategy.FocalLenght().max));
    ui->spin_focal_length->setRange(strategy.FocalLenght().min, strategy.FocalLenght().max);
    ui->slider_focal_length->setValue(static_cast<int>(dof->getFocalLength()));
    ui->spin_focal_length->setValue(dof->getFocalLength());
    ui->slider_focal_length->blockSignals(false);
    ui->spin_focal_length->blockSignals(false);

    ui->slider_diaphragm->blockSignals(true);
    ui->spin_diaphragm->blockSignals(true);
    ui->slider_diaphragm->setRange(
        static_cast<int>(strategy.Diaphragm().min),
        static_cast<int>(strategy.Diaphragm().max));
    ui->spin_diaphragm->setRange(strategy.Diaphragm().min, strategy.Diaphragm().max);
    ui->slider_diaphragm->setValue(static_cast<int>(dof->getAperture()));
    ui->spin_diaphragm->setValue(dof->getAperture());
    ui->slider_diaphragm->blockSignals(false);
    ui->spin_diaphragm->blockSignals(false);
}
