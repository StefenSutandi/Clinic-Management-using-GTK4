#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

//Fungsi untuk menampilkan data pasien beserta riwayat medisnya
void displayPatientWithMedicalRecords(GtkButton *button, gpointer user_data);

//Deklarasi variabel untuk menampilkan data pasien
int indexPatient8;
char patient_id8[15];
GtkWidget *name_show8;
GtkWidget *adress_show8;
GtkWidget *city_show8;
GtkWidget *birth_place_show8;
GtkWidget *birth_date_show8;
GtkWidget *age_show8;
GtkWidget *bpjs_show8;
GtkWidget *patient_id_show8;
GtkWidget *report_label8;
GtkWidget *ScrollGrid;

GtkWidget* Page_8() {

    // Membuat box sebagai halaman 8
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-page8");

    //Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed = addFixed(page);

    // Membuat tombol kembali ke halaman utama
    GtkWidget* BackButton = iconButton("icons/back.png", "Kembali ke menu utama", "back-button", "back-title");
    gtk_widget_set_size_request(BackButton, 240, 60);
    g_signal_connect(BackButton, "clicked", G_CALLBACK(on_go_to_main), NULL);

    // Membuat box entries untuk input ID
    GtkWidget *id_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_size_request(id_box, 500, 50);
    setinput(inputID, "Masukkan ID", id_box,"icons/id.png");
    gtk_fixed_put(GTK_FIXED(fixed), id_box, 550, 60);

    // Membuat tombol untuk menampilkan data pasien
    GtkWidget *boxbutton2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    GtkWidget* show_button = iconButton("icons/find.png", "Cari Data", "find-button", "find-title");
    gtk_widget_set_size_request(show_button,150,50);
    gtk_box_append(GTK_BOX(boxbutton2), show_button);

    //Memanggil fungsi displayPatientWithMedicalRecords ketika tombol ditekan
    g_signal_connect(show_button, "clicked", G_CALLBACK(displayPatientWithMedicalRecords), inputID);
    
    //Membuat grid untuk menampilkan data pasien
    GtkWidget *boxgrid = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_fixed_put(GTK_FIXED(fixed), boxgrid, 300, 240);

    //Menambahkan data pasien ke dalam grid
    name_show8 = gtk_label_new("");
    gtk_widget_set_halign(name_show8, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), name_show8, 1, 0, 1, 1);
    gtk_widget_add_css_class(name_show8, "label2");

    adress_show8 = gtk_label_new("");
    gtk_widget_set_halign(adress_show8, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), adress_show8, 1, 1, 1, 1);
    gtk_widget_add_css_class(adress_show8, "label2");

    city_show8 = gtk_label_new("");
    gtk_widget_set_halign(city_show8, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), city_show8, 1, 2, 1, 1);
    gtk_widget_add_css_class(city_show8, "label2");

    birth_place_show8 = gtk_label_new("");
    gtk_widget_set_halign(birth_place_show8, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), birth_place_show8, 1, 3, 1, 1);
    gtk_widget_add_css_class(birth_place_show8, "label2");

    age_show8 = gtk_label_new("");
    gtk_widget_set_halign(age_show8, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), age_show8, 1, 4, 1, 1);
    gtk_widget_add_css_class(age_show8, "label2");

    birth_date_show8 = gtk_label_new("");
    gtk_widget_set_halign(birth_date_show8, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), birth_date_show8, 1, 5, 1, 1);
    gtk_widget_add_css_class(birth_date_show8, "label2");

    bpjs_show8 = gtk_label_new("");
    gtk_widget_set_halign(bpjs_show8, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), bpjs_show8, 1, 6, 1, 1);
    gtk_widget_add_css_class(bpjs_show8, "label2");

    patient_id_show8 = gtk_label_new("");
    gtk_widget_set_halign(patient_id_show8, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), patient_id_show8, 1, 7, 1, 1);
    gtk_widget_add_css_class(patient_id_show8, "label2");

    //Tambahkan box untuk pesan warning
    GtkWidget* boxWarning2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    report_label8 = gtk_label_new("");
    gtk_box_append(GTK_BOX(boxWarning2), report_label8);
    gtk_widget_add_css_class(report_label8, "white-report");
    gtk_fixed_put(GTK_FIXED(fixed), boxWarning2, 575, 135);

    // Membuat grid untuk menampilkan riwayat medis pasien
    ScrollGrid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(ScrollGrid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(ScrollGrid), 6);

    //Membuat supaya grid dapat digeser
    GtkWidget *scrolled_window = gtk_scrolled_window_new();
    gtk_widget_set_size_request(scrolled_window,550,400);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_fixed_put(GTK_FIXED(fixed), scrolled_window, 650, 300);

    //Menambahkan halaman 8 ke stack pada main window
    gtk_stack_add_named(GTK_STACK(stack), page, "Page_8");
    return page;
}

