#include "Food.h"
#include<cstdlib>
#include <windows.h>
#define WIDTH 50
#define HEIGHT 25

void Food::gen_food()
{
    pos.X= rand()% (WIDTH-3) + 1;
    pos.Y= rand()% (HEIGHT-3) + 1;

}

COORD Food::get_pos(){return pos;}

