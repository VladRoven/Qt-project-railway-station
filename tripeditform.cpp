#include "tripeditform.h"
#include "ui_tripeditform.h"

#include <QMessageBox>

TripEditForm::TripEditForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TripEditForm)
{
    ui->setupUi(this);

    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

TripEditForm::~TripEditForm()
{
    delete ui;
}

void TripEditForm::setModel(QAbstractItemModel *model)
{
    mapper->setModel(model);
    mapper->addMapping(ui->trip_name, 0);
    mapper->addMapping(ui->date_from, 1);
    mapper->addMapping(ui->date_to, 2);
    mapper->addMapping(ui->count_wagons, 3);
    mapper->addMapping(ui->count_stop, 4);
    mapper->addMapping(ui->count_tickets, 5);
}

void TripEditForm::on_btn_accept_clicked()
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
        mapper->submit();
        close();
    }
}

void TripEditForm::on_btn_cancle_clicked()
{
    close();
}
