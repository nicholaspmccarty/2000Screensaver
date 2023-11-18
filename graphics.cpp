#include <SFML/Graphics.hpp>
#include <iostream>
 


/**
 * Function theMagic: In this functionw we will use SFML methods to 
 * create our logo and animate it.
 * Params: none
 * return : void
*/
void theMagic() {
  

    // TODO - Put the image you want here. In my example, I will use the Xavier Musketeers basketball logo.

    const std::string imagePath = "xavier.png";



    // Load the image
    sf::Texture texture;
    if (!texture.loadFromFile(imagePath)) {
        std::cerr << "Failed to load image from file." << std::endl;
        std::cout << "Fatal Error" << std::endl;
    }

    // Create a window
    sf::RenderWindow window(sf::VideoMode(texture.getSize().x, texture.getSize().y), "SFML Image from File");

    // Create a sprite and set its texture
    sf::Sprite sprite(texture);

    // Creating a position vector and setting the initial velocity of it.
    sf::Vector2f position(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
    sprite.setPosition(position);
    sf::Vector2f velocity(2.0f, 1.5f);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        position += velocity;
        sprite.setPosition(position);

        // Bounce off the window edges
       if (position.x < 0 || position.x > window.getSize().x - sprite.getLocalBounds().width) {
             velocity.x = -velocity.x;
        }
        if (position.y < 0 || position.y > window.getSize().y - sprite.getLocalBounds().height) {
            velocity.y = -velocity.y;
        }
        // Clear the window
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Display the contents of the window
        window.display();
    }
}


int main() {
    
    
    // Calling our beautiful function
    theMagic();

    return 0;
}
