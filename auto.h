#include <SFML/System.hpp>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include "Vector2.hpp"
#define PI 3.14159265

class Auto;
class Engine;

class Engine
{
public:
    Engine();
    ~Engine();
    float klatka; //dlugosc trwania klatki
    sf::Vector2f temp1;
    float temp2;
    bool blad; //Gdy jest program przestaje dziala.
    std::vector <Auto> gracze; //Wektor zawieraj¹cy wszystkich graczy.
    void testParam(float statMaxpr, float statPrzys, float statSter); //Sprawdza czy gracz nie wydal za du¿o punktów i oblicz maksymalne wartosci.
    void ustawTrajektorie(float statMaxpr, float statSter, float statPrzys, sf::Vector2f zmiana); //Ustala aktualna predkosc pojazdu.
    void Nawierzchnia(); //Sprawdza po czym jedzie auto i okresla wplyw na jazde.
    void Error(int idbledu); //Informuje usera o bledach.
    void Init(); //Funkcja inicjalizujaca wartosci poczatkowe.
    float sprawdzTarcie();
};

class Auto
{
public:
    Auto();
    ~Auto();
    int id;
    sf::Vector2f zmiana; //Modyfikowana predkosc i skret. x-predkosc y-skret
    sf::Vector2f tempPozycja; //Pozycja auta na trasie.
    sf::Vector2f tempKat;
    sf::Vector2f tempPredkosc;
    sf::Vector2f tempPrzyspieszenie;
    sf::Vector2f stanWyjscia[3];
    float statMaxpr, statPrzys, statSter; //Zmienne wplywajace na wlasciwosci pojazdu.

    //zmienne JESZCZE nie uzyte
    float kopiaMaxpred; //Zmienne ustalane przez gracza.
    sf::Vector2f kopiaPrzys;
    sf::Vector2f kopiaSter;
    sf::Vector2f Przys; //Przyspieszenie auta.
    sf::Vector2f Ster; //Sterownosc.
    sf::Vector2f katAuta; //Pozycja samochodu wzgledem kol.
};
