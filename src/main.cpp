# include "Character.h"
# include "Cosmetic.h"
# include <iostream>
# include <string>

int main()
{
    Character myCharacter { "bit" };
    std::cout << myCharacter.getName() << myCharacter.getSpeed();
    myCharacter.increaseSpeed();
    std::cout << myCharacter.getSpeed() << '\n'; //should print bit12

    int whoop;
    std::cin >> whoop;
    return 0;
}
