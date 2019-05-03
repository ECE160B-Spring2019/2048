#include "header.h"
#include "check.h"
#include "move.h"
using namespace std;

//constructor
check::check()
{}
        
//copy-constructor
check::check(check& c)
{}

int check::possiblemoves()
{
         for(int jj=0; jj<4; jj++)
         {
                 for(int ii=0; ii<4; ii++)
                 {
                         if(tile[jj][ii]==tile[jj][ii+1])
                         {
                                 return 1;
                         }
                         else if(tile[jj][ii]==tile[jj+1][ii])
                         {
                                 return 1;
                         }
                 }
         }
         return 0;
}

//finds any empty space
int check::findempty()
{
        int count, end, emptyfound[15];
        count=0;

       //in order to ensure that the number picked out is random all empty spaces are found 
        for(int jj=0; jj<4; jj++)
        {
                for(int ii=0; ii<4; ii++)
                {
                        if(tile[jj][ii]==0)
                        {  
                               emptyfound[count]=(jj*4)+ii;
                               count++;
                        }
                }
        }

        if(count==0)
        {
                return 0;
        }
        end = rand()%(count);

        //Returns value of the empty space +1 to diffrent between the space and zero.
        return emptyfound[end]+1;
}

int check::randomnumber()
{
        int space, row, col, value;
        if((space=findempty())!=0){
                space --;
                row = space/4;
                col=space%4;
                tile[row][col]=2;
         }
         return win(); 
}

int check::win()
{
        int end;
        draw(); 
        if(max_value==2048){
                 printw("You won!!!\n");
                 refresh();
                 end = playagain();
        }else if(findempty()==0 && possiblemoves()==0){
                printw("You lose, you loser!\n");
                refresh();
                end=playagain();
        }else{
                 end = 1;
        }
        return end;
}

int check::playagain()
{
        char answer;
        printw("Do you want to play again? (y or n)\n");
        refresh();
        do{
                answer=getch();
        }while(answer!='Y' && answer!='y' && answer!='N' && answer!='n');  
        if(answer=='Y' || answer=='y')
        {
                return 2;
        }else if(answer=='N' || answer=='n'){
                return 0;
        }
}
