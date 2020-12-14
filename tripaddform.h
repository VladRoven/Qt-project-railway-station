#ifndef TRIPADDFORM_H
#define TRIPADDFORM_H

#include <QMainWindow>
#include <QDataWidgetMapper>
#include <QStandardItemModel>

namespace Ui {
class TripAddForm;
}

class TripAddForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit TripAddForm(QWidget *parent = nullptr);
    ~TripAddForm();

    void setModel(QStandardItemModel *model);
private slots:
    void on_btn_accept_clicked();

    void on_btn_cancle_clicked();

private:
    Ui::TripAddForm *ui;
    QDataWidgetMapper *mapper;
};

#endif // TRIPADDFORM_H
