#ifndef ALARM_H
#define ALARM_H

/*
 * The alarm should have both state and be checked every loop.
 */ 

#include <time.h>
#include <gtk/gtk.h>

struct alarm{
	time_t finish_time;
};

struct alarm_list{
	struct alarm *alarms;
	GtkWidget *list_display;
	int count;
	int max_count;
};

void load_alarms(char* save_file, struct alarm *alarms, int max_alarms);

void save_alarms(char* save_file);

void set_alarm(int timer, time_t end);

void check_alarms(struct alarm *alarms, int max_alarms);

#endif
