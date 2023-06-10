

#include "Prozor.hpp"

void Prozor::Prikaz(sf::RectangleShape *pRect)
{
    GetProzor().clear();
    for(int i=0;i<N;i++)
        GetProzor().draw(pRect[i]);

    static sf::Clock clock;
    sf::Text timeElapsed;
    sf::Time time=clock.getElapsedTime();
    sf::Font font;
    double vreme=time.asSeconds();
    if(!font.loadFromFile("C:\\Users\\pc\\Desktop\\programiranje\\sort_visualization\\fonts\\Minecraftia-Regular.ttf"))
    {
        //baci except
        //std::cout<<"Greska pri ucitavanju fonta\n";
        system("pause");
    }
    timeElapsed.setPosition(30.f,30.f);
    timeElapsed.setCharacterSize(20);
    timeElapsed.setFont(font);
    timeElapsed.setString("Elapsed time:   "+std::to_string(vreme)+"   sec");
    GetProzor().draw(timeElapsed);

    GetProzor().display();
}

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SORTING VISUALIZATION");

sf::RenderWindow& Prozor::GetProzor()
{
    return window;
}
