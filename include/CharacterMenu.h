# ifndef CHARACTERMENU_H
# define CHARACTERMENU_H

# include "Scene.h"
# include "Character.h"
# include "LevelUp.h"
# include "CharacterCreation.h"
# include <memory>
# include <utility>

class CharacterMenu : public Scene
{
private:
    Character &character;

public:
    std::unique_ptr<LevelUp> adjuster = nullptr;

    CharacterMenu(std::vector<Button> p_buttons, std::vector<sf::Text> p_texts,
        std::shared_ptr<sf::Texture> p_background, Character &p_character,
        std::unique_ptr<LevelUp> p_adjuster);

    void draw(sf::RenderWindow &window) const override;

    const Character & getCharacter() const;
};

# endif
