#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

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
        "player_level,player_hp,player_dmg,monster_level,monster_hp,monster_dmg,won,turns,player_remaining_hp\n"
    );

    
    // Simulation Loop Logic




    fclose(outfile);
    return EXIT_SUCCESS;
}