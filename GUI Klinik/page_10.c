#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

//Fungsi untuk menampilkan seluruh data pasien beserta riwayat medisnya
void displayAllPatientsAndRecords();
//Fungsi untuk menampilkan data pasien berikutnya
void button_next(GtkButton *button, gpointer user_data);
//Fungsi untuk menampilkan data pasien sebelumnya
void button_prev(GtkButton *button, gpointer user_data);

//Deklarasi variabel untuk menampilkan data pasien
int indexPatient10 =0;
char patient_id10[15];
GtkWidget *name_show10;
GtkWidget *adress_show10;
GtkWidget *city_show10;
GtkWidget *birth_place_show10;
GtkWidget *age_show10;
GtkWidget *bpjs_show10;
GtkWidget *patient_id_show10;
GtkWidget *report_label10;
GtkWidget *ScrollGrid10;

GtkWidget* Page_10() {

    // Membuat box sebagai halaman 10
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-page8");

    //Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed = addFixed(page);

    // Membuat tombol kembali ke halaman utama
    GtkWidget* BackButton = iconButton("icons/back.png", "Kembali ke menu utama", "back-button", "back-title");
    gtk_widget_set_size_request(BackButton, 240, 60);
    g_signal_connect(BackButton, "clicked", G_CALLBACK(on_go_to_main), NULL);
    gtk_fixed_put(GTK_FIXED(fixed), BackButton, 60, 50);

    //Membuat tombol untuk menampilkan data pasien berikutnya
    GtkWidget* nextButton = NextButton("icons/next.png", "Data Pasien Berikutnya", "back-button", "back-title");
    gtk_widget_set_size_request(nextButton, 100, 60);

    //Memanggil fungsi button_next ketika tombol ditekan
    g_signal_connect(nextButton, "clicked", G_CALLBACK(button_next), NULL);

    //Membuat tombol untuk menampilkan data pasien sebelumnya
    GtkWidget* prevButton = iconButton("icons/previous.png", "Data Pasien Sebelumnya", "back-button", "back-title");
    gtk_widget_set_size_request(prevButton, 100, 60);
    gtk_fixed_put(GTK_FIXED(fixed), prevButton, 670, 100);

    //Memanggil fungsi button_prev ketika tombol ditekan
    g_signal_connect(prevButton, "clicked", G_CALLBACK(button_prev), NULL);
    
    //Membuat grid untuk menampilkan data pasien
    GtkWidget *boxgrid = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_box_append(GTK_BOX(boxgrid), grid);

    //Menambahkan data pasien ke dalam grid
    name_show10 = gtk_label_new("");
    gtk_widget_set_halign(name_show10, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), name_show10, 1, 0, 1, 1);
    gtk_widget_add_css_class(name_show10, "label2");

    adress_show10 = gtk_label_new("");
    gtk_widget_set_halign(adress_show10, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), adress_show10, 1, 1, 1, 1);
    gtk_widget_add_css_class(adress_show10, "label2");

    city_show10 = gtk_label_new("");
    gtk_widget_set_halign(city_show10, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), city_show10, 1, 2, 1, 1);
    gtk_widget_add_css_class(city_show10, "label2");

    birth_place_show10 = gtk_label_new("");
    gtk_widget_set_halign(birth_place_show10, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), birth_place_show10, 1, 3, 1, 1);
    gtk_widget_add_css_class(birth_place_show10, "label2");

    age_show10 = gtk_label_new("");
    gtk_widget_set_halign(age_show10, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), age_show10, 1, 4, 1, 1);
    gtk_widget_add_css_class(age_show10, "label2");

    birth_date_show10 = gtk_label_new("");
    gtk_widget_set_halign(birth_date_show10, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), birth_date_show10, 1, 5, 1, 1);
    gtk_widget_add_css_class(birth_date_show10, "label2");

    bpjs_show10 = gtk_label_new("");
    gtk_widget_set_halign(bpjs_show10, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), bpjs_show10, 1, 6, 1, 1);
    gtk_widget_add_css_class(bpjs_show10, "label2");

    patient_id_show10 = gtk_label_new("");
    gtk_widget_set_halign(patient_id_show10, GTK_ALIGN_START);
    gtk_grid_attach(GTK_GRID(grid), patient_id_show10, 1, 7, 1, 1);
    gtk_widget_add_css_class(patient_id_show10, "label2");

    //Menambahkan box untuk menampilkan warning
    GtkWidget* boxWarning2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    report_label10 = gtk_label_new("");
    gtk_widget_add_css_class(report_label10, "white-report");
    gtk_box_append(GTK_BOX(boxWarning2), report_label10);
    gtk_fixed_put(GTK_FIXED(fixed), boxWarning2, 660, 170);

    //Membuat grid untuk menampilkan riwayat medis pasien
    ScrollGrid10 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(ScrollGrid10), 5);
    gtk_grid_set_column_spacing(GTK_GRID(ScrollGrid10), 6);

    //Membuat supaya grid dapat digeser
    GtkWidget *scrolled_window = gtk_scrolled_window_new();
    gtk_widget_set_size_request(scrolled_window,550,400);
    gtk_fixed_put(GTK_FIXED(fixed), scrolled_window, 650, 300);
    displayAllPatientsAndRecords();

    //Menambahkan halaman 10 ke stack pada main window
    gtk_stack_add_named(GTK_STACK(stack), page, "Page_10");
    return page;
}

