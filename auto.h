#include <SFML/System.hpp>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <vector>

class Auto;
class Engine;

class Engine
{
    Engine();
    ~Engine();
    std::vector <Auto> gracze; //Wektor zawieraj¹cy wszystkich graczy.
    void testParam(float Maxpred, float Przys, float Hamulce, float Ster); //Sprawdza czy gracz nie wyda³ za du¿o punktów.
    void ustawPredkosc(float Mapred, float Przys, float Hamulce); //Ustala aktualn¹ prêdkoœæ pojazdu.
    void ustawSkret(float Ster, float katKol, float katAuta); //Porownuje pozycjê kó³ wzglêdem auta i koryguje k¹t skrêtu.
    void Nawierzchnia(); //Sprawdza po czym jedzie auto i okreœla wp³yw na jazdê.
};

class Auto
{
public:
    Auto();
    ~Auto();
    int id;
    int x,y; //Pozycja auta na trasie.
    float katKol; //Skrêt kó³ ustawiany przez gracza.
    float predkosc; //Aktualna prêdkoœæ.
    float kopiaMaxpred; //Zmienne ustalane przez gracza.
    float kopiaPrzys;
    float kopiaHamulce;
    float kopiaSter;
private:
    float Maxpred; //Maksymalna prêdkoœæ pojazdu.
    float Przys; //Przyspieszenie auta.
    float Hamulce; //Moc hamulców.
    float Ster; //Sterownoœæ.
    float katAuta; //Pozycja samochodu wzglêdem kó³.
};
