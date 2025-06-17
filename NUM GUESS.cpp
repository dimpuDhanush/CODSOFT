#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    int guess;

    cout << " Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > secretNumber) {
            cout << "Too high! Try again. " << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again. " << endl;
        } else {
            cout << " Correct! You guessed the number!" << endl;
        }

    } while (guess != secretNumber);

    return 0;
}
