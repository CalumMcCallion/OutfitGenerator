/*
* An SFML application using a vector list to store point data - Calum McCallion
* SFML Documentation https://www.sfml-dev.org/documentation/2.5.1/
*/
#include <iostream>                                                     // std namespace
#include <SFML/Graphics.hpp>                                            // sf namespace 
#include <string>
#include "MoveBG.h"
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <windows.h> //Win32 import to use sleep function
#include <math.h>
#include <SFML/Audio.hpp>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;
using namespace sf;



int main() {
start:

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow Window(sf::VideoMode(desktopMode.width, desktopMode.height, desktopMode.bitsPerPixel), "Outfit Generator", sf::Style::Fullscreen);

    sf::View View(Window.getDefaultView());
    sf::FloatRect fBounds(0.f, 0.f, 2500.f, 3000.f); // arbitrary > view "SIZE"



//=============================================================================BACKGROUND================================================================================================================
    sf::Texture backgroundPic;
    if (!backgroundPic.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/misc/bg.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite background;
    background.setTexture(backgroundPic);
    sf::FloatRect goSize = background.getGlobalBounds();
    background.setOrigin(0, 0);
    background.setScale(1.6f, 1.4f);




    //=============================================================================JACKETS/HOODIES================================================================================================================

    //========================JACKET1========================
    sf::Texture jacket1;
    if (!jacket1.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Jacket/bg.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite jacket1s;
    jacket1s.setTexture(jacket1);
    sf::FloatRect goSize = background.getGlobalBounds();
    jacket1s.setOrigin(0, 0);
    jacket1s.setScale(1.6f, 1.4f);

    //========================JACKET2========================
    sf::Texture jacket2;
    if (!jacket1.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Jacket/bg.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite jacket2s;
    jacket2s.setTexture(jacket2);
    sf::FloatRect goSize = background.getGlobalBounds();
    jacket2s.setOrigin(0, 0);
    jacket2s.setScale(1.6f, 1.4f);

    //========================JACKET3========================
    sf::Texture jacket1;
    if (!jacket1.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/misc/bg.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite background;
    background.setTexture(jacket1);
    sf::FloatRect goSize = background.getGlobalBounds();
    background.setOrigin(0, 0);
    background.setScale(1.6f, 1.4f);

    //========================JACKET4========================
    sf::Texture jacket1;
    if (!jacket1.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/misc/bg.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite background;
    background.setTexture(jacket1);
    sf::FloatRect goSize = background.getGlobalBounds();
    background.setOrigin(0, 0);
    background.setScale(1.6f, 1.4f);

    //========================JACKET5========================
    sf::Texture jacket1;
    if (!jacket1.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/misc/bg.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite background;
    background.setTexture(jacket1);
    sf::FloatRect goSize = background.getGlobalBounds();
    background.setOrigin(0, 0);
    background.setScale(1.6f, 1.4f);

    //=============================================================================TEES================================================================================================================
    sf::Texture backgroundPic;
    if (!backgroundPic.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/misc/bg.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite background;
    background.setTexture(backgroundPic);
    sf::FloatRect goSize = background.getGlobalBounds();
    background.setOrigin(0, 0);
    background.setScale(1.6f, 1.4f);



    //=============================================================================TROUSERS================================================================================================================
    sf::Texture backgroundPic;
    if (!backgroundPic.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/misc/bg.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite background;
    background.setTexture(backgroundPic);
    sf::FloatRect goSize = background.getGlobalBounds();
    background.setOrigin(0, 0);
    background.setScale(1.6f, 1.4f);





    //=============================================================================SHOES================================================================================================================
    sf::Texture backgroundPic;
    if (!backgroundPic.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/misc/bg.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite background;
    background.setTexture(backgroundPic);
    sf::FloatRect goSize = background.getGlobalBounds();
    background.setOrigin(0, 0);
    background.setScale(1.6f, 1.4f);




    //=============================================================================THE BRAIN================================================================================================================
    sf::Clock timer;

    while (Window.isOpen())
    {
        // Process events
        sf::Event event;
        while (Window.pollEvent(event))
        {
            // Close the window if a key is pressed or if requested
            if (event.type == sf::Event::Closed) Window.close();

        }


        int jackNum = 0;
        int teeNum = 0;
        int trouNum = 0;
        int shoeNum = 0;

        Window.draw(background);

        if (jackNum = 1) {
            Window.draw(jacket1s);
        }
        else if (jackNum = 2) {

        }



        // Update display and wait for vsync
        Window.display();

    }

}