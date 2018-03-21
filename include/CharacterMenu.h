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

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    std::unique_ptr<LevelUp> adjuster = nullptr;

    CharacterMenu(std::vector<Button> p_buttons, std::vector<sf::Text> p_texts,
        std::shared_ptr<sf::Texture> p_background, Character &p_character,
        std::unique_ptr<LevelUp> p_adjuster);

    const Character & getCharacter() const;
};

# endif
