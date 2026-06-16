#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>

typedef struct _Player {
    
    uint8_t level;
    uint32_t xp;

    uint32_t max_health;
    uint32_t health;
    uint32_t dmg;

} Player;

Player init_player();
void player_heal(Player *p, uint32_t amt);
void damage_player(Player *p, uint32_t amt);
void player_to_string(Player *p);

#endif