#include "header.h"
#include "board.h"
using namespace std;

//copy constructor
board::board(board& b)
{
        memcpy(tile, b.tile, sizeof(tile));
}

//sets all values in the array to zero
void board::initialize()
{
        int first_pos, row, col, first_value;
        for(int jj=0; jj<4; jj++)
        {
                for(int ii=0; ii<4; ii++)
                {
                        tile[jj][ii]=0;
                }
        }
        first_pos=rand()%16;
        row=first_pos/4;
        col=first_pos%4;
        tile[row][col]=2;
}

void board::draw()
{
        clear();
        printw("*************************\n"); 
        for(int jj=0; jj<4; jj++)
        {
                printw("*");
                for(int ii=0; ii<4; ii++)
                {
                        if(tile[jj][ii]!=0){
                                if(tile[jj][ii]<10){
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
        printw("\n*************************\n");                   
        } 
        printw("\n");
        refresh();
}
