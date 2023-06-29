
#include <iostream>
#include "Prozor.hpp"

sf::Font Prozor::font;
sf::Clock clck;
void Prozor::Prikaz(sf::RectangleShape *pRect)
{

    static sf::Text timeElapsed;
    GetProzor().clear();
    for(int i=0;i<N;i++)
        GetProzor().draw(pRect[i]);


    static bool set= false;
    if(!set){
        try {
            if (!font.loadFromFile("C:\\Users\\pc\\Desktop\\programiranje\\sort_visualization\\fonts\\Minecraftia-Regular.ttf")) {
                throw std::runtime_error("Neuspesno ucitavanje fonta");
            }
        } catch (const std::exception& e) {
            std::cout << "Uhvacen izuzetak: " << e.what() << std::endl;
            system("pause");
        }
        timeElapsed.setPosition(30.f,30.f);
        timeElapsed.setCharacterSize(20);
        timeElapsed.setFont(font);
        set= true;
    }
    sf::Time time=clck.getElapsedTime();

    double vreme=time.asSeconds();

    timeElapsed.setString("Elapsed time:   "+std::to_string(vreme)+"   sec");
    GetProzor().draw(timeElapsed);

    GetProzor().display();
}

 sf::RenderWindow window;

sf::RenderWindow& Prozor::GetProzor()
{
    return window;
}

void Prozor::CreateProzor()
{
    if(!window.isOpen())
    {
        window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SORTING VISUALIZATION");
        clck.restart();
    }
}


