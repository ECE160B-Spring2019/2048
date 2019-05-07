#include <iostream>
#include <string.h>
#include <string>
#include <ncurses.h>
using namespace std;

class board{                              //this class contains everything that sets up the game board
    public:
      int tile[5][5];
      board(){initialize();}             //constructor
      void initialize();
      void draw();
      void set(int, int, int);
      int pull(int, int);  
      ~board(){}                         //destructor
      board(board&);
      board& operator=(board& b){memcpy(tile, b.tile, sizeof(tile));} //operator assignment
};

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
        char mesg[]="*************************";
        getmaxyx(stdscr,row,col);		// get the number of rows and columns
        col=(col-strlen(mesg))/2;
        row=(row/2)-5; 
        attron(COLOR_PAIR(1));
        mvprintw(row,col,"%s\n",mesg);          //prints the boarder of the board 
        attroff(COLOR_PAIR(1));
        for(int jj=0; jj<4; jj++)
        {
                attron(COLOR_PAIR(1));
                mvprintw((row+(2*jj)+1),col,"*");
                attroff(COLOR_PAIR(1));
                for(int ii=0; ii<4; ii++)               //prints the diffrent values of the board
                {
                        if(tile[jj][ii]!=0){
                                if(tile[jj][ii]==2){            //each number prints diffrent number of spaces
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
                                printw("*");
                                attroff(COLOR_PAIR(1));
                        }else{
                                attron(COLOR_PAIR(1));
                                printw("     *");
                                attroff(COLOR_PAIR(1));
                        }
                }
                attron(COLOR_PAIR(1));
                printw("\n");
                mvprintw((row+(2*jj)+2),col,"%s\n",mesg);                   //prints boarder of the board
                attroff(COLOR_PAIR(1));
        } 
        printw("\n");
        refresh();              //loard the bpard onto the window
}

class move: public board{                       //this class deals with the movements of the game. it includes moving/swapping and combining
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
        move(){max_value=0;}    //constructor
        ~move(){}       //deconstructor
        move& operator=(move& o){} //assignment overload
        move(move& o){} //copy constructor
};

int move::move_up(int array [5][5]){                 //overall, this function moves all the numbers up if user chooses the option to
  int counter;
  int a,b,c;
  int moved=0;                                       //the defaulted value of moved =0 because it means that the board isnt changing and a random number should not appear

  for (int counter=0;counter<3;counter++) {          //this cycles for 3 times to ensure that all the values are moved up
    for ( int column = 0; column < 4; column++) {    //loops through the columns
      for (int row=0; row < 4; row++) {              //loops through the rows within each column
        if (array [row][column]== 0) {               //if there is an empty spot then swap so that all the values gets "pushed" or moved up
          a= array[row][column];                     //if the current element is a 0, then call a swap
          b=array[row+1][column];                    //store the next value in order to perform the swap
          c=b;                                       //c is a temp variable to store the value of b(second element)
          b=a;                                       //swaps->the value of the second element is now equal to the value of the first element
          a=c;                                       //swaps->the value of the first element is now equal to the value of the secocnd element(since c stores value of 2nd element)
          array[row][column]=a;                      //puts value back into the array/board
          array[row+1][column]=b;                    //puts value back into the array/board
        if(a!=0){                                    //check if the numbers swapped are both 0. if so,it is an invalid move so a random should not pop up. if no, random# should pop up
          moved = 1;                                 //set value = 1 so random # pops up
        }
        if (row==3){                                 //if you are at the last row then set the value equal to 0 or blank 
          array[row][column]=0;                      //the last elements of the rows are empty if a swap is performed
    //      array[row+1][column]=-1;
        }
        }
      }
    }
  }
  return moved;                                     //return the value of moved so it can be used to call if a random number should or should not be added to the board
}

int move::combine_up (int array [5][5]) {           //this function combines the numbers after moving it up
  int combined; 
  combined=0;                                       //similar to the "moved" in the move functions, this is initialized to 0 and will or will not be changed later 
  for(int column =0;column<4;column++) {            //loops through the columns
    for (int row =0;row<4;row++) {                  //loops through the rows
      if (array[row][column] == array [row+1][column]) {  //if the current element is equal to the next element, then it should be combined 
        if(array[row][column]!=0){                   //if the numbers being combined are not 0, then it is a "valid" move and a random # should appear
                combined=1;                           //change the value of combined so a random # will appear
        }
        array[row][column] = array [row][column] * 2;  //to combine, the numbers are always double of what it originally was. set that value equal to the current element
        array[row+1][column]=0;                        //set the next element equal to 0 
        if (array[row][column] > max_value) {          //check if the current element is bigger than the max value. this keeps track of the highest value on the board
          max_value= array[row][column];               //if there is a new max value, then set it equal to a variable (max_value)
        }
      }
    }
    move_up(array);                           //since the second element was set to 0, a move function needs to be called so the "correct" values are pushed up 
  }
  return combined;                            //this value will be used later to "trigger" the random number function or not
}

