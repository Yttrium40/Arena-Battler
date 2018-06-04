# ifndef CHARACTERCREATION_H
# define CHARACTERCREATION_H

# include <string>
# include "LevelUp.h"

class CharacterCreation : public LevelUp {
public:
    CharacterCreation(Character &p_character, int p_points);

    void setName(const std::string &name);
    void setRace(const std::string &race);
    void setWeapon(const std::string &weapon);
    void setElement(const std::string &element);
    void setDescription(const std::string &description);
};

# endif
