# include "Button.h"

Button::Button(sf::RectangleShape p_box, sf::Text p_text,
    std::shared_ptr<sf::Texture> p_backgroundClicked)
: box { p_box }, text { p_text }, background { std::make_shared<sf::Texture>(*p_box.getTexture()) },
    backgroundClicked { p_backgroundClicked }
{
    text.setPosition(box.getPosition());
    text.move(box.getSize().x/2 - text.getGlobalBounds().width/2,
        box.getSize().y/2 - text.getGlobalBounds().height/2);
}

Button::Button(sf::Vector2f p_position, sf::Vector2f p_size, std::string p_text,
    std::shared_ptr<sf::Texture> p_background, std::shared_ptr<sf::Texture> p_backgroundClicked)
: box { p_size }, text { p_text, sf::Font(), globalFontSize },
    background { p_background }, backgroundClicked { p_backgroundClicked }
{
    box.setPosition(p_position);
    box.setTexture(background.get());
    text.setFont(globalFont);
    text.setPosition(p_position);
    text.move(box.getSize().x/2 - text.getGlobalBounds().width/2,
        box.getSize().y/2 - text.getGlobalBounds().height/2);
}

void Button::draw(sf::RenderWindow &window) const
{
    window.draw(box);
    window.draw(text);
}

bool Button::containsClick(const sf::Event &event) const
{
    return (event.mouseButton.x > box.getPosition().x)
        && (event.mouseButton.x < box.getPosition().x + box.getSize().x)
        && (event.mouseButton.y > box.getPosition().y)
        && (event.mouseButton.y < box.getPosition().y + box.getSize().y);
}

void Button::setClicked()
{
    if (clicked)
        return;
    clicked = true;
    if (backgroundClicked != nullptr)
        box.setTexture(backgroundClicked.get());
}
void Button::setUnclicked()
{
    if (!clicked)
        return;
    clicked = false;
    if (background != nullptr)
        box.setTexture(background.get());
}

void Button::setBackground(std::shared_ptr<sf::Texture> background)
    { this->background = background; }
void Button::setBackgroundClicked(std::shared_ptr<sf::Texture> backgroundClicked)
    { this->backgroundClicked = backgroundClicked; }

bool Button::isClicked() const { return clicked; }
