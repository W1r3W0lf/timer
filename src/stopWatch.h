#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <semaphore.h>

typedef struct {
	time_t start_time;
	time_t end_time;
	sem_t lock; // I don't think I want a lock. 
}timer;

void init_timer(timer *new_timer);
void start_timer(timer *this_timer);
void pause_timer(timer *this_timer);
void save_timer(timer *this_timer);



#endif
