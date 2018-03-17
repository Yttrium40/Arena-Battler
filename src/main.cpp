# include "Character.h"
# include "Cosmetic.h"
# include <iostream>
# include <string>

int main()
{
    std::string bit { "Joe" };
    Character myCharacter { bit };
    std::cout << myCharacter.getName();

    return 0;
}
