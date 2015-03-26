#include "auto.h"



void Engine::testParam(float statMaxpr, float statPrzys, float statSter)
{
    float suma;
    suma=statMaxpr+statPrzys+statSter;

    if(suma>10)
        Error(0);
    else
    {
        gracze[0].maxZmiana=10+10*sin(statPrzys);
        gracze[0].maxSkret=10+10*sin(statSter);
        gracze[0].maxPred=220+220*sin(statMaxpr);
    }

}

void Engine::ustawPredkosc(float maxPred, sf::Vector2f Przys)
{
    gracze[0].predkosc.x+=Przys.x*gracze[0].maxZmiana;
    gracze[0].predkosc.y+=Przys.y*gracze[0].maxZmiana;

    if(gracze[0].predkosc.x>maxPred)
        gracze[0].predkosc.x=maxPred;
    else if(gracze[0].predkosc.x<=0)
        gracze[0].predkosc.x=0;
    if(gracze[0].pozycja.y>maxPred)
        gracze[0].pozycja.y=maxPred;
    else if(gracze[0].predkosc.y<=0)
        gracze[0].predkosc.y=0;
}

void ustawSkret(sf::Vector2f Ster, sf::Vector2f katKol, sf::Vector2f katAuta)
{

}

void Engine::Error(int idBledu)
{
    switch(idBledu){
    case 0:
        {
            printf("Zly stosunek parametrów pojazdu.\n");
            blad=true;
            break;
        }
    }

}
