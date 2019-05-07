#include "board.h"
using namespace std;

class move: public board{
     protected:
        int max_value;
     public:
        int move_up(int array[5][5]);
        int move_down(int array[5][5]);
        int move_left(int array[5][5]);
        int move_right(int array[5][5]);
        int combine_up(int array[5][5]);
        int combine_down(int array[5][5]);
        int combine_left(int array[5][5]);
        int combine_right(int array[5][5]);
        move(){max_value=0;}
        ~move(){}
        move& operator=(move& o){}
        move(move& o){}
};

