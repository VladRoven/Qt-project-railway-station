#include "tripeditform.h"
#include "ui_tripeditform.h"

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
    mapper->submit();
    close();
}

void TripEditForm::on_btn_cancle_clicked()
{
    close();
}
