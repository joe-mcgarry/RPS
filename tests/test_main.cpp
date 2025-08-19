#include <catch2/catch_test_macros.hpp>
#include "../include/Game.h"

TEST_CASE("determineWinner handles game logic correctly") {
    Game game;

    SECTION("handles ties") {
        REQUIRE(game.determineWinner('r', 'r') == "tie");
        REQUIRE(game.determineWinner('s', 's') == "tie");
        REQUIRE(game.determineWinner('p', 'p') == "tie");
    }

    SECTION("player wins scenarios") {
        REQUIRE(game.determineWinner('p', 'r') == "player");
        REQUIRE(game.determineWinner('r', 's') == "player");
        REQUIRE(game.determineWinner('s', 'p') == "player");
    }

    SECTION("computer wins scenarios") {
        REQUIRE(game.determineWinner('s', 'r') == "computer");
        REQUIRE(game.determineWinner('r', 'p') == "computer");
        REQUIRE(game.determineWinner('p', 's') == "computer");
    }

    SECTION("handles mixed case input") {
        REQUIRE(game.determineWinner('R', 's') == "player");
        REQUIRE(game.determineWinner('P', 'R') == "player");
        REQUIRE(game.determineWinner('p', 'p') == "tie");
        REQUIRE(game.determineWinner('r', 'S') == "player");
    }
}

TEST_CASE("getComputerChoice returns valid choice") {
    Game game;

    for (int i = 0; i < 100; ++i) {
        char choice = game.getComputerChoice();
        REQUIRE((choice == 'r' || choice == 'p' || choice == 's'));
    }
}
