#include <iostream>
#include <string.h>
#include <string>
#include <ncurses.h>
using namespace std;

class board{
    public:
      int tile[5][5];
      board(){initialize();} //constructor
      void initialize();
      void draw();
      void set(int, int, int);
      int pull(int, int);  
      ~board(){} //destructor
      board(board&);
      board& operator=(board& b){memcpy(tile, b.tile, sizeof(tile));} //operator assignment
};

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

//prints the board out
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

int move::move_up(int array [5][5]){
  int counter;
  int a,b,c;
  int moved=0;

  for (int counter=0;counter<3;counter++) {             //this cycles for 3 times to ensure that all the values are moved up
    for ( int column = 0; column < 4; column++) {      //loops through the columns
      for (int row=0; row < 4; row++) {               //loops through the rows within each column
        if (array [row][column]== 0) {               //if there is an empty spot then swap so that all the values gets "pushed" or moved up
          a= array[row][column];
          b=array[row+1][column];
          c=b;
          b=a;
          a=c;
          array[row][column]=a;
          array[row+1][column]=b;
        if(a!=0){  
          moved = 1;
        }
        if (row==3){                               //if you are at the last row then set the value equal to 0 or blank 
          array[row][column]=0;
    //      array[row+1][column]=-1;
        }
        }
      }
    }
  }
  return moved;
}

int move::combine_up (int array [5][5]) {
  int moved, combined;
  combined=0;
  for(int column =0;column<4;column++) {
    for (int row =0;row<4;row++) {
      if (array[row][column] == array [row+1][column]) {
        array[row][column] = array [row][column] * 2;
        array[row+1][column]=0;
        combined=1;
        if (array[row][column] > max_value) {
          max_value= array[row][column];
        }
      }
    }
    moved=move_up(array);
  }
  return (moved==1 || combined==1) ? 1 : 0; 
}

//  else if (user_vertical_input == "s") {
int move::move_down(int array [5][5]) {
  int a,b,c;
  int moved=0;

  for (int counter=0;counter<3;counter++) {
    for ( int column = 0; column <4; column++) {      //loops through the columns
      for (int row=3; row >=0; row--) {        //loops through the rows 
        if (array [row][column]== 0) {
          a= array[row][column];
          b=array[row-1][column];
          c=b;
          b=a;
          a=c;
          array[row][column]=a;
          if(a!=0){
                moved=1;
          }
          if (row!=0){
            array[row-1][column]=b;
          }
          if (row==0){
            array[row][column]=0;
          }
        }
      }
    }
  }
  return moved;
}

int move::combine_down (int array[5][5]) {
  int combined,moved;
  combined=0;
  for(int column =0;column<4;column++) {
    for (int row =3;row>=0;row--) {
      if (row!=0) { 
        if (array[row][column] == array [row-1][column]) {
          array[row][column] = array [row][column] * 2;
          array[row-1][column]=0;
          combined=1;
          if (array[row][column] > max_value) {
            max_value= array[row][column];
          }
        }
      }
    }
    moved = move_down(array);
  }
  return (moved==1||combined==1) ? 1 : 0;
}

int move::move_left (int array [5][5]) {
  int a,b,c;
  int moved=0;

  for (int counter=0;counter<3;counter++) {
    for ( int row = 0; row <4; row++) {      //loops through the columns
      for (int column=0; column<4; column++) {        //loops through the rows 
        if (array [row][column]== 0) {
          a= array[row][column];
          b=array[row][column+1];
          c=b;
          b=a;
          a=c;
          array[row][column]=a;
          array[row][column+1]=b;
          if(a!=0){
                moved=1;
          }
          if (column==3){
            array[row][column]=0;
          }
        }
      }
    }
  }
 
  return moved;
}

int move::combine_left (int array [5][5]) {
  int moved, combined;
  combined=0;
  for(int row =0;row<4;row++) {
    for (int column =0;column<4;column++) {
      if (array[row][column] == array [row][column+1]) {
        array[row][column] = array [row][column] * 2;
        array[row][column+1]=0;
        combined=1;
        if (array[row][column] > max_value) {
          max_value= array[row][column];
        }
      }
    }
    moved=move_left(array);
  }
  return (moved==1||combined==1) ? 1 : 0;
}

int move::move_right(int array [5][5]) {
  int a,b,c;
  int moved=0; 
       
  for (int counter=0;counter<3;counter++) {
    for ( int row = 0; row <4; row++) {      //loops through the columns
      for (int column=3; column >=0; column--) {        //loops through the rows 
        if (array [row][column]== 0) {
          a= array[row][column];
          b=array[row][column-1];
          c=b;
          b=a;
          a=c;
          if(a!=0){
                  moved=1;
          }
          array[row][column]=a;
          if (column!=0){
            array[row][column-1]=b;
          }
          if (column==0){
            array[row][column]=0;
          }
        }
      }
    }
  }
 
  return moved;
}

int move::combine_right (int array [5][5]) {
  int moved, combined;
  combined=0;
  for(int row =0;row<4;row++) {
    for (int column =3;column>=0;column--) {
      if (column!=0) { 
        if (array[row][column] == array [row][column-1]) {
          array[row][column] = array [row][column] * 2;
          array[row][column-1]=0;
          combined=1;
          if (array[row][column] > max_value) {
            max_value= array[row][column];
          }
        }
      }
    }
    moved=move_right(array);
  }
  return (moved==1||combined==1) ? 1 : 0;
}




class check: public move{
      public: 
        int randomnumber();
        int findempty();
        int win();
        int possiblemoves();
        int playagain();
        check();
        ~check(){}
        check& operator=(check& c){max_value=c.max_value;}
        check(check& c);
};

//constructor
check::check()
{
       
}        
//copy-constructor
check::check(check& c)
{
       
}

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

//checks for empty space and then inserts a 2 or 4 there, then checks in the player won or lost yet.
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

int main()
{
        initscr();
        keypad(stdscr, TRUE);
        cbreak();
        noecho();

        int answer, valid;
        do{
                check c;
                //something with move
                answer = c.randomnumber();
                //randomnumber inserts a random number in a random spot and also checks if the player won or lost and if they did they ask if they want to play again. 
                //answer=0
                //doen't want to play again
                //answer=1
                //in middle of the game
                //answer = 2
                //wants to play again
                do{
                        int s;
                        valid=0;
                        s=getch();
                        switch(s){
                        case KEY_UP:
                                c.move_up(c.tile);
                                valid = c.combine_up(c.tile);
                                if(valid==1){ 
                                        answer=c.randomnumber();
                                }else{
                                        answer=c.win();
                                }
                                break;
                        case KEY_DOWN:
                                c.move_down(c.tile);
                                valid = c.combine_down(c.tile);
                                if(valid==1){ 
                                        answer=c.randomnumber();
                                }else{
                                        answer=c.win();        
                                }
                                break;
                        case KEY_LEFT:
                                c.move_left(c.tile);
                                valid = c.combine_left(c.tile);
                                if(valid==1){
                                        answer=c.randomnumber();
                                }else{
                                        answer=c.win();
                                }
                                break;
                        case KEY_RIGHT:
                                c.move_right(c.tile);
                                valid = c.combine_right(c.tile);
                                if(valid==1){
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
