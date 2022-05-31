//Compile : gcc -Wno-format -o coffee_machine coffee_machine.c -Wno-deprecated-declarations -Wno-format-security -lm `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <gtk/gtk.h>

gchar harga[200] ;
gchar coffee[200];

//Inisialisasi css
GtkCssProvider *cssProvider;

//Inisialisasi window menu
GtkWidget	*window_menu;
GtkWidget	*box_menu;
GtkWidget	*menu_but1;

//Inisialisasi window popup1
GtkWidget	*popup1;
GtkWidget   *pop1_grid, *pop1_box1, *pop1_box2, *pop1_box3, *pop1_box4;
GtkWidget	*pop1_but1, *pop1_but2, *pop1_but3, *pop1_but4, *pop1_quit;
GtkWidget	*pop1_but1_name, *pop1_but2_name, *pop1_but3_name, *pop1_but4_name;
GtkWidget	*pop1_but1_price, *pop1_but2_price, *pop1_but3_price, *pop1_but4_price, *pop1_label;
GtkWidget	*coffee1, *coffee2, *coffee3, *coffee4;

//Inisisalisasi window popup2
GtkWidget   *popup2;
GtkWidget   *pop2_grid;
GtkWidget   *pop2_but1, *pop2_but2, *pop2_but3, *pop2_but4, *pop2_but5, *pop2_but6, *pop2_quit;
GtkWidget	*logo_linkaja, *logo_qris, *logo_dana, *logo_spay, *logo_gopay, *logo_ovo, *cal_imgKembali;
GtkWidget	*pop2_label, *labelKembali3;

//Inisialisasi window popup3
GtkWidget   *popup3;
GtkWidget   *pop3_box;
GtkWidget   *pop3_label1, *pop3_label2;
GtkWidget   *pop3_but1;
GtkWidget   *qris_img;

//Inisialisasi window popup success
GtkWidget   *pop_success;
GtkWidget   *succ_but1;
GtkWidget   *succ_box;
GtkWidget   *logo_success;
GtkWidget   *label_success;

GtkBuilder	*builder; 

