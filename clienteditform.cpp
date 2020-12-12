#include "clienteditform.h"
#include "ui_clienteditform.h"

ClientEditForm::ClientEditForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientEditForm)
{
    ui->setupUi(this);

    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

ClientEditForm::~ClientEditForm()
{
    delete ui;
}

void ClientEditForm::setModel(QAbstractItemModel *model)
{
    mapper->setModel(model);
    mapper->addMapping(ui->client_surname, 0);
    mapper->addMapping(ui->client_name, 1);
    mapper->addMapping(ui->client_ticket, 2);
    mapper->addMapping(ui->client_trip, 3);
}

void ClientEditForm::setComboBox(const QStringList list)
{
    ui->client_trip->clear();
    ui->client_trip->addItems(list);
}

void ClientEditForm::on_btn_accept_clicked()
{
    mapper->submit();
    close();
}

void ClientEditForm::on_btn_cancle_clicked()
{
    close();
}
