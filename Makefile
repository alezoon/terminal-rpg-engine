CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LIBS = -lm

SRC = src/main.c src/player.c src/monster.c src/monster_db.c src/battle.c src/experience.c

OUT = bin/rpg

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

clean:
	rm -f $(OUT)
