#ifndef RPS_GAMEMANAGER_H
#define RPS_GAMEMANAGER_H

#include "Game.h"
#include "GameInterface.h"

class GameManager {
public:
    Game startGame();
    void endGame();

private:
    Game game;
    GameInterface& gameInterface;
    char choseGameMode();
    void playBestOfThree();
    void playSingleGame();
    void displayScore();
    void announceRoundWinner();
    void announceSessionWinner();

    int currentRoundScore;
    int playerWins;
    int computerWins;
};

#endif //RPS_GAMEMANAGER_H