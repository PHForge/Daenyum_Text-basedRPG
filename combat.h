#ifndef COMBAT_H
#define COMBAT_H
#include "character.h"

void start_combat(Character* player, int language);
int calculate_damage(Character* attacker, Character* defender, int language);
int attempt_flee(Character* player);
const char* get_random_location(int language);
void trigger_random_event(Character* player, Character* enemy, int language);

#endif
