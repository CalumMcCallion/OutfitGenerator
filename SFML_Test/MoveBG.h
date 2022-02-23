#pragma once
#ifndef GUIMOVABLEBACKGROUNDS_H
#define GUIMOVABLEBACKGROUNDS_H

#include <SFML\Graphics.hpp>
# include <iostream>

class MovableBackground
{
public:
    MovableBackground();
    void Update(sf::RenderWindow& window, float elapsedTime);
    void Render(sf::RenderWindow& window);

private:
    sf::Texture bg1Tex;
    sf::Texture bg2Tex;

    sf::Sprite      bg1Sprite;
    sf::Sprite      bg2Sprite;

    float bgSpeed;
    float bg1Y;
    float bg2Y;
};
#endif
