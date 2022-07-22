#ifndef FOLHA_H
#define FOLHA_H

#include <QWidget>
#include "sculptor.h"

struct Cores{
    int r, g, b, t;
    int x, y, z;
};

class Folha:public QWidget{
    Q_OBJECT
public:
    std::vector<Cores> Cores;
    Sculptor *artista2;
    int r=0, g=0, b=0;
    int z=1;
    explicit Folha(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);//constroi a matriz
    void mousePressEvent(QMouseEvent *evClick);//verifica se foi clicado
    void mouseReleaseEvent(QMouseEvent *evArrast);//verifica se o mouse foi arrastado
    void mouseMoveEvent(QMouseEvent *evMov);//verifica se movel
    void draw(int x, int y);//captura a posição xy da matriz

public slots:
    void setValorZ(int z);//seta os valores z
    void setValorR(int r);
    void setValorG(int g);
    void setValorB(int b);
    void recebeArt(Sculptor *a);//função pra receber sinais de widget e modifica o Sculptor

signals:

private:
    std::string estado;
    bool clicou;
};

#endif // FOLHA_H
