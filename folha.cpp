#include "folha.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QMouseEvent>
#include <stdio.h>

Folha::Folha(QWidget *parent) : QWidget{parent}{
    clicou = false;
}

void Folha::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0,0,0));
    pen.setWidth(1);

    painter.setBrush(brush);
    painter.setPen(pen);

    painter.drawRect(0,0,431,431);

    for(int i=0; i<431; i=i+10){
        for(int j=0; j<431; j=j+10){
            painter.drawRect(i,j,10,10);
        }
    }

    for(int x = 0; x < this->Cores.size();x++){
        if(Cores[x].z == this->z){
            pen.setColor(QColor(Cores[x].r,Cores[x].g,Cores[x].b));
            brush.setColor(QColor(Cores[x].r,Cores[x].g,Cores[x].b));
            brush.setStyle(Qt::SolidPattern);
            painter.setPen(pen);
            painter.setBrush(brush);
            painter.drawRect((float) Cores[x].x*10+2.5,(float)Cores[x].y*10+2.5,7,7);
            artista2->setColor(Cores[x].r/255.0,Cores[x].g/255.0,Cores[x].b/255.0,1);
            artista2->putVoxel(Cores[x].x,Cores[x].y,Cores[x].z);
        }
    }
}

void Folha::mousePressEvent(QMouseEvent *evClick){
    clicou = true;
    if(evClick->x() < 450 && evClick->y() <450){
        draw(evClick->x(),evClick->y());
    }
}

void Folha::mouseReleaseEvent(QMouseEvent *evArrast){
    clicou = false;
}

void Folha::mouseMoveEvent(QMouseEvent *evMov){
    if((evMov->x() < 450 && evMov->y() <450) && clicou){
        draw(evMov->x(),evMov->y());
    }
}

void Folha::draw(int x, int y){
    struct Cores o;
    o.b = this->b;
    o.g = this->g;
    o.r = this->r;
    o.x = x/10;
    o.y = y/10;
    o.z = this->z;
    this->Cores.push_back(o);
    repaint();
}

void Folha::setValorZ(int z_){
    this->z=z_;
    repaint();
}

void Folha::setValorR(int r_){
    this->r=r_;
}

void Folha::setValorG(int g_){
    this->g=g_;
}

void Folha::setValorB(int b_){
    this->b=b_;
}

void Folha::recebeArt(Sculptor *a){
    artista2 = a;
}