int move::move_down(int array [5][5]) {           //this function deals with all the swapping and moving down  
  int a,b,c;
  int moved=0;                                    //the defaulted value is equal to 0 so that a random number is not called 

  for (int counter=0;counter<3;counter++) {       //this ensures that all the numbers are moved down   
    for ( int column = 0; column <4; column++) {      //loops through the columns
      for (int row=3; row >0; row--) {                //loops through the rows 
        if (array [row][column]== 0) {                //if a 0 is found, then the numbers should be swapped
          a= array[row][column];                      //store the current element in a variable a
          b=array[row-1][column];                     //store the next element in a variable b
          if(b!=0){                                   //if the two numbers swapped are not both 0, then a random number should be added                         
            moved=1;                                  //setting moved = 1 would call the random number function later on 
          }
          c=b;                                        //the temp variable c is used to store the value of the second element
          b=a;                                        //the second element is set equal to the first element
          a=c;                                        //the first element is equal to the previous second element that was stored in the temp variable c
          array[row][column]=a;                       //set the current element equal to the swapped value
          array[row-1][column]=b;                   //set the value of the second element equal to the swapped value
        }
      }
    }
  }
  return moved;                                      //this returns the value that can be used to call the random number function or not
}

int move::combine_down (int array[5][5]) {          //this function gives combines the numbers if its the same in the downwards direction 
  int combined;                                     
  combined=0;                                        //defaulted value to 0 so random number function is not called later on
  for(int column =0;column<4;column++) {             //loops through all the columns 
    for (int row =3;row>0;row--) {                   //loops through all the rows
      if (array[row][column] == array [row-1][column]) {    //if the current element is equal to the next element then combine
        if(array[row][column]!=0){                        //if the numbers that are being combined are not both 0, then it is a "valid" move
          combined=1;                                     //set combined=1 so the random number function is called later
        }      
        array[row][column] = array [row][column] * 2;     //multiply by 2 to get the new value after being combined
        array[row-1][column]=0;                           //set the second element equal to 0
        if (array[row][column] > max_value) {             //check if there is a new max value after combining
          max_value= array[row][column];                  //if there is a new max value, then store that in "max_value" 
        }
      }
    }
    move_down(array);                                   //since the second element is equal to 0, then a move down needs to be called so that the values are in the proper placement
  }
  return combined;                                      //return combined so that the value can be used later to see if the random number function is called or not
}

int move::move_left (int array [5][5]) {              //this function deals with the leftward movement of the game
  int a,b,c;
  int moved=0;                                        //sets the defaulted value to 0. this value may be changed later and is used to determine if the random number is called or not

  for (int counter=0;counter<3;counter++) {           //makes sure that all the numbers are moved left
    for ( int row = 0; row <4; row++) {               //loops through the rows
      for (int column=0; column<4; column++) {        //loops through the columns 
        if (array [row][column]== 0) {                //if there is a 0 or empty spot, then a swap is called
          a= array[row][column];                      //the variable a stores the current element
          b=array[row][column+1];                     //the variable b stores the next element
          c=b;                                        //c is a temp variable that stores the value of second element
          b=a;                                        //the value of the second element is changed to the value of the first element
          a=c;                                        //the current elements value changes to the old value of the second element which is stored in c
          array[row][column]=a;                       //store back the swapped value into the current element 
          array[row][column+1]=b;                     //store back the swapped value into the next element 
          if(a!=0){                                   //if after the swap, the value of a is not equal to 0, then it is considered a valid move
                moved=1;                              //make the value of moved equal to 1 so that the random number function could be called later
          }
          if (column==3){                             //it is the last column, then the last column becomes a 0 or empty
            array[row][column]=0;                     //set current element to 0
          }
        }
      }
    }
  }
 
  return moved;                                       //return the value of moved so that it can be used for the random number function 
}

int move::combine_left (int array [5][5]) {          //this is the combine function for leftward movement
  int combined;
  combined=0;                                        //make the defaulted value =0. this value is used later to determine whether or not the random number function is called or not
  for(int row =0;row<4;row++) {                      //loop through the rows
    for (int column =0;column<4;column++) {          //loop through the columns 
      if (array[row][column] == array [row][column+1]) {  //if there are the same numbers next to each other, combine it
        if(array[row][column]!=0){                     //if both numbers that are combined are not equal to 0, then it is a "valid" combine
                combined=1;                            //set the value of combined =1 so that the random number function is called later
        }
        array[row][column] = array [row][column] * 2;  //when combining, the first value is doubled 
        array[row][column+1]=0;                        //the second value is set equal to 0
        if (array[row][column] > max_value) {         //check if there is a new max value 
          max_value= array[row][column];              //if there is then change the max_value 
        }
      }
    }
    move_left(array);                              //since the second value was set to 0, a move left needs to be called so that the numbers are in the right positions 
  }
  return combined;                                 //return the value of combined so that it can be used to determine if the random number function is called or not
}

