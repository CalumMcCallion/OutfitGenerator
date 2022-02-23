/*
* An SFML application using a vector list to store point data - Calum McCallion
* SFML Documentation https://www.sfml-dev.org/documentation/2.5.1/
*/
#include <iostream>                                                     // std namespace
#include <SFML/Graphics.hpp>                                            // sf namespace 
#include <string>
#include "MoveBG.h"
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <stdlib.h>
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


    /*
    ==========COLOR KEYS==========

    * BLACK = 50
    * BLUE = 60
    * GREY = 70
    * NAVY = 80
    * YELLOW = 90
    * GREEN = 100
    *
    */


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
    if (!jacket1.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Jacket/jacket1.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite jacket1s;
    jacket1s.setTexture(jacket1);
    jacket1s.setPosition(800, 30);
    jacket1s.setOrigin(0, 0);
    jacket1s.setScale(.85f, .85f);

    //========================JACKET2========================
    sf::Texture jacket2;
    if (!jacket2.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Jacket/jacket2.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite jacket2s;
    jacket2s.setTexture(jacket2);
    jacket2s.setPosition(800, 30);
    jacket2s.setOrigin(0, 0);
    jacket2s.setScale(.85f, .85f);

    //========================JACKET3========================
    sf::Texture jacket3;
    if (!jacket3.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Jacket/jacket3.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite jacket3s;
    jacket3s.setTexture(jacket3);
    jacket3s.setPosition(800, 30);
    jacket3s.setOrigin(0, 0);
    jacket3s.setScale(.85f, .85f);

    //========================JACKET4========================
    sf::Texture jacket4;
    if (!jacket4.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Jacket/jacket4.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite jacket4s;
    jacket4s.setTexture(jacket4);
    jacket4s.setPosition(800, 30);
    jacket4s.setOrigin(0, 0);
    jacket4s.setScale(.85f, .85f);

    //========================JACKET5========================
    sf::Texture jacket5;
    if (!jacket5.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Jacket/jacket5.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite jacket5s;
    jacket5s.setTexture(jacket5);
    jacket5s.setPosition(800, 30);
    jacket5s.setOrigin(0, 0);
    jacket5s.setScale(.85f, .85f);

    //========================JACKET6========================
    sf::Texture jacket6;
    if (!jacket6.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Jacket/jacket6.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite jacket6s;
    jacket6s.setTexture(jacket6);
    jacket6s.setPosition(800, 30);
    jacket6s.setOrigin(0, 0);
    jacket6s.setScale(.85f, .85f);

    //========================JACKET7========================
    sf::Texture jacket7;
    if (!jacket7.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Jacket/jacket7.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite jacket7s;
    jacket7s.setTexture(jacket7);
    jacket7s.setPosition(800, 30);
    jacket7s.setOrigin(0, 0);
    jacket7s.setScale(.85f, .85f);

    //========================JACKET8========================
    sf::Texture jacket8;
    if (!jacket8.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Jacket/jacket8.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite jacket8s;
    jacket8s.setTexture(jacket8);
    jacket8s.setPosition(800, 30);
    jacket8s.setOrigin(0, 0);
    jacket8s.setScale(.85f, .85f);

    //========================JACKET9========================
    sf::Texture jacket9;
    if (!jacket9.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Jacket/jacket9.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite jacket9s;
    jacket9s.setTexture(jacket9);
    jacket9s.setPosition(800, 30);
    jacket9s.setOrigin(0, 0);
    jacket9s.setScale(.85f, .85f);

    //========================JACKET10========================
    sf::Texture jacket10;
    if (!jacket10.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Jacket/jacket9.png"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite jacket10s;
    jacket10s.setTexture(jacket10);
    jacket10s.setPosition(800, 30);
    jacket10s.setOrigin(0, 0);
    jacket10s.setScale(.85f, .85f);

    //=============================================================================TEES================================================================================================================
    //========================TEE1========================
    sf::Texture tee1;
    if (!tee1.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Tees/tee1.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite tee1s;
    tee1s.setTexture(tee1);
    tee1s.setPosition(1000, 90);
    //tee1s.setOrigin(0, 0);
    tee1s.setScale(.6f, .6f);

    //========================TEE2========================
    sf::Texture tee2;
    if (!tee2.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Tees/tee2.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite tee2s;
    tee2s.setTexture(tee2);
    tee2s.setPosition(1000, 90);
    tee2s.setOrigin(0, 0);
    tee2s.setScale(.6f, .6f);

    //========================TEE3========================
    sf::Texture tee3;
    if (!tee3.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Tees/tee3.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite tee3s;
    tee3s.setTexture(tee3);
    tee3s.setPosition(1000, 90);
    tee3s.setOrigin(0, 0);
    tee3s.setScale(.6f, .6f);

    //========================TEE4========================
    sf::Texture tee4;
    if (!tee4.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Tees/tee4.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite tee4s;
    tee4s.setTexture(tee4);
    tee4s.setPosition(1000, 90);
    tee4s.setOrigin(0, 0);
    tee4s.setScale(.6f, .6f);

    //========================TEE5========================
    sf::Texture tee5;
    if (!tee5.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Tees/tee5.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite tee5s;
    tee5s.setTexture(tee5);
    tee5s.setPosition(1000, 90);
    tee5s.setOrigin(0, 0);
    tee5s.setScale(.6f, .6f);


    //=============================================================================TROUSERS================================================================================================================
      //========================TROU1========================
    sf::Texture trou1;
    if (!trou1.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Trousers/trousers1.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite trou1s;
    trou1s.setTexture(trou1);
    trou1s.setPosition(600, 300);
    trou1s.setOrigin(0, 0);
    trou1s.setScale(.6f, .6f);

    //========================TROU2========================
    sf::Texture trou2;
    if (!trou2.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Trousers/trousers2.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite trou2s;
    trou2s.setTexture(trou2);
    trou2s.setPosition(600, 300);
    trou2s.setOrigin(0, 0);
    trou2s.setScale(.6f, .6f);

    //========================TROU3========================
    sf::Texture trou3;
    if (!trou3.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Trousers/trousers3.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite trou3s;
    trou3s.setTexture(trou3);
    trou3s.setPosition(600, 300);
    trou3s.setOrigin(0, 0);
    trou3s.setScale(.6f, .6f);

    //========================TROU4========================
    sf::Texture trou4;
    if (!trou4.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Trousers/trousers4.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite trou4s;
    trou4s.setTexture(trou4);
    trou4s.setPosition(600, 300);
    trou4s.setOrigin(0, 0);
    trou4s.setScale(.6f, .6f);

    //========================TROU5========================
    sf::Texture trou5;
    if (!trou5.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Trousers/trousers5.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite trou5s;
    trou5s.setTexture(trou5);
    trou5s.setPosition(600, 300);
    trou5s.setOrigin(0, 0);
    trou5s.setScale(.6f, .6f);





    //=============================================================================SHOES================================================================================================================
   //========================SHOE1========================
    sf::Texture shoe1;
    if (!shoe1.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Shoes/shoe1.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite shoe1s;
    shoe1s.setTexture(shoe1);
    shoe1s.setPosition(600, 600);
    shoe1s.setOrigin(0, 0);
    shoe1s.setScale(.6f, .6f);

    //========================SHOE2========================
    sf::Texture shoe2;
    if (!shoe2.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Shoes/shoe2.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite shoe2s;
    shoe2s.setTexture(shoe2);
    shoe2s.setPosition(600, 600);
    shoe2s.setOrigin(0, 0);
    shoe2s.setScale(.6f, .6f);

    //========================SHOE3========================
    sf::Texture shoe3;
    if (!shoe3.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Shoes/shoe3.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite shoe3s;
    shoe3s.setTexture(shoe3);
    shoe3s.setPosition(600, 600);
    shoe3s.setOrigin(0, 0);
    shoe3s.setScale(.6f, .6f);

    //========================SHOE4========================
    sf::Texture shoe4;
    if (!shoe4.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Shoes/shoe4.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite shoe4s;
    shoe4s.setTexture(shoe4);
    shoe4s.setPosition(600, 600);
    shoe4s.setOrigin(0, 0);
    shoe4s.setScale(.6f, .6f);

    //========================SHOE5========================
    sf::Texture shoe5;
    if (!shoe5.loadFromFile("C:/Users/mccal/Desktop/OutfitGenerator/Pics/Shoes/shoe5.jpg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    sf::Sprite shoe5s;
    shoe5s.setTexture(shoe5);
    shoe5s.setPosition(600, 600);
    shoe5s.setOrigin(0, 0);
    shoe5s.setScale(.6f, .6f);



    //Random Number Code
    srand(time(NULL));
    int jacketRand;
    int teeRand;
    int trouRand;
    int shoeRand;

    jacketRand = rand() % 10 + 1;
    teeRand = rand() % 5 + 1;
    trouRand = rand() % 5 + 1;
    shoeRand = rand() % 5 + 1;

    int jackNum = jacketRand;
    int teeNum = teeRand;
    int trouNum = trouRand;
    int shoeNum = shoeRand;

    cout << "jack" << jackNum;
    cout << "tee " << teeNum;
    cout << "trou " << trouNum;

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


        Window.draw(background);

        //JACKET IF STATEMENTS
        if (jackNum == 1) {
            Window.draw(jacket1s);
        }
        else if (jackNum == 2) {
            Window.draw(jacket2s);
        }
        else if (jackNum == 3) {
            Window.draw(jacket3s);
        }
        else if (jackNum == 4) {
            Window.draw(jacket4s);
        }
        else if (jackNum == 5) {
            Window.draw(jacket5s);
        }
        else if (jackNum == 6) {
            Window.draw(jacket6s);
        }
        else if (jackNum == 7) {
            Window.draw(jacket7s);
        }
        else if (jackNum == 8) {
            Window.draw(jacket8s);
        }
        else if (jackNum == 9) {
            Window.draw(jacket9s);
        }
        else if (jackNum == 10) {
            Window.draw(jacket10s);
        }

        //TEE IF STATEMENTS
        if (teeNum == 1) {
            Window.draw(tee1s);
        }
        else if (teeNum == 2) {
            Window.draw(tee2s);
        }
        else if (teeNum == 3) {
            Window.draw(tee3s);
        }
        else if (teeNum == 4) {
            Window.draw(tee4s);
        }
        else if (teeNum == 5) {
            Window.draw(tee5s);
        }

        //TROUSERS IF STATEMENTS
        if (trouNum == 1) {
            Window.draw(trou1s);
        }
        else if (trouNum == 2) {
            Window.draw(trou2s);
        }
        else if (trouNum == 3) {
            Window.draw(trou3s);
        }
        else if (trouNum == 4) {
            Window.draw(trou4s);
        }
        else if (trouNum == 5) {
            Window.draw(trou5s);
        }

        //SHOES IF STATEMENTS
        if (shoeNum == 1) {
            Window.draw(shoe1s);
        }
        else if (shoeNum == 2) {
            Window.draw(shoe2s);
        }
        else if (shoeNum == 3) {
            Window.draw(shoe3s);
        }
        else if (shoeNum == 4) {
            Window.draw(shoe4s);
        }
        else if (shoeNum == 5) {
            Window.draw(shoe5s);
        }

        // Update display and wait for vsync
        Window.display();

    }

}