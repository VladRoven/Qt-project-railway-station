#include "clientaddform.h"
#include "ui_clientaddform.h"

#include <QMessageBox>

ClientAddForm::ClientAddForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientAddForm)
{
    ui->setupUi(this);
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

ClientAddForm::~ClientAddForm()
{
    delete ui;
}

void ClientAddForm::setModel(QStandardItemModel *model)
{
    mapper->clearMapping();
    mapper->setModel(model);
}

void ClientAddForm::setComboBox(const QStringList list)
{
    ui->client_trip->clear();
    ui->client_trip->addItems(list);
}

void ClientAddForm::on_btn_accept_clicked()
{
    QString error = "";
    QRegExp client_name_surname_reg("([А-Я][а-яё]+)");
    QRegExp client_ticket("([А-ЯЁ]){2,2}([\\d]){6,6}([А-ЯЁ]){2,2}");
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
        mapper->model()->insertRow(mapper->model()->rowCount());
        mapper->setCurrentModelIndex(mapper->model()->index(mapper->model()->rowCount() - 1, 0));

        mapper->addMapping(ui->client_surname, 0);
        mapper->addMapping(ui->client_name, 1);
        mapper->addMapping(ui->client_ticket, 2);
        mapper->addMapping(ui->client_trip, 3);

        mapper->submit();

        close();
        emit add_count_ticket_sale(ui->client_trip->currentText());

        ui->client_surname->clear();
        ui->client_name->clear();
        ui->client_ticket->clear();
    }
}

void ClientAddForm::on_btn_cancle_clicked()
{
    close();
}
