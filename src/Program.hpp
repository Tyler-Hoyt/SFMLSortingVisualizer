#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Container.hpp"

class Program {
    private:
        sf::RenderWindow window;
    
        Container mainContainer;

        std::vector<sf::RectangleShape> barContainer;

        void handleEvents();
        void update();
        void render();

    public:
        void run();

    public:
        Program();
};
