# include "Cosmetic.h"

std::mt19937 Cosmetic::rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

std::map<std::string, std::vector<std::string>> Cosmetic::raceAppearance;
std::map<std::string, std::vector<std::string>> Cosmetic::raceClothing;
std::map<std::string, std::vector<std::string>> Cosmetic::weaponAppearance;
std::map<std::string, std::vector<std::string>> Cosmetic::weaponAttack;
std::map<std::string, std::vector<std::string>> Cosmetic::elementOddity;
std::map<std::string, std::vector<std::string>> Cosmetic::elementAttack;

const std::vector<std::string> Cosmetic::fileNames {
    "race_appearance",
    "race_clothing",
    "weapon_appearance",
    "weapon_attack",
    "element_oddity",
    "element_attack"
};

void Cosmetic::populateMaps() {
    std::ifstream ifs;
    std::map<std::string, std::vector<std::string>> *currentMap = &raceAppearance;
    int count = 0;
    for (const std::string &file : fileNames) {
        if (count == 1) {
            currentMap = &raceClothing;
        }
        else if (count == 2) {
            currentMap = &weaponAppearance;
        }
        else if (count == 3) {
            currentMap = &weaponAttack;
        }
        else if (count == 4) {
            currentMap = &elementOddity;
        }
        else if (count == 5) {
            currentMap = &elementAttack;
        }
        ifs.open("../resources/cosmetics/" + file + ".txt", std::ifstream::in);
        std::string head;
        std::string line;
        while (std::getline(ifs, line)) {
            if (!line.empty() && line[0] == '!') {
                head = line.substr(1);
                (*currentMap).insert(std::pair<std::string, std::vector<std::string>>(head, {}));
            }
            else if (!line.empty()) {
                (*currentMap).at(head).push_back(line);
            }
        }
        ++count;
        ifs.close();
    }
}

Cosmetic::Cosmetic() {
    populateMaps();
}

std::string Cosmetic::getRandomizedDescription(const Character &character) const {
    std::uniform_int_distribution<> dis0(0, raceAppearance.at(character.getRace()).size() - 1);
    const std::string &randomRaceAppearance = raceAppearance.at(character.getRace())[dis0(rng)];

    std::uniform_int_distribution<> dis1(0, raceClothing.at(character.getRace()).size() - 1);
    const std::string &randomRaceClothing = raceClothing.at(character.getRace())[dis1(rng)];

    std::uniform_int_distribution<> dis2(0, weaponAppearance.at(character.getWeapon()).size() - 1);
    const std::string &randomWeaponAppearance = weaponAppearance.at(character.getWeapon())[dis2(rng)];

    std::uniform_int_distribution<> dis3(0, elementOddity.at(character.getElement()).size() - 1);
    const std::string &randomElementOddity = elementOddity.at(character.getElement())[dis3(rng)];

    return character.getName() + " is a " + randomRaceAppearance + " wearing " +
        randomRaceClothing + ". They wield " + randomWeaponAppearance + ".\n\n"
        + "The magical powers " + character.getName() + " wields have " +
        "transformed their body. " + randomElementOddity + "!";
}
