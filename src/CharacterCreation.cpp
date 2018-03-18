# include "CharacterCreation.h"

CharacterCreation::CharacterCreation(Character &p_character, int p_points)
: LevelUp(p_character, p_points)
{
}

void CharacterCreation::setName(const std::string &name)
{
    character.name = name;
}
void CharacterCreation::setRace(const std::string &race)
{
    character.race = race;
}
void CharacterCreation::setWeapon(const std::string &weapon)
{
    character.weapon = weapon;
}
void CharacterCreation::setElement(const std::string &element)
{
    character.element = element;
}
void CharacterCreation::setDescription(const std::string &description)
{
    character.description = description;
}
