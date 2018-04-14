# ifndef GAMESTATE_H
# define GAMESTATE_H

# include <memory>
# include "Button.h"
# include "Scene.h"
# include "CharacterCreation.h"
# include "LevelUp.h"
# include "Character.h"

class GameState
{
private:
    Scene *scene = nullptr;
    Button *button = nullptr;
    std::unique_ptr<CharacterCreation> creator = nullptr;
    std::unique_ptr<LevelUp> leveler = nullptr;
    std::unique_ptr<Character> player = nullptr;
    std::unique_ptr<Character> opponent = nullptr;

public:
    GameState();

    void clearState();
    void clearScene();
    void clearButton();
    void clearCreator();
    void clearLeveler();
    void clearPlayer();
    void clearOpponent();

    void setScene(Scene &s);
    void setButton(Button &b);
    void setCreator(CharacterCreation &c);
    void setCreator(CharacterCreation c);
    void setLeveler(LevelUp &l);
    void setLeveler(LevelUp l);
    void setPlayer(Character &p);
    void setPlayer(Character p);
    void setOpponent(Character &o);
    void setOpponent(Character o);

    Scene * getScene();
    Button * getButton();
    Button *& getButtonRef();
    CharacterCreation * getCreator();
    LevelUp * getLeveler();
    Character * getPlayer();
    Character * getOpponent();
};

# endif
