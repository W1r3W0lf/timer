#ifndef CLOCK_H
#define CLOCK_H

#include <gtk/gtk.h>
/*
 * The Clock should be stateless and just display the time on the screen.
 */ 

void update_clock(GtkWidget *this_clock);

GtkWidget* clock_ui(GtkWidget *this_clock);

#endif
