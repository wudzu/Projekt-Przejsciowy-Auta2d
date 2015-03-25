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
    bool blad; //Gdy jest program przestaje dzia�a�.
    std::vector <Auto> gracze; //Wektor zawieraj�cy wszystkich graczy.
    void testParam(float statMaxpr, float statPrzys, float statSter); //Sprawdza czy gracz nie wyda� za du�o punkt�w i oblicz maksymalne wartosci.
    void ustawPredkosc(float maxPred, sf::Vector2f Przys); //Ustala aktualn� pr�dko�� pojazdu.
    void ustawSkret(sf::Vector2f Ster, sf::Vector2f katKol, sf::Vector2f katAuta); //Porownuje pozycj� k� wzgl�dem auta i koryguje k�t skr�tu.
    void Nawierzchnia(); //Sprawdza po czym jedzie auto i okre�la wp�yw na jazd�.
    void Error(int idbledu); //Informuje usera o b��dach.
};

class Auto
{
public:
    Auto();
    ~Auto();
    int id;
    sf::Vector2f pozycja; //Pozycja auta na trasie.
    sf::Vector2f katKol; //Skr�t k� ustawiany przez gracza.
    sf::Vector2f predkosc; //Aktualna pr�dko��.
    float kopiaMaxpred; //Zmienne ustalane przez gracza.
    sf::Vector2f kopiaPrzys;
    //sf::Vector2f kopiaHamulce;
    sf::Vector2f kopiaSter;
    float statMaxpr, statPrzys, statSter; //Zmienne wplywajace na wlasciwosci pojazdu.
    //float statHam;
    float maxPred; //Maksymalna pr�dko�� pojazdu.
    sf::Vector2f Przys; //Przyspieszenie auta.
    //sf::Vector2f Hamulce; //Moc hamulc�w.
    sf::Vector2f Ster; //Sterowno��.
    sf::Vector2f katAuta; //Pozycja samochodu wzgl�dem k�.
    float maxZmiana; // Maksymalne wartosci obliczane z rozdanych punktow.
    float maxSkret;
};
