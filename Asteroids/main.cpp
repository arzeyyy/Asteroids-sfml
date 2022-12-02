#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <ctime>

#include "Game.h"

int main()
{
    srand(time(NULL));
    Game game;

    game.Run();

    return 0;
}

