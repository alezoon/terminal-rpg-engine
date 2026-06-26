#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "simulation_utils.h"


int main(int argc, char **argv) {
    srand(time(NULL));


    if (argc != 3) {
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    long sim_count = strtol(argv[2], NULL, 10);

    FILE *outfile;
    outfile = fopen(filename, "w");
    if (outfile == NULL) {
        perror("Error creating File.");
        return EXIT_FAILURE;
    }

    // Header Information
    fprintf(outfile, 
        "player_level,player_hp,player_dmg,monster_level,monster_hp,monster_dmg,won,turns,player_remaining_hp,zone\n"
    );

    
    // Simulation Loop Logic
    for (long i = 0; i < sim_count; i++) {
        CSV_OUTPUT result = battle_simulation();

        fprintf(outfile,
        "%u,%u,%u,%u,%u,%u,%d,%u,%u,%s\n",
        result.player_level,
        result.player_hp,
        result.player_dmg,
        result.monster_level,
        result.monster_hp,
        result.monster_dmg,
        result.player_won,
        result.turns,
        result.player_remaining_hp,
        result.zone == FOREST ? "FOREST" : result.zone == DEEP_FOREST ? "DEEP_FOREST" : result.zone == PLAINS ? "PLAINS" : "UNKOWN"
        );
    }



    fclose(outfile);
    return EXIT_SUCCESS;
}