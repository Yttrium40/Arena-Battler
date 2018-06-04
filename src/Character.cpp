# include "Character.h"

Character::Character(std::string p_name)
: name { p_name } {}

int32_t Character::damageStamina(int damage) {
    stamina -= damage;
    return getStamina();
}
int32_t Character::damageMana(int damage) {
    mana -= damage;
    return getMana();
}
int32_t Character::damageWill(int damage) {
    will -= damage;
    return getWill();
}

void Character::recoverPartial() {
    stamina = getPhysique()*5  + 5;
    mana    = getFocus()*5     + 5;
    // TODO find out how this works
}

void Character::recoverFull() {
    stamina = getPhysique()*5  + 5;
    mana    = getFocus()*5     + 5;
    will    = getEndurance()*5 + 5;
}

const std::string & Character::getName() const        { return name; }
const std::string & Character::getRace() const        { return race; }
const std::string & Character::getWeapon() const      { return weapon; }
const std::string & Character::getElement() const     { return element; }
const std::string & Character::getDescription() const { return description; }
int32_t Character::getStamina() const                 { return stamina; }
int32_t Character::getMana() const                    { return mana; }
int32_t Character::getWill() const                    { return will; }
uint16_t Character::getPhysique() const               { return physique; }
uint16_t Character::getFocus() const                  { return focus; }
uint16_t Character::getEndurance() const              { return endurance; }
uint16_t Character::getSpeed() const                  { return speed; }