int main (int argc, char **argv)
{
	gtk_init (&argc, &argv);
	
	//connect dengan glade
	builder = gtk_builder_new_from_file ("coffee_machine.glade");
	
	//WindowMenu
	window_menu = GTK_WIDGET (gtk_builder_get_object(builder, "window_menu"));
	g_signal_connect (window_menu, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	gtk_builder_connect_signals (builder, NULL);
	box_menu = GTK_WIDGET (gtk_builder_get_object (builder, "box_menu"));
	menu_but1 = GTK_WIDGET (gtk_builder_get_object (builder, "menu_but1"));

	//WindowPopup1
	popup1 = GTK_WIDGET (gtk_builder_get_object (builder, "popup1"));
	pop1_but1 = GTK_WIDGET (gtk_builder_get_object (builder, "pop1_but1"));
	pop1_but2 = GTK_WIDGET (gtk_builder_get_object (builder, "pop1_but2"));
	pop1_but3 = GTK_WIDGET (gtk_builder_get_object (builder, "pop1_but3"));
	pop1_but4 = GTK_WIDGET (gtk_builder_get_object (builder, "pop1_but4"));
	pop1_quit = GTK_WIDGET (gtk_builder_get_object (builder, "pop1_quit"));
	pop1_label	 = GTK_WIDGET (gtk_builder_get_object (builder, "pop1_label"));

	//WindowPopup2
	popup2 = GTK_WIDGET (gtk_builder_get_object (builder, "popup2"));
	pop2_but1 = GTK_WIDGET (gtk_builder_get_object (builder, "pop2_but1"));
	
	//WindowPopup3
	popup3 = GTK_WIDGET (gtk_builder_get_object (builder, "popup3"));
	pop3_but1 = GTK_WIDGET (gtk_builder_get_object (builder, "pop3_but1"));
	pop3_label1 = GTK_WIDGET (gtk_builder_get_object (builder, "pop3_label1"));
	pop3_label2 = GTK_WIDGET (gtk_builder_get_object (builder, "pop3_label2"));
	
	//WindowPopup_success
	pop_success = GTK_WIDGET (gtk_builder_get_object (builder, "pop_success"));
	
	//Set CSS
	cssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(cssProvider, "style.css", NULL);
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	
	//Set Fullscreen
	gtk_window_fullscreen (GTK_WINDOW (window_menu));
	gtk_window_fullscreen (GTK_WINDOW (popup1));
	gtk_window_fullscreen (GTK_WINDOW (popup2));
	//~ gtk_window_set_default_size (GTK_WINDOW (window_menu), 1366, 768);
	//~ gtk_window_set_keep_above (GTK_WINDOW (window_menu), TRUE);
	
	gtk_widget_show(window_menu);			//Print window

	gtk_main();
	
	return EXIT_SUCCESS;
}

//Window Menu

void on_menu_but1_clicked (GtkButton *b)
{
		gtk_widget_show (popup1);
}

//Window popup1

void on_pop1_but1_clicked (GtkButton *b)
{
		gtk_widget_show (popup2);
		strcpy(harga, "Rp. 10.000");
		strcpy(coffee, "Longblack");
}

void on_pop1_but2_clicked (GtkButton *b)
{
		gtk_widget_show (popup2);
		strcpy(harga, "Rp. 10.000");
		strcpy(coffee, "Americano");
}

void on_pop1_but3_clicked (GtkButton *b)
{
		gtk_widget_show (popup2);
		strcpy(harga, "Rp. 20.000");
		strcpy(coffee, "Cappuccino");
}

void on_pop1_but4_clicked (GtkButton *b)
{
		gtk_widget_show (popup2);
		strcpy(harga, "Rp. 20.000");
		strcpy(coffee, "Latte");
}

void on_pop1_quit_clicked (GtkButton *b)
{
		gtk_widget_hide (popup1);
}

//Window popup2

void on_pop2_but1_clicked (GtkButton *b)
{
		gtk_widget_show (popup3);
		gtk_label_set_text (GTK_LABEL(pop3_label1), (const gchar* ) coffee);
		gtk_label_set_text (GTK_LABEL(pop3_label2), (const gchar* ) harga);
}

void on_pop2_but2_clicked (GtkButton *b)
{
		gtk_widget_show (popup3);
		gtk_label_set_text (GTK_LABEL(pop3_label1), (const gchar* ) coffee);
		gtk_label_set_text (GTK_LABEL(pop3_label2), (const gchar* ) harga);
}

void on_pop2_but3_clicked (GtkButton *b)
{
		gtk_widget_show (popup3);
		gtk_label_set_text (GTK_LABEL(pop3_label1), (const gchar* ) coffee);
		gtk_label_set_text (GTK_LABEL(pop3_label2), (const gchar* ) harga);
}

void on_pop2_but4_clicked (GtkButton *b)
{
		gtk_widget_show (popup3);
		gtk_label_set_text (GTK_LABEL(pop3_label1), (const gchar* ) coffee);
		gtk_label_set_text (GTK_LABEL(pop3_label2), (const gchar* ) harga);
}

void on_pop2_but5_clicked (GtkButton *b)
{
		gtk_widget_show (popup3);
		gtk_label_set_text (GTK_LABEL(pop3_label1), (const gchar* ) coffee);
		gtk_label_set_text (GTK_LABEL(pop3_label2), (const gchar* ) harga);
}

void on_pop2_but6_clicked (GtkButton *b)
{
		gtk_widget_show (popup3);
		gtk_label_set_text (GTK_LABEL(pop3_label1), (const gchar* ) coffee);
		gtk_label_set_text (GTK_LABEL(pop3_label2), (const gchar* ) harga);
}

void on_pop2_quit_clicked (GtkButton *b)
{
		gtk_widget_hide (popup2);
		gtk_widget_hide (popup3);
}

//Window popup3

void on_pop3_but1_clicked (GtkButton *b)
{
		gtk_widget_show (pop_success);
}

//Window success

void on_succ_but1_clicked (GtkButton *b)
{
		gtk_widget_hide (popup3);
		gtk_widget_hide (popup2);
		gtk_widget_hide (popup1);
		gtk_widget_hide (pop_success);
}
