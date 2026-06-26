#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "monster.h"
#include "monster_db.h"
#include "locations.h"
#include "experience.h"

/**
 * Battle loop logic
 * 
 * @param p Pointer to a player struct
 * @param m Pointer to a monster struct
 */
void battle(Player *p, Monster *m) {

    uint32_t action;

    while (1) {

        printf("Your turn.\n");
        printf("1. %-10s    2. %-10s\n", "Attack", "Run");
        printf("Enter choice: ");
        if (scanf("%u", &action) != 1) {
            return;
        }

        // Action logic
        switch (action) {
            case 1: // Attack
                damage_monster(m, p->dmg);
                printf("You have dealt %u damage.\n", p->dmg);
                break;

            case 2: // Run
                printf("You have fled.\n");
                return;
            
            default:
                printf("Error: Action failure.\n") ;   
                return;
        }

        
        // Check if the monster is alive
        if (monster_alive(m)) {
            monster_to_string(m);
        }
        else {
            printf("You have killed %s.\n", m->name);
            
            //TODO:  Add experience to player
            add_experience(p,m);
            break;
        }

        // Monster turn, just damage player for now
        damage_player(p, m->dmg);


        // Check if the player is alive
        if (player_alive(p)) {
            printf("Player | HP: %u\n\n",p->health);
        }
        else {
            printf("You have died.\n");
            break;
        }
    }
}


/**
 * Randomly decide a monster within zone
 * 
 * @param zone A Zone ENUM
 * 
 * returns: Fully initialized monster from respective zone
 */
Monster encounter(Zone zone) {
    switch (zone) {
        
        case FOREST:
            return create_monster(forest[rand() % forest_size]);

        case PLAINS:
            return create_monster(plains[rand() % plains_size]);

        default:
            return (Monster){0}; // zero-init 
    }
}