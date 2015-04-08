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
    float qrsqrt(float num);//szybkie odwrotny pierwiastek
private:
    HINSTANCE DLL;
    typedef void( * POBRANE )(float&, float&);
    void tworzMape();
    POBRANE test2;
    //float klatka; //dlugosc trwania klatki
    sf::Vector2f temp1;
    float temp2;
    sf::Clock zegar;
    sf::Time czas;
    sf::Time klatka;
    float qx2;
    int* qi;     // zmienne do szybkiego pierwiastka odwrotnego
    std::vector<std::vector<std::vector<unsigned char>>> mapaRGB;
    bool blad; //Gdy jest program przestaje dziala.
    std::vector <Auto> gracze; //Wektor zawieraj¹cy wszystkich graczy.
    void testParam(float statMaxpr, float statPrzys, float statSter); //Sprawdza czy gracz nie wydal za du¿o punktów i oblicz maksymalne wartosci.
    void ustawTrajektorie(int nrAuta); //Ustala aktualna predkosc pojazdu.
    void nawierzchnia(); //Sprawdza po czym jedzie auto i okresla wplyw na jazde.
    void Error(int idbledu); //Informuje usera o bledach.
    void rysujScene();
    //void Init(); //Funkcja inicjalizujaca wartosci poczatkowe.
    float sprawdzTarcie(int nrAuta);
    std::vector <float> tarcie;

    sf::RenderWindow okno;
    sf::Texture samochod;
    sf::Texture mapaT;
    sf::Sprite mapa;
};

class Auto
{
    friend class Engine;
public:
    Auto();
    Auto(sf::Texture* tekstura);
    ~Auto();
    int id;
    //sf::Vector2f tempPozycja; //Pozycja auta na trasie.
    //sf::Vector2f tempKat;
    //sf::Vector2f tempPredkosc;
    //sf::Vector2f tempPrzyspieszenie;
    //sf::Vector2f stanWyjscia[3];
    float statMaxpr, statPrzys, statSter; //Zmienne wplywajace na wlasciwosci pojazdu.
    //zmienne JESZCZE nie uzyte
    //float kopiaMaxpred; //Zmienne ustalane przez gracza.
    sf::Vector2f kopiaPrzyspieszenie;
    sf::Vector2f kopiaSterowanie;
    sf::Vector2f kopiaOrientacja;
    sf::Vector2f V;
    sf::Vector2f kopiaV;
    sf::Vector2f przyspieszenie; //Przyspieszenie auta.
    sf::Vector2f sterowanie; //
    sf::Vector2f orientacja; //Pozycja samochodu wzgledem kol.
    sf::Vector2f pozycja;
    sf::Vector2f kopiaPozycja;
    sf::Sprite obrazek;
};
