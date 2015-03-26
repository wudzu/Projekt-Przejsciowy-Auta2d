#include "game.h"

Game::Game(float screenW, float screenH, std::string str)
{
    gameWindow.create(sf::VideoMode(screenW,screenH), str);
}
// MAGIC! DON'T TOUCH IT ;)
//-----------------------
void Game::initWindow()
{
    while(gameWindow.isOpen())
    {
        sf::Event event;
        while(gameWindow.pollEvent(event))
        {
            /*Gry bedzie wiecej, mozna wrzucic switcha
            ------------------
            switch(event.type)
            {
                case sf::Event::Closed:
                    gameWindow.close();
                    break;
                case sf::Event::Resized:
                    gameWindow.setSize(sf::Vector2u(event.size.width, event.size.height));
                    break;
            }*/
                //wyjscie z gry - escape
            if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                gameWindow.close();
        }
        gameWindow.clear();
        gameWindow.display();
    }
}

void Game::setTitle(std::string str)
{
    gameWindow.setTitle(str);
}
