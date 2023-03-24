#include "Program.hpp"

Program::Program() {
    window.create(sf::VideoMode(1600, 900), "SFML Sort");
    barContainer = mainContainer.getBarContainer();
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
                std::cout << "Key Pressed" << std::endl;
                for(int i = 0; i < barContainer.size(); i++) {
                    for(int j = 0; j < barContainer.size() - i - 1; j++) {
                        if(barContainer[j].getSize().x > barContainer[j + 1].getSize().x) {
                            std::swap(barContainer[j], barContainer[j + 1]);
                            float xTemp = barContainer[j].getPosition().x;
                            barContainer[j].setPosition(barContainer[j + 1].getPosition().x, 0);
                            barContainer[j + 1].setPosition(xTemp, 0);
                            render();
                        }
                     }
                }
            }
        }
    }
}

void Program::render() {
    window.clear(sf::Color::Black);

    for(auto& bar : barContainer) {
        window.draw(bar);
    }
    window.display();
}

void Program::run() {
    while(window.isOpen()) {
        handleEvents();
        render();
    }
}
