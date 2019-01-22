/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QPushButton *submit;
    QLabel *title;
    QLabel *label_login;
    QLabel *label_password;
    QLineEdit *edit_login;
    QLineEdit *edit_password;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(400, 300);
        submit = new QPushButton(LoginWindow);
        submit->setObjectName(QStringLiteral("submit"));
        submit->setGeometry(QRect(160, 240, 93, 28));
        title = new QLabel(LoginWindow);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(170, 10, 55, 16));
        label_login = new QLabel(LoginWindow);
        label_login->setObjectName(QStringLiteral("label_login"));
        label_login->setGeometry(QRect(180, 70, 55, 16));
        label_password = new QLabel(LoginWindow);
        label_password->setObjectName(QStringLiteral("label_password"));
        label_password->setGeometry(QRect(180, 160, 55, 16));
        edit_login = new QLineEdit(LoginWindow);
        edit_login->setObjectName(QStringLiteral("edit_login"));
        edit_login->setGeometry(QRect(140, 110, 113, 22));
        edit_password = new QLineEdit(LoginWindow);
        edit_password->setObjectName(QStringLiteral("edit_password"));
        edit_password->setGeometry(QRect(150, 190, 113, 22));
        edit_password->setEchoMode(QLineEdit::Password);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "Dialog", nullptr));
        submit->setText(QApplication::translate("LoginWindow", "\320\236\320\232", nullptr));
        title->setText(QString());
        label_login->setText(QApplication::translate("LoginWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_password->setText(QApplication::translate("LoginWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
