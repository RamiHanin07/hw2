//Names: Rami Hanin & Jeremy Dobzranski
//Assignment: Homework 2
//Project Description: Creating a virtual roulette simulation and testing multiple betting types. 
//Date: 9/14/2021


#include <iostream>

using namespace std;

int martinGaleStrat(int slots, int zeroes, int visits, int money);
int fixedStrat(int slots, int zeroes, int visits, int money);
int randomStrat(int slots, int zeroes, int visits, int money);

int main(){
    int slots = 0;
    int zeroes = 0;
    int visits = 0;
    int money = 0;
    int menu = 0;

    //Initial information gathering section and opening pleasantries
    cout << "Welcome to Casino Simulator, today we're playing Roulette." << endl;
    cout << "Please answer the following questions so we can get started: " <<endl;
    cout << "1. How many slots should there be on your roulette wheel? (2-200)" << endl;
    cin >> slots;
    while(slots < 2 || slots > 200){
        cout << "That is an invalid input. Please enter an integer from 2-200" << endl;
        cin >> slots;
    }
    cout << "2. How many of the slots will be labeled with 0 or 00? (0, 1, 2)" <<endl;
    cin >> zeroes;
    while(zeroes < 0 || zeroes > 2){
        cout << "That is an invalid input. Please enter an integer of 0, 1, or 2" << endl;
        cin >> zeroes;
    }
    cout << "3. How many times do you want to visit the casino in this simulation? (1-100,000)" << endl;
    cin >> visits;
    while(visits < 1 || visits > 100000){
        cout << "That is an invalid input. Please enter an integer between 1 and 100,000 inclusive" << endl;
        cin >> visits;
    }
    cout << "4. How many dollars do you wish to start with during each visit? (1-1,000,000)" << endl;
    cin >> money;
    while(money < 1 || money > 1000000){
        cout << "That is an invalid input. Please enter an integer between 1 and 1,000,000 inclusive" << endl;
        cin >> money;
    }
    cout << "|-----------------------------------------------------|" << endl;
    cout << "Thank you for inputting all the relevant information" << endl;
    cout << "Please select from one of the below betting strategies to get started simulating" << endl;
    cout << "1. Martingale Strategy" << endl;
    cout << "2. Random Strategy" << endl;
    cout << "3. Fixed Bet Strategy" << endl;
    cin >> menu;
    while(menu < 1 || menu > 3){
        cout << "That was an invalid input." << endl;
        cout << "Please select from one of the below betting strategies to get started simulating" << endl;
        cout << "1. Martingale Strategy" << endl;
        cout << "2. Random Strategy" << endl;
        cout << "3. Fixed Bet Strategy" << endl;
        cin >> menu;
    }

    if(menu == 1){
        martinGaleStrat(slots,zeroes,visits,money);
    }else if(menu == 2){
        randomStrat(slots,zeroes,visits,money);
    }else if(menu == 3){
        fixedStrat(slots,zeroes,visits,money);
    }
    return 0;
}


int martinGaleStrat(int slots, int zeroes, int visits, int money){
    cout << "Martingale Strategy has been selected." << endl;
    int betAmt = 1;
    int cont;
    bool quit = true;
    int spin = rand() % slots + 0;
    cout << "Now betting with $1" << endl;
    if (spin % 2 == 0){
        cout << "You won your bet!" << endl;
    }
    else {
        cout << "You lost your bet. Doubling your betting amount and trying again." << endl;
            money = money - betAmt;
            cout << "\nYour remaining balance: $" << money << endl;
        do {
                cout << "\nNow betting with $" << (betAmt * 2)  << endl;
                spin = rand() % slots + 0;
                    if (spin % 2 == 0){
                        cout << "\nYou won your bet and have earned $"<< (betAmt * 4) << endl;
                        money = money + (betAmt * 4);
                        cout << "\nYour new balance: $" << money << endl; 
                        cout << "|-----------------------------------------------------|" << endl;
                        cout << "Would you like to continue? Press 1 to continue, and 2 to exit: ";
                        while(!(cin >> cont) || cont < 1 || cont > 2){
                            cout << "Please enter 1 or 2: ";
                            cin.clear();
                            cin.ignore(132, '\n');
                        }
                        if(cont == 1){
                            quit = false;
                            cout << "Continuing..." << endl;
                            betAmt = betAmt * 2;
                        }
                        else if(cont == 2){
                            quit = true; 
                            cout << "Exiting..." << endl;
                            return 0;
                        }
                    }
                    else{
                        betAmt = betAmt * 2;
                        if (betAmt > money){
                            cout << "You don't have enough money to bet again!" << endl;
                            return 0;
                        }
                        else{
                            cout << "You lost your bet. Doubling your betting amount and trying again." << endl;
                            money = money - betAmt;
                            cout << "Your remaining balance: $" << money << endl;
                            quit = false;
                        }
                    }
        } while (money > 0 && quit == false);
    }
    return 0;
}

int randomStrat(int slots, int zeroes, int visits, int money){
    cout << "Random Strategy" << endl;
    return 0;
}

int fixedStrat(int slots, int zeroes, int visits, int money){
    cout << "fixedStrat" << endl;
}
