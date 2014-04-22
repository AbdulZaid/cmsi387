#include <pthread.h>
#include <semaphore.h>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define HUNGRY 0
#define EATING 1
#define THINKING 2 

//The number of philisophers.
int philosopher_number[5];
//The number of states.
int philosopher_state[5];
int chopstick_state[5];
pthread_mutex_t chopsticks[5];

/**
 * This function lets us see a visual representation of our philosophers.
 */
void printPhilosophers () {

}

/**
 * This is taken from GitHub user Dondi's bounder buffer code.
 */

int randomWait(int bound) {
    int wait = rand() % bound;
    sleep(wait);
    return wait;
}


/**
 *  This lets the philospher get a chopstick.
*/ 
void useChopstick (int chopstick) {
	pthread_mutex_lock(&chopsticks[chopstick]);
	chopstick_state[chopstick] += 1;
}

/**
 *  This lets the philospher put down a chopstick.
*/ 
void putDownChopstick (int chopstick) {
	pthread_mutex_unlock(&chopsticks[chopstick]);
	chopstick_state[chopstick] -= 1;
}

/**
 * This lets the philospher think.
 */
void think (int philosopher) {
	randomWait(5);
	philosopher_state[philosopher] = HUNGRY;
}

/**
 * This function lets a philosopher pick up some chopsticks.
 */
void eat (int philosopher) {
	useChopstick(philosopher);
	useChopstick((philosopher + 1) % NUM);
	philosopher_state[philosopher] = EATING;
	randomWait(5);
}

/**
 * This function lets a philosopher put down his chopsticks.
 */

void doneEating (int philosopher) {
	putDownChopstick(philosopher);
	putDownChopstick((philosopher + 1) % NUM);
	philosopher_state[philosopher] = THINKING;
}

/**
 *  This function will let the philosophers eat and think.
 * This method was implemented by looking at: http://rosettacode.org/wiki/Dining_philosophers
 */ 
void* philosophize (void* philosopher) {
	int id = *(int*) philosopher;
	printPhilosophers();
	while (1) {
		printPhilosophers();
		if (philosopher_state[id] == THINKING) {
			think(id);
		} else if (philosopher_state[id] == HUNGRY) {
			eat(id);
		} else if (philosopher_state[id] == EATING) {
			doneEating(id);
		}
	}
}
int main () {
	int i;
	pthread_t philosphers[5];

	return 0;

}