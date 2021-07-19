#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include "map.h"
#include <QTimer>
#include "heroplane.h"

#include "bullet.h"
#include "enemyplane.h"
#include "bomb.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    void initScene();//初始化场景

    QTimer m_Timer;//定时器对象

    //bullet temp_bullet;//测试子弹

    HeroPlane m_hero;//创建飞机对象

    void enemyToScene();//敌机出场
    enemyplane m_enemys[ENEMY_NUM];
    int m_recorder;

    void collisionDection();

    bomb m_bombs[BOMB_NUM];

    void playGame();
    void updatePosition();//更新坐标
    void paintEvent(QPaintEvent *event);//绘图事件
    void mouseMoveEvent(QMouseEvent *event);//重写鼠标移动事件
    Map m_map;//地图对象
private:
    Ui::MainScene *ui;
};



#endif // MAINSCENE_H
