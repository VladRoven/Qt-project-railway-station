#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QMap>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_file_triggered()
{
    QString openFileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), QString(), tr("JSON (*.json)"));
    model_trip->clear();
    model_client->clear();
    file_info = openFileName;
    QFile jsonFile(openFileName);

    if (!jsonFile.open(QIODevice::ReadOnly))
    {
        return;
    }

    QByteArray saveData = jsonFile.readAll();
    json_doc = QJsonDocument::fromJson(saveData);
    QStringList horizontalHeader;
    horizontalHeader.append({"Рейс", "Отправление", "Прибытие", "Кол-во вагонов", "Остановок", "Билетов всего", "Билетов продано"});

    model_trip->setHorizontalHeaderLabels(horizontalHeader);

    horizontalHeader.clear();
    horizontalHeader.append({"Фамилия", "Имя", "Номер билета", "Рейс"});
    model_client->setHorizontalHeaderLabels(horizontalHeader);

    ui->table_trip->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table_client->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QJsonArray temp_array = json_doc.array();
    QMap<QString, QVariant> temp_map;
    QMap<QString, QVariant> temp_client_map;
    QList<QStandardItem *> temp_list;
    QList<QStandardItem *> temp_list_client;
    QString current_trip;
    int current_count_client;

    for (int i = 0; i < json_doc.array().count(); i++)
    {
        temp_map = temp_array[i].toVariant().toMap();
        temp_list.clear();
        for (QVariant var : temp_map)
        {
            if (var.toString().contains('-'))
                current_trip = var.toString();
            if (var.toJsonArray().size())
            {
                current_count_client = var.toJsonArray().size();
                for (int j = 0; j < var.toJsonArray().size(); j++)
                {
                    temp_list_client.clear();
                    temp_client_map = var.toJsonArray()[j].toVariant().toMap();
                    for (QVariant var_sec : temp_client_map)
                    {
                        temp_list_client.append(new QStandardItem(var_sec.toString()));
                    }
                    temp_list_client.append(new QStandardItem(current_trip));
                    model_client->insertRow(j, temp_list_client);
                }
            }
            else
                temp_list.append(new QStandardItem(var.toString()));
        }
        temp_list.append(new QStandardItem(QString::number(current_count_client)));
        current_count_client = 0;
        model_trip->insertRow(i, temp_list);
    }
    ui->table_trip->setModel(model_trip);
    ui->table_client->setModel(model_client);
}
