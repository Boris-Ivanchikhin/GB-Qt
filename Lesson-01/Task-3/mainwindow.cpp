#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Lesson 01. Exercise 3.");

    // Связываем сигнал clicked() кнопки с методом QCoreApplication::quit()
    QObject::connect(ui->btnOK, &QPushButton::clicked, &QCoreApplication::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAdd_clicked()
{
    QString str=ui->plainTextEdit1->toPlainText();
    ui->plainTextEdit2->appendPlainText(str);
}


void MainWindow::on_btnReplace_clicked()
{
    QString str=ui->plainTextEdit1->toPlainText();
    ui->plainTextEdit2->setPlainText(str);
}


void MainWindow::on_btnHTML_clicked()
{
    const QString str {"<font color='red'>Hello</font>"};
    //ui->plainTextEdit2->clear();
    ui->plainTextEdit2->appendHtml(str);
}

