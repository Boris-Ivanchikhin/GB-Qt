#include <QDoubleValidator>
#include <cmath>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Расчет стороны треугольника");

    ui->lb_answer->clear();

    // Создаем экземпляр QLocale с десятичной точкой в качестве разделителя дробной части
    QLocale locale = QLocale::c();
    locale.setNumberOptions(QLocale::RejectGroupSeparator);

    QDoubleValidator *size_val = new QDoubleValidator(0.0, 100000.0, 1, this);
    size_val->setLocale(locale);

    ui->le_size_1->setValidator(size_val);
    ui->le_size_2->setValidator(size_val);

    QDoubleValidator *angle_val = new QDoubleValidator(0.0, 180.0, 1, this);
    angle_val->setLocale(locale);
    ui->le_angle->setValidator(angle_val);

    ui->rb_in_degrees->setChecked(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    float size_1 = ui->le_size_1->text().toFloat();
    float size_2 = ui->le_size_2->text().toFloat();
    float angle  = ui->le_angle->text().toFloat();

    float angle_rad = (ui->rb_in_degrees->isChecked()) ?
                angle * M_PI / 180.0 : angle;

    if (size_1 <= 0 || size_2 <= 0 || angle_rad <= 0 || angle_rad > M_PI)
    {
        ui->lb_answer->setText("ошибка!");
    }
    else
    {
        float size_3 = qSqrt(pow(size_1, 2) + pow(size_2, 2) - 2*size_1*size_2*std::cos(angle_rad));
        size_3 = qRound(size_3 * 10) / 10.0f; // округляем до 1 знака после запятой
        QString result = QString::number(size_3, 'f', 1); // конвертируем в QString
        ui->lb_answer->setText("ответ: " + result);
    }


}


void MainWindow::on_le_size_1_textChanged(const QString &arg1)
{
    ui->lb_answer->clear();
}


void MainWindow::on_le_size_2_textChanged(const QString &arg1)
{
    ui->lb_answer->clear();
}


void MainWindow::on_le_angle_textChanged(const QString &arg1)
{
    ui->lb_answer->clear();
}

