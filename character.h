#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct {
    char name[50];
    int hp, max_hp;
    int attack, defense;
    int dodge, crit, luck;
    int level, xp;
} Character;

Character* create_character(const char* name, int hp, int attack, int defense, int dodge, int crit, int luck);
void free_character(Character* character);
void save_character(const Character* character);
Character* load_character(void);
void display_stats(const Character* character, int language); // Ajouté language
Character* create_enemy(int player_level);
void gain_xp(Character* character, int xp, int language);
void reset_life(Character* character);

#endif
