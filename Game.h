#ifndef RPS_GAME_H
#define RPS_GAME_H

#include <string>
#include "GameInterface.h"
#include "GameConstants.h"

class Game {
public:
    void playRound();
    char getPlayerChoice();
    char getComputerChoice();
    std::string determineWinner(char playerChoice, char computerChoice);
    bool playAgain();

private:
    GameInterface gameInterface;
    Choice charToChoice(char choice);
    std::string choiceToString(char choice);
    std::string choiceToString(Choice choice);
    bool playerBeats(Choice player, Choice computer);
};

#endif //RPS_GAME_H