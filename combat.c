#include <stdio.h>
#include "combat.h"
#include "utils.h"

// Starts a combat
void start_combat(Character* player, int language) {
    const char* location = get_random_location(language);
    Character* enemy = create_enemy(player->level);
    printf("\n");
    printf(get_message(MSG_COMBAT_START, language), location, enemy->name);
    printf("\n");

    while (player->hp > 0 && enemy->hp > 0) {
        printf("\n%s\n%s\n", get_message(MSG_ATTACK, language), get_message(MSG_FLEE, language));
        printf("\n%s: ", get_message(MSG_ENTER_CHOICE, language));
        int choice;
        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf(get_message(MSG_INVALID_CHOICE, language));
            printf("\n");
            continue;
        }
        clear_input_buffer();

        if (choice == 2) {
            if (attempt_flee(player)) {
                printf("\n");
                printf(get_message(MSG_FLEE_SUCCESS, language), player->name, enemy->name);
                printf("\n");
                free_character(enemy);
                return;
            } else {
                printf("\n");
                printf(get_message(MSG_FLEE_FAIL, language));
                printf("\n");
            }
        } else if (choice != 1) {
            printf(get_message(MSG_INVALID_CHOICE, language));
            printf("\n");
            continue;
        }

        int damage = calculate_damage(player, enemy, language);
        enemy->hp -= damage;
        printf("\n");
        printf(get_message(MSG_BATTLE, language), player->name, damage, enemy->name, enemy->hp, enemy->max_hp);
        printf("\n");
        if (enemy->hp <= 0) break;

        damage = calculate_damage(enemy, player, language);
        player->hp -= damage;
        printf("%s deals %d damage to %s (HP: %d/%d)\n", enemy->name, damage, player->name, player->hp, player->max_hp);
        printf("\n");

        //trigger a random event
        trigger_random_event(player, enemy, language);
    }

    if (player->hp > 0) {
        int xp_gained = 50 + player->level * 10;
        gain_xp(player, xp_gained, language);
        printf(get_message(MSG_XP_GAINED, language), xp_gained);
        printf("\n");
        printf(get_message(MSG_VICTORY, language), player->name, enemy->name);
        printf("\n");
        reset_life(player);
    } else {
        printf(get_message(MSG_DEFEAT, language), player->name, enemy->name);
        printf("\n");
    }
    free_character(enemy);
}

// Calculates damage dealt
int calculate_damage(Character* attacker, Character* defender, int language) {
    if (get_random_int(0, 100) < defender->dodge) {
        printf("\n");
        printf("||||||||||||||||||||\n");
        printf(get_message(MSG_DODGE, language), defender->name);
        printf("\n||||||||||||||||||||\n");
        return 0;
    }
    int damage = attacker->attack - defender->defense;
    if (get_random_int(0, 100) < attacker->crit) {
        damage *= 2;
        printf("\n");
        printf("!!!!!!!!!!!!!!!\n");
        printf(get_message(MSG_CRIT, language));
        printf("\n!!!!!!!!!!!!!!!\n");
    }
    damage += get_random_int(-5, 5);
    if (damage < 1) damage = 1;
    return damage;
}

// Attempts to flee
int attempt_flee(Character* player) {
    int flee_chance = player->luck + 20;
    return get_random_int(0, 100) < flee_chance;
}

// Returns a random combat location
const char* get_random_location(int language) {
    static const char* locations[4][4] = {
        {"Cave", "Dungeon", "Labyrinth", "Forest"},
        {"Grotte", "Donjon", "Labyrinthe", "Foret"},
        {"Cueva", "Mazmorra", "Laberinto", "Bosque"},
        {"Caverna", "Masmorra", "Labirinto", "Floresta"}
    };
    return locations[language][get_random_int(0, 3)];
}

// Triggers a random event
void trigger_random_event(Character* player, Character* enemy, int language) {
    if (get_random_int(0, 100) > 5) return;
    int event = get_random_int(0, 2);
    switch (event) {
        case 0:
            if (player->hp <= 0) {
                player->hp = player->max_hp / 2;
                printf("\n");
                printf("@@@@@@@@@@@@@@@@@@@@@@@@\n");
                printf(get_message(MSG_DIVINE, language), player->name, player->hp);
                printf("\n@@@@@@@@@@@@@@@@@@@@@@@@\n");
            }
            break;
        case 1:
            player->attack += 5;
            printf("\n");
            printf("################\n");
            printf(get_message(MSG_SHOCK, language), player->name, player->attack);
            printf("\n################\n");
            break;
        case 2:
            enemy->attack -= 3;
            if (enemy->attack < 0) enemy->attack = 0;
            printf("\n");
            printf("いいいいいいいn");
            printf(get_message(MSG_CURSE, language), enemy->name, enemy->attack);
            printf("\nいいいいいいいn");
            break;
    }
}
