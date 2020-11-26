#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <gtk/gtk.h>
//#include <semaphore.h>

struct timer{
	time_t start_time;
	time_t end_time;
	GtkWidget *timer_display;
};

struct timer_list{
	struct timer *timers;
	GtkWidget *timer_list_box;

	int timer_count;
};

void init_timer(struct timer *new_timer);
void start_timer(struct timer *this_timer);
void pause_timer(struct timer *this_timer);
void save_timer(struct timer *this_timer);

GtkWidget* timer_ui(GtkWidget *timer_display);


#endif
