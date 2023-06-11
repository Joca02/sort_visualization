
#include <iostream>
#include "Program.hpp"
#include "Algoritam.hpp"
#include "Insertion_sort.hpp"
#include "Selection_sort.hpp"
#include "Bubble_sort.hpp"
#include "Quick_sort.hpp"
bool Program::potvrda;
std::string PromeniTxt(int izabrani);
Algoritam* KreirajObj(int izabrani);
enum IZABRANI_ALGORITAM{BUBBLE_SORT,SELECTION_SORT,INSERTION_SORT,QUICK_SORT,UKUPAN_BROJ};
void Program::Start()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SORTING VISUALIZATION");
    sf::Text txtIzabrani;
    sf::Font font;
    try {
        if (!font.loadFromFile("C:\\Users\\pc\\Desktop\\programiranje\\sort_visualization\\fonts\\Minecraftia-Regular.ttf")) {
            throw std::runtime_error("Neuspesno ucitavanje fonta");
        }
    } catch (const std::exception& e) {
        std::cout << "Uhvacen izuzetak: " << e.what() << std::endl;
        system("pause");
    }
    txtIzabrani.setFont(font);
    txtIzabrani.setPosition(280.f,300.f);
    txtIzabrani.setCharacterSize(40);
    potvrda= false;
    int izabrani=0;
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type==sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    izabrani--;
                    if(izabrani<0)
                        izabrani=UKUPAN_BROJ-1;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    izabrani++;
                    if(izabrani==UKUPAN_BROJ)
                        izabrani=0;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    potvrda= true;
                }
            }
        }
        if(potvrda)
        {
            Algoritam *pA= KreirajObj(izabrani);
            potvrda= false;
            pA->sortiraj();

            delete  pA;

        }
        txtIzabrani.setString(PromeniTxt(izabrani));
        window.clear();
        window.draw(txtIzabrani);
        window.display();
    }


}
Algoritam* KreirajObj(int izabrani)
{
    switch (izabrani)
    {
        case BUBBLE_SORT:
            return new Bubble_sort();

        case SELECTION_SORT:
            return new Selection_sort();

        case INSERTION_SORT:
            return new Insertion_sort();

        case QUICK_SORT:
            return new Quick_sort();
    }
}
std::string PromeniTxt(int izabrani)
{
    switch (izabrani)
    {
        case BUBBLE_SORT:
            return ("Izabran algoritam:\n\n      BUBBLE_SORT");

        case SELECTION_SORT:
            return("Izabran algoritam:\n\n  SELECTION_SORT");

        case INSERTION_SORT:
            return("Izabran algoritam:\n\n  INSERTION_SORT");

        case QUICK_SORT:
            return("Izabran algoritam:\n\n       QUICK_SORT");
    }
}
