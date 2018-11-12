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

    //Setting defaul
    ui->combo_background->addItems(dof->getBackgroundsList());
    ui->combo_background->setCurrentIndex(dof->getBackgroundIndex());

    ui->combo_model->addItems(dof->getModelsList());
    ui->combo_model->setCurrentIndex(dof->getModelIndex());

    ui->combo_sensor->addItems(dof->getSensorsList());
    ui->combo_sensor->setCurrentIndex(dof->getSensorIndex());

    ui->spin_crop->setValue(dof->getCropFactor());

    ui->slider_distance->setValue(static_cast<int>(dof->getModelDistance()));
    ui->spin_distance->setValue(dof->getModelDistance());

    ui->slider_focallen->setValue(static_cast<int>(dof->getFocalLength()));
    ui->spin_focallen->setValue(dof->getFocalLength());

    ui->slider_aperture->setValue(static_cast<int>(dof->getAperture()));
    ui->spin_aperture->setValue(dof->getAperture());

    ui->slider_backgroun_distance->setValue(static_cast<int>(dof->getBackgroundDistance()));
    ui->spin_backgrond_distance->setValue(dof->getBackgroundDistance());

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


void MainWindow::on_spin_distance_valueChanged(double arg1)
{
    dof->setModelDistance(arg1);
    ui->slider_distance->setValue(static_cast<int>(dof->getModelDistance()));
    updateImage();
}

void MainWindow::on_slider_distance_sliderMoved(int position)
{
    dof->setModelDistance(position);
    ui->spin_distance->setValue(dof->getModelDistance());
    updateImage();
}


void MainWindow::on_spin_backgrond_distance_valueChanged(double arg1)
{
    dof->setBackgroundDistance(arg1);
    ui->slider_backgroun_distance->setValue(static_cast<int>(dof->getBackgroundDistance()));
    updateImage();
}

void MainWindow::on_slider_backgroun_distance_sliderMoved(int position)
{
    dof->setBackgroundDistance(position);
    ui->spin_backgrond_distance->setValue(dof->getBackgroundDistance());
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
    dof->setAperture(position);
    ui->spin_aperture->setValue(dof->getAperture());
    updateImage();
}

void MainWindow::on_spin_aperture_valueChanged(double arg1)
{
    dof->setAperture(arg1);
    ui->slider_aperture->setValue(static_cast<int>(dof->getAperture()));
    updateImage();
}


bool MainWindow::eventFilter(QObject *obj, QEvent *event)   //todo
{
    if (obj == ui->image && event->type() == QEvent::Resize) updateImage();
    return QObject::eventFilter(obj, event);
}

void MainWindow::updateImage()  //todo
{
    QString sample = QDir::toNativeSeparators(QApplication::applicationDirPath() + "/test.png");
    QPixmap pm(sample);

    ui->image->setPixmap(pm.scaled(ui->image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    //happens something strange with format!!!
    ui->table_dof->setItem(0,0, new QTableWidgetItem(QString::number(dof->getGRIP(), 'f', 2)));
    ui->table_dof->setItem(0,1, new QTableWidgetItem(QString::number(dof->getNearestPointOfSharpness(), 'f', 2)));
    ui->table_dof->setItem(0,2, new QTableWidgetItem(QString::number(dof->getFarestPointOfSharpness(), 'f', 2)));
    ui->table_dof->setItem(0,3, new QTableWidgetItem(QString::number(dof->getHyperFocal(), 'f', 2)));
}

