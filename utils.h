#ifndef UTILS_H
#define UTILS_H

#define LANG_ENGLISH 0
#define LANG_FRENCH 1
#define LANG_SPANISH 2
#define LANG_PORTUGUESE 3

typedef struct {
    int language; // 0: English, 1: French, 2: Spanish, 3: Portuguese
} GameSettings;

enum {
    MSG_MENU_TITLE, MSG_START_ADVENTURE, MSG_VIEW_STATS, MSG_SETTINGS, MSG_CREDITS, MSG_QUIT,
    MSG_INVALID_CHOICE, MSG_COMBAT_START, MSG_ATTACK, MSG_FLEE, MSG_BATTLE, MSG_VICTORY, MSG_DEFEAT,
    MSG_DODGE, MSG_CRIT, MSG_FLEE_SUCCESS, MSG_FLEE_FAIL, MSG_DIVINE, MSG_SHOCK, MSG_CURSE, MSG_GAME_OVER,
    MSG_ENTER_CHOICE, MSG_QUIT_MESSAGE,
    MSG_STAT_NAME, MSG_STAT_LEVEL, MSG_STAT_XP, MSG_STAT_HP, MSG_STAT_ATTACK, MSG_STAT_DEFENSE,
    MSG_STAT_DODGE, MSG_STAT_CRIT, MSG_STAT_LUCK, MSG_XP_GAINED, MSG_LEVEL_UP, MSG_LANGUAGE, MSG_BACK
};

int get_random_int(int min, int max);
void clear_input_buffer(void);
const char* get_message(int message_id, int language);
void display_banner();
void display_credits(int language);
void configure_settings(GameSettings* settings);

#endif
