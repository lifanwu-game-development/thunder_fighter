#ifndef PLAYER_H
#define PLAYER_H
#include<QPainter>
#include<bullet.h>
class player{
public:
    int x,y;
    int health;
    QPixmap *player_img;
    player()
    {
        x=100;
        y=100;
        player_img=new QPixmap(":/img/player.png");
        health=20;
    }

    void drawplayer(QPainter &painter);
    void fire(std::vector<bullet> &Bullet);
    void move(bool keypressed[],std::vector<bullet> &Bullet);
    bool crash(std::vector<bullet>::iterator& Bullet);
    void hitted();
};



#endif // PLAYER_H
