#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sculptor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    Sculptor *artista;

public slots:
    void Cubo();//Responsavel por setar a geometria do cupo
    void noCubo();//Responsavel por retirar a geometria do cupo
    void Elipsoide();
    void noElipsoide();
    void Esfera();
    void noEsfera();

private slots:
    void on_corR_valueChanged(int value);//recebe os valores do slide da com red
    void on_corG_valueChanged(int value);//green
    void on_corB_valueChanged(int value);//blue
    void on_xC_valueChanged(int value);//dimensão x do cubo
    void on_yC_valueChanged(int value);
    void on_zC_valueChanged(int value);
    void on_rX_valueChanged(int value);//dimensão x do slipse
    void on_rY_valueChanged(int value);
    void on_rZ_valueChanged(int value);
    void on_raio_valueChanged(int value);//raio da esfera
    void setT();//seta a transparencia
    void noSet();//deseta a transparencia

private:
    Ui::MainWindow *ui;

signals:
    void ligaArtista(Sculptor *artista);//Manda as modificações para a variavel da clase Sculptor
};

#endif // MAINWINDOW_H
