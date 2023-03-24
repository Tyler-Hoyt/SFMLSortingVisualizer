#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>

class Container{
    private:
        std::vector<sf::RectangleShape> barContainer;

    public:
        Container();

    public:
        std::vector<sf::RectangleShape> getBarContainer();
};
