# PS#: Universe

## Contact
Name: Patricia Antlitz
Section: 202
Time to Complete: days

## Description
This program simulates a celestial Nbody system, modeling the motion of celestial bodies in a two-dimensional space. It consists of two main classes, "Universe" and "CelestialBody", which are responsible for storing information about celestial bodies and their interactions. The "Universe" class manages a collection of celestial bodies and can read and write their data from and to input/output streams. The "CelestialBody" class represents individual celestial bodies with properties such as position, velocity, mass, and an associates image. The program reads data from an input source, simulates the motion of the celestial bodies based on gravitational interactions, and visualized the system using the SFML library.

### Features

#### 4. Scaling Planet Positions

In this NBody Simulation, the positions of the celestial bodies (planets) are scaled to fit the window based on the values obtained from the planet.txt file. This scaling ensures that the planets are properly positioned within the simulation window.

#### a. Reading Planet Data

The planet data is read from the planet.txt file, which contains information about each celestial body, including its initial position, velocity, mass, and image file name.

#### b. Scaling Position Values

To scale the planet positions based on the data from the planet.txt file, the following code is used within the `CelestialBody::draw` function:

```cpp
// Set sprite position based on body's data
sprite.setPosition(static_cast<float>(xpos) / 1e9 + 400, static_cast<float>(ypos) / 1e9 + 300);
```

#### Usage

To run the NBody Simulation with the added background image, simply compile and execute the program. The background image will serve as the backdrop for the celestial bodies in the universe.

``` bash
make
./NBody < planets.txt 
```

### Issues

### Extra Credit

In this extra credit work, I added a background image to the NBody Simulation program to appear behind all the celestial bodies (planets) in the universe. Here's a description of how I implemented this feature:

#### 1. Loading the Background Image

I loaded a background image named "starfield.jpg" to serve as the backdrop for the simulation. I used the SFML library to load the image with the following code:

```cpp
sf::Texture backgroundTexture;
if (!backgroundTexture.loadFromFile("assets/starfield.jpg"))
{
    // Handle the error if the image loading fails
    return 1;
}
sf::Sprite backgroundImage(backgroundTexture);
```

#### 2. Scaling the Background Image

To ensure that the background image scales to fill the entire window while keeping its center at (400, 300), I used the following code:

```cpp
sf::View view;
view.setSize(800.0f, 600.0f);
view.setCenter(400.0f, 300.0f);
window.setView(view);
```

Additionally, I adjusted the scale of the background image to match the window size while preserving its aspect ratio. This was done using the following code:

```cpp
// Calculate the aspect ratio of the background image and the window
float aspectRatioImage = static_cast<float>(backgroundTexture.getSize().x) / backgroundTexture.getSize().y;
float aspectRatioWindow = static_cast<float>(windowSize.x) / windowSize.y;

// Set the scale of the background image to fill the window while preserving aspect ratio
float scaleFactor;
if (aspectRatioWindow > aspectRatioImage)
{
    // Window is wider, scale by width
    scaleFactor = static_cast<float>(windowSize.x) / backgroundTexture.getSize().x;
}
else
{
    // Window is taller, scale by height
    scaleFactor = static_cast<float>(windowSize.y) / backgroundTexture.getSize().y;
}
backgroundImage.setScale(scaleFactor, scaleFactor);
```

#### 3. Drawing the Background Image

I ensured that the background image is drawn first, so it appears behind all the celestial bodies in the simulation. I used the following code to draw the background image:

```cpp
// Clear the window
window.clear();

// Draw the background image
window.draw(backgroundImage);
```
