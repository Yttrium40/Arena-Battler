# ifndef CHARACTER_H
# define CHARACTER_H

# include <string>
# include <cstdint>
# include <cassert>

class LevelUp;
class CharacterCreation;

class Character {
    friend class LevelUp;
    friend class CharacterCreation;

protected:
    std::string name        = "";
    std::string race        = "";
    std::string weapon      = "";
    std::string element     = "";
    std::string description = "";

    int32_t stamina = 5;
    int32_t mana    = 5;
    int32_t will    = 5;

    uint16_t physique  = 0;
    uint16_t focus     = 0;
    uint16_t endurance = 0;
    uint16_t speed     = 1;

public:
    Character(std::string p_name);

    // lower stat by damage and return new value of stat
    int32_t damageStamina(int damage);
    int32_t damageMana(int damage);
    int32_t damageWill(int damage);

    // recover each derived stat according to current value of mutable stat,
    // modified by current value of will
    void recoverPartial();

    // recover all derived stats to full, including will
    void recoverFull();

    const std::string & getName() const;
    const std::string & getRace() const;
    const std::string & getWeapon() const;
    const std::string & getElement() const;
    const std::string & getDescription() const;
    int32_t getStamina() const;
    int32_t getMana() const;
    int32_t getWill() const;
    uint16_t getPhysique() const;
    uint16_t getFocus() const;
    uint16_t getEndurance() const;
    uint16_t getSpeed() const;
};

# endif
