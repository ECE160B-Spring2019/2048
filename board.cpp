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
