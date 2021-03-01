#include "widget.h"
#include "ui_widget.h"
#include<vector>
#include<QLabel>
std::vector<bullet> Bullet;
player *plane;
std::vector<enemy> Enemy;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    plane=new player;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(20);
    QTimer *timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(refresh()));
    timer2->start(20);
    QTimer *timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()), this, SLOT(generate_enemy()));
    timer3->start(2000);
    score=0;
    score_label=new QLabel(this);
    score_label->setGeometry(0,20,100,100);

    score_label->setText(QString::number(score).prepend("score:"));
    hp_label=new QLabel(this);
    hp_label->setGeometry(0,80,100,100);
    hp_label->setText(QString::number(plane->health).prepend("hp:"));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    plane->drawplayer(painter);
    for(int i=0;i<Bullet.size();i++)
    {
        Bullet.at(i).drawbullet(painter);
    }
    for(int i=0;i<Enemy.size();i++)
    {
        Enemy.at(i).drawenemy(painter);
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case 'a':{

    }
    case 'A':{
        keypressed[2]=true;
        break;
    }
    case 'd':{

    }
    case 'D':{
        keypressed[3]=true;
        break;
    }
    case 'w':{

    }
    case 'W':{
        keypressed[0]=true;
        break;
    }
    case 's':{

    }
    case 'S':{
        keypressed[1]=true;
        break;
    }
    case 16777220:
    {
        keypressed[4]=true;
    }

    }

}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case 'a':{

    }
    case 'A':{
        keypressed[2]=false;
        break;
    }
    case 'd':{

    }
    case 'D':{
        keypressed[3]=false;
        break;
    }
    case 'w':{

    }
    case 'W':{
        keypressed[0]=false;
        break;
    }
    case 's':{

    }
    case 'S':{
        keypressed[1]=false;
        break;
    }
    case 16777220:
    {
        keypressed[4]=false;
    }

    }
}

void Widget::refresh()
{
    plane->move(keypressed,Bullet);
    for(int i=0;i<Bullet.size();i++)
    {
        Bullet.at(i).refresh();
    }
    detect_crash();
    enemy_AI();
    if(plane->health<0)exit(0);
}

void Widget::generate_enemy()
{
    if(Enemy.size()<5){
        enemy *a=new enemy();
        Enemy.push_back(*a);
    }

    std::vector<bullet>(Bullet).swap(Bullet);//释放rease的内存
}

void Widget::detect_crash()
{
    int flag;
    for(int i=0;i<Bullet.size();i++)
    if(Bullet.at(i).y<0)Bullet.erase(Bullet.begin()+i);
    for(int j=0;j<Enemy.size();j++)
    {
        if(Enemy.at(j).health<0){
            Enemy.erase(Enemy.begin()+j);
            score++;
            score_label->setText(QString::number(score).prepend("score:"));
        }
    }
    for(std::vector<bullet>::iterator i=Bullet.begin();i!=Bullet.end();)
    {
        flag=0;
        if(i->is_my)
        {
            for(int j=0;j<Enemy.size();j++)
            {
                if(Enemy.at(j).crash(i))
                {
                    Enemy.at(j).hitted();
                    i=Bullet.erase(i);
                    flag=1;
                    break;
                }

            }

        }
        else{
            if(plane->crash(i))
            {
                plane->hitted();
                i=Bullet.erase(i);
                flag=1;
                hp_label->setText(QString::number(plane->health).prepend("hp:"));
            }
        }
        if(flag==0)i++;
    }


}

void Widget::enemy_AI()
{
    for(int i=0;i<Enemy.size();i++)
    {
        Enemy.at(i).AI(*plane,Bullet);
    }
}
