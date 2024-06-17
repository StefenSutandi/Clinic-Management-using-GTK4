#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

// Deklarasi label untuk menampilkan pesan 
GtkWidget *report_label7;

// Deklarasi fungsi untuk menghapus riwayat medis
GtkWidget* deleteMedicalRecord(GtkButton *button, gpointer user_data);

GtkWidget* Page_7() {

    // Membuat box sebagai halaman 7
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-page3_1");

    //Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed = addFixed(page);

    // Membuat tombol kembali ke halaman utama
    GtkWidget* BackButton = iconButton("icons/back.png", "Kembali ke menu utama", "back-button", "back-title");
    gtk_widget_set_size_request(BackButton, 240, 60);
    g_signal_connect(BackButton, "clicked", G_CALLBACK(on_go_to_main), NULL);
    gtk_fixed_put(GTK_FIXED(fixed), BackButton, 60, 50);

    // Membuat box entries untuk input ID
    GtkWidget *id_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_size_request(id_box, 500, 50);
    GtkWidget *inputID = gtk_entry_new();
    setinput(inputID, "Masukkan ID riwayat medis yang ingin dihapus:", id_box, "icons/id.png");
    gtk_fixed_put(GTK_FIXED(fixed), id_box, 330, 160);

    //Membuat tombol untuk menghapus riwayat medis
    GtkWidget* show_button = iconButton("icons/trash.png", "Hapus Riwayat Medis", "find-button", "find-title");
    gtk_widget_set_size_request(show_button,150,50);
    gtk_fixed_put(GTK_FIXED(fixed), show_button, 860, 176);

    //Memanggil fungsi deleteMedicalRecord ketika tombol ditekan
    g_signal_connect(show_button, "clicked", G_CALLBACK(deleteMedicalRecord), inputID);

    // Membuat box untuk menampilkan warning
    GtkWidget* boxWarning2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    report_label7 = gtk_label_new("");
    gtk_widget_add_css_class(report_label7, "white-report");
    gtk_box_append(GTK_BOX(boxWarning2), report_label7);
    gtk_fixed_put(GTK_FIXED(fixed), boxWarning2, 350,230);

    // Menambahkan halaman 7 ke stack pada main window
    gtk_stack_add_named(GTK_STACK(stack), page, "Page_7");
    return page;
}

// Fungsi untuk menghapus riwayat medis
GtkWidget* deleteMedicalRecord(GtkButton *button, gpointer user_data) {

    // Mendapatkan data dari input ID
    GtkWidget *entry = GTK_WIDGET(user_data);
    gchar *data = g_strdup(gtk_editable_get_text(GTK_EDITABLE(entry)));
    GtkEntryBuffer *bufferId = gtk_entry_get_buffer(GTK_ENTRY(entry));

    // Mencari riwayat medis berdasarkan ID
    char temp_id[5];
    g_strlcpy(temp_id, data, sizeof(temp_id));
    int record_id = atoi(temp_id);
    int indexRecord7 = findMedicalRecordById(record_id);

    if (indexRecord7 == -1) {
        gtk_label_set_text(GTK_LABEL(report_label7), "*Riwayat medis tidak ditemukan");

    } else {

        for (int i = indexRecord7; i < record_count - 1; i++) {
            records[i] = records[i + 1];
        }
        record_count--;
        gtk_label_set_text(GTK_LABEL(report_label7), "*Riwayat medis berhasil dihapus");
        WriteFileRecord();
    }
    // Mengosongkan input ID
    gtk_entry_buffer_set_text(bufferId, "", -1);
}