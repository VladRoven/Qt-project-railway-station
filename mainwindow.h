#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QStandardItemModel>
#include <QJsonDocument>
#include "tripeditform.h"
#include "clienteditform.h"
#include "tripaddform.h"
#include "clientaddform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void add_count_ticket_sale(QString trip);
    void del_count_ticket_sale(QString trip);
    void edit_count_ticket_sale(QString old_trip, QString new_trip);

    void on_open_file_triggered();

    void on_search_client_textChanged(const QString &arg1);

    void on_search_trip_textChanged(const QString &arg1);

    void on_btn_set_filter_clicked();

    void on_btn_drop_filter_clicked();

    void on_save_file_triggered();

    void on_save_file_as_triggered();

    void on_search_ticket_textChanged(const QString &arg1);

    void on_table_trip_doubleClicked(const QModelIndex &index);

    void on_table_client_doubleClicked(const QModelIndex &index);

    void on_btn_del_trip_clicked();

    void on_btn_del_client_clicked();

    void on_btn_add_trip_clicked();

    void on_btn_add_client_clicked();

    void on_new_file_triggered();

    void on_to_excel_triggered();

private:
    Ui::MainWindow *ui;
    QFileInfo file_info;
    QStandardItemModel *model_trip = new QStandardItemModel;
    QStandardItemModel *model_client = new QStandardItemModel;
    TripEditForm *edit_trip;
    ClientEditForm *edit_client;
    TripAddForm *add_trip;
    ClientAddForm *add_client;
};
#endif // MAINWINDOW_H
