# include "Character.h"
# include "Cosmetic.h"
# include "LevelUp.h"
# include "CharacterCreation.h"
# include "global.h"
# include "Scene.h"
# include "CharacterMenu.h"
# include "Button.h"
# include "ButtonEnum.h"
# include <iostream>
# include <string>
# include <memory>
# include <SFML/Graphics.hpp>

sf::Font globalFont;
unsigned int globalFontSize { 16 };
sf::Vector2f globalWindowSize { 1000, 750 };
sf::Vector2f globalButtonSize { 200, 50 };

int main()
{
    globalFont.loadFromFile("../resources/fonts/cambriab.ttf");

    sf::RenderWindow mainWindow { sf::VideoMode { globalWindowSize.x, globalWindowSize.y }, "Arena Battler" };


    sf::Texture newGameTexture;
    newGameTexture.loadFromFile("../resources/images/NewGameButton.png");
    auto newGameTexture_ptr = std::make_shared<sf::Texture>(newGameTexture);

    sf::Texture newGameClickedTexture;
    newGameClickedTexture.loadFromFile("../resources/images/NewGameButtonClicked.png");
    auto newGameClickedTexture_ptr = std::make_shared<sf::Texture>(newGameClickedTexture);

    Button newGameButton { ButtonEnum::NewGame, { globalWindowSize.x/2 - globalButtonSize.x, globalWindowSize.y/8 }, globalButtonSize, newGameTexture_ptr, newGameClickedTexture_ptr };
    Scene mainMenu { { newGameButton }, {}, newGameTexture_ptr };


    Scene *currentScene = &mainMenu;
    Button *currentButton;
    while (mainWindow.isOpen())
    {
        sf::Event event;
        while (currentScene == &mainMenu && mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                mainWindow.close();
            }
            if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
            {
                if ((*currentScene).getClickedButton(event, currentButton))
                {
                    std::cout << "Button pressed!\n";
                    (*currentButton).setClicked();
                }
            }
            if ((event.type == sf::Event::MouseButtonReleased) && (event.mouseButton.button == sf::Mouse::Left))
            {
                (*currentButton).setUnclicked();
            }
        }
        mainWindow.clear();
        mainWindow.draw(*currentScene);
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
