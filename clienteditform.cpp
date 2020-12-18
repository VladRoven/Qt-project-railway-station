#include "clienteditform.h"
#include "ui_clienteditform.h"

#include <QMessageBox>

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

void ClientEditForm::setModel(QAbstractItemModel *model, QString old_trip)
{
    mapper->setModel(model);
    mapper->addMapping(ui->client_surname, 0);
    mapper->addMapping(ui->client_name, 1);
    mapper->addMapping(ui->client_ticket, 2);
    mapper->addMapping(ui->client_trip, 3);
    this->old_trip = old_trip;
}

void ClientEditForm::setComboBox(const QStringList list)
{
    ui->client_trip->clear();
    ui->client_trip->addItems(list);
}

void ClientEditForm::on_btn_accept_clicked()
{
    QString error = "";
    QRegExp client_name_surname_reg("([А-Я][а-яё]+)");
    QRegExp client_ticket("([А-Я]){2,2}([\\d]){6,6}([А-Я]){2,2}");
    if (!client_name_surname_reg.exactMatch(ui->client_surname->text()))
        error += "Корректно введите фамилию!\n";

    if (!client_name_surname_reg.exactMatch(ui->client_name->text()))
        error += "Корректно введите имя!\n";

    if (!client_ticket.exactMatch(ui->client_ticket->text()))
        error += "Корректно введите номер билета!\n";

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
        emit edit_count_ticket_sale(old_trip, ui->client_trip->currentText());
        close();
    }
}

void ClientEditForm::on_btn_cancle_clicked()
{
    close();
}
