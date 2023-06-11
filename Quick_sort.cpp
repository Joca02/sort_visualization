//
// Created by pc on 6/11/2023.
//

#include "Quick_sort.hpp"

Quick_sort::Quick_sort()
{
    pRect= GenerisiNiz<sf::RectangleShape>(N);
    PopuniNiz();
}

int partition(sf::RectangleShape * pRect,int start,int end)
{
    int pivot=pRect[end].getSize().y;
    int i=start-1;

    for (int j = start; j <= end; j++)
    {
        if(pRect[j].getSize().y<pivot)
        {
            i++;
            float pomX=pRect[i].getPosition().x;

            pRect[i].setPosition(pRect[j].getPosition().x,WINDOW_HEIGHT);
            pRect[j].setPosition(pomX,WINDOW_HEIGHT);
            sf::RectangleShape pomRect=pRect[i];
            pRect[i]=pRect[j];
            pRect[j]=pomRect;
        }
        Prozor::Prikaz(pRect);
    }
    i++;
    float pomX=pRect[i].getPosition().x;

    pRect[i].setPosition(pRect[end].getPosition().x,WINDOW_HEIGHT);
    pRect[end].setPosition(pomX,WINDOW_HEIGHT);
    sf::RectangleShape pomRect=pRect[i];
    pRect[i]=pRect[end];
    pRect[end]=pomRect;

    Prozor::Prikaz(pRect);

    return i;
}
void quick_sort(sf::RectangleShape * pRect,int start,int end)
{
    if(end<=start)
        return;
    int pivot=partition(pRect,start,end);

    quick_sort(pRect,start,pivot-1);
    quick_sort(pRect,pivot+1,end);

}
void Quick_sort::sortiraj()
{
    quick_sort(pRect,0,N-1);
}
