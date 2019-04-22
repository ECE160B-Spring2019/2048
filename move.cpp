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


void move_up(int array [5][5])
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

  return;
}

//this is to combine the same tiles for up
void combine_up (int array [5][5]) {
  for(int column =0;column<4;column++) {
    for (int row =0;row<4;row++) {
      if (array[row][column] == array [row+1][column]) {
        array[row][column] = array [row][column] * 2;
        array[row+1][column]=0;
      }
    }
 /*   if (array[1][column] ==0 && array[3][column] ==0) {
      int temp1;
      temp1 = array [1][column];
      array[1][column]=array[2][column];
      array[2][column]=temp1;
    }
    if (array [2] [column] ==0 && array [3][column]!=0) {
      int temp2= array[2][column];
      array[2][column]=array[3][column];
      array[3][column]=temp2;

    }
*/move_up(array);
  }
  return; 
}
//movev(array);
/*
cout<< "row 1 column 2 is " <<array[1][2]<<endl;
cout<<"row 2 column 2 is "<<array[2][2]<<endl;
cout<<"going to swap when row1column2 hits 0"<<endl;
cout<<endl;
cout<<"row is "<<row<<endl;
cout<<"column is "<<column<<endl;
*/
/*
        if (row <3 && array [row][column] ==0){

cout<<endl;
cout<<endl;
 cout<<"some logic that swaps" <<endl;

          for (int counter = 0; counter <3;counter++){
*/
/*
cout<<"SWAP TIME"<<endl;
cout<<endl;
cout<<counter<<endl;
cout<<endl;

cout<<"this is saying row is less than 3 and the current element is equal to 0"<<endl;
cout<<"row is "<<row<<endl;
cout<<"the current element is "<<array[row][column]<<endl;
cout<<"column is "<<column<<endl;

*/


  //        int a= array[row][column];
    //      int b=array[row+1][column];
//          int c=b;
//cout<<row<<" "<<column<<endl;
//cout<<"this is a before swap " <<a<<endl;
//cout<< "this is b before swap"<<b<<endl;
//cout<<endl;
  //        b=a;
    //      a=c;
      //    array[row][column]=a;
        //  array[row+1][column]=b;
       

//      }
//        }
  //    }


    //}


//  } 







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



//  return;
//}


void printArray(int array[5][5]) {
  for (int i = 0;i<4;i++) {
    for (int j = 0; j<4;j++) {


      cout <<array[i][j] <<" ";
    }
    cout<<endl;
  }
}
int main () {

  int tile [5][5]= { {2,4,2,2}, {8,4,2,2},{0,2,0,4},{8,4,2,4}  };


  cout<<"you are moving up"<<endl;
  printArray(tile);
  move_up(tile);
  combine_up(tile);
  cout<<"after move"<<endl;
  printArray(tile);




  return 0;
}
