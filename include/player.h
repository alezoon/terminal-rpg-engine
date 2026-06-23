#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct _Player {
    
    uint32_t level;
    uint32_t xp_req;
    uint32_t xp;

    uint32_t max_health;
    uint32_t health;
    uint32_t dmg;

} Player;

Player init_player();
void adjust_stats(Player *p, uint32_t lvl);
bool player_alive(Player *p);
void player_heal(Player *p, uint32_t amt);
void damage_player(Player *p, uint32_t amt);
void player_to_string(Player *p);

#endif