#include "header.h"
#include "check.h"
using namespace std;

int main()
{
        initscr();
        keypad(stdscr, TRUE);           //allows the use of the arrow keys
        cbreak();               
        noecho();                       //no echo in the board

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
                                printw("Choice is invaild, please use arrow keys.\n");        //if the user does not enter a valid key, then prompt an error message
                                refresh();      //prints to board
                        }
                        refresh();
                }while(answer==1);      //while the player neither lost or won
                clear();        //game ended board is cleared
        }while(answer==2);      //while player chooses to play again
        endwin();               //window is closed
        return 0;
}
