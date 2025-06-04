#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "character.h"
#include "utils.h"

// Creates a new character with given stats
Character* create_character(const char* name, int hp, int attack, int defense, int dodge, int crit, int luck) {
    Character* c = malloc(sizeof(Character));
    if (c) {
        strncpy(c->name, name, 49);
        c->name[49] = '\0';
        c->hp = c->max_hp = hp;
        c->attack = attack;
        c->defense = defense;
        c->dodge = dodge;
        c->crit = crit;
        c->luck = luck;
        c->level = 1;
        c->xp = 0;
    }
    return c;
}

// Frees a character
void free_character(Character* character) {
    free(character);
}

// Save the character
void save_character(const Character* character) {
    FILE* file = fopen("player.txt", "w");
    if (!file) {
        printf("Error: Could not save character.\n");
        return;
    }
    fprintf(file, "%s %d %d %d %d %d %d %d %d\n",
            character->name, character->max_hp, character->attack, character->defense,
            character->dodge, character->crit, character->luck, character->level, character->xp);
    fclose(file);
}

// Load the character
Character* load_character(void) {
    FILE* file = fopen("player.txt", "r");
    if (!file) return NULL;
    char name[50];
    int max_hp, attack, defense, dodge, crit, luck, level, xp;
    if (fscanf(file, "%49s %d %d %d %d %d %d %d %d", name, &max_hp, &attack, &defense,
               &dodge, &crit, &luck, &level, &xp) != 9) {
        fclose(file);
        return NULL;
    }
    fclose(file);
    Character* c = create_character(name, max_hp, attack, defense, dodge, crit, luck);
    if (c) {
        c->level = level;
        c->xp = xp;
        c->hp = c->max_hp;
    }
    return c;
}

// Displays character stats
void display_stats(const Character* character, int language) {
    printf("\n");
    printf("%s: %s\n", get_message(MSG_STAT_NAME, language), character->name);
    printf("%s: %d, %s: %d\n", get_message(MSG_STAT_LEVEL, language), character->level, get_message(MSG_STAT_XP, language), character->xp);
    printf("%s: %d/%d\n", get_message(MSG_STAT_HP, language), character->hp, character->max_hp);
    printf("%s: %d, %s: %d\n", get_message(MSG_STAT_ATTACK, language), character->attack, get_message(MSG_STAT_DEFENSE, language), character->defense);
    printf("%s: %d%%, %s: %d%%, %s: %d%%\n", get_message(MSG_STAT_DODGE, language), character->dodge,
           get_message(MSG_STAT_CRIT, language), character->crit, get_message(MSG_STAT_LUCK, language), character->luck);
}

// Creates a random enemy based on player level
Character* create_enemy(int player_level) {
    static const struct { const char* name; int hp, attack, defense, dodge, crit, luck; } enemy_types[] = {
        {"Goblin", 50, 15, 5, 5, 5, 5},
        {"Troll", 80, 20, 10, 0, 10, 0},
        {"Skeleton", 60, 18, 8, 10, 8, 5}
    };
    int index = get_random_int(0, 2);
    int scale = player_level * 5;
    return create_character(enemy_types[index].name,
                           enemy_types[index].hp + scale,
                           enemy_types[index].attack + scale / 2,
                           enemy_types[index].defense + scale / 2,
                           enemy_types[index].dodge,
                           enemy_types[index].crit,
                           enemy_types[index].luck);
}

// Adds XP and handles level-up
void gain_xp(Character* character, int xp, int language) {
    character->xp += xp;
    while (character->xp >= character->level * 100) {
        int xp_required = character->level * 100;
        character->xp -= xp_required;
        character->level++;
        character->max_hp += 10;
        character->hp = character->max_hp;
        character->attack += 2;
        character->defense += 1;
        character->dodge += 1;
        character->crit += 1;
        character->luck += 1;
        printf(get_message(MSG_LEVEL_UP, language), character->name, character->level);
        printf("\n");
    }
}

//reset life after battle
void reset_life(Character* character){
    character->hp = character->max_hp;
}
