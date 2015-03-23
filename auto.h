#include <SFML/System.hpp>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdio.h>

class Auto;
class Engine;

class Engine
{
    Engine();
    ~Engine();
    bool blad; //Gdy jest program przestaje dzia�a�.
    std::vector <Auto> gracze; //Wektor zawieraj�cy wszystkich graczy.
    void testParam(float Maxpred, float Przys, float Hamulce, float Ster); //Sprawdza czy gracz nie wyda� za du�o punkt�w.
    void ustawPredkosc(float Mapred, float Przys, float Hamulce); //Ustala aktualn� pr�dko�� pojazdu.
    void ustawSkret(float Ster, float katKol, float katAuta); //Porownuje pozycj� k� wzgl�dem auta i koryguje k�t skr�tu.
    void Nawierzchnia(); //Sprawdza po czym jedzie auto i okre�la wp�yw na jazd�.
    void Error(int idbledu); //Informuje usera o b��dach.
};

class Auto
{
public:
    Auto();
    ~Auto();
    int id;
    int x,y; //Pozycja auta na trasie.
    float katKol; //Skr�t k� ustawiany przez gracza.
    float predkosc; //Aktualna pr�dko��.
    float kopiaMaxpred; //Zmienne ustalane przez gracza.
    float kopiaPrzys;
    float kopiaHamulce;
    float kopiaSter;
private:
    float Maxpred; //Maksymalna pr�dko�� pojazdu.
    float Przys; //Przyspieszenie auta.
    float Hamulce; //Moc hamulc�w.
    float Ster; //Sterowno��.
    float katAuta; //Pozycja samochodu wzgl�dem k�.
};