//Fungsi untuk menampilkan seluruh data pasien beserta riwayat medisnya
void displayAllPatientsAndRecords() {

    //Menghapus data pasien dan riwayat medis sebelumnya
    GtkWidget *child = gtk_widget_get_first_child(GTK_WIDGET(ScrollGrid10));
    while (child != NULL) {
        gtk_widget_unparent(child);
        child = gtk_widget_get_first_child(GTK_WIDGET(ScrollGrid10));
    }

    //Menampilkan data pasien dan riwayat medis
    GtkWidget *Medical_Data[6];
    gtk_label_set_text(GTK_LABEL(name_show10), patients[indexPatient10].name);
    gtk_label_set_text(GTK_LABEL(adress_show10), patients[indexPatient10].address);
    gtk_label_set_text(GTK_LABEL(city_show10), patients[indexPatient10].city);
    gtk_label_set_text(GTK_LABEL(birth_place_show10), patients[indexPatient10].birth_place);
    char str[20];
    sprintf(str, "%d", patients[indexPatient10].age);
    gtk_label_set_text(GTK_LABEL(age_show10), str);
    gtk_label_set_text(GTK_LABEL(birth_date_show10), patients[indexPatient10].birth_date);
    gtk_label_set_text(GTK_LABEL(bpjs_show10), patients[indexPatient10].bpjs);
    gtk_label_set_text(GTK_LABEL(patient_id_show10), patients[indexPatient10].patient_id);
    
    strcpy(patient_id10, patients[indexPatient10].patient_id);
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].patient_id, patient_id10) == 0) {
            sprintf(str, "%d", records[i].id);
            Medical_Data[0] = gtk_label_new(str);
            gtk_grid_attach(GTK_GRID(ScrollGrid10), Medical_Data[0], 0, i + 1, 1, 1);
            gtk_widget_add_css_class(Medical_Data[0], "label3");
            Medical_Data[1] = gtk_label_new(records[i].date);
            gtk_grid_attach(GTK_GRID(ScrollGrid10), Medical_Data[1], 1, i + 1, 1, 1);
            gtk_widget_add_css_class(Medical_Data[1], "label3");
            Medical_Data[2] = gtk_label_new(records[i].diagnosis);
            gtk_grid_attach(GTK_GRID(ScrollGrid10), Medical_Data[2], 2, i + 1, 1, 1);
            gtk_widget_add_css_class(Medical_Data[2], "label3");
            Medical_Data[3] = gtk_label_new(records[i].treatment);
            gtk_grid_attach(GTK_GRID(ScrollGrid10), Medical_Data[3], 3, i + 1, 1, 1);
            gtk_widget_add_css_class(Medical_Data[3], "label3");
            Medical_Data[4] = gtk_label_new(records[i].control_date);
            gtk_grid_attach(GTK_GRID(ScrollGrid10), Medical_Data[4], 4, i + 1, 1, 1);
            gtk_widget_add_css_class(Medical_Data[4], "label3");
            sprintf(str, "%d", records[i].cost);
            Medical_Data[5] = gtk_label_new(str);
            gtk_grid_attach(GTK_GRID(ScrollGrid10), Medical_Data[5], 5, i + 1, 1, 1);
            gtk_widget_add_css_class(Medical_Data[5], "label3");
        }
    }
}

//Fungsi untuk menampilkan data pasien berikutnya
void button_next(GtkButton *button, gpointer user_data){
    if(indexPatient10 >= patient_count-1){
        gtk_label_set_text(GTK_LABEL(report_label10), "*Tidak ada data pasien berikutnya");
    } else {
        gtk_label_set_text(GTK_LABEL(report_label10), "");
        indexPatient10++;
        displayAllPatientsAndRecords(button, user_data);
    }
}

//Fungsi untuk menampilkan data pasien sebelumnya
void button_prev(GtkButton *button, gpointer user_data){
    if(indexPatient10 <= 0){
        gtk_label_set_text(GTK_LABEL(report_label10), "*Tidak ada data pasien sebelumnya");
    } else {
        gtk_label_set_text(GTK_LABEL(report_label10), "");
        indexPatient10--;
        displayAllPatientsAndRecords(button, user_data);
    }
}