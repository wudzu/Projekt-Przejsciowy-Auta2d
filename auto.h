#include <SFML/System.hpp>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include "Vector2.hpp"

class Auto;
class Engine;

class Engine
{
public:
    Engine();
    ~Engine();
    bool blad; //Gdy jest program przestaje dzia³aæ.
    std::vector <Auto> gracze; //Wektor zawieraj¹cy wszystkich graczy.
    void testParam(float statMaxpr, float statPrzys, float statSter); //Sprawdza czy gracz nie wyda³ za du¿o punktów i oblicz maksymalne wartosci.
    void ustawPredkosc(float maxPred, sf::Vector2f Przys); //Ustala aktualn¹ prêdkoœæ pojazdu.
    void ustawSkret(sf::Vector2f Ster, sf::Vector2f katKol, sf::Vector2f katAuta); //Porownuje pozycjê kó³ wzglêdem auta i koryguje k¹t skrêtu.
    void Nawierzchnia(); //Sprawdza po czym jedzie auto i okreœla wp³yw na jazdê.
    void Error(int idbledu); //Informuje usera o b³êdach.
};

class Auto
{
public:
    Auto();
    ~Auto();
    int id;
    sf::Vector2f pozycja; //Pozycja auta na trasie.
    sf::Vector2f katKol; //Skrêt kó³ ustawiany przez gracza.
    sf::Vector2f predkosc; //Aktualna prêdkoœæ.
    float kopiaMaxpred; //Zmienne ustalane przez gracza.
    sf::Vector2f kopiaPrzys;
    //sf::Vector2f kopiaHamulce;
    sf::Vector2f kopiaSter;
    float statMaxpr, statPrzys, statSter; //Zmienne wplywajace na wlasciwosci pojazdu.
    //float statHam;
    float maxPred; //Maksymalna prêdkoœæ pojazdu.
    sf::Vector2f Przys; //Przyspieszenie auta.
    //sf::Vector2f Hamulce; //Moc hamulców.
    sf::Vector2f Ster; //Sterownoœæ.
    sf::Vector2f katAuta; //Pozycja samochodu wzglêdem kó³.
    float maxZmiana; // Maksymalne wartosci obliczane z rozdanych punktow.
    float maxSkret;
};
