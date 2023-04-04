#include "Program.hpp"
#include <memory>

Program::Program() {
    window.create(sf::VideoMode(1600, 900), "SFML Sort");
    for(int i = 0; i < 500; i++) {
        vec.push_back(rand() % 800 + 1); 
    }
}

void Program::handleEvents() {
    sf::Event e;
    while(window.pollEvent(e)) {
        if(e.type == sf::Event::Closed){
            window.close();
            break;
        }

        if(e.type == sf::Event::KeyPressed){
            if(e.key.code == sf::Keyboard::Space) {
                for(int i = 0; i < vec.size(); i++) {
                    for(int j = 0; j < vec.size() - i - 1; j++) {
                        if(vec[j] > vec[j + 1]) {
                            std::swap(vec[j], vec[j + 1]);
                            render(j);
                        }
                    }
                }
            }

            if(e.key.code == sf::Keyboard::R) {
                newData();
            }
        }
    }
}

void Program::newData() {
    vec.clear();
    for(int i = 0; i < 500; i++) {
        vec.push_back(rand() % 800 + 1);
    }
}

void Program::render(int j) {
    window.clear(sf::Color::Black);
    for(int i = 0; i < vec.size(); i++) {
        sf::RectangleShape shape(sf::Vector2f(3.2, -vec[i]));
        shape.setPosition(i * 3.2, 900);
        if(i == j) {
            shape.setFillColor(sf::Color::Red);
        }
        window.draw(shape);
    }
    window.display();
}

void Program::run() {
    while(window.isOpen()) {
        handleEvents();
        render(101); // A bad way to handle this but it works so.
    }
}
