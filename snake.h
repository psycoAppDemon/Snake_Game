#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <list>
using namespace std;
class snake
{
    private:
        COORD pos;
        int vel;
        char direction;
        int len;
        list<COORD> body;
    public:

        snake(COORD pos,int vel);
        void change_dir(char dir);
        void move_snake();
        COORD get_pos();
        bool tasted(COORD pos);
        void grow();
        bool colloided();
        list<COORD> getBody();
};

#endif // SNAKE_H
