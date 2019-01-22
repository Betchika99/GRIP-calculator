#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::setTitle(QString title)
{
    setWindowTitle(title);
}

void LoginWindow::setWelcome(QString text)
{
    ui->title->setText(text);
}

QString LoginWindow::login()
{
    return ui->edit_login->text();
}

QString LoginWindow::password()
{
    return ui->edit_password->text();
}

void LoginWindow::on_edit_login_textChanged(const QString &arg1)
{
    bool enabled = !arg1.isEmpty() && !ui->edit_password->text().isEmpty();
    ui->submit->setEnabled(enabled);
}

void LoginWindow::on_edit_password_textChanged(const QString &arg1)
{
    bool enabled = !arg1.isEmpty() && !ui->edit_login->text().isEmpty();
    ui->submit->setEnabled(enabled);
}

void LoginWindow::on_submit_clicked()
{
    accept();
}
