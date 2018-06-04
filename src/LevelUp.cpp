# include "LevelUp.h"

LevelUp::LevelUp(Character &p_character, int p_points)
: character { p_character }, points { p_points } {}

void LevelUp::increasePhysique() {
    assert(points > 0);
    --points;
    ++character.physique;
}
void LevelUp::increaseFocus() {
    assert(points > 0);
    --points;
    ++character.focus;
}
void LevelUp::increaseEndurance() {
    assert(points > 0);
    --points;
    ++character.endurance;
}
void LevelUp::increaseSpeed() {
    assert(points > 1 && character.speed < 3);
    points -= 2;
    ++character.speed;
}
void LevelUp::decreasePhysique() {
    assert(character.physique > 0);
    ++points;
    --character.physique;
}
void LevelUp::decreaseFocus() {
    assert(character.focus > 0);
    ++points;
    --character.focus;
}
void LevelUp::decreaseEndurance() {
    assert(character.endurance > 0);
    ++points;
    --character.endurance;
}
void LevelUp::decreaseSpeed() {
    assert(character.speed > 1);
    points += 2;
    --character.speed;
}

const Character & LevelUp::getCharacter() const { return character; }
int LevelUp::getPoints() const                  { return points; }
