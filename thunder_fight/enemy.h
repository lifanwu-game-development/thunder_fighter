#ifndef ENEMY_H
#define ENEMY_H
#include<QPainter>
#include<bullet.h>
#include<stdlib.h>
#include<player.h>
class enemy{
public:
    int x,y;
    int health;
    int cd;
    QPixmap *enemy_img=new QPixmap(":/img/enemy.png");
    enemy()
    {
        x=rand()%700;
        y=60;
        health=30;
        cd=0;
    }

    void drawenemy(QPainter &painter);
    void fire(std::vector<bullet> &Bullet);
    bool crash(std::vector<bullet>::iterator& Bullet);
    void hitted();
    void AI(player &plane,std::vector<bullet> &Bullet);
};



#endif // ENEMY_H
