#ifndef __INPUT__
#define __INPUT__

#include <SFML/Graphics.hpp>

class Input
{
    struct Button{bool left, right, up, down, attack, escape;};
    
    public:
        Input();
        void inputHandler(sf::Event event, sf::RenderWindow &window); 
        Button getButton() const;

    private:
        Button button;

};

#endif