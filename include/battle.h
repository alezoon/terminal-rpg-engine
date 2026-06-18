#ifndef BATTLE_H
#define BATTLE_H

#include "player.h"
#include "monster.h"
#include "locations.h"

void battle(Player *p, Monster *m);
Monster encounter(Zone zone);


#endif