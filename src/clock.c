#include "clock.h"
#include <gtk/gtk.h>
#include <glib.h>
#include <time.h>
#include <assert.h>

void update_clock(GtkWidget *this_clock){

	GDateTime *now;
	gchar *nowStr;

	now = g_date_time_new_now_local();
	nowStr = g_date_time_format(now, "%H:%M:%S");

	gtk_label_set_text(GTK_LABEL(this_clock), nowStr);
}


GtkWidget* clock_ui(GtkWidget *this_clock){

	//PangoAttribute *fontSize; // Trying to change the font size
	//PangoAttrList *pangoList;
	//fontSize = pango_attr_size_new(1);
	//pangoList = pango_attr_list_new();
	//pango_attr_list_insert(pangoList, fontSize);
	//
	//
	//gtk_label_set_attributes(clock_display_label, pangoList);
	
	this_clock = gtk_label_new("00:00:00");
	
	return this_clock;
}
