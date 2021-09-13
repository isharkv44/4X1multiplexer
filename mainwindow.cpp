#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectOutput(){
    int input1, input2, input3, input4, output;

    bool selector1, selector2;

    input1 = ui->lcdNumber->value();
    input2 = ui->lcdNumber_2->value();
    input3 = ui->lcdNumber_3->value();
    input4 = ui->lcdNumber_4->value();

    selector1 = ui->select1CheckBox->isChecked();
    selector2 = ui->select2CheckBox->isChecked();

    if(!selector1 && !selector2)
    {
        output = input1;
    }
    else if (selector1 && !selector2) {
        output = input2;
    }
    else if (!selector1 && selector2) {
        output = input3;
    }
    else {
        output = input4;
    }
    ui->lcdNumber_5->display(output);
}
void MainWindow::toggleSelectLines(){
    bool selector1, selector2;

    selector1 = ui->select1CheckBox->isChecked();
    selector2 = ui->select2CheckBox->isChecked();

    if(!selector1 && !selector2)
    {
        ui->select1CheckBox->setCheckState(Qt::CheckState::Checked);
    }
    else if (selector1 && !selector2)
    {
        ui->select1CheckBox->setCheckState(Qt::CheckState::Unchecked);
        ui->select2CheckBox->setCheckState(Qt::CheckState::Checked);
    }
    else if (!selector1 && selector2)
    {
        ui->select1CheckBox->setCheckState(Qt::CheckState::Checked);
    }
    else
    {
        ui->select1CheckBox->setCheckState(Qt::CheckState::Unchecked);
        ui->select2CheckBox->setCheckState(Qt::CheckState::Unchecked);
    }
  }



