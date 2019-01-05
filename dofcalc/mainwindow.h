#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
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
    void on_button_login_clicked();
    void on_button_register_clicked();

    void on_combo_strategy_currentIndexChanged(int index);
    void on_combo_background_currentIndexChanged(int index);
    void on_combo_model_currentIndexChanged(int index);
    void on_combo_crop_currentIndexChanged(int index);
    void on_spin_crop_valueChanged(double arg1);
    void on_slider_model_distance_sliderMoved(int position);
    void on_spin_model_distance_valueChanged(double arg1);
    void on_slider_background_distance_sliderMoved(int position);
    void on_spin_backgrond_distance_valueChanged(double arg1);
    void on_slider_focal_length_sliderMoved(int position);
    void on_spin_focal_length_valueChanged(double arg1);
    void on_slider_diaphragm_sliderMoved(int position);
    void on_spin_diaphragm_valueChanged(double arg1);

    void on_combo_favorite_currentIndexChanged(int index);
    void on_combo_favorite_editTextChanged(const QString &arg1);
    void on_button_save_clicked();
    void on_button_delete_clicked();
    
    void on_button_logout_clicked();

protected:
    Ui::MainWindow *ui;
    DOFManager dof;

private:
    bool eventFilter(QObject *obj, QEvent *event);
    template <class T> void updateWidget(QComboBox *wg, const PropertySwitch<T> &p);
    template <class T> void updateWidget(QDoubleSpinBox *wg, const PropertyValue<T> &p);
    template <class T> void updateWidget(QSlider *wg, const PropertyValue<T> &p);
    void updateUI();
    void updateImage();
};

#endif // MAINWINDOW_H
