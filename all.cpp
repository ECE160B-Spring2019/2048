#include <iostream>
#include <string.h>
using namespace std;

class board{
    protected:
      int tile[4][4];
    public:
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
        cout<<"*********************"<<endl;
        for(int jj=0; jj<4; jj++)
        {
                cout<<"*";
                for(int ii=0; ii<4; ii++)
                {
                        if(tile[jj][ii]!=0){
                                if(tile[jj][ii]<10){
                                        cout<<"  "<<tile[jj][ii]<<" *";
                                }else if(tile[jj][ii]<100){
                                        cout<<" "<<tile[jj][ii]<<" *";
                                }else if(tile[jj][ii]<1000){
                                        cout<<tile[jj][ii]<<" *";
                                }else{
                                        cout<<tile[jj][ii]<<"*";
                                }

                        }else{
                                cout<<"   *";
                        }
                }
        cout<<endl<<"*********************"<<endl;                   
        } 
        cout<<endl;
}

//sets value in the array
void board::set(int row, int col, int number)
{
        tile[row][col]=number;
}

//reads the value in the array
int board::pull(int row, int col)
{
        return tile[row][col];
}

class check: public board{
        int max_value;
      public:
        board b; 
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
        board x;
        x=b;
}

//copy-constructor
check::check(check& c)
{
        b=c.b;
        max_value=c.max_value;
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
                        if(b.pull(jj,ii)==0)
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
                value==1 ? b.set(row,col,4) : b.set(row,col,2);
         }
         return win(); 
}

int check::win()
{
        int end;
        b.draw(); 
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
        check c;
        //something with move
        int answer = c.randomnumber();
        //randomnumber inserts a random number in a random spot and also checks if the player won or lost and if they did they ask if they want to play again. 
        //answer=0
        //doen't want to play again
        //answer=1
        //in middle of the game
        //answer = 2
        //wants to play again
}
