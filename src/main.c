#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "player.h"
#include "monster.h"
#include "monster_db.h"
#include "battle.h"
#include "experience.h"

int main(void) {
    // Random seed
    srand(time(NULL));


    // Player Test
    Player player = init_player();
    player.xp_req = require_experience(&player);
    player_to_string(&player);
    adjust_stats(&player, player.level);
    player_to_string(&player);
    //printf("\n");

    // Monster Test
    //Monster monster = create_monster(forest[0]);
    //monster_to_string(&monster);
    //printf("\n");


    // Encounter test
    Zone zone = FOREST;
    //Monster forest_m = encounter(zone);
    //monster_to_string(&forest_m);
    //printf("\n");

    //zone = PLAINS;
    //Monster plains_m = encounter(zone);
    //monster_to_string(&plains_m);
    //printf("\n");


    // Battle Test (BASIC FUNCTIONALITY WORKING)
    


    uint32_t choice;
    // Main loop test
    while (1) {
        printf("1. Battle   | 2. Status\n3. Quit\n");
        if (scanf("%u", &choice) != 1) {
            return EXIT_FAILURE;
        }

        switch (choice) {
            case 1:
                if (player.health == 0) {
                    printf("Cannot battle, you are dead.\n");
                    break;
                }
                Monster monster = encounter(zone);
                battle(&player, &monster);
                break;
            case 2:
                player_to_string(&player);
                break;
            case 3:
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice.\n");
                break;
        }

    }


}