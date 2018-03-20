# ifndef SCENE_H
# define SCENE_H

# include <SFML/Graphics.hpp>
# include <string>
# include <memory>
# include <vector>
# include "global.h"
# include "Button.h"

class Scene
{
protected:
    std::shared_ptr<sf::Texture> background;
    std::vector<Button> buttons;
    std::vector<sf::Text> texts;

public:
    Scene(std::vector<Button> p_buttons, std::vector<sf::Text> p_texts,
        std::shared_ptr<sf::Texture> p_background);

    virtual void draw(sf::RenderWindow &window) const;
};

# endif
