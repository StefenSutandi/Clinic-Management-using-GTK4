#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

//Inisialisasi stack untuk menyimpan subhalaman
GtkWidget *stack6;
GtkWidget *page6_1;
GtkWidget *page6_2;
GtkWidget* Page6_1();
GtkWidget* Page6_2();

//Fungsi untuk mencari riwayat medis dan mengubahnya
void findRecord(GtkButton *button, gpointer user_data);
void updateMedicalRecord(GtkButton *button, gpointer user_data);

//Inisialisasi box entri
GtkWidget *date_entry6;
GtkWidget *patient_id_entry6;
GtkWidget *diagnosis_entry6;
GtkWidget *treatment_entry6;
GtkWidget *control_date_entry6;
GtkWidget *cost_entry6;
GtkWidget *report_label6_1;
GtkWidget *report_label6_2;

//Inisialisasi variabel sementara
int indexRecord6;
char date_Temp6[50];
char patient_id_Temp6[50];
char diagnosis_Temp6[50];
char treatment_Temp6[50];
char control_date_Temp6[50];
char cost_Temp6[50];

GtkWidget* Page_6() {

    // Membuat box sebagai halaman ke-6
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    
    //Membuat stack untuk menyimpan subhalaman 6
    stack6 = gtk_stack_new();
    gtk_stack_set_transition_type(GTK_STACK(stack6), GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
    gtk_box_append(GTK_BOX(page), stack6);

    // Membuat Halaman 1 dari menu 6
    page6_1 = Page6_1();

    // Membut Halaman 2 dari menu 6
    page6_2 = Page6_2();

    // Menambahkan halaman 6 ke stack pada main window
    gtk_stack_add_named(GTK_STACK(stack), page, "Page_6");

    return page;
}

//  Fungsi untuk mencari riwayat medis
void findRecord(GtkButton *button, gpointer user_data){

    //Mengambil data dari entri
    GtkWidget *entry = gtk_widget_paintable_new(user_data);
    gchar *data = g_strdup(gtk_editable_get_text(GTK_EDITABLE(entry)));
    GtkEntryBuffer *bufferId = gtk_entry_get_buffer(GTK_ENTRY_BUFFER_CLASS(entry));

    //Mencari riwayat medis berdasarkan ID
    char temp_id[5];
    g_strlcpy(temp_id, data, sizeof(temp_id));
    int record_id = atoi(temp_id);
    indexRecord6 = findMedicalRecordById(record_id);

    if (indexRecord6 == -1) {
        gtk_label_set_text(GTK_LABEL(report_label6_1), "*Riwayat medis tidak ditemukan");

    } else {
        gtk_label_set_text(GTK_LABEL(report_label6_1), "");
        // Menampilkan subhalaman 2 jika data ditemukan
    }
    // Mengosongkan entri
    gtk_entry_buffer_set_text(bufferId, "", -1);
}

GtkWidget* Page6_1(){

    //Membuat box sebagai subhalaman 6.1
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_size_request(page, 1300, 762);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-page3_1");

    //Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed1 = addFixed(page);

    //Membuat box input ID
    GtkWidget *box_id = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_size_request(box_id, 500, 50);
    GtkWidget *entry_Id = gtk_entry_new();
    setinput(entry_Id, "Masukkan ID riwayat medis yang ingin diubah:", box_id, "icons/id.png");

    //Membuat tombol kembali ke menu utama
    GtkWidget* BackButton = iconButton("icons/back.png", "Kembali ke menu utama", "back-button", "back-title");
    gtk_widget_set_size_request(BackButton, 240, 60);

    //Kembali ke menu utama ketika tombol diklik
    g_signal_connect(BackButton, "clicked", G_CALLBACK(on_go_to_main), NULL);

    //Membuat tombol cari data pasien
    GtkWidget* show_button = iconButton("icons/find.png", "Cari Data", "find-button", "find-title");
    gtk_widget_set_size_request(show_button,150,50);

    //Memanggil fungsi findRecord ketika tombol cari data pasien ditekan
    g_signal_connect(show_button, "clicked", G_CALLBACK(findRecord), entry_Id);   

    //Membuat box untuk menampilkan pesan
    GtkWidget* box_report = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    report_label6_1 = addReport(box_report);
    gtk_widget_add_css_class(report_label6_1, "white-report");
    gtk_fixed_put(GTK_FIXED(fixed1), box_report, 350, 230);

    //Menambahkan subhalaman 6.1 ke stack pada halaman 6
    gtk_stack_add_named(GTK_STACK(stack6), page, "Page_6_1");
    return page;
}

GtkWidget* Page6_2(){

    //Membuat box sebagai subhalaman 6.2
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_size_request(page, 1300, 760);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-page5");

    //Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed = addFixed(page);

    //Membuat box untuk menyiapkan entri
    GtkWidget *boxInput = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_size_request(boxInput, 300, 500);
    gtk_fixed_put(GTK_FIXED(fixed), boxInput, 710, 90);

    date_entry6 = gtk_entry_new();
    setinput(date_entry6, "Masukkan tanggal baru (contoh: 1 Januari 2022): ", boxInput, "icons/date.png");
    patient_id_entry6 = gtk_entry_new();
    setinput(patient_id_entry6, "Masukkan ID pasien baru : ", boxInput,"icons/id.png");
    diagnosis_entry6 = gtk_entry_new();
    setinput(diagnosis_entry6, "Masukkan diagnosis baru : ", boxInput, "icons/sick.png");
    treatment_entry6 = gtk_entry_new();
    setinput(treatment_entry6, "Masukkan tindakan baru : ", boxInput, "icons/cure.png");
    control_date_entry6 = gtk_entry_new();
    setinput(control_date_entry6, "Masukkan tanggal kontrol baru (contoh: 4 Januari 2022): ", boxInput, "icons/date.png");
    cost_entry6 = gtk_entry_new();
    setinput(cost_entry6, "Masukkan biaya baru : ", boxInput, "icons/cost.png");

    //Membuat tombol simpan data
    GtkWidget* save_button = gtk_button_new_with_label("Simpan Data");
    gtk_widget_set_size_request(save_button,150,50);
    gtk_widget_add_css_class(save_button, "save-button");
    gtk_fixed_put(GTK_FIXED(fixed), save_button, 850, 535);

    //Memanggil fungsi updateMedicalRecord ketika tombol simpan ditekan
    g_signal_connect(save_button, "clicked", G_CALLBACK(updateMedicalRecord), patient_id_entry6);
    g_signal_connect(save_button, "clicked", G_CALLBACK(updateMedicalRecord), date_entry6);
    g_signal_connect(save_button, "clicked", G_CALLBACK(updateMedicalRecord), diagnosis_entry6);
    g_signal_connect(save_button, "clicked", G_CALLBACK(updateMedicalRecord), treatment_entry6);
    g_signal_connect(save_button, "clicked", G_CALLBACK(updateMedicalRecord), control_date_entry6);
    g_signal_connect(save_button, "clicked", G_CALLBACK(updateMedicalRecord), cost_entry6);

    //Membuat box untuk menampilkan pesan
    GtkWidget* box_report = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    report_label6_2 = addReport(box_report);
    gtk_fixed_put(GTK_FIXED(fixed), box_report, 730, 490);

    //Menambahkan subhalaman 6.2 ke stack pada halaman 6
    gtk_stack_add_named(GTK_STACK(stack6), page, "Page_6_2");

    return page;
}

//Fungsi untuk mengubah data riwayat medis
void updateMedicalRecord(GtkButton *button, gpointer user_data) {

    //Mengambil data dari entri
    GtkWidget *entry = GTK_WIDGET(user_data);
    gchar *data = g_strdup(gtk_editable_get_text(GTK_EDITABLE(entry)));
    GtkEntryBuffer *bufferpatient_id = gtk_entry_get_buffer(GTK_ENTRY(patient_id_entry6));
    GtkEntryBuffer *bufferdate = gtk_entry_get_buffer(GTK_ENTRY(date_entry6));
    GtkEntryBuffer *bufferdiagnosis = gtk_entry_get_buffer(GTK_ENTRY(diagnosis_entry6));
    GtkEntryBuffer *buffertreatment = gtk_entry_get_buffer(GTK_ENTRY(treatment_entry6));
    GtkEntryBuffer *buffercontrol_date = gtk_entry_get_buffer(GTK_ENTRY(control_date_entry6));
    GtkEntryBuffer *buffercost = gtk_entry_get_buffer(GTK_ENTRY(cost_entry6));

    //Menyimpan data ke variabel sementara
    gchar *dataTemps = "";
    dataTemps = data;
    char dataTemp[50];
    g_strlcpy(dataTemp, dataTemps, 50);

    if (user_data == patient_id_entry6){
        g_strlcpy(patient_id_Temp6, dataTemp, 50);
    } else if (user_data == date_entry6){
        g_strlcpy(date_Temp6, dataTemp, 50);
    } else if (user_data == diagnosis_entry6){
        g_strlcpy(diagnosis_Temp6, dataTemp, 50);
    } else if (user_data == treatment_entry6){
        g_strlcpy(treatment_Temp6, dataTemp, 50);
    } else if (user_data == control_date_entry6){
        g_strlcpy(control_date_Temp6, dataTemp, 50);
    } else if (user_data == cost_entry6){
        g_strlcpy(cost_Temp6, dataTemp, 50);
    }

    //Mengubah data riwayat medis jika data lengkap
    if (strcmp(date_Temp6, "") !=0 && strcmp(diagnosis_Temp6, "") !=0 && 
        strcmp(treatment_Temp6, "") !=0 && strcmp(control_date_Temp6, "") !=0 && 
        strcmp(cost_Temp6, "") !=0){
        
        MedicalRecord *r = &records[indexRecord6];
        
        int day, year;
        char month[MAX_STRING_LENGTH];
        int month_number = 0;
        sscanf(date_Temp6, "%d %s %d", &day, month, &year);
        for (month_number = 0; month_number < 12; month_number++){
            if (strcmp(months[month_number], month) == 0){
                month_number = month_number + 1;
                break;
            }
        }
        snprintf(r->date, sizeof(r->date), "%d-%d-%d", year, month_number, day);

        strcpy(r->patient_id, patient_id_Temp6);
        strcpy(r->diagnosis, diagnosis_Temp6);
        strcpy(r->treatment, treatment_Temp6);

        sscanf(control_date_Temp6, "%d %s %d", &day, month, &year);
        for (month_number = 0; month_number < 12; month_number++){
            if (strcmp(months[month_number], month) == 0){
                month_number = month_number + 1;
                break;
            }
        }
        snprintf(r->control_date, sizeof(r->control_date), "%d-%d-%d", year, month_number, day);
        r->cost = atoi(cost_Temp6);
        WriteFileRecord();

        gtk_entry_buffer_set_text(bufferpatient_id, "", -1);
        gtk_entry_buffer_set_text(bufferdate, "", -1);
        gtk_entry_buffer_set_text(bufferdiagnosis, "", -1);
        gtk_entry_buffer_set_text(buffertreatment, "", -1);
        gtk_entry_buffer_set_text(buffercontrol_date, "", -1);
        gtk_entry_buffer_set_text(buffercost, "", -1);

        gtk_label_set_text(GTK_LABEL(report_label6_2), "");
        gtk_stack_set_visible_child(GTK_STACK(stack6), page6_1);
        gtk_stack_set_visible_child(GTK_STACK(stack), MainPage); //Kembali ke menu utama
    }
    else {
        gtk_label_set_text(GTK_LABEL(report_label6_2), "*Data tidak lengkap.");
    }
}