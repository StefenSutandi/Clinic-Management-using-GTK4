#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "fungsi.c"
#include "StartingWindow.c"
#include "MainPage.c"
#include "page_1.c"
#include "page_2.c"
#include "page_3.c"
#include "page_4.c"
#include "page_5.c"
#include "page_6.c"
#include "page_7.c"
#include "page_8.c"
#include "page_9.c"
#include "page_10.c"
#include "page_11.c"
#include "page_12.c"
#include "page_13.c"

GtkWidget *stack;
GtkWidget *MainPage;
GtkWidget *StartingPage;
GtkWidget *Page[16];

static void activate(GtkApplication *app, gpointer user_data) {

    // Membuat jendela aplikasi
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_default_size(GTK_WINDOW(window), 1300, 800);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    // Membuat stack untuk menyimpan halaman-halaman menu
    stack = gtk_stack_new();
    gtk_stack_set_transition_type(GTK_STACK(stack), GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
    gtk_stack_set_transition_duration(GTK_STACK(stack), 1000);
    gtk_window_set_child(GTK_WINDOW(window), stack);

    // Menambahkan CSS ke aplikasi
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "style.css");
    gtk_style_context_add_provider_for_display(gdk_display_get_default(),
                                         GTK_STYLE_PROVIDER(cssProvider),
                                         GTK_STYLE_PROVIDER_PRIORITY_USER);
    
    //Membuat halaman awal ketika aplikasi dijalankan
    StartingPage = startingPage();

    //Membuat halaman utama yang berisi menu-menu 
    MainPage = mainPage();

    // Halaman 1 berisi form untuk menambahkan pasien
    Page[1] = Page_1();

    // Halaman 2 berisi form untuk menampilkan pasien
    Page[2] = Page_2();

    // Halaman 3 berisi form untuk mengubah data pasien
    Page[3] = Page_3();

    // Halaman 4 berisi form untuk menghapus data pasien
    Page[4] = Page_4();

    // Halaman 5 berisi form untuk menambahkan riwayat medis
    Page[5] = Page_5();

    // Halaman 6 berisi form untuk mengubah riwayat medis
    Page[6] = Page_6();

    // Halaman 7 berisi form untuk menghapus riwayat medis
    Page[7] = Page_7();

    // Halaman 8 berisi informasi penyakit pasien beserta data diri pasien
    Page[8] = Page_8();

    // Halaman 9 berisi laporan riwayat medis pasien bulanan dan tahunan
    Page[9] = Page_9();

    // Halaman 10 berisi informasi seluruh pasien beserta penyakit yang diderita
    Page[10] = Page_10();

    // Halaman 11 berisi informasi laporan keuangan
    Page[11] = Page_11();

    // Halaman 12 berisi informasi jadwal kontrol pasien
    Page[12] = Page_12();

    // Halaman 13 berisi identitas kelompok
    Page[13] = Page_13();
}

int main(int argc, char *argv[]) {

    //Mengambil data dari file csv dan menyimpannya ke dalam struct
    load_data();

    //Inisialisasi variabel dan membuat aplikasi GTK 
    GtkApplication *app;
    int status;
    
    app = gtk_application_new("com.example.KlinikX", G_APPLICATION_DEFAULT_FLAGS);
    
    //Menjalankan aplikasi
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}