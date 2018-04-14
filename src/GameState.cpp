# include "GameState.h"

GameState::GameState()
{
}

void GameState::clearState()
{
    scene = nullptr;
    button = nullptr;
    creator = nullptr;
    leveler = nullptr;
    player = nullptr;
    opponent = nullptr;
}
void GameState::clearScene()
{
    scene = nullptr;
}
void GameState::clearButton()
{
    button = nullptr;
}
void GameState::clearCreator()
{
    creator = nullptr;
}
void GameState::clearLeveler()
{
    leveler = nullptr;
}
void GameState::clearPlayer()
{
    player = nullptr;
}
void GameState::clearOpponent()
{
    opponent = nullptr;
}

void GameState::setScene(Scene &s)
{
    scene = &s;
}
void GameState::setButton(Button &b)
{
    button = &b;
}
void GameState::setCreator(CharacterCreation &c)
{
    creator = std::make_unique<CharacterCreation>(c);
}
void GameState::setCreator(CharacterCreation c)
{
    creator = std::make_unique<CharacterCreation>(c);
}
void GameState::setLeveler(LevelUp &l)
{
    leveler = std::make_unique<LevelUp>(l);
}
void GameState::setLeveler(LevelUp l)
{
    leveler = std::make_unique<LevelUp>(l);
}
void GameState::setPlayer(Character &p)
{
    player = std::make_unique<Character>(p);
}
void GameState::setPlayer(Character p)
{
    player = std::make_unique<Character>(p);
}
void GameState::setOpponent(Character &o)
{
    opponent = std::make_unique<Character>(o);
}
void GameState::setOpponent(Character o)
{
    opponent = std::make_unique<Character>(o);
}

Scene * GameState::getScene()
{
    return scene;
}
Button * GameState::getButton()
{
    return button;
}
Button *& GameState::getButtonRef()
{
    return button;
}
CharacterCreation * GameState::getCreator()
{
    return creator.get();
}
LevelUp * GameState::getLeveler()
{
    return leveler.get();
}
Character * GameState::getPlayer()
{
    return player.get();
}
Character * GameState::getOpponent()
{
    return opponent.get();
}
