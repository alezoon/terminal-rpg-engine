#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "monster.h"

/**
 * Get required experience needed to level up
 * 
 * @param p Pointer to player structure
 * 
 * returns: The amount of experience needed to level up
 */
uint32_t require_experience(Player *p) {
    // Soft exponential requirement
    return 10 * p->level + 20 * p->level * p->level;
}


/**
 * Calculate the experience given by the monster
 * 
 * @param m Pointer to monster struct
 * 
 * returns: An amount of experience
 */
uint32_t calculate_experience(Monster *m) {
    return m->level * 5;
}


/**
 * Add calculated experience to the player
 * 
 * @param p Pointer to player struct
 * @param m Pointer to monster struct
 */
void add_experience(Player *p, Monster *m) {

    uint32_t exp = calculate_experience(m);

    p->xp += exp;
    printf("You have gained %u experience.\n\n", exp);

    while (p->xp >= require_experience(p)) {
        p->xp -= require_experience(p);
        p->level++;
        p->xp_req = require_experience(p);
        printf("You have leveld up!\n");
    }
    

}