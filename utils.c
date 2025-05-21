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
            "=== Combat RPG Textuel ===\n", "1. Partir � l'aventure", "2. Voir stats", "3. Param�tres",
            "4. Cr�dits", "5. Quitter\n", "Choix invalide.", "L'aventure commence ! Dans un %s, un %s appara�t !",
            "1. Attaquer", "2. Fuir", "%s inflige %d de d�g�ts au %s (HP: %d/%d)", "\nVictoire ! %s a vaincu %s !", "\nD�faite ! %s a �t� tu� par %s.",
            "%s esquive l'attaque !", "Coup critique !", "%s s'est enfui de %s !", "�chec de la fuite !",
            "Intervention divine ! %s est ressuscit� avec %d PV !", "Choc c�leste ! L'attaque de %s augmente � %d !",
            "Mal�diction ! L'attaque de %s diminue � %d !", "\nGame Over\n", "Choisir une option : ", "\n\nMerci d'avoir jou� !\n\n",
            "Nom", "Niveau", "XP", "PV", "Attaque", "D�fense", "Esquive", "Critique", "Chance",
            "Vous gagnez %d XP !", "Mont�e de niveau ! %s est maintenant niveau %d !", "Langue", "Retour"
        },
        // Spanish
        {
            "=== Combate RPG de Texto ===\n", "1. Comenzar aventura", "2. Ver estad�sticas", "3. Configuraci�n",
            "4. Cr�ditos", "5. Salir\n", "Opci�n inv�lida.", "�La aventura comienza! �En un %s, aparece un %s!",
            "1. Atacar", "2. Huir", "%s inflige %d de da�o al %s (HP: %d/%d)", "\n�Victoria! �%s derrot� a %s!", "\n�Derrota! �%s fue eliminado por %s!",
            "�%s esquiva el ataque!", "�Golpe cr�tico!", "�%s huy� de %s!", "�No pudo huir!",
            "�Intervenci�n divina! �%s revive con %d HP!", "�Choque celestial! �El ataque de %s aumenta a %d!",
            "�Maldici�n! �El ataque de %s disminuye a %d!", "\nGame Over\n", "Ingrese su elecci�n: ", "\n\n�Gracias por jugar!\n\n",
            "Nombre", "Nivel", "XP", "HP", "Ataque", "Defensa", "Esquiva", "Cr�tico", "Suerte",
            "�Ganaste %d XP!", "�Subida de nivel! �%s ahora es nivel %d!", "Idioma", "Volver"
        },
        // Portuguese (Brazil)
        {
            "=== Combate RPG em Texto ===\n", "1. Iniciar aventura", "2. Ver estat�sticas", "3. Configura��es",
            "4. Cr�ditos", "5. Sair\n", "Escolha inv�lida.", "A aventura come�a! Em um %s, um %s aparece!",
            "1. Atacar", "2. Fugir", "%s causa %d de dano ao %s (HP: %d/%d)", "\nVit�ria! %s derrotou %s!", "\nDerrota! %s foi morto por %s.",
            "%s esquiva o ataque!", "Acerto cr�tico!", "%s fugiu de %s!", "Falha ao fugir!",
            "Interven��o divina! %s � revivido com %d HP!", "Choque celestial! O ataque de %s aumenta para %d!",
            "Maldi��o! O ataque de %s diminui para %d!", "\nGame Over\n", "Ingrese su elecci�n: ", "\n\n�Gracias por jugar!\n\n",
            "Nome", "N�vel", "XP", "HP", "Ataque", "Defesa", "Esquiva", "Cr�tico", "Sorte",
            "Voc� ganhou %d XP!", "Subida de n�vel! %s agora � n�vel %d!", "Idioma", "Voltar"
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
        "Ce jeu est d�di� � ma femme et mon fils ador�s, dont la patience et l�amour m�inspirent chaque jour.",
        "Este juego est� dedicado a mi amada esposa e hijo, cuya paciencia y amor me inspiran cada d�a.",
        "Este jogo � dedicado � minha amada esposa e filho, cuja paci�ncia e amor me inspiram todos os dias."
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
               settings->language == LANG_FRENCH ? "Fran�ais" :
               settings->language == LANG_SPANISH ? "Espa�ol" : "Portugu�s");
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
            printf("1. English\n2. Fran�ais\n3. Espa�ol\n4. Portugu�s\n\n");
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
                   settings->language == LANG_FRENCH ? "Fran�ais" :
                   settings->language == LANG_SPANISH ? "Espa�ol" : "Portugu�s");
        } else if (choice == 2) {
            break; // Return to main menu
        } else {
            printf("%s\n", get_message(MSG_INVALID_CHOICE, settings->language));
        }
    } while (1);
}
