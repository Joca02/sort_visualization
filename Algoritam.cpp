//
// Created by pc on 5/30/2023.
//

#include "Algoritam.hpp"
void Algoritam::PopuniNiz() {
    if(pRect!= nullptr)//PROBAJ OVDE EXCEPT
    {
        float rectWidth=(float)WINDOW_WIDTH/N;
        int rectHeight;
        float razmak=rectWidth; //ne pocinjem od 0 jer sam ga zarotirao dole
        for(int i=0;i<N;i++)
        {

            rectHeight=rand()%(WINDOW_HEIGHT-100)+100;
            pRect[i].setSize(sf::Vector2f(rectWidth,rectHeight));
            pRect[i].rotate(180);   //rotiram svaki rect za 180 stepeni kako mi ne bi "leteli" pri setovanju pozicije
            pRect[i].setPosition(sf::Vector2f(razmak,WINDOW_HEIGHT));
            pRect[i].setFillColor(sf::Color::Magenta);
            razmak+=rectWidth;
        }
    }
}