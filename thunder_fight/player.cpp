#include "player.h"
#define PLANE_WIDTH 70
#define PLANE_HEIGHT 100
#define SPEED 5
void player::drawplayer(QPainter &painter)
{
    painter.drawPixmap(x,y,PLANE_WIDTH,PLANE_HEIGHT,*player_img);
}

void player::fire(std::vector<bullet> &Bullet)
{
    bullet *a=new bullet(true,this->x+PLANE_WIDTH/2,this->y);
    Bullet.push_back(*a);
}


void player::move(bool *keypressed,std::vector<bullet> &Bullet)
{
    if(keypressed[0])this->y-=SPEED;
    if(keypressed[1])this->y+=SPEED;
    if(keypressed[2])this->x-=SPEED;
    if(keypressed[3])this->x+=SPEED;
    if(keypressed[4])this->fire(Bullet);
}

bool player::crash(std::vector<bullet>::iterator& Bullet)
{
    if(abs(Bullet->y-(this->y+PLANE_HEIGHT/2))<(PLANE_HEIGHT/2)&&abs(Bullet->x-(this->x+PLANE_WIDTH/2))<(PLANE_WIDTH/2))
    return true;
    else return false;
}
void player::hitted()
{
    this->health--;
}
