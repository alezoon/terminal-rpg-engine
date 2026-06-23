#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

typedef struct _Monster {

    // Settings
    char *name;
    uint32_t max_level;
    uint32_t min_level;

    // Stats
    uint32_t level;
    uint32_t max_health;
    uint32_t health;
    uint32_t dmg;
    
} Monster;


/**
 * Create a monster with proper stat values (CHATGPT BALANCED)
 * 
 * @param m Monster struct from DB
 * 
 * returns: A monster struct with initialized stats
 */
Monster create_monster(Monster template) {
    Monster monster = template;

    monster.level = rand() % (template.max_level - template.min_level + 1)
                  + template.min_level;

    // Stronger scaling
    monster.max_health = 20 + monster.level * 12;
    monster.health = monster.max_health;
    monster.dmg = 5 + monster.level * 3;

    return monster;
}


/**
 * Check if the Monster is alive
 * 
 * @param m Pointer to monster struct
 * 
 * returns: bool value respective to alive or not
 */
bool monster_alive(Monster *m) {
    return m->health > 0;
}


/**
 * Decrease the Monsters current hp
 * 
 * @param m     Pointer to Monster struct
 * @param amt   Amount to change health by
 */
void damage_monster(Monster *m, uint32_t amt) {
    if (amt >= m->health) {
        m->health = 0;
    } else {
        m->health -= amt;
    }
}


/**
 * Print Monster information to stdout
 * 
 * @param p Pointer to player struct
 */
void monster_to_string(Monster *m) {
    printf("Name: %s    | Level: %u\nHealth: %u     | Damage: %u\n",
    m->name, m->level, m->health, m->dmg);
}
