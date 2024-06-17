#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

//Fungsi untuk menampilkan laporan pasien beserta riwayat medis bulanan dan tahunan
void getRevenueDisease(GtkButton *button, gpointer user_data);

//Deklarasi label untuk menampilkan laporan
GtkWidget *MonthlyShow9;
GtkWidget *AnnualShow9;

//Deklarasi grid untuk menampilkan data pasien dan riwayat medis
typedef struct {
    char name[50];
    int count;
} diseasekind;

//Deklarasi grid untuk menampilkan data pasien dan riwayat medis
GtkWidget *ScrollGrid9;
GtkWidget *ScrollGrid9_2;
GtkWidget *ScrollGrid9_3;
GtkWidget *ScrollGrid9_4;

GtkWidget* Page_9() {

    //Membuat page untuk halaman 9
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-page9");

    //Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed = addFixed(page);

    // Membuat tombol kembali ke halaman utama
    GtkWidget* BackButton = iconButton("icons/back.png", "Kembali ke menu utama", "back-button", "back-title");
    gtk_widget_set_size_request(BackButton, 240, 60);
    g_signal_connect(BackButton, "clicked", G_CALLBACK(on_go_to_main), NULL);

    GtkWidget *month_spin;
    GtkAdjustment *month_adj = gtk_adjustment_new(1, 1, 12, 1, 1, 0);
    month_spin = gtk_spin_button_new(month_adj, 1, 0);
    gtk_widget_add_css_class(month_spin, "spin-button");

    GtkWidget *year_spin;
    GtkAdjustment *year_adj = gtk_adjustment_new(2023, 1900, 2100, 1, 10, 0);
    year_spin = gtk_spin_button_new(year_adj, 1, 0);
    gtk_widget_add_css_class(year_spin, "spin-button");

    g_object_set_data(G_OBJECT(month_spin), "year_spin", year_spin);
    gtk_fixed_put(GTK_FIXED(fixed), month_spin, 520, 100);
    gtk_fixed_put(GTK_FIXED(fixed), year_spin, 650, 100);

    // Membuat tombol untuk menampilkan laporan
    GtkWidget* show_button = iconButton("icons/finds.png", "Cari Laporan", "report-button", "report-title");
    gtk_widget_set_size_request(show_button,150,50);
    gtk_fixed_put(GTK_FIXED(fixed), show_button, 820, 96);

    // Memanggil fungsi getRevenueDisease ketika tombol ditekan
    g_signal_connect(show_button, "clicked", G_CALLBACK(getRevenueDisease), month_spin);

    // Membuat label untuk menampilkan laporan pasien beserta riwayat medis bulanan dan tahunan
    MonthlyShow9 = gtk_label_new("");
    gtk_widget_set_size_request(MonthlyShow9, 500, 50);
    gtk_fixed_put(GTK_FIXED(fixed), MonthlyShow9, 400, 300);

    AnnualShow9 = gtk_label_new("");
    gtk_widget_set_size_request(AnnualShow9, 500, 50);

    // Membuat grid untuk menampilkan data pasien dan riwayat medis bulanan
    ScrollGrid9 = gtk_grid_new();
    gtk_grid_set_column_spacing(GTK_GRID(ScrollGrid9), 20);
    
    // Membuat grid dapat digeser
    GtkWidget *scrolled_window = gtk_scrolled_window_new();
    gtk_widget_set_size_request(scrolled_window,380,130);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window), ScrollGrid9);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_fixed_put(GTK_FIXED(fixed), scrolled_window, 200, 320);
    gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(scrolled_window), FALSE);

    // Membuat grid untuk menampilkan data pasien dan riwayat medis tahunan
    ScrollGrid9_2 = gtk_grid_new();
    gtk_grid_set_column_spacing(GTK_GRID(ScrollGrid9_2), 20);
    
    // Membuat grid dapat digeser
    GtkWidget *scrolled_window2 = gtk_scrolled_window_new();
    gtk_widget_set_size_request(scrolled_window2,380,130);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window2), ScrollGrid9_2);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window2), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_fixed_put(GTK_FIXED(fixed), scrolled_window2, 800, 320);
    gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(scrolled_window2), FALSE);

    // Membuat grid untuk menampilkan grafik riwayat medis bulanan
    ScrollGrid9_3 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(ScrollGrid9_3), 10);
    gtk_grid_set_column_spacing(GTK_GRID(ScrollGrid9_3), 20);

    // Membuat grid dapat digeser
    GtkWidget *scrolled_window3 = gtk_scrolled_window_new();
    gtk_widget_set_size_request(scrolled_window3,350,90);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window3), ScrollGrid9_3);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window3), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_fixed_put(GTK_FIXED(fixed), scrolled_window3, 220, 600);
    gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(scrolled_window3), FALSE);

    // Membuat grid untuk menampilkan grafik riwayat medis tahunan
    ScrollGrid9_4 = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(ScrollGrid9_4), 10);
    gtk_grid_set_column_spacing(GTK_GRID(ScrollGrid9_4), 20);

    // Membuat grid dapat digeser
    GtkWidget *scrolled_window4 = gtk_scrolled_window_new();
    gtk_widget_set_size_request(scrolled_window4,350,90);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window4), ScrollGrid9_4);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window4), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_fixed_put(GTK_FIXED(fixed), scrolled_window4, 820, 600);
    gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(scrolled_window4), FALSE);

    // Menambahkan halaman 9 ke stack pada main window
    gtk_stack_add_named(GTK_STACK(stack), page, "Page_9");
    return page;
}

