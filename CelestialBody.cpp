/*
    Copyright 2023 Patricia Antlitz
*/
#include "CelestialBody.hpp"

CelestialBody::CelestialBody() : xPos(0.0), yPos(0.0), xVel(0.0), yVel(0.0), mass(0.0), image("") {}

// Overload the >> operator to read the planet data
std::istream& operator>>(std::istream& is, CelestialBody& body) {
    is >> body.xPos >> body.yPos >> body.xVel >> body.yVel >> body.mass >> body.image;
    return is;
}

// Overload the << operator to print the information back
std::ostream& operator<<(std::ostream& os, const CelestialBody& body) {
    os << body.xPos << " " << body.yPos << " " << body.xVel << " " << body.yVel
        << " " << body.mass << " " << body.image;
    return os;
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Create and draw an SFML sprite for this CelestialBody
    sf::Sprite sprite;
    sf::Texture texture;

    if (!texture.loadFromFile("assets/" + image))
        return;

    sprite.setTexture(texture);
    // Set sprite position based on body's data
    sprite.setPosition(static_cast<float>(xPos)/1e9 + 400, static_cast<float>(yPos)/1e9 + 300);
    // Draw the sprite
    target.draw(sprite, states);
}
