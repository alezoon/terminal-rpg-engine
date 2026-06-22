CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LIBS = -lm

SRC = src/main.c src/player.c src/monster.c src/monster_db.c src/battle.c src/experience.c

OUT = bin/rpg

# Change this to be multiple .o files to learn linking and building
all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)


# Simulation
simulation: src/simulation.c
	gcc -Wall -Wextra -std=c11 -o bin/simulation src/simulation.c



# clean
clean:
	rm -f $(OUT)
