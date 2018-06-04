# include "Scene.h"

Scene::Scene(std::vector<Button*> p_buttons, std::vector<sf::Text*> p_texts,
    std::shared_ptr<sf::Texture> p_background)
: buttons { p_buttons }, texts { p_texts }, background { p_background } {}

void Scene::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::RectangleShape back { sf::Vector2f(target.getSize()) };
    back.setTexture(background.get());
    target.draw(back, states);
    for (const Button *button : buttons) {
        target.draw(*button, states);
    }
    for (const sf::Text *text : texts) {
        target.draw(*text, states);
    }
}

bool Scene::getClickedButton(sf::Event &event, Button *&foundButton) {
    for (Button *button : buttons) {
        if (button->containsClick(event)) {
            foundButton = button;
            return true;
        }
    }
    return false;
}
