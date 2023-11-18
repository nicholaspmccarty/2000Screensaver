#include <SFML/Graphics.hpp>
#include <iostream>
 






/**
 * Function drawSpeechBubble: Draws a speech bubble on the given window.
 * Params: sf::RenderWindow& window - the window to draw on
 *         sf::Vector2f position - the position of the speech bubble
 *         std::string text - the text to display in the speech bubble
 * return : void
*/
void drawSpeechBubble(sf::RenderWindow& window, sf::Vector2f position, std::string text) {
    sf::RectangleShape bubble;
    bubble.setSize(sf::Vector2f(200.0f, 100.0f)); // Adjust the size of the speech bubble as needed
    bubble.setFillColor(sf::Color::White);
    bubble.setOutlineThickness(2);
    bubble.setOutlineColor(sf::Color::Black);
    bubble.setPosition(position.x - bubble.getSize().x / 2.0f, position.y - bubble.getSize().y / 2.0f);

    sf::Text bubbleText;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font." << std::endl;
        // Handle the error appropriately, e.g., return from the function or exit the program.
    }
    bubbleText.setFont(font);
    bubbleText.setString(text);
    bubbleText.setCharacterSize(16);
    bubbleText.setFillColor(sf::Color::Black);
    bubbleText.setPosition(position.x - bubbleText.getLocalBounds().width / 2.0f,
                            position.y - bubbleText.getLocalBounds().height / 2.0f);

    window.draw(bubble);
    window.draw(bubbleText);
}

/**
 * Function theMagic: In this function we will use SFML methods to 
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
    sf::Time elapsed;
    sf::Clock clock;
    
    drawSpeechBubble(window, sf::Vector2f(25, 25), "Hello, SFML!");
    


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

        elapsed = clock.getElapsedTime();

        // Change the color every 1 second
        if (elapsed.asSeconds() >= 1.0f) {
            // Toggle between red and blue
            if (sprite.getColor() == sf::Color::Red) {
                sprite.setColor(sf::Color::Blue);
            } else {
                sprite.setColor(sf::Color::Red);
            }

            // Reset the clock
            clock.restart();
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
