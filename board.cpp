#include <iostream>
#include <string.h>
using namespace std;

class board{
    protected:
      int tile[4][4];
    public:
      board()
      {
              initialize();
      }
      void initialize();
      void draw();  
      ~board(){}
      board(board&);
      board& operator=(board& b){memcpy(tile, b.tile, sizeof(tile));}
};

board::board(board& b)
{
        memcpy(tile, b.tile, sizeof(tile));
}

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

void board::draw()
{
        cout<<"*****************"<<endl;
        for(int jj=0; jj<4; jj++)
        {
                cout<<"*";
                for(int ii=0; ii<4; ii++)
                {
                        if(tile[jj][ii]!=0){
                                cout<<tile[jj][ii]<<"*";
                        }else{
                                cout<<"   *";
                        }
                }
        cout<<endl<<"*****************"<<endl;                   
        } 
}

int main()
{
        board b;
        b.draw();
}
