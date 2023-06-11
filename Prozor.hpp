
#include <SFML/Graphics.hpp>
#ifndef SORT_VISUALIZATION_PROZOR_HPP
#define SORT_VISUALIZATION_PROZOR_HPP

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800
#define N 300
class Prozor {
private:
    static sf::Font font;
public:
    static void Prikaz(sf::RectangleShape *pRect);
    static sf::RenderWindow& GetProzor();
};


#endif //SORT_VISUALIZATION_PROZOR_HPP
