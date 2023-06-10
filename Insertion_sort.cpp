//
// Created by pc on 6/10/2023.
//

#include "Insertion_sort.hpp"

Insertion_sort::Insertion_sort()
{
    pRect= GenerisiNiz<sf::RectangleShape>(N);
    PopuniNiz();
}

void Insertion_sort::sortiraj()
{
    for(int i=1;i<N;i++)
    {
        float pomY=pRect[i].getSize().y;
        sf::RectangleShape pomRect=pRect[i];
        int j=i-1;
        float pomX_key=pRect[i].getPosition().x;    //koristim ga kao X koordinatu na koju vracam/smestam pRect[i]
        while(j>=0 && pomY<pRect[j].getSize().y)
        {
            pomX_key=pRect[j].getPosition().x;
            float pomX=pRect[j+1].getPosition().x;  //pamtim X koordinate recta na mesto kojeg cu da shiftujem njegovog prethodnika
            pRect[j+1]=pRect[j];
            pRect[j+1].setPosition(pomX,WINDOW_HEIGHT);

            j--;
            Prozor::Prikaz(pRect);

        }
        pRect[j+1]=pomRect;
        pRect[j+1].setPosition(pomX_key,WINDOW_HEIGHT);

        Prozor::Prikaz(pRect);
    }
}
