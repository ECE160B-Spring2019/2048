#include <iostream>
using namespace std;

class board{
      int tile[4][4];
    public:
      board()
      {
              initialize();
      }
      void initialize();
      void draw();  
      ~board();
      board(board&);
      board& operator=(board&);
};
class check: public board{
      public:
        int max_value;
        void randomnumber();
        int findempty();
        int win();
        int playagain();
        check();
        ~check();
        check& operator=(check&);
        check(check&);
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
//        move(&move);
};

int main()
{
        //do{
                //board
                //move
                //check
//        }
}
