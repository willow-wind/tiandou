#include "bullet.h"
#include "config.h"

bullet::bullet()
{
    m_bullet.load(BULLET_PATH);//加载子弹资源
    m_x=GAME_WIDTH*0.5-m_bullet.width()*0.5;
    m_y=GAME_HEIGHT;

    m_speed=BULLET_SPEED;//弹速
    m_free=true;//子弹空闲状态
    m_Rect.setWidth(m_bullet.width());
    m_Rect.setHeight(m_bullet.height());//矩形边框，碰撞检测用
    m_Rect.moveTo(m_x,m_y);
}

void bullet::updatePosition(){
    if(m_free){
        return;
    }
    m_y-=m_speed;
    m_Rect.moveTo(m_x,m_y);
    if(m_y<=-m_Rect.height()){
        m_free=true;
    }
}//更新子弹坐标
