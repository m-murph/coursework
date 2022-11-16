#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

class Card{
    private:
        int rank; //0 = ace 10=jack 11=queen 12=king
        int suit; //0=diamonds, 1=clubs, 2=hearts, 3=spades

    public:
        void print();
        int getRank();
        int getSuit();
        void printSuit();
        void setContent(int rank, int suit);
};







#endif