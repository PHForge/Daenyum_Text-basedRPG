#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

// Returns a random integer between min and max (inclusive)
int get_random_int(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Clears the input buffer
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Displays the retro ASCII banner
void display_banner() {
    printf("\n");
    printf("      ***** **\n");
    printf("   ******  ***\n");
    printf(" **    *  * ***\n");
    printf("*     *  *   ***\n");
    printf("     *  *     ***                                   **   ****      **   ****\n");
    printf("    ** **      **    ****       ***    ***  ****     **    ***  *   **    ***  * *** **** ****\n");
    printf("    ** **      **   * ***  *   * ***    **** **** *  **     ****    **     ****   *** **** ***  *\n");
    printf("    ** **      **  *   ****   *   ***    **   ****   **      **     **      **     **  **** ****\n");
    printf("    ** **      ** **    **   **    ***   **    **    **      **     **      **     **   **   **\n");
    printf("    ** **      ** **    **   ********    **    **    **      **     **      **     **   **   **\n");
    printf("    *  **      ** **    **   *******     **    **    **      **     **      **     **   **   **\n");
    printf("       *       *  **    **   **          **    **    **      **     **      **     **   **   **\n");
    printf("  *****       *   **    **   ****    *   **    **     *********      ******* **    **   **   **\n");
    printf(" *   *********     ***** **   *******    ***   ***      **** ***      *****   **   ***  ***  ***\n");
    printf("*       ****        ***   **   *****      ***   ***           ***                   ***  ***  ***\n");
    printf("*                                                      *****   ***\n");
    printf(" **                                                  ********  **\n");
    printf("                                                    *      ****\n");
    printf("\n");
    printf("                     Daenyum, Text-based RPG Combat by PHForge\n");
    printf("\n");
}

const char* get_message(int message_id, int language) {
    static const char* messages[4][36] = {
        // English
        {
            "=== Text-based RPG Combat ===\n", "1. Start adventure", "2. View stats", "3. Settings",
            "4. Credits", "5. Quit\n", "Invalid choice.", "The aventure start! In a %s, a %s appears!",
            "1. Attack", "2. Flee", "%s deals %d damage to %s (HP: %d/%d)", "\nVictory! %s defeated %s!", "\nDefeat! %s was slain by %s.",
            "%s dodges the attack!", "Critical hit!", "%s fled from %s!", "Failed to flee!",
            "Divine Intervention! %s is revived with %d HP!", "Celestial Shock! %s's attack increases to %d!",
            "Curse! %s's attack decreases to %d!", "\nGame Over\n", "Enter choice: ", "\n\nThank you for playing!\n\n",
            "Name", "Level", "XP", "HP", "Attack", "Defense", "Dodge", "Crit", "Luck",
            "You gain %d XP!", "Level up! %s is now level %d!", "Language", "Back"
        },
        // French
        {
            "=== Combat RPG Textuel ===\n", "1. Partir à l'aventure", "2. Voir stats", "3. Paramètres",
            "4. Crédits", "5. Quitter\n", "Choix invalide.", "L'aventure commence ! Dans un %s, un %s apparaît !",
            "1. Attaquer", "2. Fuir", "%s inflige %d de dégâts au %s (HP: %d/%d)", "\nVictoire ! %s a vaincu %s !", "\nDéfaite ! %s a été tué par %s.",
            "%s esquive l'attaque !", "Coup critique !", "%s s'est enfui de %s !", "Échec de la fuite !",
            "Intervention divine ! %s est ressuscité avec %d PV !", "Choc céleste ! L'attaque de %s augmente à %d !",
            "Malédiction ! L'attaque de %s diminue à %d !", "\nGame Over\n", "Choisir une option : ", "\n\nMerci d'avoir joué !\n\n",
            "Nom", "Niveau", "XP", "PV", "Attaque", "Défense", "Esquive", "Critique", "Chance",
            "Vous gagnez %d XP !", "Montée de niveau ! %s est maintenant niveau %d !", "Langue", "Retour"
        },
        // Spanish
        {
            "=== Combate RPG de Texto ===\n", "1. Comenzar aventura", "2. Ver estadísticas", "3. Configuración",
            "4. Créditos", "5. Salir\n", "Opción inválida.", "¡La aventura comienza! ¡En un %s, aparece un %s!",
            "1. Atacar", "2. Huir", "%s inflige %d de daño al %s (HP: %d/%d)", "\n¡Victoria! ¡%s derrotó a %s!", "\n¡Derrota! ¡%s fue eliminado por %s!",
            "¡%s esquiva el ataque!", "¡Golpe crítico!", "¡%s huyó de %s!", "¡No pudo huir!",
            "¡Intervención divina! ¡%s revive con %d HP!", "¡Choque celestial! ¡El ataque de %s aumenta a %d!",
            "¡Maldición! ¡El ataque de %s disminuye a %d!", "\nGame Over\n", "Ingrese su elección: ", "\n\n¡Gracias por jugar!\n\n",
            "Nombre", "Nivel", "XP", "HP", "Ataque", "Defensa", "Esquiva", "Crítico", "Suerte",
            "¡Ganaste %d XP!", "¡Subida de nivel! ¡%s ahora es nivel %d!", "Idioma", "Volver"
        },
        // Portuguese (Brazil)
        {
            "=== Combate RPG em Texto ===\n", "1. Iniciar aventura", "2. Ver estatísticas", "3. Configurações",
            "4. Créditos", "5. Sair\n", "Escolha inválida.", "A aventura começa! Em um %s, um %s aparece!",
            "1. Atacar", "2. Fugir", "%s causa %d de dano ao %s (HP: %d/%d)", "\nVitória! %s derrotou %s!", "\nDerrota! %s foi morto por %s.",
            "%s esquiva o ataque!", "Acerto crítico!", "%s fugiu de %s!", "Falha ao fugir!",
            "Intervenção divina! %s é revivido com %d HP!", "Choque celestial! O ataque de %s aumenta para %d!",
            "Maldição! O ataque de %s diminui para %d!", "\nGame Over\n", "Ingrese su elección: ", "\n\n¡Gracias por jugar!\n\n",
            "Nome", "Nível", "XP", "HP", "Ataque", "Defesa", "Esquiva", "Crítico", "Sorte",
            "Você ganhou %d XP!", "Subida de nível! %s agora é nível %d!", "Idioma", "Voltar"
        }
    };
    if (message_id < 0 || message_id >= 36 || language < 0 || language > 3) {
        return "Invalid message";
    }
    return messages[language][message_id];
}

// Displays game credits
void display_credits(int language) {
    static const char* credits[4] = {
        "This game is dedicated to my beloved wife and son, whose patience and love inspire me every day.",
        "Ce jeu est dédié à ma femme et mon fils adorés, dont la patience et l’amour m’inspirent chaque jour.",
        "Este juego está dedicado a mi amada esposa e hijo, cuya paciencia y amor me inspiran cada día.",
        "Este jogo é dedicado à minha amada esposa e filho, cuja paciência e amor me inspiram todos os dias."
    };
    printf("\n=== %s ===\n", get_message(MSG_CREDITS, language));
    printf("\n");
    printf("%s\n", credits[language]);
}

// Configures game settings
void configure_settings(GameSettings* settings) {
    int choice;
    do {
        printf("\n=== %s ===\n", get_message(MSG_SETTINGS, settings->language));
        printf("\n");
        printf("1. %s (~~ %s ~~)\n",
               get_message(MSG_LANGUAGE, settings->language),
               settings->language == LANG_ENGLISH ? "English" :
               settings->language == LANG_FRENCH ? "Français" :
               settings->language == LANG_SPANISH ? "Español" : "Português");
        printf("2. %s\n\n", get_message(MSG_BACK, settings->language));
        printf("%s: ", get_message(MSG_ENTER_CHOICE, settings->language));

        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("%s\n", get_message(MSG_INVALID_CHOICE, settings->language));
            continue;
        }
        clear_input_buffer();

        if (choice == 1) {
            printf("\n=== %s ===\n", get_message(MSG_LANGUAGE, settings->language));
            printf("\n");
            printf("1. English\n2. Français\n3. Español\n4. Português\n\n");
            printf("%s: ", get_message(MSG_ENTER_CHOICE, settings->language));
            if (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
                clear_input_buffer();
                printf("%s\n", get_message(MSG_INVALID_CHOICE, settings->language));
                continue;
            }
            clear_input_buffer();
            settings->language = choice - 1;
            printf("%s: %s\n", get_message(MSG_LANGUAGE, settings->language),
                   settings->language == LANG_ENGLISH ? "English" :
                   settings->language == LANG_FRENCH ? "Français" :
                   settings->language == LANG_SPANISH ? "Español" : "Português");
        } else if (choice == 2) {
            break; // Return to main menu
        } else {
            printf("%s\n", get_message(MSG_INVALID_CHOICE, settings->language));
        }
    } while (1);
}
