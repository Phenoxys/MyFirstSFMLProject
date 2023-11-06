#include "../include/input.hpp"


Input::Input()
{
    button.left = button.right = button.up = button.down = button.attack = button.escape = false;
}

Input::Button Input::getButton() const
{
    return button;
}


void Input::inputHandler(sf::Event event, sf::RenderWindow &window)
{
    if(event.type == sf::Event::Closed)
    {
        window.close();
    }

    //key pressed
    if(event.type == sf::Event::KeyPressed)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Escape:
                button.escape = true;
                break;

            case sf::Keyboard::Left:
                button.left = true;
                break;

            case sf::Keyboard::Right:
                button.right = true;
                break;

            case sf::Keyboard::Down:
                button.down = true;
                break;

            case sf::Keyboard::Up:
                button.up = true;
                break;

            default:
                break;
        }
    }

    // key released
    if(event.type == sf::Event::KeyReleased)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Escape:
                button.escape = false;
                break;

            case sf::Keyboard::Left:
                button.left = false;
                break;

            case sf::Keyboard::Right:
                button.right = false;
                break;

            case sf::Keyboard::Down:
                button.down = false;
                break;

            case sf::Keyboard::Up:
                button.up = false;
                break;

            default:
                break;
        }
    }

    // mouse pressed
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            button.attack = true;
        }
    } 

    // mouse released
    if(event.type == sf::Event::MouseButtonReleased)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            button.attack = false;
        }
    }  
}