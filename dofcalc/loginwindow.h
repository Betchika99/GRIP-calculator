#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    void setTitle(QString title);
    void setWelcome(QString text);
    QString login();
    QString password();


private slots:
    void on_edit_login_textChanged(const QString &arg1);

    void on_edit_password_textChanged(const QString &arg1);

    void on_submit_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
