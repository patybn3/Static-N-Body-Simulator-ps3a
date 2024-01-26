/*
    Copyright 2023 Patricia Antlitz
*/
#include "Universe.hpp"

Universe::Universe() : numPlanets(0), radius(0.0) {}

std::istream& operator>>(std::istream& is, Universe& universe) {
    is >> universe.numPlanets >> universe.radius;
    // Resize the vector to hold the specified number of CelestialBody objects
    universe.bodies.resize(universe.numPlanets);

    for (int i = 0; i < universe.numPlanets; ++i) {
        is >> universe.bodies[i];  // Read CelestialBody data
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Universe& universe) {
    os << universe.numPlanets << " " << universe.radius << '\n';
    for (const CelestialBody& body : universe.bodies) {
        os << body << '\n';  // Write CelestialBody data
    }
    return os;
}


void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const CelestialBody& body : bodies) {
        // Draw each CelestialBody in the Universe
        target.draw(body, states);
    }
}
