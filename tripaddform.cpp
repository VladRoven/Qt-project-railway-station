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
    ui->count_tickets_sale->setValue(0);
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

        close();

        QString strValue = "2020-01-01T00:00:00.000";
        QString format = "yyyy-MM-ddTHH:mm:ss.zzz";
        QDateTime dt = QDateTime :: fromString (strValue, format);

        ui->trip_name->clear();
        ui->date_from->setDateTime(dt);
        ui->date_to->setDateTime(dt);
        ui->count_wagons->setValue(7);
        ui->count_stop->setValue(4);
        ui->count_tickets->setValue(120);
    }
}

void TripAddForm::on_btn_cancle_clicked()
{
    close();
}
