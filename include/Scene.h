# ifndef SCENE_H
# define SCENE_H

# include <SFML/Graphics.hpp>
# include <string>
# include <memory>
# include <vector>
# include "global.h"
# include "Button.h"

class Scene : public sf::Drawable
{
protected:
    std::shared_ptr<sf::Texture> background;
    std::vector<Button> buttons;
    std::vector<sf::Text> texts;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    Scene(std::vector<Button> p_buttons, std::vector<sf::Text> p_texts,
        std::shared_ptr<sf::Texture> p_background);

    bool getClickedButton(sf::Event &event, Button *&foundButton);
};

# endif
