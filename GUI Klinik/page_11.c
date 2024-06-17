#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

//Fungsi untuk menghitung total pendapatan bulanan, tahunan, dan rata-rata pendapatan per tahun
void getRevenue(GtkButton *button, gpointer user_data) ;

//Deklarasi label untuk menampilkan pendapatan bulanan, tahunan, dan rata-rata pendapatan per tahun
GtkWidget *MonthlyShow;
GtkWidget *AnnualShow;
GtkWidget *AverageShow;

GtkWidget* Page_11() {

    // Membuat page untuk halaman 11
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-page11");
    
    // Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed = addFixed(page);

    // Membuat tombol kembali ke halaman utama
    GtkWidget* BackButton = iconButton("icons/back.png", "Kembali ke menu utama", "back-button", "back-title");
    gtk_widget_set_size_request(BackButton, 240, 60);
    g_signal_connect(BackButton, "clicked", G_CALLBACK(on_go_to_main), NULL);
    gtk_fixed_put(GTK_FIXED(fixed), BackButton, 60, 50);

    // Membuat input untuk memasukkan bulan dan tahun
    GtkWidget *month_spin;
    GtkAdjustment *month_adj = gtk_adjustment_new(1, 1, 12, 1, 1, 0); //Mengatur rentang
    month_spin = gtk_spin_button_new(month_adj, 1, 0); //Membuat spin button
    gtk_widget_add_css_class(month_spin, "spin-button");

    GtkWidget *year_spin;
    GtkAdjustment *year_adj = gtk_adjustment_new(2023, 1900, 2100, 1, 10, 0); //Mengatur rentang
    year_spin = gtk_spin_button_new(year_adj, 1, 0); //Membuat spin button
    gtk_widget_add_css_class(year_spin, "spin-button");

    g_object_set_data(G_OBJECT(month_spin), "year_spin", year_spin); //Menyimpan year_spin sebagai user data
    gtk_fixed_put(GTK_FIXED(fixed), month_spin, 520, 100); 
    gtk_fixed_put(GTK_FIXED(fixed), year_spin, 650, 100);

    // Membuat tombol untuk menampilkan pendapatan
    GtkWidget* show_button = iconButton("icons/finds.png", "Cari Laporan", "report-button", "report-title");
    gtk_widget_set_size_request(show_button,150,50);
    gtk_fixed_put(GTK_FIXED(fixed), show_button, 820, 96);

    // Memanggil fungsi getRevenue ketika tombol ditekan
    g_signal_connect(show_button, "clicked", G_CALLBACK(getRevenue), month_spin);

    // Membuat label untuk menampilkan pendapatan bulanan, tahunan, dan rata-rata pendapatan per tahun
    MonthlyShow = gtk_label_new("");
    gtk_widget_add_css_class(MonthlyShow, "monthly");
    gtk_fixed_put(GTK_FIXED(fixed), MonthlyShow, 200, 330);

    AnnualShow = gtk_label_new("");
    gtk_widget_add_css_class(AnnualShow, "yearly");
    gtk_fixed_put(GTK_FIXED(fixed), AnnualShow, 800, 330);

    AverageShow = gtk_label_new("");
    gtk_widget_add_css_class(AverageShow, "average");
    gtk_fixed_put(GTK_FIXED(fixed), AverageShow, 800, 585);

    // Menambahkan halaman 11 ke stack pada main window
    gtk_stack_add_named(GTK_STACK(stack), page, "Page_11");
    return page;
}

// Fungsi untuk menghitung total pendapatan bulanan, tahunan, dan rata-rata pendapatan per tahun
void getRevenue(GtkButton *button, gpointer user_data) {

    // Mendapatkan data dari input bulan dan tahun
    GtkWidget *month_spin = GTK_WIDGET(user_data);
    GtkWidget *year_spin = g_object_get_data(G_OBJECT(month_spin), "year_spin");

    int month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month_spin));
    int year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year_spin));

    // Menghitung total pendapatan bulanan, tahunan, dan rata-rata pendapatan per tahun
    int total = 0;
    for (int i = 0; i < record_count; i++) {
        int rec_year, rec_month, rec_day;
        sscanf(records[i].date, "%4d-%2d-%2d", &rec_year, &rec_month, &rec_day);
        if (rec_year == year && rec_month == month) {
            total += records[i].cost;
        }
    }

    if(total == 0){
        gtk_label_set_text(GTK_LABEL(MonthlyShow), "*Tidak ada data");
    } else {
        char text[100];
        sprintf(text, "%d",total);
        gtk_label_set_text(GTK_LABEL(MonthlyShow), text);
    }

    total = 0;
    for (int i = 0; i < record_count; i++) {
        int rec_year, rec_month, rec_day;
        sscanf(records[i].date, "%4d-%2d-%2d", &rec_year, &rec_month, &rec_day);
        if (rec_year == year) {
            total += records[i].cost;
        }
    }
    
    if(total == 0){
        gtk_label_set_text(GTK_LABEL(AnnualShow), "Tidak ada data");
    } else {
        char text[100];
        sprintf(text, "%d", total);
        gtk_label_set_text(GTK_LABEL(AnnualShow), text);
    }

    total = 0;
    int years = 0;
    int current_year = 0;
    for (int i = 0; i < record_count; i++) {
        int rec_year, rec_month, rec_day;
        sscanf(records[i].date, "%4d-%2d-%2d", &rec_year, &rec_month, &rec_day);
        if (rec_year != current_year) {
            years++;
            current_year = rec_year;
        }
        total += records[i].cost;
    }
    if (years == 0) {
        gtk_label_set_text(GTK_LABEL(AverageShow), "*Tidak ada data.");
    } else {
        char text[100];
        sprintf(text, "%d", total / years);
        gtk_label_set_text(GTK_LABEL(AverageShow), text);
    }

}