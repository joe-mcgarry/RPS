//
// Created by Joe McGarry on 09/08/2025.
//

#include "../include/Game.h"
#include <cctype>
#include <iostream>
#include <random>

GameInterface gameInterface;

std::string Game::choiceToString(char choice) {
    Choice choiceEnum = charToChoice(choice);
    return choiceToString(choiceEnum);
}

Choice Game::charToChoice(char choice) {
    char lowerChoice = gameInterface.convertToLowercase(choice);

    if (lowerChoice == GameConstants::ROCK_CHAR) return Choice::ROCK;
    if (lowerChoice == GameConstants::PAPER_CHAR) return Choice::PAPER;
    if (lowerChoice == GameConstants::SCISSORS_CHAR) return Choice::SCISSORS;
    if (lowerChoice == GameConstants::QUIT_CHAR) return Choice::QUIT;

    return Choice::INVALID;
}

std::string Game::choiceToString(Choice choice) {
    switch (choice) {
        case Choice::ROCK:
            return "rock";
        case Choice::PAPER:
            return "paper";
        case Choice::SCISSORS:
            return "scissors";
        case Choice::QUIT:
            return "quit";
        case Choice::INVALID:
            return "invalid";
        default:
            return "unknown";
    }
}

bool Game::playerBeats(Choice player, Choice computer) {
    return (player == Choice::ROCK && computer == Choice::SCISSORS) ||
           (player == Choice::PAPER && computer == Choice::ROCK) ||
           (player == Choice::SCISSORS && computer == Choice::PAPER);
}

char Game::getComputerChoice() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);

    int choice = dis(gen);
    switch (choice) {
        case 0: return GameConstants::ROCK_CHAR;
        case 1: return GameConstants::PAPER_CHAR;
        case 2: return GameConstants::SCISSORS_CHAR;
        default: return GameConstants::ROCK_CHAR; // fallback
    }
}

std::string Game::determineWinner(char playerChoice, char computerChoice) {
    Choice player = charToChoice(playerChoice);
    Choice computer = charToChoice(computerChoice);

    if (player == computer) {
        return "tie";
    }

    if (playerBeats(player, computer)) {
            return "player";
    }

    return "computer";
}

char Game::getPlayerChoice() {
    return gameInterface.getPlayerChoice();
}

bool Game::playAgain() {
    return gameInterface.getPlayAgainChoice();
}

void Game::playRound() {
    const char playerChoice = getPlayerChoice();
    if (playerChoice == GameConstants::QUIT_CHAR) {
        std::cout << "Quitting game";
        return;
    }
    const char computerChoice = getComputerChoice();
    std::string playerString = choiceToString(playerChoice);
    std::string computerString = choiceToString(computerChoice);
    const std::string winner = determineWinner(playerChoice, computerChoice);
    gameInterface.displayResult(playerString, computerString, winner);
    if (playAgain()) {
        playRound();
    }
}
