#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <fstream>

int main() {
    // Create a window
    const std::string imageUrl = "https://content.sportslogos.net/logos/35/919/full/xavier_musketeers_logo_primary_1983_sportslogosnet-3630.png";
    sf::Http http("content.sportslogos.net");
    sf::Http::Request request(imageUrl);

    // Create an HTTP request

    return 0;
}
