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

    void on_btn_search_client_clicked();

    void on_search_client_textChanged(const QString &arg1);

    void on_search_trip_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QFileInfo file_info;
    QStandardItemModel *model_trip = new QStandardItemModel;
    QStandardItemModel *model_client = new QStandardItemModel;
    QJsonDocument json_doc;
    QList<QStandardItem *> client_list;
    QList<QStandardItem *> trip_list;
};
#endif // MAINWINDOW_H
