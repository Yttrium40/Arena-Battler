# include "Cosmetic.h"

std::mt19937 Cosmetic::rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

const std::vector<std::string> Cosmetic::fileNames
{
    "race_appearance",
    "race_clothing",
    "weapon_appearance",
    "weapon_attack",
    "element_oddity",
    "element_attack"
};

void Cosmetic::populateMaps()
{
    std::ifstream ifs;
    std::map<std::string &, std::vector<std::string>> &currentMap { raceAppearance };
    for (const std::string &file : fileNames)
    {
        if (file.compare("race_appearance") == 0)
        {
            currentMap = raceAppearance;
        }
        else if (file.compare("race_clothing") == 0)
        {
            currentMap = raceClothing;
        }
        else if (file.compare("weapon_appearance") == 0)
        {
            currentMap = weaponAppearance;
        }
        else if (file.compare("weapon_attack") == 0)
        {
            currentMap = weaponAttack;
        }
        else if (file.compare("element_oddity") == 0)
        {
            currentMap = elementOddity;
        }
        else if (file.compare("element_attack") == 0)
        {
            currentMap = elementAttack;
        }
        ifs.open(".resources/" + file + ".txt", std::ifstream::in);
        std::string head;
        std::string line;
        while (!ifs.eof())
        {
            std::getline(ifs, line);
            if (line[0] == '!')
            {
                head = line.substr(1);
                currentMap[head] = {};
            }
            else if (!line.empty())
            {
                currentMap[head].push_back(line);
            }
        }
        ifs.close();
    }
}

Cosmetic::Cosmetic()
{
    populateMaps();
}

const std::string & Cosmetic::getRandomizedDescription(Character &character) const
{
    std::uniform_int_distribution<> dis(0, raceAppearance[character.getRace()].size());
    std::string &randomRaceAppearance = raceAppearance[character.getRace()][dis(rng)]
    std::uniform_int_distribution<> dis(0, raceClothing[character.getRace()].size());
    std::string &randomRaceClothing = raceClothing[character.getRace()][dis(rng)]
    std::uniform_int_distribution<> dis(0, weaponAppearance[character.getWeapon()].size());
    std::string &randomWeaponAppearance = weaponAppearance[character.getWeapon()][dis(rng)]
    std::uniform_int_distribution<> dis(0, elementOddity[character.getElement()].size());
    std::string &randomElementOddity = elementOddity[character.getElement()][dis(rng)]

    return character.getName() + " is a " + randomRaceAppearance + " wearing " +
        randomRaceClothing + ". They wield " + randomWeaponAppearance + ".\n\n"
        + "The magical powers " + character.getName() + " wields have " +
        "transformed their body. " + randomElementOddity "!"
}
