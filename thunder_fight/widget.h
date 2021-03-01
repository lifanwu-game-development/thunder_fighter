#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPainter>
#include<QKeyEvent>
#include<QDebug>
#include<QTimer>
#include<vector>
#include<bullet.h>
#include<player.h>
#include<enemy.h>
#include<QLabel>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent*)override;
    void keyPressEvent(QKeyEvent *event)override;
    void keyReleaseEvent(QKeyEvent *event)override;

public:
    bool keypressed[5]={0};
    int score;
    QLabel *score_label,*hp_label;
public slots:
    void generate_enemy();
    void refresh();
    void detect_crash();
    void enemy_AI();

private:
    Ui::Widget *ui;
};


#endif // WIDGET_H
