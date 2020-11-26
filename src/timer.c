#include "timer.h"
#include <time.h>
#include <gtk/gtk.h>
#include <semaphore.h>

void init_timer(struct timer *new_timer){
}

void start_timer(struct timer *this_timer){
	time(&this_timer->start_time); // Set start to current time.

}

void pause_timer(struct timer *this_timer){
	time(&this_timer->end_time); // Set end to current time.

}

void save_timer(struct timer *this_timer){

}

GtkWidget* timer_ui(){
	GtkWidget* listBox;

	listBox = gtk_list_box_new();


	return listBox;
}

