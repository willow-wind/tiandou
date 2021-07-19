#ifndef CONFIG_H
#define CONFIG_H

#define GAME_ICON ":/res/bomb.png"
#define GAME_WIDTH 480//宽度
#define GAME_HEIGHT 700//高度
#define GAME_TITLE "AirwarV1.0"//标题
#define MAP_PATH ":/res/background.png"//地图图片路径
#define MAP_SCROLL_SPEED 2//地图滚动速度
#define GAME_RATE 10//刷新间隔，帧率单位：毫秒

#define HERO_PATH ":/res/life.png" //英雄飞机

#define BULLET_NUM 30//弹夹容量
#define BULLET_INTERVAL 20//子弹发射时间间隔
#define BULLET_PATH ":/res/WPS图片-修改尺寸.png" //子弹图片路径
#define BULLET_SPEED 5 //子弹移动速度

#define ENEMY_PATH ":/res/enemy2.png" //敌机图片路径
#define ENEMY_SPEED 3//敌机移动速度
#define ENEMY_NUM 20
#define ENEMY_INTERVAL 60//敌机出场时间间隔

#define BOMB_PATH ":/res/enemy2_down%1.png"
#define BOMB_NUM 20 //爆炸数量
#define BOMB_MAX 4 //爆炸最大图片数量
#define BOMB_INTERVAL 20 //爆炸切图时间间隔

#endif // CONFIG_H

