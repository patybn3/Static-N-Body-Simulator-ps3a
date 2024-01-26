/*
    Copyright 2023 Patricia Antlitz
*/
#include <SFML/Graphics.hpp>
#include "Universe.hpp"
#include "CelestialBody.hpp"

int main(int argc, char const *argv[]) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "NBody Simulation");
    // Load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/starfield.jpg"))
        // Handle the error if the image loading fails
        return 1;

    sf::Sprite backgroundImage(backgroundTexture);

    Universe universe;
    std::cout << "Enter the number of planets and the universe radius: ";
    std::cin >> universe;
    std::cout << "You entered: " << universe << std::endl;

    // Set the initial view size to match the window size
    sf::View view;
    view.setSize(800.0f, 600.0f);
    view.setCenter(400.0f, 300.0f);
    window.setView(view);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Get the current window size
        sf::Vector2u windowSize = window.getSize();

        // Calculate the aspect ratio of the background image and the window
        float aspectRatioImage = static_cast<float>(backgroundTexture.getSize().x)
            / backgroundTexture.getSize().y;
        float aspectRatioWindow = static_cast<float>(windowSize.x) / windowSize.y;

        // Set the scale of the background image to fill the window while preserving aspect ratio
        float scaleFactor;
        if (aspectRatioWindow > aspectRatioImage) {
            // Window is wider, scale by width
            scaleFactor = static_cast<float>(windowSize.x) / backgroundTexture.getSize().x;
        } else {
            // Window is taller, scale by height
            scaleFactor = static_cast<float>(windowSize.y) / backgroundTexture.getSize().y;
        }
        backgroundImage.setScale(scaleFactor, scaleFactor);

        // Clear the window
        window.clear();

        // Draw the background image
        window.draw(backgroundImage);

        // Get the celestial bodies and draw them
        const std::vector<CelestialBody> &bodies = universe.getBodies();

        for (const CelestialBody &body : bodies) {
            window.draw(body);
        }
        // Display everything on the screen
        window.display();
    }

    return 0;
}
