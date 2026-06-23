#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct _Player {
    
    uint32_t level;
    uint32_t xp_req;
    uint32_t xp;

    uint32_t max_health;
    uint32_t health;
    uint32_t dmg;

} Player;


/**
 * Initialize the players stat values as level 1
 */
Player init_player() {

    Player p = {
        .level = 1,
        .xp_req = 120,
        .xp = 0,
        .max_health = 20,
        .health = 20,
        .dmg = 10
    };

    return p;
}


/**
 * Adjust stat values to match level
 * 
 * @param p Pointer to player struct
 */
void adjust_stats(Player *p, uint32_t lvl) {

    p->max_health = 20 + lvl * 5;
    p->health = p->max_health;
    p->dmg = 10 + lvl * 2;

}


/**
 * Check if the player is alive
 * 
 * @param p Pointer to player struct
 * 
 * returns: bool value respective to alive or not
 */
bool player_alive(Player *p) {
    return p->health > 0;
}


/**
 * Increase the players current hp
 * 
 * @param p     Pointer to player struct
 * @param amt   Amount to change health by
 */
void player_heal(Player *p, uint32_t amt) {
    if (p->health + amt > p->max_health) {
        p->health = p->max_health;
    } else {
        p->health += amt;
    }
}


/**
 * Decrease the players current hp
 * 
 * @param p     Pointer to player struct
 * @param amt   Amount to change health by
 */
void damage_player(Player *p, uint32_t amt) {
    if (amt >= p->health) {
        p->health = 0;
    } else {
        p->health -= amt;
    }
}


/**
 * Print player information to stdout
 * 
 * @param p Pointer to player struct
 */
void player_to_string(Player *p) {
    printf("Level: %u   | Health:  %u/%u\nEXP: %u/%u    | Damage: %u\n",
    p->level, p->health, p->max_health, p->xp, p->xp_req, p->dmg
    );
}
