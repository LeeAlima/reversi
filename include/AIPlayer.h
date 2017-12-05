
#ifndef EX2_AIPLAYER_H
#define EX2_AIPLAYER_H

#include "../include/GameLogic.h"
#include "../include/Player.h"

class AIPlayer : public Player {
public:
    /**
     * constructor of HumanPlayer.
     * @param type - as char ('X' or 'O')
     * @param screen  - as the game screen
     */
    AIPlayer(char type,ConsoleScreen *screen);

    char getType() const;

    int getScore() const;

    string chooseCell(GameLogic &game) ;

    void setScore(int number);

protected:
    char type;
    int score;
    ConsoleScreen *player_screen_;

};

#endif //EX2_AIPLAYER_H