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


GtkLabel* clock_ui(GtkLabel *clock_display){

	//PangoAttribute *fontSize; // Trying to change the font size
	//PangoAttrList *pangoList;
	//fontSize = pango_attr_size_new(1);
	//pangoList = pango_attr_list_new();
	//pango_attr_list_insert(pangoList, fontSize);
	//
	//
	//gtk_label_set_attributes(clock_display_label, pangoList);
	GTK_LABEL(gtk_label_new("00:00:00"));
	
	return clock_display;
}
