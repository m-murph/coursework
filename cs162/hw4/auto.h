#include <iostream>
#include "map.h"
using namespace std;

class Auto{
    private:
        int posx;
        int posy;

        int cx;
        int cy;
        int l1x;
        int l1y;
        int b1x;
        int b1y;
    public:
        void readPerceptions();
        void move();
};