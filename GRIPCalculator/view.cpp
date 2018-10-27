#include "view.h"
#include "ui_view.h"
#include <QStandardItemModel>

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    QStandardItemModel *resultsModel = new QStandardItemModel(4,2, this);
    resultsModel->setItem(0,0, new QStandardItem("Передняя зона ГРИП"));
    resultsModel->setItem(1,0, new QStandardItem("Задняя зона ГРИП"));
    resultsModel->setItem(2,0, new QStandardItem("Задняя зона ГРИП"));
    resultsModel->setItem(3,0, new QStandardItem("Задняя зона ГРИП"));
    ui->tableView->horizontalHeader()->hide();
    ui->tableView->verticalHeader()->hide();
    ui -> tableView ->setModel(resultsModel);
}

View::~View()
{
    delete ui;
}
