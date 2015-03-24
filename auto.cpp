#include "auto.h"

void Engine::testParam(float statMaxpr, float statPrzys, float statSter)
{
    float suma;
    suma=statMaxpr+statPrzys+statSter;

    if(suma>1.0)
        Error(0);
    else;
}

void Engine::ustawPredkosc(float Maxpred, sf::Vector2f Przys)
{
   // Auto::predkosc.x=
    if(Auto.predkosc.x>Maxpred)
        Auto.predkosc.x=Maxpred;
    if(Auto.pozycja.y>Maxpred)
        Auto.pozycja.y>Maxpred;
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
