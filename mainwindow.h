#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QStandardItemModel>
#include <QJsonDocument>

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
    void on_open_file_triggered();

    void on_search_client_textChanged(const QString &arg1);

    void on_search_trip_textChanged(const QString &arg1);

    void on_btn_set_filter_clicked();

    void on_btn_drop_filter_clicked();

    void on_save_file_triggered();

    void on_save_file_as_triggered();

    void on_search_ticket_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QFileInfo file_info;
    QStandardItemModel *model_trip = new QStandardItemModel;
    QStandardItemModel *model_client = new QStandardItemModel;
};
#endif // MAINWINDOW_H
