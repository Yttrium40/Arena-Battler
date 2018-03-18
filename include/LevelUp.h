# ifndef LEVELUP_H
# define LEVELUP_H

# include <string>
# include <cstdint>
# include <cassert>
# include "Character.h"

class LevelUp
{
protected:
    Character &character;
    int points = 0;

public:
    LevelUp(Character &p_character, int p_points);

    // change mutable stat
    void increasePhysique();
    void increaseFocus();
    void increaseEndurance();
    void increaseSpeed();
    void decreasePhysique();
    void decreaseFocus();
    void decreaseEndurance();
    void decreaseSpeed();

    const Character & getCharacter() const;
    int getPoints() const;
};

# endif
