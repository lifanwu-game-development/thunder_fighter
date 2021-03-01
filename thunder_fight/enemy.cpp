#include<enemy.h>

#define ENEMY_WIDTH 70
#define ENEMY_HEIGHT 100
#define ENEMY_SPEED 1
void enemy::drawenemy(QPainter &painter)
{
    painter.drawPixmap(x,y,ENEMY_WIDTH,ENEMY_HEIGHT,*enemy_img);
}

void enemy::fire(std::vector<bullet> &Bullet)
{
    if(cd){
        cd--;
        return;
    }

    bullet *a=new bullet(false,this->x+ENEMY_WIDTH/2,this->y);
    Bullet.push_back(*a);
    cd=50;
}

bool enemy::crash(std::vector<bullet>::iterator& Bullet)
{
    if(abs(Bullet->y-(this->y+ENEMY_HEIGHT/2))<(ENEMY_HEIGHT/2)&&abs(Bullet->x-(this->x+ENEMY_WIDTH/2))<(ENEMY_WIDTH/2))
    return true;
    else return false;
}

void enemy::hitted()
{
    this->health--;
}

void enemy::AI(player &plane,std::vector<bullet> &Bullet)
{
    if(abs(plane.x-this->x)<ENEMY_WIDTH/2)this->fire(Bullet);
    else if(plane.x>this->x)this->x+=ENEMY_SPEED;
    else this->x-=ENEMY_SPEED;

}
