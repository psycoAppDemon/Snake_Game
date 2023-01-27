#include "snake.h"
#define WIDTH 50
#define HEIGHT 25

snake::snake(COORD pos,int vel)
{
    this->pos=pos;
    this->vel=vel;
    len=1;
    direction='n';
    body.push_back(pos);
}

void snake::change_dir(char dir){
    direction=dir;
}

void snake::move_snake(){
    switch(direction){
    case 'u':pos.Y-=vel;break;
    case 'd':pos.Y+=vel;break;
    case 'l':pos.X-=vel;break;
    case 'r':pos.X+=vel;break;
    }

    if(pos.X<1)pos.X=WIDTH-2;
    if(pos.X>WIDTH-2)pos.X=1;
    if(pos.Y<1)pos.Y=HEIGHT-2;
    if(pos.Y>HEIGHT-2)pos.Y=1;

    body.push_back(pos);
    if(body.size()>len)body.pop_front();

}

COORD snake::get_pos(){return pos;}

bool snake::tasted(COORD curtmp){
     if(curtmp.X==pos.X && curtmp.Y==pos.Y)return true;
     return false;
}

bool snake::colloided(){
     if(pos.X<1||pos.X>=WIDTH-1||pos.Y<1||pos.Y>=HEIGHT-1)return true;
     auto stop=body.end();
     --stop;
     for(auto it=body.begin();it!=stop;++it){
        if(pos.Y == (*it).Y && pos.X == (*it).X){
            return true;
        }
     }
     false;
}

list<COORD> snake::getBody(){return body;}

void snake::grow(){len++;}
