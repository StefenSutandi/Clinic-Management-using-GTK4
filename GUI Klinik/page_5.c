#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

//Fungsi untuk menambahkan data riwayat medis
void addMedicalRecord(GtkButton *button, gpointer user_data);

//Inisialisasi entry
GtkWidget *date_entry;
GtkWidget* patient_id_entry;
GtkWidget *diagnosis_entry;
GtkWidget *treatment_entry;
GtkWidget *control_date_entry;
GtkWidget *cost_entry;
GtkWidget *report_label5;

//Inisialisasi variabel sementara
char date_Temp[50];
char patient_id_Temp[50];
char diagnosis_Temp[50];
char treatment_Temp[50];
char control_date_Temp[50];
char cost_Temp[50];

GtkWidget* Page_5(){

    // Membuat box sebagai halaman kelima
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-page5");

    // Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed = addFixed(page);

    // Membuat tombol kembali ke halaman utama
    GtkWidget* BackButton = iconButton("icons/back.png", "Kembali ke menu utama","back-button","back-title");
    gtk_widget_set_size_request(BackButton, 240, 60);
    g_signal_connect(BackButton, "clicked", G_CALLBACK(on_go_to_main), NULL);

    // Membuat box untuk menyimpan seluruh entri
    GtkWidget *boxInput = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_size_request(boxInput, 300, 500);

    date_entry = gtk_entry_new();
    setinput(date_entry, "Masukkan tanggal (contoh: 1 Januari 2022): ", boxInput, "icons/date.png");
    patient_id_entry = gtk_entry_new();
    diagnosis_entry = gtk_entry_new();
    setinput(diagnosis_entry, "Masukkan diagnosis: ", boxInput, "icons/sick.png");
    treatment_entry = gtk_entry_new();
    setinput(treatment_entry, "Masukkan tindakan: ", boxInput, "icons/cure.png");
    control_date_entry = gtk_entry_new();
    setinput(control_date_entry, "Masukkan tanggal kontrol (contoh: 4 Januari 2022): ", boxInput, "icons/date.png");
    cost_entry = gtk_entry_new();
    setinput(cost_entry, "Masukkan biaya: ", boxInput, "icons/cost.png");
    gtk_fixed_put(GTK_FIXED(fixed), boxInput, 710, 90);

    //Membuat tombol simpan data
    GtkWidget* save_button = gtk_button_new_with_label("Simpan Data");
    gtk_widget_set_size_request(save_button,150,50);
    gtk_widget_add_css_class(save_button, "save-button");
    gtk_fixed_put(GTK_FIXED(fixed), save_button, 850, 535);

    //Memanggil fungsi addMedicalRecord ketika tombol save ditekan
    g_signal_connect(save_button, "clicked", G_CALLBACK(addMedicalRecord), patient_id_entry);
    g_signal_connect(save_button, "clicked", G_CALLBACK(addMedicalRecord), date_entry);
    g_signal_connect(save_button, "clicked", G_CALLBACK(addMedicalRecord), diagnosis_entry);
    g_signal_connect(save_button, "clicked", G_CALLBACK(addMedicalRecord), treatment_entry);
    g_signal_connect(save_button, "clicked", G_CALLBACK(addMedicalRecord), control_date_entry);
    g_signal_connect(save_button, "clicked", G_CALLBACK(addMedicalRecord), cost_entry);
    
    //Tambahkan box untuk Warning
    GtkWidget *boxWarning = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    report_label5 = gtk_label_new("");
    gtk_box_append(GTK_BOX(boxWarning), report_label5);

    //Menambahkan halaman 5 ke stack pada main window 
    gtk_stack_add_named(GTK_STACK(stack), page, "Page_5");
    return page;
}

