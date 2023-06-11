

#include "Selection_sort.hpp"

Selection_sort::Selection_sort()
{
    pRect= GenerisiNiz<sf::RectangleShape>(N);
    PopuniNiz();
}

void Selection_sort::sortiraj()
{
    while (Prozor::GetProzor().isOpen())
    {
        for(int i=0;i<N-1;i++)
        {
            for (int j = i+1; j <N ;j++) {
                sf::Event event;
                while (Prozor::GetProzor().pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        Prozor::GetProzor().close();
                }
                if(pRect[i].getSize().y>pRect[j].getSize().y)
                {
                    float xPom=pRect[i].getPosition().x;
                    pRect[i].setPosition(sf::Vector2f(pRect[j].getPosition().x,WINDOW_HEIGHT));
                    pRect[j].setPosition(sf::Vector2f(xPom,WINDOW_HEIGHT));

                    sf::RectangleShape pomRect=pRect[i];
                    pRect[i]=pRect[j];
                    pRect[j]=pomRect;
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
