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
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
using namespace std;
using namespace sf;

// Sprite speed (high values = high speed)
#define SPRITE_SPEED        13


int main() {
    start:
int score = 0;
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow Window(sf::VideoMode(desktopMode.width, desktopMode.height, desktopMode.bitsPerPixel), "Scroll Game", sf::Style::Fullscreen);

    sf::View View(Window.getDefaultView());
    sf::FloatRect fBounds(0.f, 0.f, 2500.f, 3000.f); // arbitrary > view "SIZE"

    //code for loading font from file and storing it in the font variable
    sf::Font font;

    if (!font.loadFromFile("C:/Users/mccal/Desktop/Computer Science Uni/YEAR 2/OOP/Coursework Num1/SFML_Points-master/include/SFML/fonts/scoreFont.ttf")) { //loading in font for the text graphic
     // handle error
    }
    
    int lifes = 4;

    //creating title for x axis
    sf::Text xText;
    xText.setFont(font);
    xText.setFillColor(sf::Color::White);
    xText.setCharacterSize(40);
    xText.setPosition(240, 10);
    xText.setString(std::to_string(score));

    sf::Font font1;
    if (!font1.loadFromFile("C:/Users/mccal/Desktop/Computer Science Uni/YEAR 2/OOP/Coursework Num1/SFML_Points-master/include/SFML/fonts/scoreFont.ttf")) { //loading in font for the text graphic
    // handle error
    }
    

    //creating title for x axis
    sf::Text xText1;
    xText1.setFont(font1);
    xText1.setString("Score: ");
    xText1.setFillColor(sf::Color::Red);
    xText1.setCharacterSize(40);
    xText1.setPosition(10, 10);

    //creating the text to show notify the user that they can restart by pressing R
    sf::Text restartTxt;
    restartTxt.setFont(font1);
    restartTxt.setString("Press R to restart");
    restartTxt.setFillColor(sf::Color::White);
    restartTxt.setCharacterSize(70);
    restartTxt.setPosition(400, 800);

    //these next two restartTxt sections are displaying the same text with variations in colour and position to give the text a glitched effect to fit in with the aesthetic of the game over screen
    sf::Text restartTxt1;
    restartTxt1.setFont(font1);
    restartTxt1.setString("Press R to restart");
    restartTxt1.setFillColor(sf::Color::Blue);
    restartTxt1.setCharacterSize(70);
    restartTxt1.setPosition(410, 790);

    sf::Text restartTxt2;
    restartTxt2.setFont(font1);
    restartTxt2.setString("Press R to restart");
    restartTxt2.setFillColor(sf::Color::Red);
    restartTxt2.setCharacterSize(70);
    restartTxt2.setPosition(390, 810);
   
   
sf::Texture Texture;

// Enable vertical sync. (vsync)
Window.setVerticalSyncEnabled(true);
// When a key is pressed, sf::Event::KeyPressed will be true only once
Window.setKeyRepeatEnabled(false);

//=============================================================================SHIP SPRITE================================================================================================================
sf::Texture shipExplode;
if (!shipExplode.loadFromFile("C:/Users/mccal/Desktop/Computer Science Uni/YEAR 2/OOP/CW2 Game/Coursework Num1 - Copy/SFML_Points-master/media/bomb.png"))
{
    std::cerr << "Error while loading texture" << std::endl;
    return -1;
}
//=============================================================================GAME OVER SPRITE================================================================================================================
sf::Texture gameOverPic;
if (!gameOverPic.loadFromFile("C:/Users/mccal/Desktop/Computer Science Uni/YEAR 2/OOP/CW2 Game/Coursework Num1 - Copy/SFML_Points-master/media/gameO.jpg"))
{
    std::cerr << "Error while loading texture" << std::endl;
    return -1;
}

//creating the game over screen
sf::Sprite gameOver;
gameOver.setTexture(gameOverPic);
sf::FloatRect goSize = gameOver.getGlobalBounds();
gameOver.setOrigin(0, 0);
gameOver.setScale(3.5f, 3.5f);

//creates the texture for the broken heart effect once the user loses a life
sf::Texture brokenHeart;
if (!brokenHeart.loadFromFile("C:/Users/mccal/Desktop/Computer Science Uni/YEAR 2/OOP/CW2 Game/Coursework Num1 - Copy/SFML_Points-master/media/brokenHeart.png"))
{
    std::cerr << "Error while loading texture" << std::endl;
    return -1;
}

//loads texture for the hearts 
sf::Texture lifesPic;
if (!lifesPic.loadFromFile("C:/Users/mccal/Desktop/Computer Science Uni/YEAR 2/OOP/CW2 Game/Coursework Num1 - Copy/SFML_Points-master/media/heart.png"))
{
    std::cerr << "Error while loading texture" << std::endl;
    return -1;
}

//creates the first heart texture to signal to the user as to how many lifes they have
sf::Sprite lifesSprite;
lifesSprite.setTexture(lifesPic);
lifesSprite.setPosition(1600, 5);
lifesSprite.setScale(0.13f, 0.13f);


//creates the second heart texture to signal to the user as to how many lifes they have
sf::Sprite lifesSprite1;
lifesSprite1.setTexture(lifesPic);
lifesSprite1.setPosition(1700, 5);
lifesSprite1.setScale(0.13f, 0.13f);



//creates the third heart texture to signal to the user as to how many lifes they have
sf::Sprite lifesSprite2;
lifesSprite2.setTexture(lifesPic);
lifesSprite2.setPosition(1500, 5);
lifesSprite2.setScale(0.13f, 0.13f);


 // Create texture from PNG file
sf::Texture texture;
if (!texture.loadFromFile("C:/Users/mccal/Desktop/Computer Science Uni/YEAR 2/OOP/CW2 Game/Coursework Num1 - Copy/SFML_Points-master/media/ship.png"))
{
    std::cerr << "Error while loading texture" << std::endl;
    return -1;
}
// Enable the smooth filter. The texture appears smoother so that pixels are less noticeable.
texture.setSmooth(true);

// Create the sprite and apply the texture
sf::Sprite ship;
ship.setTexture(texture);
sf::FloatRect spriteSize = ship.getGlobalBounds();
ship.setOrigin(spriteSize.width / 2, spriteSize.height / 2);
ship.setScale(0.35f, 0.35f);

// Sprite coordinates
int xShip = Window.getSize().x / 2.;
int yShip = Window.getSize().y / 2;

float newBulletX = xShip;

/// Flags for key pressed
bool upFlag = false;
bool downFlag = false;
bool leftFlag = false;
bool rightFlag = false;
bool spaceFlag = false;

//=============================================================================ENEMY SPRITE================================================================================================================


// Create texture from PNG file
sf::Texture textureEnemy;
if (!textureEnemy.loadFromFile("C:/Users/mccal/Desktop/Computer Science Uni/YEAR 2/OOP/CW2 Game/Coursework Num1 - Copy/SFML_Points-master/media/enemy.png"))
{
    std::cerr << "Error while loading texture" << std::endl;
    return -1;
}

sf::Texture deadEnemy;
if (!deadEnemy.loadFromFile("C:/Users/mccal/Desktop/Computer Science Uni/YEAR 2/OOP/CW2 Game/Coursework Num1 - Copy/SFML_Points-master/media/ship.png"))
{
    std::cerr << "Error while loading texture" << std::endl;
    return -1;
}
// Enable the smooth filter. The texture appears smoother so that pixels are less noticeable.
textureEnemy.setSmooth(true);

srand(time(NULL));
float randNumX = rand() % ((1920 - 200) - 50 + 1) + 50;

// Create the sprite and apply the texture
sf::Sprite enemy;
enemy.setTexture(textureEnemy);
sf::FloatRect enemySize = enemy.getGlobalBounds();
enemy.setOrigin(enemySize.width / 2, enemySize.height / 2);
enemy.setScale(0.25f, 0.25f);

// Sprite coordinates
int xEnemy = randNumX;
int yEnemy = 0;

//=============================================================================BULLET SPRITE================================================================================================================

// Create texture from PNG file
sf::Texture textureBullet;
if (!textureBullet.loadFromFile("C:/Users/mccal/Desktop/Computer Science Uni/YEAR 2/OOP/CW2 Game/Coursework Num1 - Copy/SFML_Points-master/media/Untitled.png"))
{
    std::cerr << "Error while loading texture" << std::endl;
    return -1;
}
// Enable the smooth filter. The texture appears smoother so that pixels are less noticeable.
textureBullet.setSmooth(true);

// Create the sprite and apply the texture
sf::Sprite bullet;
bullet.setTexture(textureBullet);
sf::FloatRect bulletSize = bullet.getGlobalBounds();
bullet.setOrigin(bulletSize.width / 2, bulletSize.height / 2);
bullet.setScale(0.5f, 0.5f);
bullet.setPosition(800, 500);

// Sprite coordinates
int pix = 10;
int xBullet = xShip;
int yBullet = (yShip + pix);
int gameOverFlag = 0;

//=============================================================================AUDIO=======================================================================================================================

//Explosion sound
sf::SoundBuffer explosion;
if (!explosion.loadFromFile("C:/Users/mccal/Desktop/Computer Science Uni/YEAR 2/OOP/CW2 Game/Coursework Num1 - Copy/SFML_Points-master/media/boom.wav"))
return -1;

sf::Sound explosionSound;
explosionSound.setBuffer(explosion);

//Life lost sound
sf::SoundBuffer lifeLost;
if (!lifeLost.loadFromFile("C:/Users/mccal/Desktop/Computer Science Uni/YEAR 2/OOP/CW2 Game/Coursework Num1 - Copy/SFML_Points-master/media/lifeLost.wav"))
return -1;

sf::Sound lifeLostSound;
lifeLostSound.setBuffer(lifeLost);

//Game over sound
sf::SoundBuffer gameOverS;
if (!gameOverS.loadFromFile("C:/Users/mccal/Desktop/Computer Science Uni/YEAR 2/OOP/CW2 Game/Coursework Num1 - Copy/SFML_Points-master/media/gameOver.wav"))
return -1;

sf::Sound gameOverSound;
gameOverSound.setBuffer(gameOverS);

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

        // If a key is pressed ARROWS
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) rightFlag = true;
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) rightFlag = false;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) leftFlag = true;
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) leftFlag = false;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) upFlag = true;
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) upFlag = false;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) downFlag = true;
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) downFlag = false;
      
        //Shooting Bullet
        //I had almost got this code working but there was a few tweaks in which Mark figured out for me
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            pix = 60;
            newBulletX = xShip;
        }
        else {
            bullet.setPosition(newBulletX, (yShip - pix));
            pix = pix + 30;
            bullet.setPosition(newBulletX, (yShip - pix));
            Window.draw(bullet);
        }

        // Update coordinates
        if (leftFlag) xShip -= SPRITE_SPEED;
        if (rightFlag) xShip += SPRITE_SPEED;
        if (upFlag) yShip -= SPRITE_SPEED;
        if (downFlag) yShip += SPRITE_SPEED;

        // Check screen boundaries
        if (xShip < 0) xShip = 0;
        if (xShip > (int)Window.getSize().x) xShip = Window.getSize().x;
        if (yShip < 0) yShip = 0;
        if (yShip > (int)Window.getSize().y) yShip = Window.getSize().y;


        //speeds up enemy sprite once the score reaches certain amounts
        yEnemy += 6.5;
        if (score >= 10) {
            yEnemy += 1;
        }

        if (score >= 20) {
            yEnemy += 1.5;
        }

        if (score >= 30) {
            yEnemy += 2;
        }

        if (score >= 50) {
            yEnemy += 2.5;
        }

        //loading in image for the background and applying it to a texture
        Texture.loadFromFile("C:/Users/mccal/Desktop/Computer Science Uni/YEAR 2/OOP/CW2 Game/Coursework Num1 - Copy/SFML_Points-master/media/spaceScroll.png");
        sf::IntRect iBounds(fBounds);
        Texture.setRepeated(true);
        sf::Sprite Sprite(Texture, iBounds);


        Window.clear();
        Window.draw(Sprite);
        //rotates the enemy sprite
        enemy.setRotation(timer.getElapsedTime().asSeconds() / M_PI * 90.f);
        //draws ship sprite
        Window.draw(ship);
        ship.setPosition(xShip, yShip);

        //draws ship sprite
        Window.draw(enemy);
        enemy.setPosition(xEnemy, yEnemy);

        //plays sound when bullet hits enemy, increments score by 1
        if (bullet.getGlobalBounds().intersects(enemy.getGlobalBounds())) {
           
            explosionSound.play();
            enemy.setTexture(deadEnemy);
            score += 1;
            enemy.setTexture(textureEnemy);

            //xText.setString(std::to_string(score));
        }

        //resets enemy sprite position if hit by bullet or if reaches bottom of screen
        if (yEnemy > 1080 || bullet.getGlobalBounds().intersects(enemy.getGlobalBounds())) {

            Window.draw(enemy);
            yEnemy = 0;
            xEnemy = rand() % ((1920 - 200) - 50 + 1) + 50;
            enemy.setPosition(xEnemy, yEnemy);
            
        }

        //handles texture change and sound effects once you lose a life
        if (yEnemy >= 1070) {
            lifes = lifes - 1;
            lifesSprite1.setTexture(brokenHeart);
            lifesSprite1.setPosition(1700, 0);
            lifeLostSound.play();
            int inc = 0;
            inc += 1;
            if (lifes == inc) {
                lifesSprite.setTexture(brokenHeart);
                lifesSprite.setPosition(1600, 0);
                lifeLostSound.play();
                inc += 1;
            }
           
        }
        if (lifes == -1) {
            gameOverFlag = 1;
            lifesSprite2.setTexture(brokenHeart);
            lifesSprite2.setPosition(1500, 0);
            lifeLostSound.play();
        }


        xText.setString(std::to_string(score));
       
        //restarts game once R key is pressed
        //Took the idea for this from Mark 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            goto start;
        }

        //activates game over screen once enemy sprite touches ship sprite by changing game over flag to 1 which activates the if statement which has the code to draw the aspects of the game over screen
        if (ship.getGlobalBounds().intersects(enemy.getGlobalBounds())) {
            gameOverFlag = 1;
        }

        //closes program once user presses the ESC key
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            Window.close();
        }
        
        //activates once the game over flag is increased to 1, once activated it runs all the elements needed to display the screen and text
        if (gameOverFlag == 1) {
            Window.draw(gameOver);
            Window.draw(restartTxt1);
            Window.draw(restartTxt2);
            Window.draw(restartTxt);
            bullet.setPosition(10000, 10000);
            bullet.setScale(0.0f, 0.0f);
            
            //plays game over sound
            int count = 0;
            count += 1;
            if (count > 1) {
                gameOverSound.stop();
            }
            gameOverSound.play();
            sf::sleep(sf::milliseconds(1500));
        }

            /*int count = 0;
            count += 1;
            if (count > 0) {
                count += 1;
                if (count < 1000) {
                    gameOverSound.play();
                }
            }
            */

      
        //draws the aspects of the game
        Window.draw(lifesSprite);
        Window.draw(lifesSprite1);
        Window.draw(lifesSprite2);
        Window.draw(xText);
        Window.draw(xText1);
        Window.draw(bullet);
        // Update display and wait for vsync
        Window.display();

    }

}