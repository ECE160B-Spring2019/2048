#include "header.h"
#include "check.h"
using namespace std;

//constructor
check::check()
{}
        
//copy-constructor
check::check(check& c)
{}

int check::possiblemoves()
{
         for(int jj=0; jj<4; jj++)               //the nested for loops makes sure that it goes through the rows and columns
         {
                 for(int ii=0; ii<4; ii++)
                 {
                         if(tile[jj][ii]==tile[jj][ii+1])       //checks if two ajacent numbers in a column are the same
                         {
                                 return 1;
                         }
                         else if(tile[jj][ii]==tile[jj+1][ii]) //checks if two ajacent numbers in a row are the same
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
        for(int jj=0; jj<4; jj++)        //goes through all the tiles on the board
        {
                for(int ii=0; ii<4; ii++)
                {
                        if(tile[jj][ii]==0)           //the tile is empty if it equals 0. if it is true, then an empty tile is found
                        {  
                               emptyfound[count]=(jj*4)+ii;     //stores all postions that are empty 
                               count++;
                        }
                }
        }

        if(count==0)    //no empty spots were found
        {
                return 0;
        }
        end = rand()%(count);   //picks a random postion in the array of empty postions

        //Returns value of the empty space +1 to diffrent between the space and zero.
        return emptyfound[end]+1;
}

//checks for empty space and then inserts a 2 or 4 there, then checks in the player won or lost yet.
int check::randomnumber()
{
        int space, row, col, value;
        if((space=findempty())!=0){     //checks that there is a empty spot
                space --;
                row = space/4;
                col=space%4;
                tile[row][col]=2;       //puts a 2 in the random spot
         }
         return win();          //calls win
}

int check::win()
{
        int end;
        draw();                                                //draw the board
        if(max_value==2048){                                   //if the player reaches 2048, he/she wins the game
                 printw("You won!!!\n");
                 refresh();                                   //refresh the board
                 end = playagain();                           //ask if the player wants to play again
        }else if(findempty()==0 && possiblemoves()==0){       //check if all the tiles are filled up and if there are no more moves left to make 
                printw("You lose, you loser!\n");             //print a loser message 
                refresh();                                    //refresh the board
                end=playagain();                              //ask if the player wants to play again
        }else{       
                 end = 1;                                    //continue the game
        }
        return end;
}

int check::playagain()                                       //this function prompts the user a question asking if he/she wants to play again
{
        char answer;                                         //a variable to store the input
        printw("Do you want to play again? (y or n)\n");     //prompt question
        refresh();                                           
        do{
                answer=getch();                              //takes care of invalid inputs 
        }while(answer!='Y' && answer!='y' && answer!='N' && answer!='n');  
        if(answer=='Y' || answer=='y')                       //if yes, then return 2 so a new game is started
        {
                return 2;
        }else if(answer=='N' || answer=='n'){               //if no, then end game and close
                return 0;
        }
}


