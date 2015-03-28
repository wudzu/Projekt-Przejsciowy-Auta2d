#include "auto.h"

void Engine::Init()
{
    gracze[0].tempPrzyspieszenie.x=0;
    gracze[0].tempPrzyspieszenie.y=0;
    klatka=0.5;
    gracze[0].tempKat.x=0;
    gracze[0].tempKat.y=1;
    gracze[0].tempPredkosc.x=0;
    gracze[0].tempPredkosc.y=0;
}

void Engine::testParam(float statMaxpr, float statPrzys, float statSter)
{
    float suma;
    suma=statMaxpr+statPrzys+statSter;

    if(suma>5)
        Error(0);
    else
    {
        gracze[0].statPrzys=(1+statPrzys/10); //zwiekszac
        gracze[0].statSter=(1-statSter/10); //zmniejszac
        gracze[0].statMaxpr=10+statMaxpr; //Generalnie predkosc nie przekracza 15
    }

}

void Engine::ustawTrajektorie(float statMaxpr, float statSter, float statPrzys, sf::Vector2f zmiana)
{
    gracze[0].tempPredkosc=gracze[0].tempPredkosc+gracze[0].tempPrzyspieszenie*klatka;

    if(gracze[0].tempPredkosc.x>statMaxpr)
        gracze[0].tempPredkosc.x=statMaxpr;
    else if(gracze[0].tempPredkosc.x<-statMaxpr)
        gracze[0].tempPredkosc.x=-statMaxpr;

    if(gracze[0].tempPredkosc.y>statMaxpr)
        gracze[0].tempPredkosc.y=statMaxpr;
    else if(gracze[0].tempPredkosc.y<-statMaxpr)
        gracze[0].tempPredkosc.y=-statMaxpr;

    gracze[0].tempPozycja= gracze[0].tempPozycja+gracze[0].tempPredkosc*klatka;

    temp1=gracze[0].tempKat*(gracze[0].tempKat.x*gracze[0].tempPredkosc.x+gracze[0].tempKat.y*gracze[0].tempPredkosc.y);
    temp1=gracze[0].tempPredkosc-temp1;

    gracze[0].tempPrzyspieszenie=temp1*(float)(-3.0)*sprawdzTarcie()-gracze[0].tempPredkosc*sprawdzTarcie();

    gracze[0].tempKat.x=gracze[0].tempKat.x*cos(gracze[0].zmiana.y*klatka*PI/180*4)-gracze[0].tempKat.y*sin(gracze[0].zmiana.y*klatka*PI/180*4);
    gracze[0].tempKat.y=gracze[0].tempKat.y*cos(gracze[0].zmiana.y*klatka*PI/180*4)+gracze[0].tempKat.x*sin(gracze[0].zmiana.y*klatka*PI/180*4);

    temp2=(float)sqrt(gracze[0].tempKat.x*gracze[0].tempKat.x+gracze[0].tempKat.y*gracze[0].tempKat.y);

    gracze[0].tempKat=gracze[0].statSter*gracze[0].tempKat/temp2;

    gracze[0].tempPrzyspieszenie=gracze[0].tempPrzyspieszenie+gracze[0].zmiana.x*gracze[0].tempKat;
    gracze[0].tempPrzyspieszenie=gracze[0].statPrzys*gracze[0].tempPrzyspieszenie*sprawdzTarcie();

    gracze[0].stanWyjscia[0]=gracze[0].tempPozycja;
    gracze[0].stanWyjscia[1]=gracze[0].tempKat;
    gracze[0].stanWyjscia[2]=gracze[0].tempPrzyspieszenie;
}

float Engine::sprawdzTarcie()
{
    return 1;
}

void Engine::Error(int idbledu)
{
    switch(idbledu){
    case 0:
        {
            printf("Zly stosunek parametrów pojazdu.\n");
            blad=true;
            break;
        }
    }

}
