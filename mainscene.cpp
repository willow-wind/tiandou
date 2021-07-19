#include "mainscene.h"
#include "ui_mainscene.h"
#include "config.h"
#include <QPainter>
#include <QMouseEvent>
#include <ctime>
#include <QIcon>

#include "bullet.h"
#include "enemyplane.h"

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    initScene();//初始化场景
}

void MainScene::initScene(){
    setWindowIcon(QIcon(GAME_ICON));
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);//初始化窗口大小
    setWindowTitle(GAME_TITLE);//设置窗口标题
    m_Timer.setInterval(GAME_RATE);//设置定时器间隔
    playGame();//启动游戏接口
    m_recorder=0;

    srand((unsigned int)time(NULL));//随机数种子
}
void MainScene::playGame(){
    m_Timer.start();//启动定时器
    connect(&m_Timer,&QTimer::timeout ,[=](){
        enemyToScene();
        updatePosition();//更新游戏中所有元素的坐标
        update();//再调用paintEvent函数
        collisionDection();
    });//监听定时器信号
}

void MainScene::updatePosition(){
    m_map.mapPosition();//更新地图坐标

    m_hero.shoot();

    for(int i=0;i<BULLET_NUM;i++){
        if(m_hero.m_bullets[i].m_free==false){
        m_hero.m_bullets[i].updatePosition();
        }
    }

    for(int i=0;i<ENEMY_NUM;i++){
        if(m_enemys[i].m_free==false){
        m_enemys[i].updatePosition();
        }
    }

    for(int i=0;i<BOMB_NUM;i++){
        if(m_bombs[i].m_free==false){
            m_bombs[i].updateInfo();
        }
    }
    //temp_bullet.m_free=false;//测试子弹
    //temp_bullet.updatePosition();

}

void MainScene::paintEvent(QPaintEvent *event){
    QPainter painter(this);//利用画家画图片

    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);//绘制地图

    painter.drawPixmap(m_hero.m_x,m_hero.m_y,m_hero.m_plane);//绘制英雄飞机

    for(int i=0;i<BULLET_NUM;i++){
        if(m_hero.m_bullets[i].m_free==false){
            painter.drawPixmap(m_hero.m_bullets[i].m_x,m_hero.m_bullets[i].m_y,m_hero.m_bullets[i].m_bullet);
        }
    }

    for(int i=0;i<ENEMY_NUM;i++){
        if(m_enemys[i].m_free==false){
            painter.drawPixmap(m_enemys[i].m_x,m_enemys[i].m_y,m_enemys[i].m_enemy);
        }
    }

    for(int i=0;i<BOMB_NUM;i++){
        if(m_bombs[i].m_free==false){
            painter.drawPixmap(m_bombs[i].m_x,m_bombs[i].m_y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }
    //测试子弹
    //painter.drawPixmap(temp_bullet.m_x,temp_bullet.m_y,temp_bullet.m_bullet);
}

void MainScene::mouseMoveEvent(QMouseEvent *event){
    int x=event->x()-m_hero.m_Rect.width()*0.5;
    int y=event->y()-m_hero.m_Rect.height()*0.5;


    if(x<=0){
        x=0;
    }
    if(x>=GAME_WIDTH-m_hero.m_Rect.width()){
        x=GAME_WIDTH-m_hero.m_Rect.width();
    }
    if(y<=0){
        y=0;
    }
    if(y>=GAME_HEIGHT-m_hero.m_Rect.height()){
        y=GAME_HEIGHT-m_hero.m_Rect.height();
    }
    m_hero.setPosition(x,y);
}

void MainScene::enemyToScene(){
    m_recorder++;//时间间隔计时器，从1数到30
    if(m_recorder<ENEMY_INTERVAL){
        return;
    }
    m_recorder=0;
    for(int i=0;i<BULLET_NUM;i++){
        if(m_enemys[i].m_free){
            m_enemys[i].m_free=false;

            m_enemys[i].m_x=rand()%(GAME_WIDTH-m_enemys[i].m_Rect.width());
            m_enemys[i].m_y=-m_enemys[i].m_Rect.height();
            break;
        }
    }
}

void MainScene::collisionDection(){
    for(int i=0;i<ENEMY_NUM;i++){
        if(m_enemys[i].m_free){
            continue;
        }
        for(int j=0;j<BULLET_NUM;j++){
            if(m_hero.m_bullets[j].m_free){
                continue;
            }
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect)){
                m_enemys[i].m_free=true;
                m_hero.m_bullets[j].m_free=true;

                for(int k=0;k<BOMB_NUM;k++){
                    if(m_bombs[k].m_free){
                        m_bombs[k].m_free=false;

                        m_bombs[k].m_x=m_enemys[i].m_x;
                        m_bombs[k].m_y=m_enemys[i].m_y;

                    }
                }
            }
        }
    }
}//核心：遍历子弹和敌机，使非空闲状态的子弹和敌机碰撞后爆炸

MainScene::~MainScene()
{
    delete ui;
}

