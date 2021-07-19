#include "heroplane.h"
#include "config.h"

HeroPlane::HeroPlane()
{
    m_plane.load(HERO_PATH);//加载飞机图片资源

    m_x=GAME_WIDTH*0.5-m_plane.width()*0.5;
    m_y=GAME_HEIGHT-m_plane.height()-15;//初始化坐标

    m_Rect.setWidth(m_plane.width());
    m_Rect.setHeight(m_plane.height());//矩形边框，碰撞检测用
    m_Rect.moveTo(m_x,m_y);

    m_recorder=0;//初始化 间隔记录变量
}

void HeroPlane::shoot(){
    m_recorder++;//时间间隔计时器，从1数到20
    if(m_recorder<BULLET_INTERVAL){
        return;
    }
    m_recorder=0;//计时器置零，便于下一发子弹的计时
    for(int i=0;i<BULLET_NUM;i++){
        if(m_bullets[i].m_free){
            m_bullets[i].m_free=false;

            m_bullets[i].m_x=m_x+m_Rect.width()*0.5-3;
            m_bullets[i].m_y=m_y;
            break;
        }
    }
}

void HeroPlane::setPosition(int x, int y){
    m_x=x;
    m_y=y;
    m_Rect.moveTo(m_x,m_y);
}
