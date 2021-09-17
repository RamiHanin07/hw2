//Names: Rami Hanin & Jeremy Dobzranski
//Assignment: Homework 2
//Project Description: Creating a virtual roulette simulation and testing multiple betting types. 
//Date: 9/14/2021


#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int martinGaleStrat(int slots, int zeroes, int visits, int money, int &totalRisked, int &totalWinnings, int &biggestWin, int &brokeNum, int &averageChange, int &winningTimes, int &losingTimes, int &evenTimes);
int fixedStrat(int slots, int zeroes, int visits, int money, int &totalRisked, int &totalWinnings, int &biggestWin, int &brokeNum, int &averageChange, int &winningTimes, int &losingTimes, int &evenTimes);
int randomStrat(int slots, int zeroes, int visits, int money, int &totalRisked, int &totalWinnings, int &biggestWin, int &brokeNum, int &averageChange, int &winningTimes, int &losingTimes, int &evenTimes);

int main(){
    int slots = 0;
    int zeroes = 0;
    int visits = 0;
    int money = 0;
    int menu = 0;
    int totalRisked = 0;
    int totalWinnings = 0;
    int biggestWin = 0;
    int brokeNum = 0;
    int averageChange = 0;
    int winningTimes = 0;
    int losingTimes = 0;
    int evenTimes = 0;
    srand(time(NULL));

    //Initial information gathering section and opening pleasantries
    cout << "Welcome to Casino Simulator, today we're playing Roulette." << endl;
    cout << "Please answer the following questions so we can get started: " <<endl;
    cout << "1. How many slots should there be on your roulette wheel? (2-200)" << endl;
        //Input validation code segment. This is used repeatedly throughout the entirety of the program
        while(!(cin >> slots) || slots < 2 || slots > 200){
            cout << "Invalid input, please pick an integer between 2 and 200: ";
            cin.clear();
            cin.ignore(132, '\n');
        }
    cout << "2. How many of the slots will be labeled with 0 or 00? (0, 1, 2)" <<endl;
        while(!(cin >> zeroes) || zeroes < 0 || zeroes > 2){
            cout << "That is an invalid input. Please enter an integer of 0, 1, or 2" << endl;
                cin.clear();
                cin.ignore(132, '\n');
        }
    cout << "3. How many times do you want to visit the casino in this simulation? (1-100,000)" << endl;
        while(!(cin >> visits) || visits < 1 || visits > 100000){
            cout << "That is an invalid input. Please enter an integer between 1 and 100,000 inclusive" << endl;
                cin.clear();
                cin.ignore(132, '\n');
        }
    cout << "4. How many dollars do you wish to start with during each visit? (1-1,000,000)" << endl;
    while(!(cin >> money) || money < 1 || money > 1000000){
        cout << "That is an invalid input. Please enter an integer between 1 and 1,000,000 inclusive" << endl;
            cin.clear();
            cin.ignore(132, '\n');
    }
    cout << "|-----------------------------------------------------|" << endl;
    cout << "Thank you for inputting all the relevant information" << endl;
    cout << "Please select from one of the below betting strategies to get started simulating" << endl;
    cout << "1. Martingale Strategy" << endl;
    cout << "2. Random Strategy" << endl;
    cout << "3. Fixed Bet Strategy" << endl;
    
    while(!(cin >> menu) || menu < 1 || menu > 3){
        cout << "That was an invalid input." << endl;
        cout << "Please select from one of the below betting strategies to get started simulating" << endl;
        cout << "1. Martingale Strategy" << endl;
        cout << "2. Random Strategy" << endl;
        cout << "3. Fixed Bet Strategy" << endl;
            cin.clear();
            cin.ignore(132, '\n');
    }

    if(menu == 1){
        martinGaleStrat(slots,zeroes,visits,money, totalRisked, totalWinnings, biggestWin, brokeNum, averageChange, winningTimes, losingTimes, evenTimes);
        cout << "Finished with Martingale Strategy" << endl;
        cout << "Displaying Statistics:" << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "Slots Input at Start: " << slots << endl;
        cout << "Zeroes Input at Start: " << zeroes << endl;
        cout << "Visits Input at Start: " << visits << endl;
        cout << "Betting Amount Input at Start: " << money << endl;
        cout << "Total Amount Risked: " << totalRisked << endl;
        cout << "Total Amount Won: " << totalWinnings << " , " << totalWinnings / totalRisked * 100 << "\% gain" << endl;
        cout << "Largest win: " << biggestWin << endl;
        cout << "Number of times went bust: " << brokeNum << endl;
        cout << "Average Change in Money: " << averageChange / visits << endl;
        cout << "Number of winning visits: " << winningTimes << endl;
        cout << "Number of losing visits: " << losingTimes << endl;
        cout << "Number of even visits: " << evenTimes << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "Thank you for visiting the roulette simulator :)" << endl;
        cout << "Press any key + enter to exit" << endl;
        cin >> menu;
        return 0;
    }else if(menu == 2){
        randomStrat(slots,zeroes,visits,money, totalRisked, totalWinnings, biggestWin, brokeNum, averageChange, winningTimes, losingTimes, evenTimes);
        cout << "Finished with Random Strategy" << endl;
        cout << "Displaying Statistics:" << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "Slots Input at Start: " << slots << endl;
        cout << "Zeroes Input at Start: " << zeroes << endl;
        cout << "Visits Input at Start: " << visits << endl;
        cout << "Betting Amount Input at Start: " << money << endl;
        cout << "Total Amount Risked: " << totalRisked << endl;
        cout << "Total Amount Won: " << totalWinnings << " , " << totalWinnings / totalRisked * 100 << "\% gain" << endl;
        cout << "Largest win: " << biggestWin << endl;
        cout << "Number of times went bust: " << brokeNum << endl;
        cout << "Average Change in Money: " << averageChange / visits << endl;
        cout << "Number of winning visits: " << winningTimes << endl;
        cout << "Number of losing visits: " << losingTimes << endl;
        cout << "Number of even visits: " << evenTimes << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "Thank you for visiting the roulette simulator :)" << endl;
        cout << "Press any key + enter to exit" << endl;
        cin >> menu;
        return 0;
    }else if(menu == 3){
        fixedStrat(slots,zeroes,visits,money, totalRisked, totalWinnings, biggestWin, brokeNum, averageChange, winningTimes, losingTimes, evenTimes);
        cout << "Finished with Fixed Strategy" << endl;
        cout << "Displaying Statistics:" << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "Slots Input at Start: " << slots << endl;
        cout << "Zeroes Input at Start: " << zeroes << endl;
        cout << "Visits Input at Start: " << visits << endl;
        cout << "Betting Amount Input at Start: " << money << endl;
        cout << "Total Amount Risked: " << totalRisked << endl;
        cout << "Total Amount Won: " << totalWinnings << " , " << totalWinnings / totalRisked * 100 << "\% gain" << endl;
        cout << "Largest win: " << biggestWin << endl;
        cout << "Number of times went bust: " << brokeNum << endl;
        cout << "Average Change in Money: " << averageChange / visits << endl;
        cout << "Number of winning visits: " << winningTimes << endl;
        cout << "Number of losing visits: " << losingTimes << endl;
        cout << "Number of even visits: " << evenTimes << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "Thank you for visiting the roulette simulator :)" << endl;
        cout << "Press any key + enter to exit" << endl;
        cin >> menu;
        return 0;
    }
    return 0;
}


