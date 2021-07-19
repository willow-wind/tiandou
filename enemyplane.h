#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include "config.h"
#include<QPixmap>

class enemyplane
{
public:
    enemyplane();

    void updatePosition();

    QPixmap m_enemy;

    int m_x;
    int m_y;

    int m_speed;//敌机移速

    bool m_free;//敌机是否闲置

    QRect m_Rect;//敌机矩形边框（用于碰撞检测）
};

#endif // ENEMYPLANE_H
