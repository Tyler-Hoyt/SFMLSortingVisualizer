#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>

class Program {
    private:
        sf::RenderWindow window;

        std::vector<int> vec;
        
        void handleEvents();
        void update();
        void render(int j);

    public:
        void run();
        void newData();

    public:
        Program();
};
