#include "header.h"
#include "check.h"
using namespace std;

int main()
{
        initscr();
        keypad(stdscr, TRUE);
        cbreak();
        noecho();

        int answer, vmove, vcombine;
        do{
                check c;
                answer = c.randomnumber();
                do{
                        int s;
                       // vmove;
                        //vcombine;
                        s=getch();
                        switch(s){
                        case KEY_UP:
                                vmove=c.move_up(c.tile);
                                vcombine=c.combine_up(c.tile);
                                if(vmove==1 || vcombine==1){ 
                                        answer=c.randomnumber();
                                }else{
                                        answer=c.win();
                                }
                                break;
                        case KEY_DOWN:
                                vmove = c.move_down(c.tile);
                                vcombine = c.combine_down(c.tile);
                                if(vmove || vcombine){ 
                                        answer=c.randomnumber();
                                }else{
                                        answer=c.win();        
                                }
                                break;
                         case KEY_LEFT:
                                vmove=c.move_left(c.tile);
                                vcombine= c.combine_left(c.tile);
                                if(vmove || vcombine){
                                        answer=c.randomnumber();
                                }else{
                                        answer=c.win();
                                }
                                break;
                        case KEY_RIGHT:
                                vmove=c.move_right(c.tile);
                                vcombine= c.combine_right(c.tile);
                                if(vmove==1||vcombine==1){
                                        answer=c.randomnumber();
                                }else{
                                        answer = c.win();
                                }
                                break;
                        default:
                                printw("Choice is invaild, please use arrow keys.\n");
                                refresh();
                        }
                        refresh();
                }while(answer==1);
                clear();
        }while(answer==2); 
        endwin();
        return 0;
}
