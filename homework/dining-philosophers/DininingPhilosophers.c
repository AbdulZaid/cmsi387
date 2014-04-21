#include <pthread.h>
#include <semaphore.h>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define TRUE 1
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


int main () {
	int i;
	pthread_t philosphers[5];

	return 0;

}