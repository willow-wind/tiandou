#include "bomb.h"
#include"config.h"
#include<QVector>
#include<QPixmap>
bomb::bomb()
{
    for(int i=1;i<=BOMB_MAX;i++){
        QString str=QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }

    m_x=0;
    m_y=0;

    m_free=true;

    m_index=0;

    m_recoder=0;
}

void bomb::updateInfo(){
    if(m_free){
        return;
    }
    m_recoder++;
    if(m_recoder<BOMB_INTERVAL){
        return;
    }
    m_recoder=0;

    m_index++;

    if(m_index>BOMB_MAX-1){
        m_index=0;
        m_free=true;
    }
}
