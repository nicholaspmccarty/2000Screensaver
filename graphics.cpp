#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Replace this with the path to your local image file
    const std::string imagePath = "xavier.png";



    // Load the image
    sf::Texture texture;
    if (!texture.loadFromFile(imagePath)) {
        std::cerr << "Failed to load image from file." << std::endl;
        return 1; // Exit with an error code
    }

    // Create a window
    sf::RenderWindow window(sf::VideoMode(texture.getSize().x, texture.getSize().y), "SFML Image from File");

    // Create a sprite and set its texture
    sf::Sprite sprite(texture);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
