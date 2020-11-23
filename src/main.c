#include <time.h>
#include <stdio.h>
#include <unistd.h> // Used only for sleep
#include <gtk/gtk.h>

// Threading for time updating
#include <pthread.h>
#include <semaphore.h>


// Modifyed by more than one function
GtkLabel *time_label; 
time_t start_time;
sem_t time_lock;

// Running signal to update_counter
_Atomic(int) running;
void update_counter();


GtkButton *start_stop; // Only acessed by start_stop_cliekced
void start_stop_clicked();


static void on_activate (GtkApplication *app){

	GtkWidget *window;
	GtkWidget *grid;

	// Setup the window
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Timer");

	// Add the grid to the window
	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid);

	// Start/Stop button
	start_stop = GTK_BUTTON(gtk_button_new_with_label("Start"));
	g_signal_connect(start_stop, "clicked", G_CALLBACK(start_stop_clicked), NULL);
	gtk_grid_attach(GTK_GRID(grid), GTK_WIDGET(start_stop), 0,1,1,1); // Add the button to the grid

	// Timer Label
	time_label = GTK_LABEL(gtk_label_new("00:00"));
	gtk_grid_attach(GTK_GRID(grid), GTK_WIDGET(time_label), 0,0,2,1); // Add the label to the grid

	gtk_widget_show_all(window);
}

int main(int argc, char** argv){

	sem_init(&time_lock, 0, 1 /*Inital Value*/);
	start_time = 0;
	running = 1;
	int status;

	GtkApplication *app = gtk_application_new("com.michaeljury.timer", G_APPLICATION_FLAGS_NONE);

	g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}

void update_counter(){

	while(running){

		sem_wait(&time_lock); // Lock 

		time_t start = start_time;

		sem_post(&time_lock); // Unlock

		if(! start){
			// See start_stop_clicked first comment.

			time_t now;
			time(&now);

			// Old hold overs from the last timer program
			time_t diffTime = difftime(now, start_time);
			printf("%ld\n", diffTime);
			char timeString[64];
			//sprintf(timeString ,"%ld", diffTime);
			struct tm *localnow = localtime(&diffTime);
			strftime(timeString, 64, "%M:%S", localnow);
			gtk_label_set_text(time_label, timeString);

		}

		sleep(1);
	}

}

void start_stop_clicked(){

	sem_wait(&time_lock); // Lock 
	/* I could lock the thread when the timer is stopped.
	 * And that is how I keep the timer from progressing.
	 *
	 * It's a bit scetch so I'm going to do it after I get this working.
	 */

	if(!start_time){ // If the timer has not been started then Start it.
		time(&start_time);
		printf("%ld\n",start_time);
		gtk_button_set_label(start_stop, "Stop");

	}else{ // If the timer has been started then stop it.
		start_time = 0;
		gtk_button_set_label(start_stop, "Start");
	}
	sem_post(&time_lock); // Unlock
}

void exit_timer(){
	printf("save_file\n");
	running = 0; // Kill update thread
	gtk_main_quit();
}
