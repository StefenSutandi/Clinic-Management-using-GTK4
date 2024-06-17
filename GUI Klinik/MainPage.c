#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

GtkWidget* mainPage(){

    // Membuat box sebagai halaman utama
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-main");
    GtkWidget* fixed = addFixed(page);

    //Membuat grid untuk menyimpan menu-menu
    GtkWidget* grid = gtk_grid_new();
    gtk_widget_set_size_request(grid, 70, 70);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_fixed_put(GTK_FIXED(fixed), grid, 60, 180);

    //Menambahkan tombol-tombol berupa menu ke dalam grid
    GtkWidget* AddPatient = CreateButton("Tambah Pasien", grid, 1, 0, "user-avatar");
    g_signal_connect(AddPatient, "clicked", G_CALLBACK(go_to_Page_1), NULL);

    GtkWidget* ShowPatient = CreateButton("Tampilkan Pasien", grid, 3, 0, "id-card");
    g_signal_connect(ShowPatient, "clicked", G_CALLBACK(go_to_Page_2), NULL);

    GtkWidget* EditPatient = CreateButton("Ubah Pasien", grid, 1, 1, "settingdata");
    g_signal_connect(EditPatient, "clicked", G_CALLBACK(go_to_Page_3), NULL);

    GtkWidget* DeletePatient = CreateButton("Hapus Pasien", grid, 1, 2, "delete-user");
    g_signal_connect(DeletePatient, "clicked", G_CALLBACK(go_to_Page_4), NULL);

    GtkWidget* AddMedicalRecord = CreateButton("Tambah \nRiwayat Medis", grid, 2, 0, "medicaladd");
    g_signal_connect(AddMedicalRecord, "clicked", G_CALLBACK(go_to_Page_5), NULL);
    
    GtkWidget* ShowMedicalRecord =  CreateButton("Tampilkan \nRiwayat Medis", grid, 4, 0, "medicalrecord");
    g_signal_connect(ShowMedicalRecord, "clicked", G_CALLBACK(go_to_Page_8), NULL);

    GtkWidget* EditMedicalRecord =  CreateButton("Ubah \nRiwayat Medis", grid, 2, 1, "settinghealth");
    g_signal_connect(EditMedicalRecord, "clicked", G_CALLBACK(go_to_Page_6), NULL);

    GtkWidget* DeleteMedicalRecord =  CreateButton("Hapus \nRiwayat Medis", grid, 2, 2, "deletedocument");
    g_signal_connect(DeleteMedicalRecord, "clicked", G_CALLBACK(go_to_Page_7), NULL);

    GtkWidget* ShowFinancialReport =  CreateButton("Laporan Keuangan", grid, 3, 2, "money");
    g_signal_connect(ShowFinancialReport, "clicked", G_CALLBACK(go_to_Page_11), NULL);

    GtkWidget* ShowPatientDisease =  CreateButton("Informasi Seluruh \nPenyakit Pasien", grid, 3, 1, "disease");
    g_signal_connect(ShowPatientDisease, "clicked", G_CALLBACK(go_to_Page_10), NULL);

    GtkWidget* ShowPatientReturn =  CreateButton("Informasi Pasien \nKembali", grid, 4, 1, "time");
    g_signal_connect(ShowPatientReturn, "clicked", G_CALLBACK(go_to_Page_12), NULL);

    GtkWidget* ShowMedicalRecordInfo =  CreateButton("Laporan Riwayat \nMedis ", grid, 4, 2, "research");
    g_signal_connect(ShowMedicalRecordInfo, "clicked", G_CALLBACK(go_to_Page_9), NULL);
    
    GtkWidget* Exit = CreateButton("Keluar Program", grid, 5, 1, "logout");
    g_signal_connect(Exit, "clicked", G_CALLBACK(exit), NULL);

    GtkWidget* About = CreateButton("Developer", grid, 0, 1, "about");
    g_signal_connect(About, "clicked", G_CALLBACK(go_to_Page_13), NULL);

    // Menambahkan halaman ini ke dalam stack di main window
    gtk_stack_add_named(GTK_STACK(stack), page, "MainPage");
    return page;
}