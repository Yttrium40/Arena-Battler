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

    sf::Texture redBackgroundTexture;
    redBackgroundTexture.loadFromFile("../resources/images/RedBackground.png");
    auto redBackgroundTexture_ptr = std::make_shared<sf::Texture>(redBackgroundTexture);


    // Main Menu
    sf::Texture newGameTexture;
    newGameTexture.loadFromFile("../resources/images/NewGameButton.png");
    auto newGameTexture_ptr = std::make_shared<sf::Texture>(newGameTexture);

    sf::Texture newGameClickedTexture;
    newGameClickedTexture.loadFromFile("../resources/images/NewGameButtonClicked.png");
    auto newGameClickedTexture_ptr = std::make_shared<sf::Texture>(newGameClickedTexture);

    Button newGameButton { ButtonEnum::NewGame, { 200, 500 }, globalButtonSize, newGameTexture_ptr, newGameClickedTexture_ptr };
    Scene mainMenu { { newGameButton }, {}, redBackgroundTexture_ptr };


    // Character Menu
    sf::Texture mainMenuTexture;
    mainMenuTexture.loadFromFile("../resources/images/MainMenuButton.png");
    auto mainMenuTexture_ptr = std::make_shared<sf::Texture>(mainMenuTexture);

    sf::Texture mainMenuClickedTexture;
    mainMenuClickedTexture.loadFromFile("../resources/images/MainMenuButtonClicked.png");
    auto mainMenuClickedTexture_ptr = std::make_shared<sf::Texture>(mainMenuClickedTexture);

    sf::Texture continueTexture;
    continueTexture.loadFromFile("../resources/images/ContinueButton.png");
    auto continueTexture_ptr = std::make_shared<sf::Texture>(continueTexture);

    sf::Texture continueClickedTexture;
    continueClickedTexture.loadFromFile("../resources/images/ContinueButtonClicked.png");
    auto continueClickedTexture_ptr = std::make_shared<sf::Texture>(continueClickedTexture);

    sf::Texture plusTexture;
    plusTexture.loadFromFile("../resources/images/PlusButton.png");
    auto plusTexture_ptr = std::make_shared<sf::Texture>(plusTexture);

    sf::Texture minusTexture;
    minusTexture.loadFromFile("../resources/images/MinusButton.png");
    auto minusTexture_ptr = std::make_shared<sf::Texture>(minusTexture);

    Button mainMenuButton { ButtonEnum::MainMenu, { 800, 500 }, globalButtonSize, mainMenuTexture_ptr, mainMenuClickedTexture_ptr };
    Scene characterMenu { { mainMenuButton }, {}, redBackgroundTexture_ptr };


    Scene *currentScene = &mainMenu;
    Button *currentButton = nullptr;
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
                if (currentButton != nullptr)
                {
                    (*currentButton).setUnclicked();
                    switch ((*currentButton).getId())
                    {
                        case ButtonEnum::NewGame:
                            currentScene = &characterMenu;
                            break;
                    }
                }
            }
        }
        while (currentScene == &characterMenu && mainWindow.pollEvent(event))
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
                switch ((*currentButton).getId())
                {
                    case ButtonEnum::MainMenu:
                        currentScene = &mainMenu;
                        break;
                }
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
