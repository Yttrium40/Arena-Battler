# include "CharacterMenu.h"

CharacterMenu::CharacterMenu(std::vector<Button> p_buttons, std::vector<sf::Text> p_texts,
    std::shared_ptr<sf::Texture> p_background, Character &p_character,
    std::unique_ptr<LevelUp> p_adjuster)
: Scene(p_buttons, p_texts, p_background), character { p_character },
    adjuster { std::move(p_adjuster) }
{
}

// this will be different depending on whether the adjuster has points left
void CharacterMenu::draw(sf::RenderWindow &window) const
{
    sf::RectangleShape back { sf::Vector2f(window.getSize()) };
    back.setTexture(background.get());
    window.draw(back);
    for (const Button &button : buttons)
    {
        button.draw(window);
    }
    for (const sf::Text &text : texts)
    {
        window.draw(text);
    }
}

const Character & CharacterMenu::getCharacter() const { return character; }
