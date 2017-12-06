
#ifndef EX2_DSA_H
#define EX2_DSA_H

#include "../include/GameFlow.h"

#include <iostream>
#include <unistd.h>
#include "../include/AIPlayer.h"
#include "../include/ConsoleScreen.h"
#include "../include/HumanPlayer.h"
#include "../include/Client.h"

GameFlow::GameFlow(int size):size(size){
    // creating a new game
    this->screen = new ConsoleScreen();
}

GameFlow::~GameFlow() {
    delete game;
}

void GameFlow::play() {
    // printing the board
    Board *board = this->game->getBoard();
    Player *player;
    screen->printBoard(*board);
    string user_choice;
    string choice_to_compare;
    // as long as the game is not over
    while (!this->game->checksIfGameOver(*this->game->getBoard())) {
        board = this->game->getBoard();
        player = (game->getPlayer('C'));
        if (!(computer) || player->getType() == 'X' ) {
            screen->printPlayerOrder(player->getType());
        }
        // if the player can make a move
        user_choice = this->game->getPlayer('C')->chooseCell(*this->game);
        if (user_choice.compare("NO MOVE")){
            // split the input
            vector<int> point_coordinate = screen->cutPoint(user_choice);
            int first_number = point_coordinate.front();
            int second_number = point_coordinate.back();

            screen->printPlayerMove(player->getType(), first_number, second_number);

            // updating the board and printing it
            this->game->updateBoard(first_number , second_number ,
                                    this->game->getPlayer('D')->getType(),
                                    *this->game->getBoard());
            this->screen->printEndl();
            this->screen->printBoard(*board);
        }
 else { // if no move is possible
            this->screen->printString("No moves are possible for you");
            this->screen->printEndl();
        }
        this->game->changePlayer();
    }
    showScores();
}

void GameFlow::showScores() {
    screen->printGameOver(this->game->returnsWhoWon(),
                          this->game->getPlayer1Score(), game->getPlayer2Score());
}

void GameFlow::setUpGame() {
    this->screen = new ConsoleScreen();
    int playerCheck = this->screen->printOpenMenu();
    Player *player1, *player2;
    Client client();
    if (playerCheck == 2) {
        player1 = new HumanPlayer('X', screen);
        player2 = new AIPlayer('O', screen);
        this->computer = true;
    } else if (playerCheck==1){
        player1 = new HumanPlayer('X', screen);
        player2 = new HumanPlayer('O', screen);
        this->computer = false;
    }
    /*else if(playerCheck=3){
        try {

        }

    }*/
    this->game = new GameLogic(size, player1, player2, screen);
}

#endif //EX2_DSA_H