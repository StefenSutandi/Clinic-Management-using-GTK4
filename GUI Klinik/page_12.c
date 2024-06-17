#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

// Fungsi untuk menampilkan tanggal kontrol dari pasien
void displayPatientsForControl();

// Deklarasi label untuk menampilkan data pasien
GtkWidget *ScrollGrid12;

GtkWidget* Page_12() {

    // Membuat box sebagai halaman 12
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-page12");

    //Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed = addFixed(page);

    // Membuat tombol kembali ke halaman utama
    GtkWidget* BackButton = iconButton("icons/back.png", "Kembali ke menu utama", "back-button", "back-title");
    gtk_widget_set_size_request(BackButton, 240, 60);
    g_signal_connect(BackButton, "clicked", G_CALLBACK(on_go_to_main), NULL);

    // Membuat grid untuk menampilkan data pasien
    ScrollGrid12 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(ScrollGrid12), 5);
    gtk_grid_set_column_spacing(GTK_GRID(ScrollGrid12), 210);

    // Membuat grid dapat digeser
    GtkWidget *scrolled_window = gtk_scrolled_window_new();
    gtk_widget_set_size_request(scrolled_window,650,400);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window), ScrollGrid12);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(scrolled_window), FALSE);

    //Memanggil fungsi displayPatientsForControl
    displayPatientsForControl();

    // Menambahkan halaman 12 ke stack pada main window
    gtk_stack_add_named(GTK_STACK(stack), page, "Page_12");
    return page;
}

// Fungsi untuk menampilkan tanggal kontrol dari pasien
void displayPatientsForControl() {
    GtkWidget *Medical_Data[6];

    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].control_date, "") != 0) {
            int patient_index = findPatientById(records[i].patient_id);
            if (patient_index != -1) {
                Medical_Data[0] = gtk_label_new(patients[patient_index].name);
                gtk_widget_set_halign(Medical_Data[0], GTK_ALIGN_START);
                gtk_grid_attach(GTK_GRID(ScrollGrid12), Medical_Data[0], 0, i + 1, 1, 1);
                gtk_widget_add_css_class(Medical_Data[0], "label5");
                Medical_Data[1] = gtk_label_new(records[i].date);
                gtk_widget_set_halign(Medical_Data[1], GTK_ALIGN_START);
                gtk_grid_attach(GTK_GRID(ScrollGrid12), Medical_Data[1], 1, i + 1, 1, 1);
                gtk_widget_add_css_class(Medical_Data[1], "label5");
            }
        }
    }
}