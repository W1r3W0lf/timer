#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <time.h>
#include <semaphore.h>

struct stopWatch{
	time_t start_time;
	time_t end_time;
	sem_t lock; // I don't think I want a lock. 
};

void load_stopWatch(char *save_file);

void save_stopWatchs(char *save_file);

void init_stopWatch(struct stopWatch *new_timer);

void start_stopWatch(struct stopWatch *this_timer);

void pause_stopWatch(struct stopWatch *this_timer);


#endif
