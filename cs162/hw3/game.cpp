//s
#include "game.h"
#include <iostream>
#include "zoo.h"
#include "monkey.h"
#include "seaotter.h"
#include "meerkat.h"
#include <limits>

/*********************************************************************
** Function:Game
** Description: the game constructor
** Parameters: none
** Pre-Conditions: a game is created
** Post-Conditions: time is now 0
*********************************************************************/
Game::Game(){
    time = 0;
}

/*********************************************************************
** Function: start
** Description: starts the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: a game is started
*********************************************************************/
void Game::start(){
    bool go;
    cout << "You have 100000 dollars and an empty zoo, its time to buy some animals." << endl;
    go = buyAnimalsForTheFirstTime();
    cout << "--------------------------------------------------------------------------" << endl;
    if(go)
        beganCycle();
}

/*********************************************************************
** Function: begain cycle
** Description: contains the main loop that runs the game
** Parameters: none
** Pre-Conditions: start() has been called
** Post-Conditions: the game will end
*********************************************************************/
void Game::beganCycle(){
    bool playing = true;
    while (playing){
        cout << endl;
        z1.triggerRandomEvent();
        cout << "\n" << endl;
        z1.feed();
        time = time + 1;
        z1.ageAnimals();
        cout << "Summary for week " << time << endl;
        z1.printStatus();
        z1.calcRevenue();
        if (z1.isBankrupt()){
            playing = false;
            cout << "Game over" << endl;
        }
        else{
            playing = buyAnimals();
        }
        cout << "--------------------------------------------------------------------------" << endl;   
    }
}

/*********************************************************************
** Function: buyAnimals
** Description: gets input from the user and buys the amount and type of animals they ask for while checking to see if they have enough money
** Parameters: none
** Pre-Conditions: beganCycle has been called
** Post-Conditions: and animal has been added to the zoo, no animals have been added to the zoo, returns false if the user wants to quit
*********************************************************************/
bool Game::buyAnimals(){
    int input, amount = 0, zval = 0;
    bool gettingInput = true, gettingSelection = true;
    while(gettingSelection){
        cout << "input 1 to buy monkies, 2 to buy sea otters, and 3 to buy meerkats and 0 to buy nothing and -1 to quit " << endl;
        input = getUserInput(-1, 5);
        if (input == 1 && z1.getBalance() <= 12000){
            cout << "You dont have enough money for a single monkey, try again. " << endl;
        }
        else if (input == 2 && z1.getBalance() <= 4000){
            cout << "You dont have enough money for a single sea otter, try again. " << endl;
        }
        else if(input == 0){
            gettingInput = false;
            gettingSelection = false;
        }
        else if (input == -1){
            return false;
        }
        else{
            gettingSelection = false;
        }
    }
    extendedInput(input, amount, zval, gettingInput);
    cout << "You spent " << amount*zval << " dollars on animals. Your end of the week balance is " << z1.getBalance() << " dollars" << endl;
    z1.tallyAnimals();
    return true;
}


/*********************************************************************
** Function: extendedInput
** Description: support function for getting input that actually adds the animal
** Parameters: input: the animal being added, amount: the amount of animals to buy, zval: the price of the animal being bought, gettingInput: a bool to check if the user is still getting input
** Pre-Conditions: buyAnimals or buyAnimalsForTheFirstTime has been called
** Post-Conditions: an animal will be added to the zoo or it tells the user they dont have enough money to buy that many animals
*********************************************************************/
void Game::extendedInput(int& input, int& amount, int& zval, bool& gettingInput){
    while(gettingInput){
        cout << "How many would you like to buy (maximum of 100)." << endl;
        amount = getUserInput(0, 101);
        for (int i = 0; i<amount; i++){
            if (input == 1 && z1.getBalance() > (amount-i)*12000){
                Monkey* m1 = new Monkey("monkey", 104);
                z1.addAnimal(m1);
                z1.subtractBalance(12000);
                gettingInput = false;
                zval = 12000;
            }
            else if (input == 2 && z1.getBalance() > (amount-i)*4000){
                Seaotter* s1 = new Seaotter("seaotter", 104);
                z1.addAnimal(s1);
                z1.subtractBalance(4000);
                gettingInput = false;
                zval = 4000;
            }
            else if (input == 3 && z1.getBalance() > (amount-i)*500){
                Meerkat* m1 = new Meerkat("meerkat", 104);
                z1.addAnimal(m1);
                z1.subtractBalance(500);
                gettingInput = false;
                zval = 500;
            }
            else{
                cout << "You dont have enough money to buy that many animals, try again. " << endl;
                break;
            }
        }
    }
}

/*********************************************************************
** Function: buyAnimalsForTheFirstTime
** Description: like buyAnimals, but you have to buy something
** Parameters: none
** Pre-Conditions: the game has just started
** Post-Conditions: an animal will be added to the zoo
*********************************************************************/
bool Game::buyAnimalsForTheFirstTime(){
    int input, amount = 0, zval = 0;
    bool gettingInput = true, gettingSelection = true;
    while(gettingSelection){
        cout << "input 1 to buy monkies, 2 to buy sea otters, and 3 to buy meerkats and -1 to quit " << endl;
        input = getUserInput(-1, 4);
        if (input == 1 && z1.getBalance() <= 12000){
            cout << "You dont have enough money for a single monkey, try again. " << endl;
        }
        else if (input == 2 && z1.getBalance() <= 4000){
            cout << "You dont have enough money for a single sea otter, try again. " << endl;
        }
        else if(input == 0){
            cout << "You have to buy something." << endl;
        }
        else if (input == -1){
            return false;
        }
        else{
            gettingSelection = false;
        }
    }
    extendedInput(input, amount, zval, gettingInput);
    cout << "You spent " << amount*zval << " dollars on animals. Your end of the week balance is " << z1.getBalance() << " dollars" << endl;
    z1.tallyAnimals();
    return true;
}



/*********************************************************************
** Function: getUserInput
** Description: gets input from the user 
** Parameters: low: the low bound for input (inclusive), high: the high bound for the input (exclusive)
** Pre-Conditions: none
** Post-Conditions: an integer in the specfied range will be returned
*********************************************************************/
int Game::getUserInput(int low, int high){
    int input;
    bool exit;
    cin >> input;
    exit = cin.fail();
    while(true){
        if (exit){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Error, please enter the correct input type in the correct range. " << endl;
            cin >> input;
            exit = cin.fail();
        }
        if(!exit){
            if ((low <= input && input < high)){
                break;
            }
            exit = true;
        }
    }
    return input;
}