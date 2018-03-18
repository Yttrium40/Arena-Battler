# ifndef LEVELUP_H
# define LEVELUP_H

class LevelUp
{
private:
    Character &character;
    int points = 0;

public:
    LevelUp(Character &p_character, int p_points);
};

# endif
