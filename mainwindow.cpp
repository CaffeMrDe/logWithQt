#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include "logmanager.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, &MainWindow::emitTextControl,this, &MainWindow::displayTextControl);
    ui->textBrowser->document()->setMaximumBlockCount(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayTextControl(QString text)
{
   ui->textBrowser->append(text);
}

void MainWindow::on_pushButton_clicked()
{
    LOG("cube")->logInfoMessage("CUBE");
    LOG("name")->logInfoMessage("CUBE");
}
