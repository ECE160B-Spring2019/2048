#include "header.h"
#include "board.h"
using namespace std;

//copy constructor
board::board(board& b)
{
        memcpy(tile, b.tile, sizeof(tile));             //copys the values of b to it board
}

//sets all values in the array to zero
void board::initialize()                   
{
        int first_pos, row, col, first_value;
        for(int jj=0; jj<4; jj++)            //the nested for loops ensures that you cycle through all the row and column of the board
        {
                for(int ii=0; ii<4; ii++)
                {
                        tile[jj][ii]=0;      //sets all the tiles to 0 
                }
        }
        first_pos=rand()%16;            //picks a random postion
        row=first_pos/4;
        col=first_pos%4;
        tile[row][col]=2;               //inserts a 2 in that spot
}

//prints the board out
void board::draw()
{
        clear();                //clear old board out
        printw("*************************\n");          //prints the boarder of the board 
        for(int jj=0; jj<4; jj++)
        {
                printw("*");
                for(int ii=0; ii<4; ii++)               //prints the different values of the board
                {
                        if(tile[jj][ii]!=0){
                                if(tile[jj][ii]<10){            //each number prints different number of spaces
                                        printw("   %d *",tile[jj][ii]);
                                }else if(tile[jj][ii]<100){
                                        printw("  %d *",tile[jj][ii]);
                                }else if(tile[jj][ii]<1000){
                                        printw(" %d *",tile[jj][ii]);
                                }else{
                                        printw("%d*",tile[jj][ii]);
                                }

                        }else{
                                printw("     *");
                        }
                }
        printw("\n*************************\n");                   //prints boarder of the board
        } 
        printw("\n");
        refresh();              //load the board onto the window
}


