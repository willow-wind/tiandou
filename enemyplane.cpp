#include "enemyplane.h"
#include "enemyplane.h"
#include "config.h"

enemyplane::enemyplane()
{
    m_enemy.load(ENEMY_PATH);//加载敌机资源
    m_x=0;
    m_y=0;

    m_speed=ENEMY_SPEED;//敌机速度
    m_free=true;//敌机空闲状态
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());//矩形边框，碰撞检测用
    m_Rect.moveTo(m_x,m_y);
}

void enemyplane::updatePosition(){
    if(m_free){
        return;
    }
    m_y+=m_speed;
    m_Rect.moveTo(m_x,m_y);
    if(m_y>=m_Rect.height()+GAME_HEIGHT){
        m_free=true;
    }
}//更新敌机坐标
