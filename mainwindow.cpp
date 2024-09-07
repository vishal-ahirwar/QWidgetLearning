#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QTimer>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    progress_timer =new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete progress_timer;
    delete ui;
}

void MainWindow::on_b_vity_clicked()
{

}


void MainWindow::on_btn_net_clicked()
{

}


void MainWindow::on_btn_home_clicked()
{

}


void MainWindow::on_b_secure_boot_checkStateChanged(const Qt::CheckState &arg1)
{

}


void MainWindow::on_btn_update_firmware_clicked()
{
    if(progress_timer->isActive())return;
    ui->progress_bar->setValue(0);
    progress_timer->setInterval(1000);
    progress_timer->setSingleShot(false);
    connect(progress_timer,&QTimer::timeout,this,[&](){
        ui->progress_bar->setValue(ui->progress_bar->value()+2*rand()%10+1);
        qDebug()<<ui->progress_bar->value()<<"\n";
        if(ui->progress_bar->value()>=100)
        {
            progress_timer->stop();
        }
    }
);
    progress_timer->start();
    if(progress_timer->isActive())qDebug()<<"Yes";
    qDebug()<<"updating firmware...";
}


void MainWindow::on_btn_search_clicked()
{

}


void MainWindow::on_btn_restart_clicked()
{

}


void MainWindow::on_btn_shutdown_clicked()
{
    auto res=QMessageBox::question(this,"Shutdown!","do you really want to shutdown?");
    if(res==QMessageBox::Yes)
    QApplication::quit();
}


void MainWindow::on_btn_logout_clicked()
{

}

