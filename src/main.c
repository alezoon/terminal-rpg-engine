#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "player.h"
#include "monster.h"
#include "monster_db.h"

int main(void) {
    // Random seed
    srand(time(NULL));


    // Player Test
    Player player = init_player();
    player_to_string(&player);

    // Monster Test
    Monster monster = create_monster(forest[0]);
    monster_to_string(&monster);
}