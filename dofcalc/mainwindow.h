#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dofmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_combo_background_currentIndexChanged(int index);

    void on_combo_model_currentIndexChanged(int index);

    void on_combo_sensor_currentIndexChanged(int index);

    void on_spin_crop_valueChanged(double arg1);

    void on_slider_distance_sliderMoved(int position);

    void on_spin_distance_valueChanged(double arg1);

    void on_slider_focallen_sliderMoved(int position);

    void on_spin_focallen_valueChanged(double arg1);

    void on_slider_aperture_sliderMoved(int position);

    void on_combo_aperture_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    DOFManager *dof;

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private:
    void updateImage();
};

#endif // MAINWINDOW_H
