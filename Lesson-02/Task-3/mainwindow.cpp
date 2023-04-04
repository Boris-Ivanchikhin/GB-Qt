
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Связываем сигнал clicked() кнопки с методом QCoreApplication::quit()
    QObject::connect(ui->btnOK, &QPushButton::clicked, &QCoreApplication::quit);

    this->setWindowTitle("Lesson 02. Task 3.");

    create_table();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_table()
{
    // Скрываем колонку с номером строки
    ui->tableWidget->verticalHeader()->setVisible(false);

    // Создаем таблицу со столбцами №, Имя компьютера, IP адрес, MAC адрес
    ui->tableWidget->setColumnCount(4);
    QStringList headers;
    headers << "№" << "Имя компьютера" << "IP адрес" << "MAC адрес";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Заполняем таблицу данными
    QTableWidgetItem *item1 = new QTableWidgetItem("1");
    QTableWidgetItem *item2 = new QTableWidgetItem("Компьютер 1");
    QTableWidgetItem *item3 = new QTableWidgetItem("192.168.0.1");
    QTableWidgetItem *item4 = new QTableWidgetItem("00:11:22:33:44:55");
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setItem(0, 0, item1);
    ui->tableWidget->setItem(0, 1, item2);
    ui->tableWidget->setItem(0, 2, item3);
    ui->tableWidget->setItem(0, 3, item4);

    // Добавляем несколько строк в таблицу
    ui->tableWidget->insertRow(1);
    QTableWidgetItem *item5 = new QTableWidgetItem("2");
    QTableWidgetItem *item6 = new QTableWidgetItem("Компьютер 2");
    QTableWidgetItem *item7 = new QTableWidgetItem("192.168.0.2");
    QTableWidgetItem *item8 = new QTableWidgetItem("AA:BB:CC:DD:EE:FF");
    ui->tableWidget->setItem(1, 0, item5);
    ui->tableWidget->setItem(1, 1, item6);
    ui->tableWidget->setItem(1, 2, item7);
    ui->tableWidget->setItem(1, 3, item8);

    ui->tableWidget->insertRow(2);
    QTableWidgetItem *item9 = new QTableWidgetItem("3");
    QTableWidgetItem *item10 = new QTableWidgetItem("Компьютер 3");
    QTableWidgetItem *item11 = new QTableWidgetItem("192.168.0.3");
    QTableWidgetItem *item12 = new QTableWidgetItem("11:22:33:44:55:66");
    ui->tableWidget->setItem(2, 0, item9);
    ui->tableWidget->setItem(2, 1, item10);
    ui->tableWidget->setItem(2, 2, item11);
    ui->tableWidget->setItem(2, 3, item12);


}


void MainWindow::on_btnColorize_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget->selectedItems();
    foreach (QTableWidgetItem* item, selectedItems)
    {
        auto item_clr = item->background().color();
        auto def_clr = ui->tableWidget->palette().color(QPalette::Base);
        if (item_clr == Qt::yellow)
        {
            item->setBackground(def_clr);
        }
        else
        {
            item->setBackground(Qt::yellow);
        }
    }

    ui->tableWidget->repaint();

}

