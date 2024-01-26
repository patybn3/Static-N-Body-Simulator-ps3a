#pragma once
#include <iostream>
#include <string>
/*
    Copyright 2023 Patricia Antlitz
*/
#include <SFML/Graphics.hpp>

class CelestialBody :  public sf::Drawable, public sf::Transformable {
 public:
    CelestialBody();  // Constructor

    // Overload the >> operator to read the planet data
    friend std::istream &operator>>(std::istream &is, CelestialBody &body);

    // Overload the << operator to print the information back
    friend std::ostream &operator<<(std::ostream &os, const CelestialBody &body);

    void setXPos(double xPos_) { xPos = xPos_; }
    double getXPos() const { return xPos; }

    void setYPos(double yPos_) { yPos = yPos_; }
    double getYPos() const { return yPos; }

    void setXVel(double xVel_) { xVel = xVel_; }
    void setYVel(double yVel_) {yVel = yVel_; }
    void setMass(double mass_) { mass = mass_; }
    void setImage(std::string img) { image = img; }

    std::string getImage() const { return image; }

 private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    double xPos;
    double yPos;
    double xVel;
    double yVel;
    double mass;
    std::string image;
};

