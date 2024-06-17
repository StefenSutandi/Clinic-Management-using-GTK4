#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

GtkWidget* Page_13(){

    // Membuat box sebagai halaman awal
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-page13");

    // Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed = addFixed(page);

    // Membuat tombol kembali ke halaman utama
    GtkWidget* BackButton = iconButton("icons/back.png", "Kembali ke menu utama","back-button","back-title");
    gtk_widget_set_size_request(BackButton, 240, 60);
    g_signal_connect(BackButton, "clicked", G_CALLBACK(on_go_to_main), NULL);
    gtk_fixed_put(GTK_FIXED(fixed), BackButton, 60, 50);

    // Menambahkan halaman ini ke dalam stack di main window
    gtk_stack_add_named(GTK_STACK(stack), page, "Page13");
    return page;
}