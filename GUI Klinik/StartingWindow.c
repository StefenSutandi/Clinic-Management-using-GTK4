#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

GtkWidget* startingPage(){

    // Membuat box sebagai halaman awal
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    // Menambahkan background ke dalam halaman
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-window");

    // Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed = addFixed(page);

    // Membuat tombol mulai
    GtkWidget* StartButton = gtk_button_new_with_label("Mulai");
    gtk_widget_set_size_request(StartButton, 210, 55); // Mengatur ukuran tombol
    gtk_widget_add_css_class(StartButton, "start-button"); // Menambahkan class CSS ke tombol
    gtk_fixed_put(GTK_FIXED(fixed), StartButton, 667, 528); // Mengatur posisi tombol

    //Membuat fungsi ketika tombol mulai ditekan maka akan menuju ke halaman utama
    g_signal_connect(StartButton, "clicked", G_CALLBACK(on_go_to_main), NULL); // 

    // Menambahkan halaman ini ke dalam stack di main window
    gtk_stack_add_named(GTK_STACK(stack), page, "StartPage");
    return page;
}