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

    void setModel(QAbstractItemModel *model);
    QDataWidgetMapper *mapper;

private slots:
    void on_btn_accept_clicked();

    void on_btn_cancle_clicked();

private:
    Ui::TripEditForm *ui;
};

#endif // TRIPEDITFORM_H
