#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <time.h>
#include <gtk/gtk.h>

struct stop_watch{
	GtkWidget display;
	time_t start_time;
	time_t end_time;
};

void start_stop_watch(struct stop_watch *this_timer);

void pause_stop_watch(struct stop_watch *this_timer);

void display_stop_watch();

#define stop_watch_list_default_count 10

struct stop_watch_list{
	struct stop_watch *stop_watches;
	GtkWidget *list_display;
	int count;
	int max_count;
};

void init_stop_watch_list(struct stop_watch_list *new_list);
void destory_stop_watch_list(struct stop_watch_list kill_list);
void add_stop_watch(struct stop_watch *new_timer);

// TODO add save/laod support
void load_stop_watchs(struct stop_watch_list*, char *save_file);
void save_stop_watchs(struct stop_watch_list*, char *save_file);



#endif
