# Dengue Simulation
2011 Programming Laboratory 1 Final Assignment

<img src="https://lh3.googleusercontent.com/yWjN1p_oMHU9YtiGMg5r1W6UgA0NOHTsyoRcOhBC-dW7hr2Iq0-0ZHMpJE0D2LDqpN2OUtGiWP9Gyr9t9jnyl7QRCWp93EXKwP_tU82GfPDmXICTr2DMMP0LW2eKJI--cST9Q6Fyzk1BSzWH-pRTVt9kj-TOYkTgoJjOcj44iEFYWEiyyXCPkAgGv0vS3LdMUx8YHwPc9SgFIKjnBTn_cXIPw2Z0yzVzt1kKks7kkgufnXq9AYzIjoGWZwMUv2Z1UyEqbJcldBc0abY7PcnZj2A0JgDkbeUxjXPsTyX1FZnscEW9bi0S3NAQyl9masyTqrAmMcS2z4XXVvg0wHFVT6zq-zXq-GdSimjQdfcJz6VhE7t5N-9iPrLYRFErJT7KQ-YFuhaSNTFjEiuSQKUSgZ2mmTnNg3mKQm6rRPDMDg1Owps7O_vjJi8OU3MC5JxypkT3le7Z0GxfhmB1aQ7EFlBli6Hx8St1qY2wqMGgjTUWjUaJ9_Ade6gJ3S80VdhrEHEwIDTtSWa2v2lP3MXpCG4VZY92iV6c4E008fXLKMbpDo2JtkbhroSRta7qjSm8od7tRTBsRf4jv_BDFdIbzGLiv-dVvh_RuF5GewF5M3QLfIfeTxdKwzG6Xm8C7qWr2Azf7fRv3L0Mi-aVc6sDxJhBfZwoV0Np6LnhaTj2WhKx-RypFTWGZQqsLpWoDmfFMo76SAqlhCiEiqJ-QOga02IIaQ=w401-h460-no" alt="Simulacao">

It is a simulation of a <a href="https://en.wikipedia.org/wiki/Dengue_fever">dengue fever</a> epidemic.

When the program starts, one can choose the number of male mosquitoes (M), female mosquitoes (F), people (P) and agents (A). You can also choose whether to shift turns manually or automatically, and their speed in milliseconds if automatically.

The simulation takes place in turns. At each turn people and mosquitoes move a space randomly in any direction. Agents move only one space to the right with each turn. When they reach the edge of the screen, they go to position 0 of the next row.

If an element tries to move to a busy space, it can not and is still stopped for a turn. But if an agent tries to move to where there is a mosquito, that mosquito dies, and the agent occupies its position.

When a female mosquito is in a space next to a male mosquito, an egg (O) will appear on the next turn.

The eggs hatch on the next turn and can be a male or female mosquito.

Only female mosquitoes transmit the disease of dengue, so if a person is in a space next to a female mosquito, that person becomes contaminated (P becomes a C).

The simulation ends when all people are contaminated or when all mosquitoes are killed. At the end of the simulation appears a report of contaminated people, dead mosquitoes, dead eggs, and new mosquitoes.

## Skills
- C language
- Solving problems through a computer language
