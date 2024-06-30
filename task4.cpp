// Number Guessing Game CPP program\
#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

int main() {
   
    srand(static_cast<unsigned int>(time(0)));

    
    int randomNumber = rand() % 100 + 1;
    int userGuess = 0;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "I have generated a random number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

   
    while (userGuess != randomNumber) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess < 1 || userGuess > 100) {
            cout << "Please enter a number between 1 and 100." << endl;
        } else if (userGuess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number: " << randomNumber << endl;
        }
    }

    return 0;
}
