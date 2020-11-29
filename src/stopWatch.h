#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <time.h>
#include <gtk/gtk.h>

struct stop_watch{
	GtkWidget *display;
	time_t start_time;
	time_t end_time;
};

void start_stop_watch(struct stop_watch *this_stop_watch);

void pause_stop_watch(struct stop_watch *this_stop_watch);

void display_stop_watch();

#define stop_watchs_default 10

struct stop_watch_list{
	struct stop_watch *stop_watches;
	GtkWidget *list_display;
	int count;
	int max_count;
};

int init_stop_watch_list(struct stop_watch_list new_stop_watch_list);

void destory_stop_watch_list(struct stop_watch_list kill_stop_watch_list);

int add_stop_watch(struct stop_watch_list this_stop_watch_list);

GtkWidget* stop_watch_ui(struct stop_watch_list this_stop_watch_list);

// TODO add save/laod support
void load_stop_watchs(struct stop_watch_list*, char *save_file);

void save_stop_watchs(struct stop_watch_list*, char *save_file);



#endif
