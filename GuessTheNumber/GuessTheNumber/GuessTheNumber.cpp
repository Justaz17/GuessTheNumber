#include <iostream>
#include <random>

// Generates a random number between 1 and 1000
int generateRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd()); // mersenne twister generator
    std::uniform_int_distribution<> dis(1, 1000); // limits to 1 - 1k including
    return dis(gen); // generates between that limit
}

void chooseMessage() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 2);

    if (dis(gen) == 1) {
        std::cout << "You know the secret!" << std::endl;
    }
    else {
        std::cout << "You got lucky!" << std::endl;
    }
}

int main() {
    int secretNumber = generateRandomNumber();
    int userGuess;
    int guessCount = 0;

    std::cout << "Guess the number between 1 and 1000.\n";

    while (guessCount < 10) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        guessCount++;

        if (userGuess == secretNumber) {
            if (guessCount == 10) {
                std::cout << "You know the secret!\n";
            }
            else {
                chooseMessage();
            }
            return 0;
        }
        else if (userGuess < secretNumber) {
            std::cout << "Too low, try again.\n";
        }
        else {
            std::cout << "Too high, try again.\n";
        }
    }

    std::cout << "You should be able to do better!\n";
    return 0;
}
