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

class check: public move{
        int max_value;
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
       max_value = 0;
}        
//copy-constructor
check::check(check& c)
{
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
                        if(tile[jj,ii]==0)
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
                value==1 ? (tile[row,col]=4) : (tile[row,col]=2);
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
        do{
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
                do{
                        string s;
                        if(s=="w" || s="W"){
                                move_up(tile);
                                compine_up(tile);
                                answer=randomnumber();
                        }else if(s=="s" || s=="S"){
                                move_down(tile);
                                compine_down(tile); 
                                answer=randomnumber();
                        }else if(s=="a" || s=="A"){
                                move_left(tile);
                                compine_left(tile);
                                answer=randomnumber();
                        }else if(s=="d" || s=="D"){
                                move_right(tile);
                                compine_right(tile);
                                answer=randomnumber();
                        }else{
                                cout<<"Choice is invaild, please pick W, S, A, or D."<<endl;
                        }
                }while(answer==1)
        }while(answer==2)
}
