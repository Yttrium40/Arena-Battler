# include "Scene.h"

Scene::Scene(std::vector<Button> p_buttons, std::vector<sf::Text> p_texts,
    std::shared_ptr<sf::Texture> p_background)
: buttons { p_buttons }, texts { p_texts }, background { p_background }
{
}

void Scene::draw(sf::RenderWindow &window) const
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
