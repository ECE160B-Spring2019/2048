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


void movev(int array [5][5])
{
//  string user_vertical_input;                
  int counter;
  int a,b,c;
// cin>>user_vertical_input;
//  if (user_vertical_input == "w") {






//THIS IS TO GO UP

  for (int counter=0;counter<3;counter++) {
    for ( int column = 0; column < 4; column++) {      //loops through the columns
      for (int row=0; row < 4; row++) {        //loops through the rows 
        if (array [row][column]== 0) {
          a= array[row][column];
          b=array[row+1][column];
          c=b;
          b=a;
          a=c;
          array[row][column]=a;
          array[row+1][column]=b;
        if (row==3){
          array[row][column]=0;
    //      array[row+1][column]=-1;
        }

        }

      }
    }
  }
//this is to combine the same tiles for up
  for(int column =0;column<4;column++) {
    for (int row =0;row<4;row++) {
      if (array[row][column] == array [row+1][column]) {
        array[row][column] = array [row][column] * 2;
        array[row+1][column]=0;
        if (row <3 && array [row][column] ==0){
      
          int a= array[row][column];
          int b=array[row+1][column];
          int c=b;
          b=a;
          a=c;
          array[row][column]=a;
          array[row+1][column]=b;
       





      }

      }


    }


  } 







//  else if (user_vertical_input == "s") {




//THIS IS TO GO DOWN

/*


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


  //    }

      }
    }
  }
//  else {
//  cout << "Invalid input"<< endl;
//  }        

  }


*/



  return;
}


void printArray(int array[5][5]) {
  for (int i = 0;i<4;i++) {
    for (int j = 0; j<4;j++) {


      cout <<array[i][j] <<" ";
    }
    cout<<endl;
  }
}
int main () {

  int tile [5][5]= { {4,2,4,0}, {2,0,4,0},{0,0,2,0},{0,2,4,0}  };

  printArray(tile);
  movev(tile);
  cout<<"after move"<<endl;
  printArray(tile);




  return 0;
}
