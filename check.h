#include "move.h"
using namespace std;

class check: public move{
      public: 
        int randomnumber();
        int findempty();
        int win();
        int possiblemoves();
        int playagain();
        check();
        ~check(){}
        check& operator=(check& c){max_value=c.max_value;}
        check(check& c);
};


