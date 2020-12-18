#ifndef TRIPEDITFORM_H
#define TRIPEDITFORM_H

#include <QMainWindow>
#include <QDataWidgetMapper>

namespace Ui {
class TripEditForm;
}

class TripEditForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit TripEditForm(QWidget *parent = nullptr);
    ~TripEditForm();

    void setModel(QAbstractItemModel *model, QString old_trip);
    QDataWidgetMapper *mapper;

signals:
    void edit_client_trip(QString old_trip, QString new_trip);

private slots:
    void on_btn_accept_clicked();

    void on_btn_cancle_clicked();

private:
    Ui::TripEditForm *ui;
    QString old_trip;
};

#endif // TRIPEDITFORM_H