int martinGaleStrat(int slots, int zeroes, int visits, int money, int &totalRisked, int &totalWinnings, int &biggestWin, int &brokeNum, int &averageChange, int &winningTimes, int &losingTimes, int &evenTimes){
    cout << "Martingale Strategy has been selected." << endl;
    int betAmt = 1;
    int cont;
    bool quit = true;
    int startingMoney = money;
    int increment = 0;
    bool lost = false;
    do{
        //increment counter to keep track of the total number of visits to the casino
        increment++;
        cout << "Visit " << increment << " to the casino" << endl;
        startingMoney = money;
        int spin = rand() % slots + 0;
        //begins the martingale strategy with $1. This value is not entered by the user 
        cout << "Now betting with $1" << endl;
        if (spin % 2 == 0){
            cout << "You won your bet!" << endl;
            startingMoney += 1;
        }
        else {
            cout << "You lost your bet. Doubling your betting amount and trying again." << endl;
                //deducts the bet amount from the account balance that the user started with 
                startingMoney = startingMoney - betAmt;
                cout << "\nYour remaining balance: $" << startingMoney << endl;
            do {
                    cout << "\nNow betting with $" << (betAmt * 2)  << endl;
                    spin = rand() % slots + 0;
                        if(zeroes == 1){
                            if(spin == 0){
                                cout << "Spin hits: GREEN " << spin << endl;
                                lost = true;
                            }
                        }
                        if(zeroes == 2){
                            if(spin == 0 || spin == 100){
                                cout << "Spin hits: GREEN " << spin << endl;
                                lost = true;
                            }
                        }
                        if (spin % 2 == 0 && lost != true){
                            //returns to the user the amount they betted + the winnings
                            cout << "\nYou won your bet and have earned $"<< (betAmt * 4) << endl;
                            startingMoney = startingMoney + (betAmt * 4);
                            cout << "\nYour new balance: $" << startingMoney << endl; 
                            cout << "|-----------------------------------------------------|" << endl;
                            quit = true;
                            // cout << "Would you like to continue? Press 1 to continue, and 2 to exit: ";
                            // while(!(cin >> cont) || cont < 1 || cont > 2){
                            //     cout << "Please enter 1 or 2: ";
                            //     cin.clear();
                            //     cin.ignore(132, '\n');
                            // }
                            // //Allows the user to decide if they want to continue placing bets, or quitting after winning one time
                            // if(cont == 1){
                            //     quit = false;
                            //     cout << "Continuing..." << endl;
                            //     betAmt = betAmt * 2;
                            // }
                            // else if(cont == 2){
                            //     //boolean is assigned the value of 'true', ending the do-while loop and exiting the program 
                            //     quit = true; 
                            //     cout << "Exiting..." << endl;
                            //     return 0;
                            // }
                            if(betAmt > biggestWin){
                                biggestWin = betAmt;
                            }
                        }
                        if(spin % 2 != 0 && lost != true){
                            betAmt = betAmt * 2;
                            if (betAmt > startingMoney){
                                //exits the strategy when the bet amount is higher than the total amount of money the user has 
                                cout << "You don't have enough money to bet again!" << endl;
                            }
                            else{
                                cout << "You lost your bet. Doubling your betting amount and trying again." << endl;
                                startingMoney = startingMoney - betAmt;
                                cout << "Your remaining balance: $" << startingMoney << endl;
                                //boolean remains false, allowing the do-while loop to repeat 
                                quit = false;
                            }
                        }
            }while (startingMoney > 0 && quit == false);
        }
        //Updating overall statistics
        if(startingMoney == 0){
            brokeNum++;
        }
        //Check if you finished with more money than you started
        if(startingMoney > money){
            winningTimes++;
            totalWinnings+= startingMoney-money;
            averageChange += startingMoney - money;
        }
        //Check if you finished with less money than you started
        if(startingMoney < money){
            losingTimes++;
            averageChange -= money - startingMoney;
        }
        //Check if you went even
        if(startingMoney == money){
            evenTimes++;
        }
    }while(increment < visits);
    totalRisked = money * visits;
    return 0;
}

