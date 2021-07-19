#ifndef HEROPLANE_H
#define HEROPLANE_H
#include<QPixmap>
#include "bullet.h"
#include "config.h"

class HeroPlane
{
public:
    HeroPlane();

    void shoot();//发射子弹
    void setPosition(int x,int y);

    QPixmap m_plane;
    int m_x;
    int m_y;
    QRect m_Rect;//飞机矩形边框

    bullet m_bullets[BULLET_NUM];//弹匣
    int m_recorder;//发射记录
};

#endif // HEROPLANE_H
