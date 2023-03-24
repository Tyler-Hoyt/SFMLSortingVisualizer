#include "Container.hpp"

Container::Container() {
    float xPos = 16;
    for(int i = 0; i < 100; i++) {
        sf::RectangleShape shape(sf::Vector2f(1 + static_cast<float>(rand()) * static_cast<float>(800 - 1) / RAND_MAX, 16.f));
        shape.setFillColor(sf::Color::White);
        shape.rotate(90.f);
        shape.setPosition(xPos, 0);
        xPos += 16;
        barContainer.push_back(shape);
    }
}

std::vector<sf::RectangleShape> Container::getBarContainer() {
    return barContainer;
}