int randomStrat(int slots, int zeroes, int visits, int money, int &totalRisked, int &totalWinnings, int &biggestWin, int &brokeNum, int &averageChange, int &winningTimes, int &losingTimes, int &evenTimes){
    //Local Variables
    int increment = 0;
    int startingMoney = money;
    int bettingAmount = 0;
    int spin = 0;
    bool lost = false;
    int bets = 0;
    
    cout << "Random Strategy has been chosen" << endl;
    //Will have two do while loops
    //1. for controlling all visits to the casino, which will reset betting values 
    //2. for controlling each individual visit to the casino, to continue betting until stipulations are met (either 50 bets or bust)
    do{
        //Visits to the casino
        increment++;
        cout << "Visit number " << increment << " to the casino" << endl;
        startingMoney = money;
        //Individual gambling sections
        do{
            bets++;
            lost = false;
            bettingAmount = rand() % startingMoney + 1;
            cout << "Betting " << bettingAmount << " on black " << endl;
            spin = rand() % slots + 0;
            //Checking conditionals to see if it landed green, black, or red
            if(zeroes == 1){
                if(spin == 0){
                    cout << "Spin hits: GREEN " << spin << endl;
                    lost = true;
                }
            }
            if(zeroes == 2){
                if(spin == 0 || spin == 100){
                    cout << "Spin hits: GREEN " << spin << endl;
                    lost = true;
                }
            }
            //Check to see if the spin was even or odd, and if it was even you win, if it was odd you lose
            //Uses conditionals to ensure proper flag checking
            if(spin % 2 == 0 && lost != true){
                cout << "Spin hits: BLACK " << spin << endl;
                cout << "You win: " << bettingAmount  << endl;
                startingMoney += bettingAmount;
                if(bettingAmount > biggestWin){
                    biggestWin = bettingAmount;
                }
            }
            if(spin % 2 != 0 && lost != true){
                cout << "Spin hits: RED " << spin << endl;
                cout << "You lose: " << bettingAmount << endl;
                lost = true;
            }
            if(lost == true){
                startingMoney -= bettingAmount;
            }
            cout << "Current amount left: " << startingMoney << endl;
        }while(startingMoney > 0 && bets < 50);
        //Updating overall statistics
        if(startingMoney == 0){
            brokeNum++;
        }
        //Check if you finished with more money than you started
        if(startingMoney > money){
            winningTimes++;
            totalWinnings+= startingMoney-money;
            averageChange += startingMoney - money;
        }
        //Check if you finished with less money than you started
        if(startingMoney < money){
            losingTimes++;
            averageChange -= money - startingMoney;
        }
        //Check if you went even
        if(startingMoney == money){
            evenTimes++;
        }
        // cout << "Right before outside loop " << endl;
        // cout << "Increment: " << increment << endl;
        // cout << "Visits: " << visits << endl;
    }while(increment < visits);
    
    totalRisked = money * visits;
    return 0;
}

