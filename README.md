# Terminal RPG Engine

A terminal-based RPG engine written in C featuring turn-based combat, monster generation, progression systems, and combat simulation tools.

## Features

- Turn-based combat system
- Monster generation with level scaling
- Experience and leveling system
- Zone-based encounters
- Combat simulation executable
- CSV dataset generation for machine learning experiments

## Project Structure

```text
src/
include/
data/
bin/
```

## Build

```bash
make
```

## Run RPG

```bash
./bin/rpg.exe
```

## Run Simulator

Generate 100,000 battle simulations:

```bash
./bin/simulation.exe data/battle_data.csv 100000
```

Example CSV output:

```csv
player_level,player_hp,player_dmg,monster_level,monster_hp,monster_dmg,won,turns,player_remaining_hp,zone
5,45,20,4,68,17,1,3,11,DEEP_FOREST
```

## Future Plans

- Skills system
- Additional zones
- More monsters
- Combat AI
- Analytics dashboard
- Integration with Combat Balance AI

## Related Projects

- Combat Balance AI (planned)
