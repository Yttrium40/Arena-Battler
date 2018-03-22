# include "Button.h"

Button::Button(ButtonEnum p_id, sf::RectangleShape p_box,
    std::shared_ptr<sf::Texture> p_backgroundClicked)
: id { p_id }, box { p_box }, background { std::make_shared<sf::Texture>(*p_box.getTexture()) },
    backgroundClicked { p_backgroundClicked }
{
}

Button::Button(ButtonEnum p_id, sf::Vector2f p_position, sf::Vector2f p_size,
    std::shared_ptr<sf::Texture> p_background, std::shared_ptr<sf::Texture> p_backgroundClicked)
: id { p_id }, box { p_size }, background { p_background }, backgroundClicked { p_backgroundClicked }
{
    box.setPosition(p_position);
    box.setTexture(background.get());
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(box, states);
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

bool Button::isClicked() const   { return clicked; }
ButtonEnum Button::getId() const { return id; }
