# ifndef COSMETIC_H
# define COSMETIC_H

# include <fstream>
# include <map>
# include <string>
# include <random>
# include <chrono>
# include <vector>
# include <utility>
# include "Character.h"

class Cosmetic
{
private:
    static std::mt19937 rng;

    // enum class Race
    // {
    //     human,
    //     orc,
    //     cat-folk,
    //     lizard-folk,
    // };
    // enum class Weapon
    // {
    //     unarmed,
    //     dagger,
    //     shortsword,
    //     longsword,
    //     rapier,
    //     mace,
    //     bow,
    //     crossbow,
    //     spear,
    //     scimitar,
    //     staff,
    // };
    // enum class Element
    // {
    //     fire,
    //     air,
    //     water,
    //     earth,
    //     metal,
    //     sound,
    //     light,
    //     dark,
    //     chaos,
    //     mind,
    //     blood,
    //     nature,
    //     time,
    // };
    //
    // // string representation of enums. The index of each string should
    // // correspond to the int value of each enum
    // static const std::vector<std::string> raceString =
    // {
    //     "human",
    //     "orc",
    //     "cat-folk",
    //     "lizard-folk"
    // }
    // static const std::vector<std::string> weaponString =
    // {
    //     "unarmed",
    //     "dagger",
    //     "shortsword",
    //     "longsword",
    //     "rapier",
    //     "mace",
    //     "bow",
    //     "crossbow",
    //     "spear",
    //     "scimitar",
    //     "staff"
    // }
    // static const std::vector<std::string> elementString =
    // {
    //     "fire",
    //     "air",
    //     "water",
    //     "earth",
    //     "metal",
    //     "sound",
    //     "light",
    //     "dark",
    //     "chaos",
    //     "mind",
    //     "blood",
    //     "nature",
    //     "time"
    // }

    // these maps contain std::string descriptions that are randomly chosen for
    // each string key
    static std::map<std::string, std::vector<std::string>> raceAppearance;
    static std::map<std::string, std::vector<std::string>> raceClothing;
    static std::map<std::string, std::vector<std::string>> weaponAppearance;
    static std::map<std::string, std::vector<std::string>> weaponAttack;
    static std::map<std::string, std::vector<std::string>> elementOddity;
    static std::map<std::string, std::vector<std::string>> elementAttack;

    void populateMaps();

    static const std::vector<std::string> fileNames;

public:
    Cosmetic();

    std::string getRandomizedDescription(const Character &character) const;
};

#endif
