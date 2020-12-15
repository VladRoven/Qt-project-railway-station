#ifndef CLIENTEDITFORM_H
#define CLIENTEDITFORM_H

#include <QAbstractItemModel>
#include <QDataWidgetMapper>
#include <QMainWindow>

namespace Ui {
class ClientEditForm;
}

class ClientEditForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientEditForm(QWidget *parent = nullptr);
    ~ClientEditForm();

    void setModel(QAbstractItemModel *model, QString old_trip);
    void setComboBox(const QStringList list);
    QDataWidgetMapper *mapper;

signals:
    void edit_count_ticket_sale(QString old_trip, QString new_trip);

private slots:
    void on_btn_accept_clicked();

    void on_btn_cancle_clicked();

private:
    Ui::ClientEditForm *ui;
    QString old_trip;
};

#endif // CLIENTEDITFORM_H
