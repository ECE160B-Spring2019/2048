#include "header.h"
#include "check.h"
using namespace std;

int main()
{
        initscr();
        keypad(stdscr, TRUE);           //allows the use of the arrow keys
        cbreak();               
        noecho();                       //no echo in the board
        start_color();
        
        init_pair(1, COLOR_WHITE, COLOR_BLACK); //For boarder
        init_pair(2, COLOR_BLACK, COLOR_WHITE); //For 2 
        init_pair(3, COLOR_BLACK, COLOR_YELLOW); //For 4
        init_pair(4, COLOR_WHITE, COLOR_MAGENTA); //For 8
        init_pair(5, COLOR_BLACK, COLOR_MAGENTA); //for 16
        init_pair(6, COLOR_WHITE, COLOR_RED); //For 32 
        init_pair(7, COLOR_BLACK, COLOR_RED); //for 64
        init_pair(8, COLOR_MAGENTA, COLOR_YELLOW); //For 128 
        init_pair(9, COLOR_RED, COLOR_YELLOW); //For 256
        init_pair(10, COLOR_WHITE, COLOR_BLUE); //For 512
        init_pair(11, COLOR_BLACK, COLOR_GREEN); //For 1024
        init_pair(12, COLOR_BLACK, COLOR_CYAN); //For 2048

        int answer, vmove, vcombine;
        do{
                check c;
                answer = c.randomnumber();
                do{
                        int s;
                        s=getch();
                        switch(s){
                        case KEY_UP:                               //if the user wants to move the tiles up
                                vmove=c.move_up(c.tile);           //move the tiles 
                                vcombine=c.combine_up(c.tile);     //combine the tiles 
                                if(vmove==1 || vcombine==1){       //check if it is a valid move. if yes, the values of vmove or vcombine should be 1
                                        answer=c.randomnumber();   //insert a random number if move is valid
                                }else{
                                        answer=c.win();
                                }
                                break;
                        case KEY_DOWN:                             //if the user wants to move the tiles down
                                vmove = c.move_down(c.tile);
                                vcombine = c.combine_down(c.tile);
                                if(vmove || vcombine){ 
                                        answer=c.randomnumber();
                                }else{
                                        answer=c.win();        
                                }
                                break;
                        case KEY_LEFT:                             //if the user wants to move the tiles left 
                                vmove=c.move_left(c.tile);
                                vcombine= c.combine_left(c.tile);
                                if(vmove || vcombine){
                                        answer=c.randomnumber();
                                }else{
                                        answer=c.win();
                                }
                                break;
                        case KEY_RIGHT:                           //if the user wants to move the tiles right
                                vmove=c.move_right(c.tile);
                                vcombine= c.combine_right(c.tile);
                                if(vmove==1||vcombine==1){
                                        answer=c.randomnumber();
                                }else{
                                        answer = c.win();
                                }
                               break;
                        default:
                                int row, col;
                                char message[]="Choice is invalid, please use arrow key.";
                                getmaxyx(stdscr, row, col);
                                mvprintw((row/2+4),(col-strlen(message))/2,"%s\n", message);        //if the user does not enter a valid key, then prompt an error message
                        }
                        refresh();
                }while(answer==1);      //while the player neither lost or won
                clear();        //game ended board is cleared
        }while(answer==2);      //while player chooses to play again
        endwin();               //window is closed
        return 0;
}