//Fungsi untuk menampilkan laporan pasien beserta riwayat medis bulanan dan tahunan
void getRevenueDisease(GtkButton *button, gpointer user_data) {

    //Mendeklarasikan variabel untuk menyimpan data pasien dan riwayat medis
    diseaseKind diseaseKinds[100];
    diseaseKind diseaseKinds2[100];

    //Mengosongkan tampilan data pasien dan riwayat medis
    clearGrids(ScrollGrid9);
    clearGrids(ScrollGrid9_2);
    clearGrids(ScrollGrid9_3);
    clearGrids(ScrollGrid9_4);

    //Mendeklarasikan variabel untuk menyimpan data pasien dan riwayat medis
    GtkWidget *Medical_Data[2];
    GtkWidget *GraphShow[3];

    // Mendapatkan data dari input bulan dan tahun
    GtkWidget *month_spin = GTK_WIDGET(user_data);
    GtkWidget *year_spin = g_object_get_data(G_OBJECT(month_spin), "year_spin");

    int month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month_spin));
    int year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(year_spin));

    // Menghitung total pendapatan bulanan, tahunan, dan rata-rata pendapatan per tahun
    int row =0;
    int DiseaseCount = 0;
    for (int i = 0; i < record_count; i++) {
        int rec_year, rec_month, rec_day;
        sscanf(records[i].date, "%4d-%2d-%2d", &rec_year, &rec_month, &rec_day);
        if (rec_year == year && rec_month == month) {
            int patient_index = findPatientById(records[i].patient_id);
            if (patient_index != -1) {
                Medical_Data[0] = gtk_label_new(patients[patient_index].name);
                gtk_grid_attach(GTK_GRID(ScrollGrid9), Medical_Data[0], 0, row, 1, 1);
                gtk_widget_set_halign(Medical_Data[0], GTK_ALIGN_START);
                gtk_widget_add_css_class(Medical_Data[0], "label4");
                Medical_Data[1] = gtk_label_new(records[i].diagnosis);
                gtk_widget_set_halign(Medical_Data[1], GTK_ALIGN_START);
                gtk_grid_attach(GTK_GRID(ScrollGrid9), Medical_Data[1], 1, row , 1, 1);
                gtk_widget_add_css_class(Medical_Data[1], "label4");
                row++;

                if (DiseaseCount == 0) {
                    strcpy(diseaseKinds[DiseaseCount].name, records[i].diagnosis);
                    diseaseKinds[DiseaseCount].count = 1;
                    DiseaseCount++;
                } else {
                    for (int j = 0; j < DiseaseCount; j++) {
                        if (strcmp(diseaseKinds[j].name, records[i].diagnosis) == 0) {
                            diseaseKinds[j].count++;
                            break;
                        } else if (j == DiseaseCount - 1) {
                            strcpy(diseaseKinds[DiseaseCount].name, records[i].diagnosis);
                            diseaseKinds[DiseaseCount].count = 1;
                            DiseaseCount++;
                            break;
                        }
                    }
                }

            }
        }
    }
    int totalDisease = 0;
    for (int i = 0; i < DiseaseCount; i++) {
        totalDisease += diseaseKinds[i].count;
    }

    for (int i = 0; i < DiseaseCount; i++) {
        int count = diseaseKinds[i].count * 10 / totalDisease;
        char text[100]="";
        for (int j = 0; j < count; j++) {
            strcat(text, "██");
        }
        GraphShow[0] = gtk_label_new(diseaseKinds[i].name);
        GraphShow[1] = gtk_label_new(text);
        gtk_widget_set_halign(GraphShow[0], GTK_ALIGN_START);
        gtk_widget_set_halign(GraphShow[1], GTK_ALIGN_START); 

        count = diseaseKinds[i].count;
        char str[4];
        sprintf(str, "%d", count);
        GraphShow[2] = gtk_label_new(str);
        gtk_widget_set_halign(GraphShow[1], GTK_ALIGN_START); 

        if (i % 2 == 0) {
            gtk_widget_add_css_class(GraphShow[0], "graphblue");
            gtk_widget_add_css_class(GraphShow[1], "graphblue");
            gtk_widget_add_css_class(GraphShow[2], "graphblue");
        } else {
            gtk_widget_add_css_class(GraphShow[0], "graphgreen");
            gtk_widget_add_css_class(GraphShow[1], "graphgreen");
            gtk_widget_add_css_class(GraphShow[2], "graphgreen");
        }
        gtk_grid_attach(GTK_GRID(ScrollGrid9_3), GraphShow[0], 0, i, 1, 1);
        gtk_grid_attach(GTK_GRID(ScrollGrid9_3), GraphShow[1], 1, i, 1, 1);
        gtk_grid_attach(GTK_GRID(ScrollGrid9_3), GraphShow[2], 2, i, 1, 1);
    }

    
    row = 0;
    DiseaseCount = 0;
    for (int i = 0; i < record_count; i++) {
        int rec_year, rec_month, rec_day;
        sscanf(records[i].date, "%4d-%2d-%2d", &rec_year, &rec_month, &rec_day);
        if (rec_year == year) {
            int patient_index = findPatientById(records[i].patient_id);
            if (patient_index != -1) {
                Medical_Data[0] = gtk_label_new(patients[patient_index].name);
                gtk_widget_set_halign(Medical_Data[0], GTK_ALIGN_START);
                gtk_grid_attach(GTK_GRID(ScrollGrid9_2), Medical_Data[0], 0, row, 1, 1);
                gtk_widget_add_css_class(Medical_Data[0], "label4");
                Medical_Data[1] = gtk_label_new(records[i].diagnosis);
                gtk_widget_set_halign(Medical_Data[1], GTK_ALIGN_START);
                gtk_grid_attach(GTK_GRID(ScrollGrid9_2), Medical_Data[1], 1, row , 1, 1);
                gtk_widget_add_css_class(Medical_Data[1], "label4");
                row++;

                if (DiseaseCount == 0) {
                    strcpy(diseaseKinds2[DiseaseCount].name, records[i].diagnosis);
                    diseaseKinds2[DiseaseCount].count = 1;
                    DiseaseCount++;
                } else {
                    for (int j = 0; j < DiseaseCount; j++) {
                        if (strcmp(diseaseKinds2[j].name, records[i].diagnosis) == 0) {
                            diseaseKinds2[j].count++;
                            break;
                        } else if (j == DiseaseCount - 1) {
                            strcpy(diseaseKinds2[DiseaseCount].name, records[i].diagnosis);
                            diseaseKinds2[DiseaseCount].count = 1;
                            DiseaseCount++;
                            break;
                        }
                    }
                }
            }
        }
    }

    totalDisease = 0;
    for (int i = 0; i < DiseaseCount; i++) {
        totalDisease += diseaseKinds2[i].count;
    }

    for (int i = 0; i < DiseaseCount; i++) {
        int count = diseaseKinds2[i].count * 15 / totalDisease;
        char text[100]="";
        for (int j = 0; j < count; j++) {
            strcat(text, "███");
        }
        GraphShow[0] = gtk_label_new(diseaseKinds2[i].name);
        GraphShow[1] = gtk_label_new(text);
        gtk_widget_set_halign(GraphShow[0], GTK_ALIGN_START);
        gtk_widget_set_halign(GraphShow[1], GTK_ALIGN_START); 

        count = diseaseKinds2[i].count;
        char str[4];
        sprintf(str, "%d", count);
        GraphShow[2] = gtk_label_new(str);
        gtk_widget_set_halign(GraphShow[1], GTK_ALIGN_START); 

        if (i % 2 == 0) {
            gtk_widget_add_css_class(GraphShow[0], "graphblue");
            gtk_widget_add_css_class(GraphShow[1], "graphblue");
            gtk_widget_add_css_class(GraphShow[2], "graphblue");
        } else {
            gtk_widget_add_css_class(GraphShow[0], "graphgreen");
            gtk_widget_add_css_class(GraphShow[1], "graphgreen");
            gtk_widget_add_css_class(GraphShow[2], "graphgreen");
        }
        gtk_grid_attach(GTK_GRID(ScrollGrid9_4), GraphShow[0], 0, i, 1, 1);
        gtk_grid_attach(GTK_GRID(ScrollGrid9_4), GraphShow[1], 1, i, 1, 1);
        gtk_grid_attach(GTK_GRID(ScrollGrid9_4), GraphShow[2], 2, i, 1, 1);
    }

}