# ifndef BUTTON_H
# define BUTTON_H

# include <SFML/Graphics.hpp>
# include <string>
# include <memory>
# include "global.h"

class Button : public sf::Drawable
{
private:
    std::shared_ptr<sf::Texture> background;
    std::shared_ptr<sf::Texture> backgroundClicked = nullptr;
    bool clicked = false;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    sf::RectangleShape box;

    Button(sf::RectangleShape p_box,
        std::shared_ptr<sf::Texture> p_backgroundClicked = nullptr);

    Button(sf::Vector2f p_position, sf::Vector2f p_size,
        std::shared_ptr<sf::Texture> p_background,
        std::shared_ptr<sf::Texture> p_backgroundClicked = nullptr);

    bool containsClick(const sf::Event &event) const;

    void setClicked();
    void setUnclicked();

    void setBackground(std::shared_ptr<sf::Texture> background);
    void setBackgroundClicked(std::shared_ptr<sf::Texture> backgroundClicked);

    bool isClicked() const;
};

# endif
