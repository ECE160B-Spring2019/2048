#include "header.h"
#include "move.h"

using namespace std;


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



