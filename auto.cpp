#include "auto.h"

void Engine::testParam(float Maxpred, float Przys, float Hamulce, float Ster)
{
    float suma;
    suma=Maxpred+Przys+Hamulce+Ster;

    if(suma>1.0)
        Error(0);
    else;
}

void Engine::Error(int idbledu)
{
    switch(idbledu){
    case 0:
        {
            printf("Z³y stosunek parametrów pojazdu.\n");
            blad=true;
            break;
        }
    }

}
