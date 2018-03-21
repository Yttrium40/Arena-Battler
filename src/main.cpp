# include "Character.h"
# include "Cosmetic.h"
# include "LevelUp.h"
# include "CharacterCreation.h"
# include "global.h"
# include "Scene.h"
# include "CharacterMenu.h"
# include "Button.h"
# include <iostream>
# include <string>
# include <SFML/Graphics.hpp>

sf::Font globalFont;
unsigned int globalFontSize{ 16 };
sf::Vector2f globalWindowSize{ 800, 600 };

int main()
{
    globalFont.loadFromFile("../resources/fonts/cambriab.ttf");

    sf::Texture texture;
    texture.loadFromFile("../resources/images/NewGameButton.png");
    auto texture_ptr = std::make_shared<sf::Texture>(texture);

    sf::RenderWindow mainWindow { sf::VideoMode { globalWindowSize.x, globalWindowSize.y }, "Arena Battler" };
    Button shape { { 100, 100 }, { 200, 100 }, texture_ptr };

    while (mainWindow.isOpen())
    {
        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mainWindow.close();

            if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
                if (shape.containsClick(event))
                {
                    std::cout << "Button pressed!\n";
                    shape.setClicked();
                }

            if ((event.type == sf::Event::MouseButtonReleased) && (event.mouseButton.button == sf::Mouse::Left))
                shape.setUnclicked();
        }

        mainWindow.clear();
        mainWindow.draw(shape);
        mainWindow.display();
    }

    // Character myCharacter { "Sican" };
    // CharacterCreation myCreation { myCharacter, 5 };
    // myCreation.setRace("cat-folk");
    // myCreation.setWeapon("longsword");
    // myCreation.setElement("fire");
    //
    // Cosmetic myCosmetic;
    // myCreation.setDescription(myCosmetic.getRandomizedDescription(myCharacter));
    // std::cout << myCharacter.getDescription() << std::endl;
    //
    // int whoop;
    // std::cin >> whoop;
    return 0;
}
