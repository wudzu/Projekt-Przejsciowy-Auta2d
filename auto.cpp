#include "auto.h"

Engine::Engine() : okno(sf::VideoMode(800, 600), "Samochodziki")\
{
    klatka=sf::seconds(0.05f);
    samochod.loadFromFile("auto.png");
    mapaT.loadFromFile("mapa.png");
    mapa.setTexture(mapaT);
    zegar.restart();
    Auto a(&samochod);
    tarcie.push_back(0.5f);
    gracze.push_back(a);
    gracze[0].statSter=2.9f;
    gracze[0].przyspieszenie.x=0;
    gracze[0].przyspieszenie.y=0;
    gracze[0].orientacja.x=1;
    gracze[0].orientacja.y=0;
    gracze[0].V.x=0;
    gracze[0].V.y=0;
    gracze[0].pozycja.x=100;
    gracze[0].pozycja.y=50;
    gracze[0].obrazek.setColor(sf::Color::Red);
    gracze[0].sterowanie.y=1.0f;
    gracze[0].sterowanie.x=1;
    gracze[0].kopiaSterowanie.y=1;
    gracze[0].kopiaSterowanie.x=1;
}

Engine::~Engine()
{

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

void Engine::rysujScene()
{
    okno.clear();
    okno.draw(mapa);
    for (int i=0;i<gracze.size();++i)
    {
        gracze[i].obrazek.setPosition(gracze[i].pozycja);
        gracze[i].obrazek.setRotation(atan2(gracze[i].orientacja.y,gracze[i].orientacja.x)*180/ PI);
        okno.draw(gracze[i].obrazek);
    }
    okno.display();
}

void Engine::petlaGlowna()
{
    switch (gracze.size())
    {
    case 4:
        //wczytaj 4. dll i zrob czwartą funkcje

    case 3:
        // to samo dla 3.
    case 2:

    case 1:
        //DLL= LoadLibrary("DLL.dll");
        //ZewnTrajektoria=(POBRANE) GetProcAddress(DLL, "Trajektoria");
        break;
    }
    std::vector<std::thread> watki;
    bool dziala=1;
    switch (gracze.size())
    {
    case 4:
        //watki.push_back(sterowanie3, (gracze[3].kopiaV.x),(gracze[3].kopiaV.y),(gracze[3].kopiaPrzyspieszenie.x),(gracze[3].kopiaPrzyspieszenie.y),(gracze[3].kopiaOrientacja.x),(gracze[3].kopiaOrientacja.y),(gracze[3].kopiaSterowanie.x),(gracze[3].kopiaSterowanie.y),dziala);
    case 3:
        //watki.push_back(sterowanie2, (gracze[2].kopiaV.x),(gracze[2].kopiaV.y),(gracze[2].kopiaPrzyspieszenie.x),(gracze[2].kopiaPrzyspieszenie.y),(gracze[2].kopiaOrientacja.x),(gracze[2].kopiaOrientacja.y),(gracze[2].kopiaSterowanie.x),(gracze[2].kopiaSterowanie.y),dziala);
    case 2:
        //watki.push_back(sterowanie1, (gracze[1].kopiaV.x),(gracze[1].kopiaV.y),(gracze[1].kopiaPrzyspieszenie.x),(gracze[1].kopiaPrzyspieszenie.y),(gracze[1].kopiaOrientacja.x),(gracze[1].kopiaOrientacja.y),(gracze[1].kopiaSterowanie.x),(gracze[1].kopiaSterowanie.y),dziala);
    case 1:
        //watki.push_back(sterowanie0, (gracze[0].kopiaV.x),(gracze[0].kopiaV.y),(gracze[0].kopiaPrzyspieszenie.x),(gracze[0].kopiaPrzyspieszenie.y),(gracze[0].kopiaOrientacja.x),(gracze[0].kopiaOrientacja.y),(gracze[0].kopiaSterowanie.x),(gracze[0].kopiaSterowanie.y),dziala);
        break;
    }

    while(dziala)
    {
        czas+=zegar.restart();
        while (czas>=klatka)
        {
            czas-=klatka;
            for (int i=0;i<gracze.size();++i)
                ustawTrajektorie(i);
        }

        sf::Event event;
        while (okno.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                okno.close();
        }
        rysujScene();
        //ZewnTrajektoria(gracze[0].V,gracze[0].przyspieszenie,gracze[0].orientacja);
        dziala=okno.isOpen();
    }
    //tu musi byc case z zwalnianiem wszystkich bibliotek
    //FreeLibrary(DLL);
}

void Engine::ustawTrajektorie(int nrAuta)
{
    gracze[nrAuta].V=gracze[nrAuta].V+gracze[nrAuta].przyspieszenie*klatka.asSeconds();

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
    gracze[nrAuta].pozycja= gracze[nrAuta].pozycja+gracze[nrAuta].V*klatka.asSeconds()*5.0f;

    temp1=gracze[nrAuta].orientacja*(gracze[nrAuta].orientacja.x*gracze[nrAuta].V.x+gracze[nrAuta].orientacja.y*gracze[nrAuta].V.y);
    temp1=gracze[nrAuta].V-temp1;

    gracze[nrAuta].przyspieszenie=temp1*(-3.0f)*sprawdzTarcie(nrAuta)-gracze[nrAuta].V*sprawdzTarcie(nrAuta);

    gracze[nrAuta].orientacja.x=gracze[nrAuta].orientacja.x*cos(gracze[nrAuta].sterowanie.y*klatka.asSeconds()*PI/10*klatka.asSeconds()*gracze[nrAuta].statSter)-gracze[nrAuta].orientacja.y*sin(gracze[nrAuta].sterowanie.y*klatka.asSeconds()*PI/10*klatka.asSeconds()*gracze[nrAuta].statSter);
    gracze[nrAuta].orientacja.y=gracze[nrAuta].orientacja.y*cos(gracze[nrAuta].sterowanie.y*klatka.asSeconds()*PI/10*klatka.asSeconds()*gracze[nrAuta].statSter)+gracze[nrAuta].orientacja.x*sin(gracze[nrAuta].sterowanie.y*klatka.asSeconds()*PI/10*klatka.asSeconds()*gracze[nrAuta].statSter);

    temp2=sqrt(gracze[nrAuta].orientacja.x*gracze[nrAuta].orientacja.x+gracze[nrAuta].orientacja.y*gracze[nrAuta].orientacja.y);

    gracze[nrAuta].orientacja=gracze[nrAuta].orientacja/temp2;

    gracze[nrAuta].przyspieszenie=gracze[nrAuta].przyspieszenie+gracze[nrAuta].sterowanie.x*gracze[nrAuta].orientacja;
    gracze[nrAuta].przyspieszenie=gracze[nrAuta].przyspieszenie*sprawdzTarcie(nrAuta);


    gracze[nrAuta].kopiaV=gracze[nrAuta].V;
    gracze[nrAuta].kopiaPrzyspieszenie=gracze[nrAuta].przyspieszenie;
    gracze[nrAuta].kopiaOrientacja=gracze[nrAuta].orientacja;
    gracze[nrAuta].kopiaPozycja=gracze[nrAuta].pozycja;
    gracze[nrAuta].sterowanie=gracze[nrAuta].kopiaSterowanie;

    printf("\n\n\n");
    printf("%f\t%f\t%f\t%f\n",gracze[nrAuta].V.x,gracze[nrAuta].V.y,gracze[nrAuta].orientacja.x,gracze[nrAuta].orientacja.y);
    printf("%f\t%f\t",gracze[nrAuta].pozycja.x,gracze[nrAuta].pozycja.y);
    //printf("%f\t%f",)
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

Auto::Auto(sf::Texture* tekstura) : obrazek(*tekstura, sf::IntRect(42,25,155,75))
{
    //obrazek.setTexture(*tekstura);
    //obrazek.setTextureRect(sf::IntRect(42,25,155,75));
    obrazek.setOrigin(sf::Vector2f(57,25));
}

Auto::~Auto()
{

}
