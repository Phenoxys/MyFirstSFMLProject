#ifndef __MAIN__
#define __MAIN__

#include "../include/input.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

void loadFont();
void setText(sf::Text &refTxt, std::string str, int size, sf::Color col);
void CheckBtn();


#endif