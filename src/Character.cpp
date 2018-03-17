# include "Character.h"

Character::Character(std::string &name)
: this->name { name }
{
}

int32_t Character::damageStamina(int damage)
{
    stamina -= damage;
    return stamina;
}
int32_t Character::damageMana(int damage)
{
    mana -= damage;
    return mana;
}
int32_t Character::damageWill(int damage)
{
    will -= damage;
    return will;
}

void Character::recoverPartial()
{
    stamina = physique*5  + 5;
    mana    = focus*5     + 5;
    // TODO find out how this works
}

void Character::recoverFull()
{
    stamina = physique*5  + 5;
    mana    = focus*5     + 5;
    will    = endurance*5 + 5;
}

uint16_t Character::increasePhysique()
{
    return ++physique;
}
uint16_t Character::increaseFocus()
{
    return ++focus;
}
uint16_t Character::increaseEndurance()
{
    return ++endurance;
}
uint8_t Character::increaseSpeed()
{
    assert(speed < 3);
    return ++speed;
}

const std::string & Character::getName() const { return name; }
int32_t Character::getStamina() const          { return stamina; }
int32_t Character::getMana() const             { return mana; }
int32_t Character::getWill() const             { return will; }
uint16_t Character::getPhysique() const        { return physique; }
uint16_t Character::getFocus() const           { return focus; }
uint16_t Character::getEndurance() const       { return endurance; }
uint8_t Character::getSpeed() const            { return speed; }
