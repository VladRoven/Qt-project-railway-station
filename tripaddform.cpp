#include "tripaddform.h"
#include "ui_tripaddform.h"
#include <QDebug>
#include <QMessageBox>

TripAddForm::TripAddForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TripAddForm)
{
    ui->setupUi(this);
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

TripAddForm::~TripAddForm()
{
    delete ui;
}

void TripAddForm::setModel(QStandardItemModel *model)
{
    mapper->clearMapping();
    mapper->setModel(model);
}

void TripAddForm::on_btn_accept_clicked()
{
    QString error = "";
    QRegExp trip_name_reg("([А-Я][а-я]+)-([А-Я][а-я]+)");
    if (!trip_name_reg.exactMatch(ui->trip_name->text()))
        error += "Корректно введите имя!\n";

    if (ui->date_from->date() >= ui->date_to->date())
        error += "Дата отправления не может быть меньше/равна даты прибытия!\n";

    if (error.length())
    {
        QMessageBox *msg = new QMessageBox();
        msg->setIcon(QMessageBox::Warning);
        msg->setWindowTitle("Ошибка");
        msg->setInformativeText(error);
        msg->addButton("Понял", QMessageBox::AcceptRole);
        msg->exec();
    }
    else
    {
        mapper->model()->insertRow(mapper->model()->rowCount());
        mapper->setCurrentModelIndex(mapper->model()->index(mapper->model()->rowCount() - 1, 0));

        mapper->addMapping(ui->trip_name, 0);
        mapper->addMapping(ui->date_from, 1);
        mapper->addMapping(ui->date_to, 2);
        mapper->addMapping(ui->count_wagons, 3);
        mapper->addMapping(ui->count_stop, 4);
        mapper->addMapping(ui->count_tickets, 5);
        mapper->addMapping(ui->count_tickets_sale, 6);

        mapper->submit();

        ui->trip_name->clear();
        ui->date_from->clear();
        ui->date_to->clear();
        ui->count_wagons->setValue(0);
        ui->count_stop->setValue(0);
        ui->count_tickets->setValue(0);
        close();
    }
}

void TripAddForm::on_btn_cancle_clicked()
{
    close();
}
