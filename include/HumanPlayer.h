
#ifndef EX2_HUMANPLAYER_H
#define EX2_HUMANPLAYER_H

#include "../include/GameLogic.h"
#include "../include/Player.h"
#include "../include/ConsoleScreen.h"



class HumanPlayer : public Player {
public:
    /**
     * constructor of HumanPlayer.
     * @param type - as char ('X' or 'O')
     * @param screen  - as the game screen
     */
    HumanPlayer(char type,ConsoleScreen *screen);

    char getType() const;

    int getScore() const;

    string chooseCell(GameLogic &gameLogic) ;

    void setScore(int number);

    string fixPointToCom(string user_choice) const;

protected:
    char type;
    int score;
    ConsoleScreen *player_screen_;

};


#endif //EX2_HUMANPLAYER_H