#include "Program.hpp"

Program::Program() {
    window.create(sf::VideoMode(1600, 900), "SFML Sort");
    for(int i = 0; i < 100; i++) {
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
                            render();
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
    for(int i = 0; i < 100; i++) {
        vec.push_back(rand() % 800 + 1);
    }
}

void Program::render() {
    window.clear(sf::Color::Black);
    for(int i = 0; i < vec.size(); i++) {
        sf::RectangleShape shape(sf::Vector2f(16, -vec[i]));
        shape.setPosition(i * 16, 900);
        window.draw(shape);
    }
    window.display();
}

void Program::run() {
    while(window.isOpen()) {
        handleEvents();
        render();
    }
}