//Fungsi untuk menambahkan data riwayat medis
void addMedicalRecord(GtkButton *button, gpointer user_data) {

    //Mengambil data dari entry
    GtkWidget *entry = gtk_widget_get_root(user_data);
    gchar *data = g_strdup(gtk_editable_get_text(GTK_EDITABLE_LABEL(entry)));
    GtkEntryBuffer *bufferpatient_id = gtk_entry_get_buffer(GTK_ENTRY(patient_id_entry));
    GtkEntryBuffer *bufferdate = gtk_entry_get_buffer(GTK_ENTRY(date_entry));
    GtkEntryBuffer *bufferdiagnosis = gtk_entry_get_buffer(GTK_ENTRY(diagnosis_entry));
    GtkEntryBuffer *buffertreatment = gtk_entry_get_buffer(GTK_ENTRY(treatment_entry));
    GtkEntryBuffer *buffercontrol_date = gtk_entry_get_buffer(GTK_ENTRY(control_date_entry));
    GtkEntryBuffer *buffercost = gtk_entry_get_buffer(GTK_ENTRY(cost_entry));

    //Mengambil data dari entry dan menyimpannya ke variabel sementara
    gchar *dataTemps = "";
    dataTemps = data;
    char dataTemp[50];
    g_strlcpy(dataTemp, dataTemps, 50);

    if (user_data == patient_id_entry){
        g_strlcpy(patient_id_Temp, dataTemp, 50);
    } else if (user_data == date_entry){
        g_strlcpy(date_Temp, dataTemp, 50);
    } else if (user_data == diagnosis_entry){
        g_strlcpy(diagnosis_Temp, dataTemp, 50);
    } else if (user_data == treatment_entry){
        g_strlcpy(treatment_Temp, dataTemp, 50);
    } else if (user_data == control_date_entry){
        g_strlcpy(control_date_Temp, dataTemp, 50);
    } else if (user_data == cost_entry){
        g_strlcpy(cost_Temp, dataTemp, 50);
    }

    //Memasukkan data ke dalam struct jika kondisi terpenuhi
    if (strcmp(date_Temp, "") !=0 && strcmp(diagnosis_Temp, "") !=0 && 
        strcmp(treatment_Temp, "") !=0 && strcmp(control_date_Temp, "") !=0 && 
        strcmp(cost_Temp, "") !=0){ //
        
        if (record_count >= MAX_RECORDS) {
            gtk_label_set_text(GTK_LABEL(report_label5), "*Data sudah penuh.");
        }
        else {
            MedicalRecord new_record;
            new_record.id = record_count + 1;
            
            int day, year;
            char month[MAX_STRING_LENGTH];
            int month_number = 0;

            sscanf(date_Temp, "%d %s %d", &day, month, &year);
            for (month_number; month_number < 12; month_number++){
                if (strcmp(months[month_number], month) == 0){
                    month_number = month_number + 1;
                    break;
                }
            }
            snprintf(new_record.date, sizeof(new_record.date), "%d-%d-%d", year, month_number, day);

            strcpy(new_record.patient_id, patient_id_Temp);
            strcpy(new_record.diagnosis, diagnosis_Temp);
            strcpy(new_record.treatment, treatment_Temp);

            sscanf(control_date_Temp, "%d %s %d", &day, month, &year);
            for (month_number = 0; month_number < 12; month_number++){
                if (strcmp(months[month_number], month) == 0){
                    month_number = month_number + 1;
                    break;
                }
            }
            snprintf(new_record.control_date, sizeof(new_record.control_date), "%d-%d-%d", year, month_number, day);

            new_record.cost = atoi(cost_Temp);
            records[record_count++] = new_record;

            gtk_entry_buffer_set_text(bufferpatient_id, "", -1);
            gtk_entry_buffer_set_text(bufferdate, "", -1);
            gtk_entry_buffer_set_text(bufferdiagnosis, "", -1);
            gtk_entry_buffer_set_text(buffertreatment, "", -1);
            gtk_entry_buffer_set_text(buffercontrol_date, "", -1);
            gtk_entry_buffer_set_text(buffercost, "", -1);
            WriteFileRecord();
            gtk_label_set_text(GTK_LABEL(report_label5), "*Riwayat medis berhasil ditambahkan.");
        }
    }

    else {
        gtk_label_set_text(GTK_LABEL(report_label5), "*Data tidak lengkap.");
    }
}