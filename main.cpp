#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Algoritam.hpp"
#include "Insertion_sort.hpp"
#include "Selection_sort.hpp"
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800

void selection_sort(sf::RectangleShape * pRect);
void bubble_sort(sf::RectangleShape * pRect);
void insertion_sort(sf::RectangleShape * pRect);
void quick_sort(sf::RectangleShape * pRect,int start,int end);
int partition(sf::RectangleShape * pRect,int start,int end);
void display(const sf::RectangleShape * pRect);

//enum Algoritmi{Selection_sort,Bubble_sort,Insertion_sort,Quick_sort};

/*sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"SORTING VISUALIZATION");
int n=300;
sf::Text timeElapsed;
sf::Clock clock1;*/
int main()
{
    Algoritam* a=new Selection_sort();
    a->sortiraj();


    return 0;
}
/*int main() {

    srand(time(NULL));

    sf::RectangleShape *pRect;


    sf::Font font;
    if(!font.loadFromFile("C:\\Users\\pc\\Desktop\\programiranje\\sort_visualization\\fonts\\Minecraftia-Regular.ttf"))
    {
        std::cout<<"Greska pri ucitavanju fonta\n";
        system("pause");
    }
    timeElapsed.setFont(font);
    timeElapsed.setPosition(30.f,30.f);
    timeElapsed.setCharacterSize(20);

    pRect=new sf::RectangleShape[n];
    float rectWidth=WINDOW_WIDTH/(float)n;
    int rectHeight;
    float razmak=rectWidth; //ne pocinjem od 0 jer sam ga zarotirao dole
    for(int i=0;i<n;i++)
    {

        rectHeight=rand()%(WINDOW_HEIGHT-100)+100;
        pRect[i].setSize(sf::Vector2f(rectWidth,rectHeight));
        pRect[i].rotate(180);   //rotiram svaki rect za 180 stepeni kako mi ne bi "leteli" pri setovanju pozicije
        pRect[i].setPosition(sf::Vector2f(razmak,WINDOW_HEIGHT));
        pRect[i].setFillColor(sf::Color::Magenta);
        razmak+=rectWidth;
    }


     //selection_sort(pRect);
    //bubble_sort(pRect);
    // insertion_sort(pRect);

    quick_sort(pRect,0,n-1);
    while (window.isOpen())
    {
        //display(pRect);
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    delete [] pRect;

        return 0;
}*/

/*void display(const sf::RectangleShape * pRect)
{
    window.clear();
    for(int i=0;i<n;i++)
        window.draw(pRect[i]);

    sf::Time time=clock1.getElapsedTime();
    double d=time.asSeconds();
    timeElapsed.setString("Elapsed time:   "+std::to_string(d)+"   sec");
    window.draw(timeElapsed);

    window.display();
}
void selection_sort(sf::RectangleShape * pRect)
{
    for(int i=0;i<n-1;i++)
    {
        for (int j = i+1; j <n ;j++) {
            if(pRect[i].getSize().y>pRect[j].getSize().y)
            {
                float xPom=pRect[i].getPosition().x;
                pRect[i].setPosition(sf::Vector2f(pRect[j].getPosition().x,WINDOW_HEIGHT));
                pRect[j].setPosition(sf::Vector2f(xPom,WINDOW_HEIGHT));

                sf::RectangleShape pomRect=pRect[i];
                pRect[i]=pRect[j];
                pRect[j]=pomRect;
            }

            display(pRect);
        }
    }
}
void bubble_sort(sf::RectangleShape * pRect)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
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
            display(pRect);
        }
    }
}
void insertion_sort(sf::RectangleShape * pRect)
{
    for(int i=1;i<n;i++)
    {
        int pomY=pRect[i].getSize().y;
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

            display(pRect);
        }
        pRect[j+1]=pomRect;
        pRect[j+1].setPosition(pomX_key,WINDOW_HEIGHT);

        display(pRect);
    }
}

void quick_sort(sf::RectangleShape * pRect,int start,int end)
{
    if(end<=start)
        return;
    int pivot=partition(pRect,start,end);

    quick_sort(pRect,start,pivot-1);
    quick_sort(pRect,pivot+1,end);

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
        display(pRect);
    }
    i++;
    float pomX=pRect[i].getPosition().x;

    pRect[i].setPosition(pRect[end].getPosition().x,WINDOW_HEIGHT);
    pRect[end].setPosition(pomX,WINDOW_HEIGHT);
    sf::RectangleShape pomRect=pRect[i];
    pRect[i]=pRect[end];
    pRect[end]=pomRect;


    display(pRect);

    return i;
}*/
