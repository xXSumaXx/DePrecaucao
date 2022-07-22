#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "sculptor.h"
#include <QDebug>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    artista = new Sculptor(50,50,50);
    emit ligaArtista(artista);

    connect(ui->Cubo,
            SIGNAL(clicked(bool)),
            this,
            SLOT(setT()));
    connect(ui->noCubo,
            SIGNAL(clicked(bool)),
            this,
            SLOT(noSet()));
    connect(ui->Elipsoide,
            SIGNAL(clicked(bool)),
            this,
            SLOT(setT()));
    connect(ui->noElipsoide,
            SIGNAL(clicked(bool)),
            this,
            SLOT(noSet()));
    connect(ui->Esfera,
            SIGNAL(clicked(bool)),
            this,
            SLOT(setT()));
    connect(ui->noEsfera,
            SIGNAL(clicked(bool)),
            this,
            SLOT(noSet()));
}

MainWindow::~MainWindow(){
    artista->writeOFF("Arroz.off");
    delete ui;
}

void MainWindow::setT(){
    artista->valorT(1);

}

void MainWindow::noSet(){
    artista->valorT(0);
}

void MainWindow::Cubo(){
    //Sculptor::putEllipsoid();
}

void MainWindow::noCubo(){
    //Sculptor::cutEllipsoid();
}

void MainWindow::Elipsoide(){
    //Sculptor::putEllipsoid();
}

void MainWindow::noElipsoide(){
    //Sculptor::cutEllipsoid();
}

void MainWindow::Esfera(){
    //Sculptor::putSphere();
}

void MainWindow::noEsfera(){
    //Sculptor::cutSphere();
}

void MainWindow::on_corR_valueChanged(int value){
    ui->lcdR->display(value);
    qDebug()<<value;
    artista->valorR(value/255.0);
    ui->tela->setValorR(value);
}

void MainWindow::on_corG_valueChanged(int value){
    ui->lcdG->display(value);
    artista->valorG(value/255.0);
    ui->tela->setValorG(value);
}

void MainWindow::on_corB_valueChanged(int value){
    ui->lcdB->display(value);
    artista->valorB(value/255.0);
    ui->tela->setValorB(value);
}

void MainWindow::on_xC_valueChanged(int value){
    ui->Dx->display(value);
}

void MainWindow::on_yC_valueChanged(int value){
    ui->Dy->display(value);
}

void MainWindow::on_zC_valueChanged(int value){
    ui->Dz->display(value);
}

void MainWindow::on_rX_valueChanged(int value){
    ui->lcdRx->display(value);
}

void MainWindow::on_rY_valueChanged(int value){
    ui->lcdRy->display(value);
}

void MainWindow::on_rZ_valueChanged(int value){
    ui->lcdRz->display(value);
}

void MainWindow::on_raio_valueChanged(int value){
    ui->raio_2->display(value);
}

