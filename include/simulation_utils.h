#ifndef SIMULATION_UTILS_H
#define SIMULATION_UTILS_H

#include <stdint.h>
#include <stdbool.h>

typedef struct _CSV_OUTPUT {

    bool player_won;
    uint32_t turns;

    uint32_t player_level;
    uint32_t player_hp;
    uint32_t player_dmg;
    uint32_t player_remaining_hp;

    uint32_t monster_level;
    uint32_t monster_hp;
    uint32_t monster_dmg;

} CSV_OUTPUT;

CSV_OUTPUT battle_simulation();



#endif