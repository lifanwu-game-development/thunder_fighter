#ifndef BULLET_H
#define BULLET_H
#include<QPainter>

class bullet{
public:
    int x,y;
    bool is_my;

    bullet(bool is_my,int x,int y);

    void drawbullet(QPainter &painter);
    void refresh();


};



#endif // BULLET_H
