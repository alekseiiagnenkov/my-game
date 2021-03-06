#include "Object.h"

//const float SPEED=0.25;
const float SPEED = 0.9;

Object::Object(std::string &name, std::string &type, std::string &color, float x, float y, int w, int h) {
    if (x < 0 || y < 0 || h < 0 || w < 0) {
        std::cout << "Object[#8] Invalid param " << std::endl;
        throw std::exception();
    }
    this->x = x;
    this->y = y;
    this->moveY = y;
    this->moveX = x;
    this->width = w;
    this->height = h;
    this->name = name;
    this->type = type;
    this->color = color;
    sf::Image img;
    if (!img.loadFromFile("../res/image/" + color + "/" + name + ".png")) {
        std::cout << "Object[#20] No loaded " << color << " " << name << std::endl;
        throw std::exception();
    }
    texture.loadFromImage(img);
    sprite.setPosition(x, y);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, w, h));
}

void Object::updateMove() {

    if (x != moveX) {
        if (std::fabs(x - moveX) < SPEED)
            x = moveX;
        else {
            if (x < moveX)
                x += SPEED;
            else if (x > moveX)
                x -= SPEED;
        }
    }
    if (y != moveY) {
        if (std::fabs(y - moveY) < SPEED)
            y = moveY;
        else {
            if (y < moveY)
                y += SPEED;
            else if (y > moveY)
                y -= SPEED;
        }
    }
    sprite.setPosition(x, y);
}

void Object::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

sf::Vector2f Object::getCoord() {
    sf::Vector2f V(x, y);
    return V;
}
