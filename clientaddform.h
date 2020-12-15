#ifndef CLIENTADDFORM_H
#define CLIENTADDFORM_H

#include <QDataWidgetMapper>
#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class ClientAddForm;
}

class ClientAddForm : public QWidget
{
    Q_OBJECT

public:
    explicit ClientAddForm(QWidget *parent = nullptr);
    ~ClientAddForm();

    void setModel(QStandardItemModel *model);
    void setComboBox(const QStringList list);
signals:
    void add_count_ticket_sale(QString str);

private slots:
    void on_btn_accept_clicked();
    void on_btn_cancle_clicked();

private:
    Ui::ClientAddForm *ui;
    QDataWidgetMapper *mapper;
};

#endif // CLIENTADDFORM_H
