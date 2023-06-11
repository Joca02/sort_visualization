
#include <SFML/Graphics.hpp>
#include "Prozor.hpp"
#include "Program.hpp"
#ifndef SORT_VISUALIZATION_ALGORITAM_HPP
#define SORT_VISUALIZATION_ALGORITAM_HPP

template<typename T>
T* GenerisiNiz (int n){return new T[n];}

class Algoritam {
protected:
    sf::RectangleShape *pRect= nullptr;
    void PopuniNiz();

public:
    Algoritam(){pRect = GenerisiNiz<sf::RectangleShape>(N);}
    virtual void sortiraj()=0;
    friend sf::RectangleShape* GenerisiNiz(int n);
    virtual ~Algoritam(){delete pRect; Program::potvrda=false; }
};


#endif //SORT_VISUALIZATION_ALGORITAM_HPP
