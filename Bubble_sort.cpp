
#include "Bubble_sort.hpp"

Bubble_sort::Bubble_sort()
{
    pRect= GenerisiNiz<sf::RectangleShape>(N);
    PopuniNiz();
}

void Bubble_sort::sortiraj()
{
    while (Prozor::GetProzor().isOpen())
    {
        sf::Event event;

        for(int i=0;i<N-1;i++)
        {
            for(int j=0;j<N-i-1;j++)
            {
                while (Prozor::GetProzor().pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        Prozor::GetProzor().close();
                }
                if(pRect[j].getSize().y>pRect[j+1].getSize().y)
                {
                    float xPom=pRect[j].getPosition().x;
                    pRect[j].setPosition(sf::Vector2f(pRect[j+1].getPosition().x,WINDOW_HEIGHT));
                    pRect[j+1].setPosition(sf::Vector2f(xPom,WINDOW_HEIGHT));

                    sf::RectangleShape pomRect=pRect[j];
                    pRect[j]=pRect[j+1];
                    pRect[j+1]=pomRect;
                }
                Prozor::Prikaz(pRect);
            }
        }
        break;
    }

    while (Prozor::GetProzor().isOpen())
    {
        sf::Event event;
        while (Prozor::GetProzor().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Prozor::GetProzor().close();
        }
    }
}
