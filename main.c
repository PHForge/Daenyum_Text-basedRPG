/*
 * Daenym - A text-based RPG combat game
 * Copyright (c) 2025 PHForge
 *
 * A console-based RPG with a retro ASCII banner, where players fight enemies in varied locations,
 * level up, and experience random events. Features multilingual support and persistent stats.
 *
 * Licensed under the MIT License. See LICENSE file for details.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h> // Pour setlocale
#ifdef _WIN32
#include <windows.h> // Pour SetConsoleOutputCP
#endif
#include "character.h"
#include "combat.h"
#include "utils.h"

int main() {
    // Configurer les paramètres régionaux et l'encodage de la console
    setlocale(LC_ALL, ""); // Utiliser les paramètres régionaux du système
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8); // Configurer la console pour UTF-8
        SetConsoleCP(CP_UTF8);      // Configurer l'entrée pour UTF-8
    #endif

    srand(time(NULL));
    GameSettings settings = {LANG_ENGLISH};
    display_banner();
    Character* player = load_character();
    if (!player) {
        player = create_character("Hero", 100, 20, 10, 10, 10, 10);
    }
    if (!player) {
        printf("Error: Could not create player.\n");
        return 1;
    }

    int choice;
    do {
        printf("\n%s\n", get_message(MSG_MENU_TITLE, settings.language));
        printf("%s\n%s\n%s\n%s\n%s\n",
               get_message(MSG_START_ADVENTURE, settings.language),
               get_message(MSG_VIEW_STATS, settings.language),
               get_message(MSG_SETTINGS, settings.language),
               get_message(MSG_CREDITS, settings.language),
               get_message(MSG_QUIT, settings.language));
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf(get_message(MSG_INVALID_CHOICE, settings.language));
            continue;
        }
        clear_input_buffer();

        switch (choice) {
            case 1:
                start_combat(player, settings.language);
                if (player->hp <= 0) {
                    printf(get_message(MSG_GAME_OVER, settings.language));
                    free_character(player);
                    player = create_character("Hero", 100, 20, 10, 10, 10, 10);
                } else {
                    save_character(player);
                }
                break;
            case 2:
                display_stats(player, settings.language);
                break;
            case 3:
                configure_settings(&settings);
                break;
            case 4:
                display_credits(settings.language);
                break;
            case 5:
                printf(get_message(MSG_QUIT_MESSAGE, settings.language));
                break;
            default:
                printf(get_message(MSG_INVALID_CHOICE, settings.language));
        }
    } while (choice != 5);

    free_character(player);
    return 0;
}
