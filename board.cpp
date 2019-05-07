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
        int row, col;
        clear();                //clear old board out
        char mesg[]="+-----+-----+-----+-----+";
        getmaxyx(stdscr,row,col);		// get the number of rows and columns
        col=(col-strlen(mesg))/2;
        row=(row/2)-5; 
        attron(COLOR_PAIR(1));
        mvprintw(row,col,"%s\n",mesg);          //prints the boarder of the board 
        attroff(COLOR_PAIR(1));
        for(int jj=0; jj<4; jj++)
        {
                attron(COLOR_PAIR(1));
                mvprintw((row+(2*jj)+1),col,"|");
                attroff(COLOR_PAIR(1));
                for(int ii=0; ii<4; ii++)               //prints the diffrent values of the board
                {
                        if(tile[jj][ii]!=0){
                                if(tile[jj][ii]==2){            //each number prints diffrent number of spaces and colors
                                        attron(COLOR_PAIR(2));
                                        printw("   %d ",tile[jj][ii]);
                                        attroff(COLOR_PAIR(2));
                                }else if(tile[jj][ii]==4){
                                        attron(COLOR_PAIR(3));
                                        printw("   %d ",tile[jj][ii]);
                                        attroff(COLOR_PAIR(3));
                                }else if(tile[jj][ii]==8){
                                        attron(COLOR_PAIR(4));
                                        printw("   %d ",tile[jj][ii]);
                                        attroff(COLOR_PAIR(4));
                                }else if(tile[jj][ii]==16){
                                        attron(COLOR_PAIR(5));
                                        printw("  %d ",tile[jj][ii]);
                                        attroff(COLOR_PAIR(5));
                                }else if(tile[jj][ii]==32){
                                        attron(COLOR_PAIR(6));
                                        printw("  %d ",tile[jj][ii]);
                                        attroff(COLOR_PAIR(6)); 
                                }else if(tile[jj][ii]==64){
                                        attron(COLOR_PAIR(7));
                                        printw("  %d ",tile[jj][ii]);
                                        attroff(COLOR_PAIR(7));
                                }else if(tile[jj][ii]==128){
                                        attron(COLOR_PAIR(8));
                                        printw(" %d ",tile[jj][ii]);
                                        attroff(COLOR_PAIR(8));
                                }else if(tile[jj][ii]==256){
                                        attron(COLOR_PAIR(9));
                                        printw(" %d ",tile[jj][ii]);
                                        attroff(COLOR_PAIR(9));
                                }else if(tile[jj][ii]==512){
                                        attron(COLOR_PAIR(10));
                                        printw(" %d ",tile[jj][ii]);
                                        attroff(COLOR_PAIR(10));
                                }else if(tile[jj][ii]==1024){
                                        attron(COLOR_PAIR(11));
                                        printw("%d ",tile[jj][ii]);
                                        attroff(COLOR_PAIR(11));
                                }else{
                                        attron(COLOR_PAIR(12));
                                        printw("%d ",tile[jj][ii]);
                                        attroff(COLOR_PAIR(12));
                                }
                                attron(COLOR_PAIR(1));
                                printw("|");
                                attroff(COLOR_PAIR(1));
                        }else{
                                attron(COLOR_PAIR(1));
                                printw("     |");
                                attroff(COLOR_PAIR(1));
                        }
                }
                attron(COLOR_PAIR(1));
                printw("\n");
                mvprintw((row+(2*jj)+2),col,"%s\n",mesg);                   //prints boarder of the board
                attroff(COLOR_PAIR(1));
        } 
        printw("\n");
        refresh();              //load the board onto the window
}
      


