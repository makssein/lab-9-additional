#include <SFML/Graphics.hpp>
int main(){
    sf::Text text;
    sf::Font font;
    int check_x = 0, check_y = 0;

    sf::RenderWindow window(sf::VideoMode(1920, 1280), L"Летающие прямоугольники! Вау!");

    font.loadFromFile("/Users/maksimsein/Documents/gitKtaken/lab-9-additional/src/font.ttf");
    text.setString(L"Вам нужно доехать до конца страницы!");
    text.setCharacterSize(72);
    text.setFillColor(sf::Color::Red);
    text.setFont(font);

    sf::Texture carTx;
    carTx.loadFromFile("src/car.png");

    sf::Texture finishTx;
    finishTx.loadFromFile("src/finish.jpeg");

    sf::Sprite carSp;
    carSp.setTexture(carTx);
    carSp.setPosition(0,0);
    carSp.setScale(0.2f,0.2f);

    sf::Sprite finishSp;
    finishSp.setTexture(finishTx);
    finishSp.setPosition(window.getSize().x-300,window.getSize().y-300);
    finishSp.setScale(0.7f,0.7f);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            carSp.move(3.f, 0.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            carSp.move(-3.f, 0.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            carSp.move(0.f, -3.f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            carSp.move(0.f, 3.f);
        }
        if(carSp.getPosition().x > window.getSize().x - carSp.getScale().x*1000-200) {
            carSp.setPosition(window.getSize().x - carSp.getScale().x * 1000 - 200, carSp.getPosition().y);
            check_x = 1;
        }
        if(carSp.getPosition().y > window.getSize().y - carSp.getScale().y*1000-100) {
            carSp.setPosition(carSp.getPosition().x, window.getSize().y - carSp.getScale().y * 1000 - 100);
            check_y = 1;
        }

        if(check_x == 1 && check_y == 1){
            text.setFillColor(sf::Color::Green);
            text.setString(L"Вы доехали");
        }

        window.clear();
        window.draw(carSp);
        window.draw(finishSp);
        window.draw(text);
        window.display();

        window.setFramerateLimit(60);
    }

    return 0;
}
