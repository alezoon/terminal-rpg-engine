#include <stdlib.h>
#include <stdio.h>

#include "player.h"

int main(void) {

    Player player = init_player();

    player_to_string(&player);

}