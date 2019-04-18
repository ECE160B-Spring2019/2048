#include <iostream>
#include<string.h>
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
class move: public board{
        char playermove;
     public:
        void set(char);
        void movev();
        void moveh();
        void combineh();
        void combinev();
        move();
        ~move();
        check& operator=(move&);
        move(move&);
};
