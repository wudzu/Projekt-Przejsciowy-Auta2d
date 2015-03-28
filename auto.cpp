#include "auto.h"

Engine::Engine()
{
    Auto a;
    gracze.push_back(a);
    gracze[0].przyspieszenie.x=0;
    gracze[0].przyspieszenie.y=0;
    klatka=0.5;
    gracze[0].orientacja.x=0;
    gracze[0].orientacja.y=1;
    gracze[0].V.x=0;
    gracze[0].V.y=0;
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

void Engine::ustawTrajektorie(int nrAuta)
{
    gracze[nrAuta].V=gracze[nrAuta].V+gracze[nrAuta].przyspieszenie*klatka;

/*
    if(gracze[nrAuta].tempPredkosc.x>statMaxpr)
        gracze[nrAuta].tempPredkosc.x=statMaxpr;
    else if(gracze[nrAuta].tempPredkosc.x<-statMaxpr)
        gracze[nrAuta].tempPredkosc.x=-statMaxpr;

    if(gracze[0].tempPredkosc.y>statMaxpr)
        gracze[0].tempPredkosc.y=statMaxpr;
    else if(gracze[0].tempPredkosc.y<-statMaxpr)
        gracze[0].tempPredkosc.y=-statMaxpr;
*/
    gracze[nrAuta].pozycja= gracze[nrAuta].pozycja+gracze[nrAuta].V*klatka;

    temp1=gracze[nrAuta].orientacja*(gracze[nrAuta].orientacja.x*gracze[nrAuta].V.x+gracze[nrAuta].orientacja.y*gracze[nrAuta].V.y);
    temp1=gracze[nrAuta].V-temp1;

    gracze[nrAuta].przyspieszenie=temp1*(-3.0f)*sprawdzTarcie(nrAuta)-gracze[nrAuta].V*sprawdzTarcie(nrAuta);

    gracze[nrAuta].orientacja.x=gracze[nrAuta].orientacja.x*cos(gracze[nrAuta].sterowanie.y*klatka*PI/45*klatka*gracze[nrAuta].statSter)-gracze[nrAuta].orientacja.y*sin(gracze[nrAuta].sterowanie.y*klatka*PI/45*klatka*gracze[nrAuta].statSter);
    gracze[nrAuta].orientacja.y=gracze[nrAuta].orientacja.y*cos(gracze[nrAuta].sterowanie.y*klatka*PI/45*klatka*gracze[nrAuta].statSter)+gracze[nrAuta].orientacja.x*sin(gracze[nrAuta].sterowanie.y*klatka*PI/45*klatka*gracze[nrAuta].statSter);

    temp2=sqrt(gracze[nrAuta].orientacja.x*gracze[nrAuta].orientacja.x+gracze[nrAuta].orientacja.y*gracze[nrAuta].orientacja.y);

    gracze[nrAuta].orientacja=gracze[nrAuta].orientacja/temp2;

    gracze[nrAuta].przyspieszenie=gracze[nrAuta].przyspieszenie+gracze[nrAuta].sterowanie.x*gracze[nrAuta].orientacja;
    gracze[nrAuta].przyspieszenie=gracze[nrAuta].przyspieszenie*sprawdzTarcie(nrAuta);

    //gracze[0].stanWyjscia[0]=gracze[0].tempPozycja;
    //gracze[0].stanWyjscia[1]=gracze[0].orientacja;
    //gracze[0].stanWyjscia[2]=gracze[0].tempPrzyspieszenie;
}

float Engine::sprawdzTarcie(int nrAuta)
{
    return tarcie[nrAuta];
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

void Engine::nawierzchnia()
{
    //ustawia odpowiednie wartosci na wektorze z tarciem
}

Auto::Auto()
{

}

Auto::~Auto()
{

}