int fixedStrat(int slots, int zeroes, int visits, int money, int &totalRisked, int &totalWinnings, int &biggestWin, int &brokeNum, int &averageChange, int &winningTimes, int &losingTimes, int &evenTimes){
    int dollarAmt;
    int betNum = 0;
    int spin = 0;
    int increment = 0;
    int startingMoney = money;
    int next;
    bool quit = false;
    bool lost = false;
    srand(time(NULL));
    cout << "Fixed Strategy has been chosen" << endl;
    do{
        increment++;
        betNum = 0;
        quit = false;
        cout << "Visit number " << increment << " to casino" << endl;
        startingMoney = money;
        cout << "Place your bet. Enter a specific $ amount: ";
        while(!(cin >> dollarAmt) || dollarAmt < 1 || dollarAmt > startingMoney){
            cout << "Invalid amount. Must enter a dollar value between $1 and the maximum amount of money you have brought with you to the casino, which is: $" << startingMoney << endl;
            cin.clear();
            cin.ignore(132, '\n');
        }
        cout << "\nNow betting with $" << dollarAmt<< endl;
        do {
            spin = rand() % slots + 0;
            if(zeroes == 1){
                if(spin == 0){
                    cout << "Spin hits: GREEN " << spin << endl;
                    startingMoney = startingMoney - dollarAmt;
                    cout << "\nRemaining account balance: $" << startingMoney << endl;
                    spin = rand() % slots + 0;
                    betNum++;
                    lost = true;
                }
            }
            if(zeroes == 2){
                if(spin == 0 || spin == 100){
                    cout << "Spin hits: GREEN " << spin << endl;
                    startingMoney = startingMoney - dollarAmt;
                    cout << "\nRemaining account balance: $" << startingMoney << endl;
                    betNum++;
                    lost = true;
                }
            }
            if (spin % 2 == 0 && lost != true){
                cout << "\nYou won your bet and have earned $"<< (dollarAmt * 2) << endl;
                startingMoney = startingMoney + (dollarAmt * 2);
                cout << "\nNew account balance: $" << startingMoney << endl;
                betNum++;
                if(dollarAmt > biggestWin){
                    biggestWin = dollarAmt;
                }
            }
            if(spin % 2 != 0 && lost != true){
                cout << "\nYou lost your bet." << endl;
                startingMoney = startingMoney - dollarAmt;
                cout << "\nRemaining account balance: $" << startingMoney << endl;
                betNum++;
            }
            // cout << "Press 1 to continue: ";
            // while(!(cin >> next) || next != 1){
            //     cout << "Please enter 1 to continue: ";
            //         cin.clear();
            //         cin.ignore(132, '\n');
            // }
            // if(next == 1){
            //     quit = false;
            //     cout << "Continuing..." << endl;
            // }
            if (startingMoney < dollarAmt) {
                cout << "\nYou don't have enough money to continue placing bets. It's time for you to go home." << endl;
                cout << "\nYour final account balance: $" << startingMoney << endl;
                quit = true;
            }
            lost = false;
        }while (betNum <= 50 && quit == false);

        if (betNum > 50) {
            cout << "\nYou have bet 50 times. You cannot place any more than 50 bets." << endl;
        }
        if(startingMoney == 0){
            brokeNum++;
        }
        //Check if you finished with more money than you started
        if(startingMoney > money){
            winningTimes++;
            totalWinnings+= startingMoney-money;
            averageChange += startingMoney - money;
        }
        //Check if you finished with less money than you started
        if(startingMoney < money){
            losingTimes++;
            averageChange -= money - startingMoney;
        }
        //Check if you went even
        if(startingMoney == money){
            evenTimes++;
        }
    }while(increment < visits);
    totalRisked = money * visits;
}

