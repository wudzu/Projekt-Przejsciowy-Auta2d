#include "game.h"

int main()
{
    Game * game = new Game;

    game -> initWindow();

    delete game;
}
