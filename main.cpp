#include <iostream>
#include <conio.h>
#include "snake.h"
#include "Food.h"
#include <ctime>
using namespace std;

#define sq(x) x*x
#define WIDTH 50
#define HEIGHT 25

int x=10,y=10;

snake obj({WIDTH/2,HEIGHT/2},1);
Food food;
int score=0;

void board(){
    COORD snake_pos = obj.get_pos();
    COORD food_pos = food.get_pos();

    list<COORD> snake_body=obj.getBody();
    cout<<"\t\tSCORE:"<<score<<'\n';
    for(int i=0;i<HEIGHT;i++){
        cout<<"\t\t#";
        for(int j=0;j<WIDTH-2;j++){
            if(i==0 || i== HEIGHT-1)cout<<"#";
            else if(i==snake_pos.Y && snake_pos.X==j+1)cout<<"0";
            else if(i==food_pos.Y && food_pos.X==j+1)cout<<"@";
            else {
                bool isBodyPart=false;
                auto stop=snake_body.end();
                --stop;
                for(auto it=snake_body.begin();it!=stop;++it){
                    if(i == (*it).Y && j+1 == (*it).X){
                        cout<<'0';
                        isBodyPart=true;
                        break;
                    }
                }
                if(!isBodyPart)cout<<' ';
            }
        }
        cout<<"#\n";
    }
}

int main()
{
    srand(time(NULL));// controller to rand()
    food.gen_food();
    bool game_over=false;
    while(!game_over){
      board();

      if(kbhit()){
        switch(getch()){
            case 'w':obj.change_dir('u');break;
            case 's':obj.change_dir('d');break;
            case 'a':obj.change_dir('l');break;
            case 'd':obj.change_dir('r');break;
        }
      }
      if(obj.colloided())game_over=true;
      if(obj.tasted(food.get_pos()))
      {
          food.gen_food();
          score++;
          obj.grow();
      }
      obj.move_snake();
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
    }

    return 0;
}
