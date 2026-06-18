#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include "player.h"
#include "monster.h"

uint32_t require_experience(Player *p);
uint32_t calculate_experience(Monster *m);
void add_experience(Player *p, Monster *m);


#endif