#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <string>

class Game
{
private:
    sf::RenderWindow gameWindow; // okno gry
public:
    Game(float screenW = 1280, float screenH=720, std::string str = "tytul_gry");
    ~Game(){}

    void setTitle(std::string str); //ustawia tytul okna (w sumie jest domyslny konstruktor, wiec srednio to potrzebne)
    void initWindow(); // wywolanie okna
};
#endif // GAME_H_
