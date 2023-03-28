#include <cmath>
#include <QtMath>
#include <QDoubleValidator>
#include <QLocale>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Связываем сигнал clicked() кнопки с методом QCoreApplication::quit()
    QObject::connect(ui->button_ok, &QPushButton::clicked, &QCoreApplication::quit);

    this->setWindowTitle("Корни квадратного уравнения");

    // Создаем экземпляр QLocale с десятичной точкой в качестве разделителя дробной части
    QLocale locale = QLocale::c();
    locale.setNumberOptions(QLocale::RejectGroupSeparator);

    QDoubleValidator *val = new QDoubleValidator();
    val->setLocale(locale);
    //val->setNotation(QDoubleValidator::StandardNotation);
    val->setDecimals(1);

    ui->line_edit_a->setValidator(val);
    ui->line_edit_b->setValidator(val);
    ui->line_edit_c->setValidator(val);

    ui->label_answer->setText("?");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_go_clicked()
{
    float a = ui->line_edit_a->text().toFloat();
    float b = ui->line_edit_b->text().toFloat();
    float c = ui->line_edit_c->text().toFloat();

    if (!a && !b)
    {
        ui->label_answer->setText("-");
        return;
    }

    if (!a && b)
    {
        float x = -c / b;

        float rounded_x = qRound(x * 10) / 10.0f; // округляем до 1 знака после запятой
        QString result = QString::number(rounded_x, 'f', 1); // конвертируем в QString
        ui->label_answer->setText("x = " + result);

        return;
    }

    float D = pow (b, 2) - 4 * a * c;

    if (D < 0)
    {
        ui->label_answer->setText("действительных корней нет");
    }
    else if (!D)
    {
        float x = -b / (2 * a);
        float rounded_x = qRound(x * 10) / 10.0f; // округляем до 1 знака после запятой
        QString result = QString::number(rounded_x, 'f', 1); // конвертируем в QString
        ui->label_answer->setText("x = " + result);
    }
    else
    {
        auto x1 = (-b + qSqrt(D)) / (2 * a);
        auto x2 = (-b - qSqrt(D)) / (2 * a);

        float rounded_x1 = qRound(x1 * 10) / 10.0f;
        QString result_x1 = QString::number(rounded_x1, 'f', 1);

        float rounded_x2 = qRound(x2 * 10) / 10.0f;
        QString result_x2 = QString::number(rounded_x2, 'f', 1);

        ui->label_answer->setText("x1 = " + result_x1 + "; x2 = " +result_x2);
    }

}


void MainWindow::on_line_edit_a_textChanged(const QString &arg1)
{
    ui->label_answer->setText("?");
}


void MainWindow::on_line_edit_b_textChanged(const QString &arg1)
{
    ui->label_answer->setText("?");
}


void MainWindow::on_line_edit_c_textChanged(const QString &arg1)
{
    ui->label_answer->setText("?");
}

