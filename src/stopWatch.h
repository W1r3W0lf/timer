#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <semaphore.h>

struct stopWatch{
	time_t start_time;
	time_t end_time;
	sem_t lock; // I don't think I want a lock. 
};

void load_timers(char *save_file);

void save_timers(char *save_file);

void init_timer(struct stopWatch *new_timer);

void start_timer(struct stopWatch *this_timer);

void pause_timer(struct stopWatch *this_timer);


#endif
