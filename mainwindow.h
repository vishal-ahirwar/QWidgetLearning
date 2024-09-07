#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_b_vity_clicked();

    void on_btn_net_clicked();

    void on_btn_home_clicked();

    void on_b_secure_boot_checkStateChanged(const Qt::CheckState &arg1);

    void on_btn_update_firmware_clicked();

    void on_btn_search_clicked();

    void on_btn_restart_clicked();

    void on_btn_shutdown_clicked();

    void on_btn_logout_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* progress_timer{};
private:
    void worker();
};
#endif // MAINWINDOW_H
