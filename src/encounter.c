#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "monter.h"

typedef enum Zone {
	FOREST,
	PLAINS
} Zone;

/**
 * Randomly choose a monster from zone
 *
 * @param m
 */
Monster encounter(Zone zone, uint32_t size) {

	switch (zone) {
		case FOREST:
			Monster m = forest


	}
	Monster rand_m = m_arr[rand() % size];

	return rand_m;

}


int main(void) {


}