//Fungsi untuk menampilkan data pasien beserta riwayat medisnya
void displayPatientWithMedicalRecords(GtkButton *button, gpointer user_data) {

    // Mendapatkan data dari input ID
    GtkWidget *entry = GTK_WIDGET(user_data);
    gchar *data = g_strdup(gtk_editable_get_text(GTK_EDITABLE(entry)));
    GtkEntryBuffer *bufferId = gtk_entry_get_buffer(GTK_ENTRY(entry));
    GtkWidget *Medical_Data[6];

    //Mencari data pasien berdasarkan ID
    g_strlcpy(patient_id8, data, sizeof(patient_id8));
    indexPatient8 = findPatientById(patient_id8);

    if (indexPatient8 == -1) { //Jika pasien tidak ditemukan maka menampilkan pesan warning
        gtk_label_set_text(GTK_LABEL(report_label8), "*Pasien tidak ditemukan");
        gtk_label_set_text(GTK_LABEL(name_show8), "");
        gtk_label_set_text(GTK_LABEL(adress_show8), "");
        gtk_label_set_text(GTK_LABEL(city_show8), "");
        gtk_label_set_text(GTK_LABEL(birth_place_show8), "");
        gtk_label_set_text(GTK_LABEL(age_show8), "");
        gtk_label_set_text(GTK_LABEL(birth_date_show8), "");
        gtk_label_set_text(GTK_LABEL(bpjs_show8), "");
        gtk_label_set_text(GTK_LABEL(patient_id_show8), "");

    } else {

        //Menghapus data pasien pada grid dan riwayat medis sebelumnya
        GtkWidget *child = gtk_widget_get_first_child(GTK_WIDGET(ScrollGrid));
        while (child != NULL) {
            gtk_widget_unparent(child);
            child = gtk_widget_get_first_child(GTK_WIDGET(ScrollGrid));
        }

        //Menampilkan data pasien dan riwayat medisnya
        gtk_label_set_text(GTK_LABEL(report_label8), "");
        gtk_label_set_text(GTK_LABEL(name_show8), patients[indexPatient8].name);
        gtk_label_set_text(GTK_LABEL(adress_show8), patients[indexPatient8].address);
        gtk_label_set_text(GTK_LABEL(city_show8), patients[indexPatient8].city);
        gtk_label_set_text(GTK_LABEL(birth_place_show8), patients[indexPatient8].birth_place);
        char str[20];
        sprintf(str, "%d", patients[indexPatient8].age);
        gtk_label_set_text(GTK_LABEL(age_show8), str);
        gtk_label_set_text(GTK_LABEL(birth_date_show8), patients[indexPatient8].birth_date);
        gtk_label_set_text(GTK_LABEL(bpjs_show8), patients[indexPatient8].bpjs);
        gtk_label_set_text(GTK_LABEL(patient_id_show8), patients[indexPatient8].patient_id);
        
        for (int i = 0; i < record_count; i++) {
            if (strcmp(records[i].patient_id, patient_id8) == 0) {
                sprintf(str, "%d", records[i].id);
                Medical_Data[0] = gtk_label_new(str);
                gtk_grid_attach(GTK_GRID(ScrollGrid), Medical_Data[0], 0, i + 1, 1, 1);
                gtk_widget_add_css_class(Medical_Data[0], "label3");
                Medical_Data[1] = gtk_label_new(records[i].date);
                gtk_grid_attach(GTK_GRID(ScrollGrid), Medical_Data[1], 1, i + 1, 1, 1);
                gtk_widget_add_css_class(Medical_Data[1], "label3");
                Medical_Data[2] = gtk_label_new(records[i].diagnosis);
                gtk_grid_attach(GTK_GRID(ScrollGrid), Medical_Data[2], 2, i + 1, 1, 1);
                gtk_widget_add_css_class(Medical_Data[2], "label3");
                Medical_Data[3] = gtk_label_new(records[i].treatment);
                gtk_grid_attach(GTK_GRID(ScrollGrid), Medical_Data[3], 3, i + 1, 1, 1);
                gtk_widget_add_css_class(Medical_Data[3], "label3");
                Medical_Data[4] = gtk_label_new(records[i].control_date);
                gtk_grid_attach(GTK_GRID(ScrollGrid), Medical_Data[4], 4, i + 1, 1, 1);
                gtk_widget_add_css_class(Medical_Data[4], "label3");
                sprintf(str, "%d", records[i].cost);
                Medical_Data[5] = gtk_label_new(str);
                gtk_grid_attach(GTK_GRID(ScrollGrid), Medical_Data[5], 5, i + 1, 1, 1);
                gtk_widget_add_css_class(Medical_Data[5], "label3");
            }
        }
    }
    // Mengosongkan input ID
    gtk_entry_buffer_set_text(bufferId, "", -1);
}