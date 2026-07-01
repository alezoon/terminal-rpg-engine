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


    // Player initialization
    Player player = init_player();
    player.xp_req = require_experience(&player);
    adjust_stats(&player, player.level);


    // Variable Initialization
    Zone zone = FOREST;
    uint32_t zone_num = 1;







    uint32_t choice;
    // Main Game loop
    while (1) {
        printf("1. Battle   | 2. Status\n3. Zone    | 4. Quit\n");
        if (scanf("%u", &choice) != 1) {
            return EXIT_FAILURE;
        }

        switch (choice) {
            case 1:
                if (player.health == 0) {
                    printf("Cannot battle, you are dead.\n");
                    break;
                }
                printf("\n");
                Monster monster = encounter(zone);
                battle(&player, &monster);
                break;

            case 2:
                player_to_string(&player);
                break;

            case 3:
                printf("1. Forest   | 2. Deep Forest\n3. Plains\n");
                printf("Switch Zone: ");
                if (scanf("%d", &zone_num) != 1) {
                    return EXIT_FAILURE;
                }
                
                switch (zone_num) {
                    case 1:
                        zone = FOREST;
                        printf("You are in zone %u: Forest\n", zone_num);
                        break;
                    case 2:
                        zone = DEEP_FOREST;
                        printf("You are in zone %u: Deep Forest\n", zone_num);
                        break;
                    case 3:
                        zone = PLAINS;
                        printf("You are in zone %u: Plains\n", zone_num);
                        break;
                    default:
                        break;
                }
                printf("\n");
                break;

            case 4:
                return EXIT_SUCCESS;

            default:
                printf("Invalid choice.\n");
                break;
        }

    }


}