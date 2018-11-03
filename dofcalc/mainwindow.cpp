#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include "propertylist.h"   //todo
#include "imagehandler.h"   //todo

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QApplication::setStyle("Fusion");

    dof = new DOFManager();

    ui->setupUi(this);

    ui->combo_background->addItems(dof->getBackgroundsList());
    ui->combo_background->setCurrentIndex(dof->getBackgroundIndex());

    ui->combo_model->addItems(dof->getModelsList());
    ui->combo_model->setCurrentIndex(dof->getModelIndex());

    ui->combo_sensor->addItems(dof->getSensorsList());
    ui->combo_sensor->setCurrentIndex(dof->getSensorIndex());
    ui->spin_crop->setValue(dof->getCropFactor());

    ui->slider_distance->setValue(static_cast<int>(dof->getDistance()));
    ui->spin_distance->setValue(dof->getDistance());

    ui->slider_focallen->setValue(static_cast<int>(dof->getFocalLength()));
    ui->spin_focallen->setValue(dof->getFocalLength());

    ui->slider_aperture->setMaximum(dof->getAperturesList().count()-1);
    ui->slider_aperture->setValue(dof->getApertureIndex());
    ui->combo_aperture->addItems(dof->getAperturesList());
    ui->combo_aperture->setCurrentIndex(dof->getApertureIndex());

    ui->image->installEventFilter(this);

    PropertyList pl;    //todo
    ImageHandler ih;   //todo
    ih.loadFromFile("D:\\temp\\test.model.*.png");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dof;
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

void MainWindow::on_combo_sensor_currentIndexChanged(int index)
{
    dof->setSensorIndex(index);
    ui->spin_crop->setValue(dof->getCropFactor());
    updateImage();
}

void MainWindow::on_spin_crop_valueChanged(double arg1)
{
    dof->setCropFactor(arg1);
    ui->combo_sensor->setCurrentIndex(dof->getSensorIndex());
    updateImage();
}

void MainWindow::on_slider_distance_sliderMoved(int position)
{
    dof->setDistance(position);
    ui->spin_distance->setValue(dof->getDistance());
    updateImage();
}

void MainWindow::on_spin_distance_valueChanged(double arg1)
{
    dof->setDistance(arg1);
    ui->slider_distance->setValue(static_cast<int>(dof->getDistance()));
    updateImage();
}

void MainWindow::on_slider_focallen_sliderMoved(int position)
{
    dof->setFocalLength(position);
    ui->spin_focallen->setValue(dof->getFocalLength());
    updateImage();
}

void MainWindow::on_spin_focallen_valueChanged(double arg1)
{
    dof->setFocalLength(arg1);
    ui->slider_focallen->setValue(static_cast<int>(dof->getFocalLength()));
    updateImage();
}

void MainWindow::on_slider_aperture_sliderMoved(int position)
{
    dof->setApertureIndex(position);
    ui->combo_aperture->setCurrentIndex(dof->getApertureIndex());
    updateImage();
}

void MainWindow::on_combo_aperture_currentIndexChanged(int index)
{
    dof->setApertureIndex(index);
    ui->slider_aperture->setValue(dof->getApertureIndex());
    updateImage();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->image && event->type() == QEvent::Resize) updateImage();
    return QObject::eventFilter(obj, event);
}

void MainWindow::updateImage()
{
    QString sample = QDir::toNativeSeparators(QApplication::applicationDirPath() + "/test.png");
    QPixmap pm(sample);


    ui->image->setPixmap(pm.scaled(ui->image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

