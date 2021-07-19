#include "map.h"
#include "config.h"
Map::Map()
{
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);//初始化加载地图对象

    m_map1_posY=-GAME_HEIGHT;
    m_map2_posY=0;

    m_scroll_speed=MAP_SCROLL_SPEED;

}

void Map::mapPosition(){
    m_map1_posY+=MAP_SCROLL_SPEED;
    if(m_map1_posY>=0){
        m_map1_posY=-GAME_HEIGHT;
    }//处理第一张图片滚动
    m_map2_posY+=MAP_SCROLL_SPEED;
    if(m_map2_posY>=GAME_HEIGHT){
        m_map2_posY=0;
    }//处理第二张图片滚动
}
