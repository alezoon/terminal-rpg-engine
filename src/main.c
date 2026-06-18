#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "player.h"
#include "monster.h"
#include "monster_db.h"
#include "battle.h"

int main(void) {
    // Random seed
    srand(time(NULL));


    // Player Test
    Player player = init_player();
    player_to_string(&player);
    printf("\n");

    // Monster Test
    Monster monster = create_monster(forest[0]);
    monster_to_string(&monster);
    printf("\n");


    // Encounter test
    //Zone zone = FOREST;
    //Monster forest_m = encounter(zone);
    //monster_to_string(&forest_m);
    //printf("\n");

    //zone = PLAINS;
    //Monster plains_m = encounter(zone);
    //monster_to_string(&plains_m);
    //printf("\n");


    // Battle Test (BASIC FUNCTIONALITY WORKING)
    battle(&player, &monster);


}