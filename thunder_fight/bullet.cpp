#include"bullet.h"

#define BULLET_SPEED 3

bullet::bullet(bool is_my,int x,int y)
{
    this->is_my=is_my;
    this->x=x;
    this->y=y;
}




void bullet::drawbullet(QPainter &painter)
{
    painter.drawLine(QPoint(this->x,this->y),QPoint(this->x,this->y-10));
}

void bullet::refresh()
{
    if(this->is_my)this->y-=BULLET_SPEED;
    else this->y+=BULLET_SPEED;
}
