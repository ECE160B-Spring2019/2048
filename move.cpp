#include "header.h"
#include "move.h"

using namespace std;

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
        if(array[row][column]!=0){
                combined=1;
        }
        array[row][column] = array [row][column] * 2;
        array[row+1][column]=0;
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
      for (int row=3; row >0; row--) {        //loops through the rows 
        if (array [row][column]== 0) {
          a= array[row][column];
          b=array[row-1][column];
          if(b!=0){
                  moved=1;
          }
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
  return moved;
}
int move::combine_down (int array[5][5]) {
  int combined,moved;
  combined=0;
  for(int column =0;column<4;column++) {
    for (int row =3;row>=0;row--) {
      if (row!=0) { 
        if (array[row][column] == array [row-1][column]) {
          if(array[row][column]!=0){
                  combined=1;
          }      
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
  return combined;
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
        if(array[row][column]!=0){
                combined=1;
        }
        array[row][column] = array [row][column] * 2;
        array[row][column+1]=0;
        if (array[row][column] > max_value) {
          max_value= array[row][column];
        }
      }
    }
    move_left(array);
  }
  return combined;
}

int move::move_right(int array [5][5]) {
  int a,b,c;
  int moved=0; 
       
  for (int counter=0;counter<3;counter++) {
    for ( int row = 0; row <4; row++) {      //loops through the columns
      for (int column=3; column >0; column--) {        //loops through the rows 
        if (array [row][column]== 0) {
          a= array[row][column];
          b=array[row][column-1];
          if(b!=0){
                  moved=1;
          }
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
 
  return moved;
}

int move::combine_right (int array [5][5]) {
  int moved, combined;
  combined=0;
  for(int row =0;row<4;row++) {
    for (int column =3;column>=0;column--) {
      if (column!=0) { 
        if (array[row][column] == array [row][column-1]) {
          if(array[row][column]!=0){
                  combined=1;
          }
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
  return combined;
}
