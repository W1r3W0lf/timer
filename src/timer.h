#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <gtk/gtk.h>
//#include <semaphore.h>

struct timer{
	GtkWidget *timer_display;
	time_t start_time;
	time_t end_time;
};

void start_timer(struct timer *this_timer);

void pause_timer(struct timer *this_timer);

void reset_timer(struct timer *this_timer);

void save_timer(struct timer *this_timer);

#define timer_list_starting_count 10

struct timer_list{
	struct timer *timers;
	GtkWidget *timer_list_box;
	int timer_count;
	int max_timer_count;
};

void init_timer_list(struct timer_list *new_timer_list);

void destory_timer_list(struct timer_list *kill_timer_list);

void extend_timer_list(struct timer_list *this_timer_list);

void add_timer(struct timer_list *this_timer_list);

void remove_timer(struct timer_list *this_timer_list, int timer_number);


GtkWidget* timer_ui(GtkWidget *timer_display);


#endif
