# ifndef BUTTON_H
# define BUTTON_H

# include <SFML/Graphics.hpp>
# include <string>
# include <memory>
# include "global.h"

class Button
{
private:
    std::shared_ptr<sf::Texture> background;
    std::shared_ptr<sf::Texture> backgroundClicked = nullptr;
    bool clicked = false;

public:
    sf::RectangleShape box;
    sf::Text text;

    Button(sf::RectangleShape p_box, sf::Text p_text,
        std::shared_ptr<sf::Texture> p_backgroundClicked = nullptr);

    Button(sf::Vector2f p_position, sf::Vector2f p_size, std::string p_text,
        std::shared_ptr<sf::Texture> p_background, std::shared_ptr<sf::Texture> p_backgroundClicked = nullptr);

    void draw(sf::RenderWindow &window) const;

    bool containsClick(const sf::Event &event) const;

    void setClicked();
    void setUnclicked();

    void setBackground(std::shared_ptr<sf::Texture> background);
    void setBackgroundClicked(std::shared_ptr<sf::Texture> backgroundClicked);

    bool isClicked() const;
};

# endif
