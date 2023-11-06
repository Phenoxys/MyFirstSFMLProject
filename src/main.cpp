#include "../include/main.hpp"


sf::RenderWindow window;
Input input;
sf::Font font;
sf::Text txt;

float posX = 5.0f;

char temp[WIN_WIDTH];

int main()
{
    sf::ContextSettings options;

    options.antialiasingLevel = 8;

    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Mon titre", sf::Style::Close, options);

    window.setVerticalSyncEnabled(true);

    loadFont();

    setText(txt, "Appuie sur des boutons", 50, sf::Color::Cyan);

    // formes
    sf::CircleShape circleShape(80);
    circleShape.setFillColor(sf::Color(100, 175, 80));
    circleShape.setOutlineColor(sf::Color::Red);
    circleShape.setOutlineThickness(5);
    circleShape.setPosition(posX, 100);

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            input.inputHandler(event, window);
            CheckBtn();
            circleShape.setPosition(posX, 100);
        }

        sf::Color color(60, 0, 70);

        window.clear(color);

        
        window.draw(circleShape);
        window.draw(txt);

        window.display();
    }
    
    
    return 0;
}

void loadFont()
{
    if(!font.loadFromFile("assets/fonts/Poppins-Regular.ttf"))
    {
        throw("Erreur chargement fonte");
    }
}

void setText(sf::Text &refTxt, std::string str, int size, sf::Color col)
{
    refTxt.setFont(font);

    refTxt.setString(str);

    refTxt.setCharacterSize(size);

    refTxt.setFillColor(col);

    refTxt.setStyle(sf::Text::Bold | sf::Text::Italic); 
}

void CheckBtn()
{
    if(input.getButton().escape == true)
    {
        window.close();
    }

    if(input.getButton().left == true)
    {
        if(posX > 0)
        {
            posX -= 5.0f;
            sprintf(temp, "%f", posX);
            setText(txt, temp, 80, sf::Color::White);
        }
    }

    if(input.getButton().right == true)
    {
        if(posX < WIN_WIDTH - 80 * 2 - 5)
        {
            posX += 5.0f;
            sprintf(temp, "%f", posX);
            setText(txt, temp, 80, sf::Color::White);
        }
    }

    if(input.getButton().up == true)
    {
        setText(txt, "Up", 80, sf::Color::White);
    }

    if(input.getButton().down == true)
    {
        setText(txt, "Down", 80, sf::Color::White);
    }

    if(input.getButton().attack == true)
    {
        setText(txt, "Attack", 80, sf::Color::White);
    }
}