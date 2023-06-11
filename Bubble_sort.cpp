//
// Created by pc on 6/11/2023.
//

#include "Bubble_sort.hpp"

Bubble_sort::Bubble_sort()
{
    pRect= GenerisiNiz<sf::RectangleShape>(N);
    PopuniNiz();
}

void Bubble_sort::sortiraj()
{
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-i-1;j++)
        {
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
}
