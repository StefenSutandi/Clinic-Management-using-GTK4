#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

void displayPatient(GtkButton *button, gpointer user_data);

// Inisialisasi variabel untuk menampilkan data pasien
GtkWidget *name_show;
GtkWidget *adress_show;
GtkWidget *city_show;
GtkWidget *birth_place_show;
GtkWidget *age_show;
GtkWidget *bpjs_show;
GtkWidget *patient_id_show;
GtkWidget *LabelWarning2;

GtkWidget* page_2() {

    // Membuat box sebagai halaman kedua
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-page2");

    // Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed = addFixed(page);

    // Membuat tombol kembali ke halaman utama
    GtkWidget* BackButton = iconButton("icons/back.png", "Kembali ke menu utama", "back-button", "back-title");
    gtk_widget_set_size_request(BackButton, 240, 60);
    g_signal_connect(BackButton, "clicked", G_CALLBACK(on_go_to_main), NULL);
    
    // Membuat box entri untuk memasukkan ID pasien
    GtkWidget *id_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_size_request(id_box, 500, 50);
    GtkWidget *inputID = gtk_entry_new();
    setinput(inputID, "Masukkan ID", id_box, "icons/id.png");
    gtk_fixed_put(GTK_FIXED(fixed), id_box, 330, 160);

    // Membuat tombol cari data pasien
    GtkWidget *boxbutton2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    GtkWidget* show_button = iconButton("icons/find.png", "Cari Data", "find-button", "find-title");
    gtk_widget_set_size_request(show_button,150,50);
    gtk_box_append(GTK_BOX(boxbutton2), show_button);

    // Memanggil fungsi displayPatient ketika tombol cari data pasien ditekan
    g_signal_connect(show_button, "clicked", G_CALLBACK(displayPatient), inputID);
    
    // Membuat grid untuk menampilkan data pasien
    GtkWidget *boxgrid = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *grid = gtk_grid_new();
    gtk_box_append(GTK_BOX(boxgrid), grid);

    // Menambahkan label ke dalam grid untuk menampilkan data pasien
    EditGrid(grid, &name_show, 0, 0);
    EditGrid(grid, &adress_show, 0, 1);
    EditGrid(grid, &city_show, 0, 2);
    EditGrid(grid, &birth_place_show, 0, 3);

    // Membuat grid untuk menampilkan data pasien
    GtkWidget *grid2 = gtk_grid_new();
    gtk_fixed_put(GTK_FIXED(fixed), grid2, 910, 360);

    //Menambahkan label ke dalam grid untuk menampilkan data pasien
    EditGrid(grid2, &age_show, 0, 0);
    EditGrid(grid2, &birth_date_show, 0, 1);
    EditGrid(grid2, &bpjs_show, 0, 2);

    //Tambahkan box untuk Warning
    GtkWidget* boxWarning2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    LabelWarning2 = gtk_label_new("");
    gtk_widget_add_css_class(LabelWarning2, "white-report");
    gtk_box_append(GTK_BOX(boxWarning2), LabelWarning2);

    // Menambahkan halaman 2 ke dalam stack di main window
    gtk_stack_add_named(GTK_STACK(stack), page, "Page_2");
    return page;
}

// Fungsi untuk menampilkan data pasien
void displayPatient(GtkButton *button, gpointer user_data) {
    // Mengambil data dari entri ID pasien
    GtkWidget *entry = GTK_WIDGET(user_data);
    gchar *data = g_strdup(gtk_editable_get_text(GTK_EDITABLE(entry)));
    GtkEntryBuffer *bufferId = gtk_entry_get_buffer(GTK_ENTRY(entry));

    char patient_id[15];
    // Mencari data pasien berdasarkan ID pasien
    int index = findPatientById(patient_id);

    if (index == -1) { //Mengosongkan data jika pasien tidak ditemukan
        gtk_label_set_text(GTK_LABEL(LabelWarning2), "*Pasien tidak ditemukan");
        gtk_label_set_text(GTK_LABEL(name_show), "");
        gtk_label_set_text(GTK_LABEL(adress_show), "");
        gtk_label_set_text(GTK_LABEL(city_show), "");
        gtk_label_set_text(GTK_LABEL(birth_place_show), "");
        gtk_label_set_text(GTK_LABEL(age_show), "");
        gtk_label_set_text(GTK_LABEL(birth_date_show), "");
        gtk_label_set_text(GTK_LABEL(bpjs_show), "");
        gtk_label_set_text(GTK_LABEL(patient_id_show), "");

    } else { //Menampilkan data pasien jika ditemukan
        gtk_label_set_text(GTK_LABEL(LabelWarning2), "");
        char strs[20];
        gtk_label_set_text(GTK_LABEL(name_show), patients[index].name);
        gtk_label_set_text(GTK_LABEL(adress_show), patients[index].address);
        gtk_label_set_text(GTK_LABEL(city_show), patients[index].city);
        gtk_label_set_text(GTK_LABEL(birth_place_show), patients[index].birth_place);
        char str[20];
        sprintf(str, "%d", patients[index].age);
        gtk_label_set_text(GTK_LABEL(age_show), str);
        gtk_label_set_text(GTK_LABEL(birth_date_show), patients[index].birth_date);
        gtk_label_set_text(GTK_LABEL(bpjs_show), patients[index].bpjs);
        gtk_label_set_text(GTK_LABEL(patient_id_show), patients[index].patient_id);
    }
    gtk_entry_buffer_set_text(bufferId, "", -1); // Mengosongkan entri ID pasien
}
