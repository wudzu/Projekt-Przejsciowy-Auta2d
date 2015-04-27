#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include <stdio.h>
#include "Vector2.hpp"
#define PI 3.14159265
#include <windows.h>



class Auto;
class Engine;

class Engine
{
public:
    Engine();
    ~Engine();
    void petlaGlowna();
    float qrsqrt(float num);//szybki odwrotny pierwiastek

private:
    HINSTANCE DLL0,DLL1,DLL2,DLL3;
    typedef void( * POBRANE )(float*, float*, float*, float*, float*, float*, float*, float*, float*, float*, bool*, std::vector<std::vector<std::vector<unsigned char>>>,float, float);
    POBRANE sterowanie0;
    POBRANE sterowanie1;
    POBRANE sterowanie2;
    POBRANE sterowanie3;

    void tworzMape(char*);
    void rysujScene();
    std::vector<sf::Text> tekst;
    sf::RenderWindow okno;
    sf::Texture samochod;
    sf::Texture mapaT;
    sf::Sprite mapa;

    float sprawdzTarcie(int nrAuta);
    void nawierzchnia(); //Sprawdza po czym jedzie auto i okresla wplyw na jazde.
    std::vector <float> tarcie;
    float wspolTarcia;
    float wspolWysokosci;
    float wspolTarcieBoczne;
    float wspolPredkosci;
    float wspolSterownosci;

    std::vector<std::vector<std::vector<unsigned char>>> mapaRGB;
    sf::Vector2f sprawdzWysokosc(int nrAuta);
    void znajdzStart(sf::Vector2f &start, sf::Vector2f &startOrientacja);
    void znajdzMete();
    int sprawdzWygrana();
    sf::Vector2f meta;

    sf::Vector2f temp1;
    float temp2;

    sf::Clock zegar;
    sf::Time czas;
    sf::Time klatka;

    float qx2;
    int* qi;     // zmienne do szybkiego pierwiastka odwrotnego

    std::vector <Auto> gracze; //Wektor zawieraj¹cy wszystkich graczy.
    void ustawTrajektorie(int nrAuta); //Ustala aktualna predkosc pojazdu.
};

class Auto
{
    friend class Engine;
public:
    Auto();
    Auto(sf::Texture* tekstura, sf::Vector2f pol, sf::Vector2f orient);
    ~Auto();
    float statPrzys, statSter; //Zmienne wplywajace na wlasciwosci pojazdu.
    sf::Vector2f kopiaPrzyspieszenie;
    sf::Vector2f kopiaSterowanie;
    sf::Vector2f kopiaOrientacja;
    sf::Vector2f kopiaPozycja;
    sf::Vector2f kopiaV;
    sf::Vector2f V;
    sf::Vector2f przyspieszenie; //Przyspieszenie auta.
    sf::Vector2f sterowanie;
    sf::Vector2f orientacja; //Pozycja samochodu wzgledem kol.
    sf::Vector2f pozycja;
    sf::Sprite obrazek;
};
