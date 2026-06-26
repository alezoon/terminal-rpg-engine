#include <stdlib.h>
#include <stdbool.h>
#include "player.h"
#include "monster.h"
#include "locations.h"
#include "battle.h"

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

    Zone zone;

} CSV_OUTPUT;



CSV_OUTPUT battle_simulation() {

    CSV_OUTPUT output = {0};

    // Generate Level 1 Player
    Player player = init_player();

    // Randomize zone
    Zone zone;
    uint32_t z_val = rand() % 3;
    switch (z_val) {
        case 0:
            zone = FOREST;
            break;
        case 1:
            zone = DEEP_FOREST;
            break;
        case 2:
            zone = PLAINS;
            break;
        default:
            return output;
    }

    // Generate random monster
    Monster monster = encounter(zone);

    // Adjust player values within +- 2 levels of monster
    uint32_t min_level = monster.level > 2 ? monster.level - 2 : 1;
    uint32_t max_level = monster.level + 2;

    player.level = min_level + rand() % (max_level - min_level + 1);

    adjust_stats(&player, player.level);

    // Basic Battle loop
    uint32_t turns = 0;
    bool won = false;
    while (1) {
        
        turns += 1;

        // Player turn
        damage_monster(&monster, player.dmg);

        // Check if monster alive
        if (!monster_alive(&monster)) {
            won = true;
            break;
        }

        // Monster turn
        damage_player(&player, monster.dmg);

        // Check if player alive
        if (!player_alive(&player)) {
            break;
        }
    }


    // Finalize Values in OUTPUT struct
    output.player_won = won;
    output.turns = turns;
    output.player_level = player.level;
    output.player_hp = player.max_health;
    output.player_dmg = player.dmg;
    output.player_remaining_hp = player.health;
    output.monster_level = monster.level;
    output.monster_hp = monster.max_health;
    output.monster_dmg = monster.dmg;
    output.zone = zone;

    return output;
}

