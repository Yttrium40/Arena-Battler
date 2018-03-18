# include "Character.h"
# include "Cosmetic.h"
# include "LevelUp.h"
# include "CharacterCreation.h"
# include <iostream>
# include <string>

int main()
{
    Character myCharacter { "Sican" };
    CharacterCreation myCreation { myCharacter, 5 };
    myCreation.setRace("cat-folk");
    myCreation.setWeapon("longsword");
    myCreation.setElement("fire");

    Cosmetic myCosmetic;
    myCreation.setDescription(myCosmetic.getRandomizedDescription(myCharacter));
    std::cout << myCharacter.getDescription() << std::endl;

    int whoop;
    std::cin >> whoop;
    return 0;
}
