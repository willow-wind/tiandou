#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include<QPixmap>

class bullet
{
public:
    bullet();

    void updatePosition();

    QPixmap m_bullet;

    int m_x;
    int m_y;

    int m_speed;//子弹移速

    bool m_free;//子弹是否闲置

    QRect m_Rect;//子弹矩形边框（用于碰撞检测）
};


#endif // BULLET_H
