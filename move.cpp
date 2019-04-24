#include <iostream>
#include <string>
using namespace std;
/*
class move : public board {
        char playermove;
     public:
        void set(char);
        void movev(int array[4][4]);
        void moveh();
        void combineh();
        void combinev();
//        move();
//        ~move();
//        check& operator=(move&);
//        move(move&);
};
*/

/*
//void move::
*/


//  string user_vertical_input;                
// cin>>user_vertical_input;
//  if (user_vertical_input == "w") {


int max_value=0;

void move_up(int array [5][5]){
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

void combine_up (int array [5][5]) {
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
void move_down(int array [5][5]) {
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

void combine_down (int array[5][5]) {
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

void move_left (int array [5][5]) {
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

void combine_left (int array [5][5]) {
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

void move_right(int array [5][5]) {
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

void combine_right (int array [5][5]) {

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



/*
void printArray(int array[5][5]) {
  for (int i = 0;i<4;i++) {
    for (int j = 0; j<4;j++) {


      cout <<array[i][j] <<" ";
    }
    cout<<endl;
  }
}
int main () {

  int tile [5][5]= { {0,8,4,4}, {0,8,0,8},{8,2,2,2},{2,8,2,2}  };


  cout<<"you are moving left"<<endl;
  printArray(tile);
  cout<<"after move"<<endl;
  move_left(tile);
  combine_left(tile);
  printArray(tile);

  return 0;
}

*/
