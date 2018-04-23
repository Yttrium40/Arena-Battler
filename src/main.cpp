# include "Character.h"
# include "Cosmetic.h"
# include "LevelUp.h"
# include "CharacterCreation.h"
# include "global.h"
# include "Scene.h"
# include "CharacterMenu.h"
# include "Button.h"
# include "ButtonEnum.h"
# include "GameState.h"
# include <iostream>
# include <string>
# include <memory>
# include <SFML/Graphics.hpp>

sf::Font globalFont;
unsigned int globalFontSize { 16 };
sf::Vector2f globalWindowSize { 1000, 750 };
sf::Vector2f globalButtonSize { 200, 50 };
sf::Vector2f globalSquareButtonSize { 50, 50 };

int main()
{
    globalFont.loadFromFile("../resources/fonts/cambriab.ttf");

    sf::RenderWindow mainWindow { sf::VideoMode { globalWindowSize.x, globalWindowSize.y }, "Arena Battler", sf::Style::Titlebar | sf::Style::Close };

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

    Button newGameButton { ButtonEnum::NewGame, { globalWindowSize.x/2 - globalButtonSize.x/2, 0 }, globalButtonSize, newGameTexture_ptr, newGameClickedTexture_ptr };
    Scene mainMenu       { { newGameButton }, {}, redBackgroundTexture_ptr };


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

    Button mainMenuButton      { ButtonEnum::MainMenu, { globalWindowSize.x - globalButtonSize.x, 0 }, globalButtonSize, mainMenuTexture_ptr, mainMenuClickedTexture_ptr };
    sf::Text nameText          { "Example", globalFont, globalFontSize };
    nameText.setPosition(0, 0);

    Button minusPhysiqueButton { ButtonEnum::MinusPhysique,
                               { 0, nameText.getPosition().y }, globalSquareButtonSize, minusTexture_ptr };
    sf::Text physiqueText      { "Physique", globalFont, globalFontSize };
    physiqueText.setPosition(minusPhysiqueButton.box.getPosition().x + globalSquareButtonSize.x, minusPhysiqueButton.box.getPosition().y);
    Button plusPhysiqueButton  { ButtonEnum::PlusPhysique,
                               { physiqueText.getPosition().x + physiqueText.getGlobalBounds().width, minusPhysiqueButton.box.getPosition().y }, globalSquareButtonSize, plusTexture_ptr };

    Button minusFocusButton    { ButtonEnum::MinusFocus,
                               { 0, globalSquareButtonSize.y }, globalSquareButtonSize, minusTexture_ptr };
    sf::Text focusText         { "Focus", globalFont, globalFontSize };
    focusText.setPosition(minusFocusButton.box.getPosition().x + globalSquareButtonSize.x, minusFocusButton.box.getPosition().y);
    Button plusFocusButton     { ButtonEnum::PlusFocus,
                               { focusText.getPosition().x + focusText.getGlobalBounds().width, minusFocusButton.box.getPosition().y }, globalSquareButtonSize, plusTexture_ptr };

    Button minusEnduranceButton{ ButtonEnum::MinusEndurance,
                               { 0, globalSquareButtonSize.y }, globalSquareButtonSize, minusTexture_ptr };
    sf::Text enduranceText     { "Endurance", globalFont, globalFontSize };
    enduranceText.setPosition(minusEnduranceButton.box.getPosition().x + globalSquareButtonSize.x, minusEnduranceButton.box.getPosition().y);
    Button plusEnduranceButton { ButtonEnum::PlusEndurance,
                               { enduranceText.getPosition().x + enduranceText.getGlobalBounds().width, minusEnduranceButton.box.getPosition().y }, globalSquareButtonSize, plusTexture_ptr };

    Button minusSpeedButton    { ButtonEnum::MinusSpeed,
                               { 0, globalSquareButtonSize.y }, globalSquareButtonSize, minusTexture_ptr };
    sf::Text speedText         { "Speed", globalFont, globalFontSize };
    speedText.setPosition(minusSpeedButton.box.getPosition().x + globalSquareButtonSize.x, minusSpeedButton.box.getPosition().y);
    Button plusSpeedButton     { ButtonEnum::PlusSpeed,
                               { speedText.getPosition().x + speedText.getGlobalBounds().width, minusSpeedButton.box.getPosition().y }, globalSquareButtonSize, plusTexture_ptr };

    Scene characterMenu        { { mainMenuButton, minusPhysiqueButton, plusPhysiqueButton, minusFocusButton, plusFocusButton, minusEnduranceButton, plusEnduranceButton, minusSpeedButton, plusSpeedButton },
                               { nameText, physiqueText, focusText, enduranceText, speedText }, redBackgroundTexture_ptr };


    GameState state;
    state.setScene(mainMenu);
    while (mainWindow.isOpen())
    {
        sf::Event event;
        while (state.getScene() == &mainMenu && mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                mainWindow.close();
            }
            if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
            {
                if (state.getScene()->getClickedButton(event, state.getButtonRef()))
                {
                    std::cout << "Button pressed!\n";
                    state.getButton()->setClicked();
                }
            }
            if ((event.type == sf::Event::MouseButtonReleased) && (event.mouseButton.button == sf::Mouse::Left))
            {
                if (state.getButton() != nullptr)
                {
                    state.getButton()->setUnclicked();
                    switch (state.getButton()->getId())
                    {
                        case ButtonEnum::NewGame:
                            state.setScene(characterMenu);
                            state.setPlayer({ "DEFAULT NAME" });
                            state.setCreator({ *state.getPlayer(), 5 });
                            break;
                    }
                }
            }
        }
        while (state.getScene() == &characterMenu && mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                mainWindow.close();
            }
            if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
            {
                if (state.getScene()->getClickedButton(event, state.getButtonRef()))
                {
                    std::cout << "Button pressed!\n";
                    state.getButton()->setClicked();
                }
            }
            if ((event.type == sf::Event::MouseButtonReleased) && (event.mouseButton.button == sf::Mouse::Left))
            {
                state.getButton()->setUnclicked();
                switch (state.getButton()->getId())
                {
                    case ButtonEnum::MainMenu:
                        state.setScene(mainMenu);
                        break;
                    case ButtonEnum::PlusPhysique:
                        if (state.getCreator()->getPoints() > 0)
                        {
                            state.getCreator()->increasePhysique();
                        }
                        break;
                    case ButtonEnum::PlusFocus:
                        if (state.getCreator()->getPoints() > 0)
                        {
                            state.getCreator()->increaseFocus();
                        }
                        break;
                    case ButtonEnum::PlusEndurance:
                        if (state.getCreator()->getPoints() > 0)
                        {
                            state.getCreator()->increaseEndurance();
                        }
                        break;
                    case ButtonEnum::PlusSpeed:
                        if (state.getCreator()->getPoints() > 1 && state.getPlayer()->getSpeed() < 3)
                        {
                            state.getCreator()->increaseSpeed();
                        }
                        break;
                    case ButtonEnum::MinusPhysique:
                        if (state.getPlayer()->getPhysique() > 0)
                        {
                            state.getCreator()->decreasePhysique();
                        }
                        break;
                    case ButtonEnum::MinusFocus:
                        if (state.getPlayer()->getFocus() > 0)
                        {
                            state.getCreator()->decreaseFocus();
                        }
                        break;
                    case ButtonEnum::MinusEndurance:
                        if (state.getPlayer()->getEndurance() > 0)
                        {
                            state.getCreator()->decreaseEndurance();
                        }
                        break;
                    case ButtonEnum::MinusSpeed:
                        if (state.getPlayer()->getSpeed() > 1)
                        {
                            state.getCreator()->decreaseSpeed();
                        }
                        break;
                }
            }
        }
        mainWindow.clear();
        mainWindow.draw(*state.getScene());
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