int move::move_right(int array [5][5]) {          //this is the function for move in the rightward direction
  int a,b,c;            
  int moved=0;                                    //set the default value of moved to 0. this value may change and would be returned at the end of the function 
       
  for (int counter=0;counter<3;counter++) {       //loops through 3 times to make sure that all the numbers are moved / swapped properly
    for ( int row = 0; row <4; row++) {           //loops through the rows
      for (int column=3; column >0; column--) {   //loops through the columns
        if (array [row][column]== 0) {            //if the current element is =0 then a swap needs to happen
          a= array[row][column];                  //store the value of the current element in the variable a 
          b=array[row][column-1];                 //store the value of the next element in the variable b
          if(b!=0){                               //if both values (a&b) are not equal to 0, then it is a valid move 
            moved=1;                              //change the value of moved to 1 so that it can call the random number function later 
          }
          c=b;                                    //c is a temp variable that stores the value of the second element
          b=a;                                    //the second element value is now equal to the value of the first element
          a=c;                                    //the value of the first element is now equall to the value of the old second element which is stored in temp variable c
          array[row][column]=a;                   //set the current element to the swapped value
     //     if (column!=0){                         //if not at the first column
            array[row][column-1]=b;               //set the value of the next element equal to the swapped value
       //   }
     //     if (column==0){
     //     array[row][column]=0;
     //     }
        }
      }
    }
  }
 
  return moved;                                   //return moved so that the value can be used for the random number function later
}

int move::combine_right (int array [5][5]) {       //this is the function to combine rightwards 
  int combined;
  combined=0;                                              //default the value of combined to 0
  for(int row =0;row<4;row++) {                            //loop through the rows 
    for (int column =3;column>0;column--) {                //loop through the column
      if (array[row][column] == array [row][column-1]) {   //if the numbers are the same then combine
        if(array[row][column]!=0){                         //if both numbers that are being combined are not equal to 0, then it is a "valid" move
          combined=1;                                      //set the value of combined =1 so that random number function can be called 
        }
        array[row][column] = array [row][column] * 2;      //to combine, the first element is doubled 
        array[row][column-1]=0;                            //the second element after combining is set to 0
        if (array[row][column] > max_value) {              //after combining, if there is a new max value then set that equal to "max_value"
          max_value= array[row][column];                   //change the max_value
        } 
      }
    }
    move_right(array);                                     //since there is a 0 placed in for the 2nd element, the values needs to be moved right in order to be in the proper placement
  }
  return combined;                                         //return the value of combined so it can be to determine whether or not the random number function is called or not
}




class check: public move{
      public: 
        int randomnumber();
        int findempty();
        int win();
        int possiblemoves();
        int playagain();
        check(){}                //constructor
        ~check(){}              //deconstructor
        check& operator=(check& c){max_value=c.max_value;}      //assignment overload
        check(check& c){}        //copy-constructor        
};

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
        int end,row,col;
        char message1[]="You won!!!";
        char message2[]="You lose, you loser!"; 
        getmaxyx(stdscr,row,col);
        draw();                                                //draw the board
        if(max_value==2048){                                   //if the player reaches 2048, he/she wins the game
                 mvprintw((row/2+4),(col-strlen(message1))/2,"%s\n",message1);
                 refresh();                                   //refresh the board
                 end = playagain();                           //ask if the player wants to play again
        }else if(findempty()==0 && possiblemoves()==0){       //check if all the tiles are filled up and if there are no more moves left to make 
                mvprintw((row/2+4),(col-strlen(message2))/2,"%s\n",message2); //print a loser message 
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
        int row, col;
        getmaxyx(stdscr, row, col);
        char message[]="Do you want to play again? (y or n)";
        mvprintw(row/2+5,(col-strlen(message))/2,"%s\n",message);     //prompt question
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
        init_pair(11, COLOR_BLACK, COLOR_BLUE); //For 1024
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
                                refresh();      //prints to board
                        }
                        refresh();
                }while(answer==1);      //while the player neither lost or won
                clear();        //game ended board is cleared
        }while(answer==2);      //while player chooses to play again
        endwin();               //window is closed
        return 0;
}
