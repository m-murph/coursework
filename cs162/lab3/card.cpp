#include <iostream>
#include "card.h"
using namespace std;

void Card::setContent(int r, int s){
    rank = r;
    suit = s;
}

int Card::getRank(){
    return rank;
}

int Card::getSuit(){
    return suit;
}