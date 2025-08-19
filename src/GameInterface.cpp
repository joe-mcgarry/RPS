#include "../include/GameInterface.h"
#include <iostream>

// Input strings
static const std::string CHOICE_PROMPT = "Enter 'r' for rock, 'p' for paper, 's' for scissors, or 'q' to quit: ";
static const std::string PLAY_AGAIN_PROMPT = "Play again? Enter 'y' to play again, or 'q' to quit: ";

void GameInterface::displayResult(const std::string& playerChoice, const std::string& computerChoice, const std::string& winner) {
    std::string winnerString;

    if (winner == "player") {
        winnerString = "You win!";
    } else if (winner == "computer") {
        winnerString = "Computer wins!";
    } else {
        winnerString = "It's a tie.";
    }

    std::cout << "You chose " << playerChoice << ", computer chose " << computerChoice << ". " <<
        winnerString << std::endl;
}

char GameInterface::getPlayerChoice() {
    char playerInput;
    do {
        displayInputPrompt(CHOICE_PROMPT);
        playerInput = readPlayerInput();

        if (!isValidChoice(playerInput)) {
            std::cout << "Invalid choice. Please enter 'r', 'p', 's' or 'q' " << std::endl;
        }
    } while (!isValidChoice(playerInput));

    return playerInput;
}

bool GameInterface::getPlayAgainChoice() {
    char lowerInput;
    bool shouldPlayAgain = false;
    do {
        displayInputPrompt(PLAY_AGAIN_PROMPT);
        char playAgainInput = readPlayerInput();
        lowerInput = convertToLowercase(playAgainInput);

        if (!isValidChoice(lowerInput)) {
            std::cout << "Invalid choice. Please enter 'y' or 'q' " << std::endl;
        }

        shouldPlayAgain = (lowerInput == GameConstants::PLAY_AGAIN_CHAR);
    } while (lowerInput != GameConstants::PLAY_AGAIN_CHAR && lowerInput != GameConstants::QUIT_CHAR);
    return shouldPlayAgain;
}

// Private methods
void GameInterface::displayInputPrompt(const std::string& prompt) {
    std::cout << prompt;
}

char GameInterface::readPlayerInput() {
    char playerInput;
    std::cin >> playerInput;
    return playerInput;
}

bool GameInterface::isValidChoice(char choice) {
    char lowerChoice = convertToLowercase(choice);
    return (lowerChoice == GameConstants::ROCK_CHAR ||
        lowerChoice == GameConstants::PAPER_CHAR ||
        lowerChoice == GameConstants::SCISSORS_CHAR ||
        lowerChoice == GameConstants::PLAY_AGAIN_CHAR ||
        lowerChoice == GameConstants::QUIT_CHAR);
}

char GameInterface::convertToLowercase(char choice) {
    return std::tolower(choice);
}