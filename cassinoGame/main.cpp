#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function declarations
void rules();

int main() {
    string playerName;
    int balance; // Player's balance
    int bettingAmount;
    int guess;
    int dice; // The number to guess
    char choice;

    srand(time(0)); // Seed for random number generator

    cout << "\t\t==== WELCOME TO THE CASINO NUMBER GUESSING GAME ====\n\n";
    cout << "Enter your name: ";
    getline(cin, playerName);

    cout << "Enter the starting balance to play: $";
    cin >> balance;

    do {
        system("clear||cls");
        rules();

        cout << "\nYour current balance is: $" << balance << "\n";

        // Get player's betting amount
        do {
            cout << "Enter amount to bet: $";
            cin >> bettingAmount;
            if (bettingAmount > balance) {
                cout << "Betting amount cannot be more than your balance!\n"
                     << "Re-enter amount:\n";
            }
        } while (bettingAmount > balance);

        // Get player's guess
        do {
            cout << "Guess a number between 1 and 10: ";
            cin >> guess;
            if (guess <= 0 || guess > 10) {
                cout << "Number must be between 1 and 10!\nRe-enter your guess:\n";
            }
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1; // Random number between 1 and 10

        if (guess == dice) {
            cout << "\nCongratulations! You guessed the number " << dice << " correctly.\n";
            balance += bettingAmount * 10;
        } else {
            cout << "\nOops! The winning number was " << dice << ".\n";
            balance -= bettingAmount;
        }

        cout << "Your new balance is: $" << balance << "\n";

        if (balance == 0) {
            cout << "You have
