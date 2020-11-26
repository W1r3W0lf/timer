#include "clock.h"
#include <gtk/gtk.h>
#include <glib.h>
#include <time.h>

void update_clock(GtkLabel *clock){

	GDateTime *now;
	gchar *nowStr;

	now = g_date_time_new_now_local();
	nowStr = g_date_time_format(now, "%H:%M:%S");

	gtk_label_set_text(clock, nowStr);
}
