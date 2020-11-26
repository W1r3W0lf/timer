#include "stopWatch.h"
#include <time.h>
#include <gtk/gtk.h>


void start_stop_watch(struct stop_watch *this_timer){
	time_t now;
	time(&now);
	if (this_timer->start_time){
		this_timer->end_time = 0;
	} else {
		this_timer->start_time = now;
	}
}

void pause_stop_watch(struct stop_watch *this_timer){
	time_t now;
	time(&now);
	this_timer->end_time = now;
}

void display_stop_watch(){

}


void add_timer(struct stop_watch_list *this_list){

}

void init_stop_watch_list(struct stop_watch_list *new_list){
	new_list->list_display = gtk_list_box_new();

}

void destory_stop_watch_list(struct stop_watch_list kill_list){

}
