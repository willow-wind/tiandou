#ifndef BOMB_H
#define BOMB_H
#include "config.h"
#include<QPixmap>
#include<QVector>

class bomb
{
public:
    bomb();

    void updateInfo();

    QVector<QPixmap> m_pixArr;

    int m_x;
    int m_y;

    bool m_free;

    int m_recoder;//爆炸切图时间间隔

    int m_index;//爆炸时加载的图片下标
};



#endif // BOMB_H
