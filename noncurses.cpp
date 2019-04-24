#include <iostream>
#include <string.h>
#include <string>
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
        first_value=rand()%2;
        row=first_pos/4;
        col=first_pos%4;
        first_value==0 ? tile[row][col]=2 : tile[row][col]=4;
}

//prints the board out
void board::draw()
{
        cout<<"*************************"<<endl;
        for(int jj=0; jj<4; jj++)
        {
                cout<<"*";
                for(int ii=0; ii<4; ii++)
                {
                        if(tile[jj][ii]!=0){
                                if(tile[jj][ii]<10){
                                        cout<<"   "<<tile[jj][ii]<<" *";
                                }else if(tile[jj][ii]<100){
                                        cout<<"  "<<tile[jj][ii]<<" *";
                                }else if(tile[jj][ii]<1000){
                                        cout<<tile[jj][ii]<<" *";
                                }else{
                                        cout<<tile[jj][ii]<<"*";
                                }

                        }else{
                                cout<<"     *";
                        }
                }
        cout<<endl<<"*************************"<<endl;                   
        } 
        cout<<endl;
}

class move: public board{
     protected:
        int max_value;
     public:
        void move_up(int array[5][5]);
        void move_down(int array[5][5]);
        void move_left(int array[5][5]);
        void move_right(int array[5][5]);
        void combine_up(int array[5][5]);
        void combine_down(int array[5][5]);
        void combine_left(int array[5][5]);
        void combine_right(int array[5][5]);
        move(){max_value=0;}
        ~move(){}
        move& operator=(move& o){}
        move(move& o){}
};

void move::move_up(int array [5][5]){
  int counter;
  int a,b,c;

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
        if (row==3){                               //if you are at the last row then set the value equal to 0 or blank 
          array[row][column]=0;
    //      array[row+1][column]=-1;
        }
        }
      }
    }
  }
  return;
}

void move::combine_up (int array [5][5]) {
  for(int column =0;column<4;column++) {
    for (int row =0;row<4;row++) {
      if (array[row][column] == array [row+1][column]) {
        array[row][column] = array [row][column] * 2;
        array[row+1][column]=0;
        if (array[row][column] > max_value) {
          max_value= array[row][column];
        }
      }
    }
    move_up(array);
  }
  return; 
}

//  else if (user_vertical_input == "s") {
void move::move_down(int array [5][5]) {
  int a,b,c;

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
  return;
}

void move::combine_down (int array[5][5]) {
  for(int column =0;column<4;column++) {
    for (int row =3;row>=0;row--) {
      if (row!=0) { 
        if (array[row][column] == array [row-1][column]) {
          array[row][column] = array [row][column] * 2;
          array[row-1][column]=0;
          if (array[row][column] > max_value) {
            max_value= array[row][column];
          }
        }
      }
    }
    move_down(array);
  }
  return;
}

void move::move_left (int array [5][5]) {
  int a,b,c;

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

          if (column==3){
            array[row][column]=0;
          }
        }
      }
    }
  }
 
  return;
}

void move::combine_left (int array [5][5]) {
  for(int row =0;row<4;row++) {
    for (int column =0;column<4;column++) {
      if (array[row][column] == array [row][column+1]) {
        array[row][column] = array [row][column] * 2;
        array[row][column+1]=0;
        if (array[row][column] > max_value) {
          max_value= array[row][column];
        }
      }
    }
    move_left(array);
  }
 
  return;
}

void move::move_right(int array [5][5]) {
  int a,b,c;

  for (int counter=0;counter<3;counter++) {
    for ( int row = 0; row <4; row++) {      //loops through the columns
      for (int column=3; column >=0; column--) {        //loops through the rows 
        if (array [row][column]== 0) {
          a= array[row][column];
          b=array[row][column-1];
          c=b;
          b=a;
          a=c;
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
 
  return;
}

void move::combine_right (int array [5][5]) {

  for(int row =0;row<4;row++) {
    for (int column =3;column>=0;column--) {
      if (column!=0) { 
        if (array[row][column] == array [row][column-1]) {
          array[row][column] = array [row][column] * 2;
          array[row][column-1]=0;
          if (array[row][column] > max_value) {
            max_value= array[row][column];
          }
        }
      }
    }
    move_right(array);
  }
  return;
}




class check: public move{
      public: 
        int randomnumber();
        int findempty();
        int win();
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
                value = rand()%2;
                value==1 ? (tile[row][col]=4) : (tile[row][col]=2);
         }
         return win(); 
}

int check::win()
{
        int end;
        draw(); 
        if(max_value==2048){
                 cout<<"You won!!!"<<endl;
                 end = playagain();
        }else if(findempty()==0){
                cout<<"You lose, you loser!"<<endl;
                end=playagain();
        }else{
                 end = 1;
        }
        return end;
}

int check::playagain()
{
        char answer;
        cout<<"Do you want to play again? (y or n)"<<endl;
        do{
                cin>>answer;
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

        int answer;
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
                        string s;
                        cin>>s;
                        if(s=="w" || s=="W"){
                                c.move_up(c.tile);
                                c.combine_up(c.tile);
                                answer=c.randomnumber();
                        }else if(s=="s" || s=="S"){
                                c.move_down(c.tile);
                                c.combine_down(c.tile); 
                                answer=c.randomnumber();
                        }else if(s=="a" || s=="A"){
                                c.move_left(c.tile);
                                c.combine_left(c.tile);
                                answer=c.randomnumber();
                        }else if(s=="d" || s=="D"){
                                c.move_right(c.tile);
                                c.combine_right(c.tile);
                                answer=c.randomnumber();
                        }else{
                                cout<<"Choice is invaild, please pick W, S, A, or D."<<endl;
                        }
                }while(answer==1);
        }while(answer==2); 
  return 0;        
}
