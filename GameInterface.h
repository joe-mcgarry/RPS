#ifndef RPS_GAMEINTERFACE_H
#define RPS_GAMEINTERFACE_H

#include <string>
#include "GameConstants.h"

enum class Choice {
    ROCK,
    PAPER,
    SCISSORS,
    QUIT,
    INVALID
};

class GameInterface {
public:
    void displayResult(const std::string& playerChoice,
        const std::string& computerChoice,
        const std::string& winner);
    char getPlayerChoice();
    bool getPlayAgainChoice();
    char convertToLowercase(char choice);
private:
    bool isValidChoice(char choice);
    void displayInputPrompt(const std::string& prompt);
    char readPlayerInput();
};

#endif //RPS_GAMEINTERFACE_H