# Dengue Simulation
2011 Programming Laboratory 1 Final Assignment

It is a simulation of a dengue epidemic.

When the program starts, one can choose the number of male mosquitoes (M), female mosquitoes (F), people (P) and agents (A).

The simulation takes place in turns. At each turn people and mosquitoes move a space randomly in any direction. Agents move only one space to the right with each turn. When they reach the edge of the screen, they go to position 0 of the next line.

If an element tries to move to a busy space, it can not and is still stopped for a turn. But if an agent tries to move to where there is a mosquito, that mosquito dies, and the agent occupies its position.

When a female mosquito is in a space next to a male mosquito, an egg (O) will appear on the next turn.

The eggs are born the other turn and can be born as a male or female mosquito.

Only female mosquitoes transmit the disease of dengue, so if a person is a space next to a female mosquito, that person becomes contaminated (P becomes a C).

The simulation ends when all people are contaminated or when all mosquitoes are killed. At the end of the simulation appears a report of contaminated people, dead mosquitoes, dead eggs, and new mosquitoes.

## Skills
- C language
- Solving problems through a computer language
