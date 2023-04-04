#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SpecialCharacters.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Связываем сигнал clicked() кнопки с методом QCoreApplication::quit()
    QObject::connect(ui->btnOK, &QPushButton::clicked, &QCoreApplication::quit);

    this->setWindowTitle("Lesson 02. Task 1.");

    ui->plainTextEdit->setPlainText("This text contains the word @RUB@. Let's replace it with ₽.");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnReplace_clicked()
{
    SpecialCharacters sc;

    //QString text =ui->plainTextEdit->toPlainText();
    QString text = sc.replace(ui->plainTextEdit->toPlainText());
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText(text);
    QMessageBox::information(this, "Autocorrect", "the action is completed!");
}

