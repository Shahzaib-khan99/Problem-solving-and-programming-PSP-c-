#include <iostream>
using namespace std;

int main() 
{
    int secretnumber = 15;
    int tries = 3;
    int guess;
    
    cout << "Welcome to the guessing game." << endl;
    cout << "Try to guess the secret number." << endl;

    for (int i = 1; i <= tries; i++) 
    {
        cout << "\nAttempt " << i << ": Enter your guess: ";
        cin >> guess;

        if (guess != secretnumber)
        {
            cout << "Incorrect guess. Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You have guessed the number." << endl;
            break;  
        }

        if (guess > secretnumber)
        {
            cout << "Your guess is too high. Try again.\n";
        }
        else if (guess < secretnumber)
        {
            cout << "Your guess is too low. Try again.\n";
        }

        if (i == tries)
        {
            cout << "You've used all your attempts. The secret number was " << secretnumber << endl;
        }
    }

    return 0;
}
