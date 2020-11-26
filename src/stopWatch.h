#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <time.h>
#include <semaphore.h>

struct stop_watch{
	time_t start_time;
	time_t end_time;
	sem_t lock; // I don't think I want a lock. 
};

void load_stop_watch(char *save_file);

void save_stop_watchs(char *save_file);

void init_stop_watch(struct stop_watch *new_timer);

void start_stop_watch(struct stop_watch *this_timer);

void pause_stop_watch(struct stop_watch *this_timer);


#endif
