#include "timer.h"
#include <time.h>
#include <semaphore.h>

void init_timer(timer *new_timer){
	sem_init(&new_timer->lock, 0, 1 /*Inital Value*/);
}

void start_timer(timer *this_timer){
	time(&this_timer->start_time); // Set start to current time.

}

void pause_timer(timer *this_timer){
	time(&this_timer->end_time); // Set end to current time.

}

void reset_timer(timer *this_timer){

}

void save_timer(timer *this_timer){

}
