# ifndef BATTLE_H
# define BATTLE_H

class Battle {
private:
    Character &competitor1;
    Character &competitor2;

public:
    Battle(Character &competitor1, Character &competitor2);
};

# endif
