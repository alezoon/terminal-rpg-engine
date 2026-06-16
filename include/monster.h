#ifndef MONSTER_H
#define MONSTER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct _Monster {

    // Settings
    char *name;
    uint32_t max_level;
    uint32_t min_level;

    // Stats
    uint32_t level;
    uint32_t health;
    uint32_t dmg;
    
} Monster;

Monster create_monster(Monster template);
bool monster_alive(Monster *m);
void damage_monster(Monster *m, uint32_t amt);
void monster_to_string(Monster *m);

#endif