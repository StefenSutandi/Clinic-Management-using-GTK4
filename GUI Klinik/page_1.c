#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

void addPatient(GtkButton *button, gpointer user_data);

//Inisialisasi box entri
GtkWidget *name_entry;
GtkWidget *adress_entry;
GtkWidget *city_entry;
GtkWidget *birth_place_entry;
GtkWidget *birth_date_entry;
GtkWidget *age_entry;
GtkWidget *bpjs_entry;
GtkWidget *patient_id_entry1;
GtkWidget *LabelWarning;

//Inisialisasi variabel sementara
char name_Temp[50];
char adress_Temp[50];
char city_Temp[50];
char birth_place_Temp[50];
char birth_date_Temp[50];
char age_Temp[50];
char bpjs_Temp[50];
char patient_id_Temp1[50];

GtkWidget* Page_1(){

    // Membuat box sebagai halaman pertama
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-page1");

    // Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed = addFixed(page);

    // Membuat tombol kembali ke halaman utama
    GtkWidget* BackButton = iconButton("icons/back.png", "Kembali ke menu utama","back-button","back-title");
    gtk_widget_set_size_request(BackButton, 240, 60);
    g_signal_connect(BackButton, "clicked", G_CALLBACK(on_go_to_main), NULL);
    gtk_fixed_put(GTK_FIXED(fixed), BackButton, 60, 50);

    // Membuat box untuk menyimpan seluruh entri
    GtkWidget *boxInput = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_size_request(boxInput, 300, 500);

    // Membuat masing-masing entri untuk memasukkan data pasien
    name_entry = gtk_entry_new();
    setinput(name_entry, "Masukkan nama lengkap pasien: ", boxInput,"icons/name.png");
    adress_entry = gtk_entry_new();
    setinput(adress_entry, "Masukkan alamat: ", boxInput,"icons/adress.png");
    city_entry = gtk_entry_new();
    setinput(city_entry, "Masukkan kota (contoh: Kota Palembang): ", boxInput,"icons/city.png");
    birth_place_entry = gtk_entry_new();
    setinput(birth_place_entry, "Masukkan tempat lahir (contoh: Kota Batam):", boxInput,"icons/city.png");
    birth_date_entry = gtk_entry_new();
    setinput(birth_date_entry, "Masukkan tanggal lahir (contoh: 28 April 1973): ", boxInput,"icons/date.png");
    age_entry = gtk_entry_new();
    setinput(age_entry, "Masukkan umur: ", boxInput,"icons/name.png");
    bpjs_entry = gtk_entry_new();
    setinput(bpjs_entry, "Masukkan nomor BPJS (format: 1234567xxx): ", boxInput,"icons/bpjs.png");
    patient_id_entry1 = gtk_entry_new();
    setinput(patient_id_entry1, "Masukkan ID pasien (format: 1230xxx): ", boxInput,"icons/id.png");
    gtk_fixed_put(GTK_FIXED(fixed), boxInput, 710, 90);

    // Membuat tombol simpan data
    GtkWidget *boxbutton = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    GtkWidget* save_button = gtk_button_new_with_label("Simpan Data");
    gtk_widget_set_size_request(save_button,150,50);
    gtk_widget_add_css_class(save_button, "save-button");
    gtk_box_append(GTK_BOX(boxbutton), save_button);
    gtk_fixed_put(GTK_FIXED(fixed), boxbutton, 850, 650);

    //Mengatur fungsi tombol ketika tombol simpan ditekan
    g_signal_connect(save_button, "clicked", G_CALLBACK(addPatient), name_entry);
    g_signal_connect(save_button, "clicked", G_CALLBACK(addPatient), adress_entry);
    g_signal_connect(save_button, "clicked", G_CALLBACK(addPatient), city_entry);
    g_signal_connect(save_button, "clicked", G_CALLBACK(addPatient), birth_place_entry);
    g_signal_connect(save_button, "clicked", G_CALLBACK(addPatient), birth_date_entry);
    g_signal_connect(save_button, "clicked", G_CALLBACK(addPatient), age_entry); 
    g_signal_connect(save_button, "clicked", G_CALLBACK(addPatient), bpjs_entry);
    g_signal_connect(save_button, "clicked", G_CALLBACK(addPatient), patient_id_entry1);

    //Memberikan label warning
    GtkWidget *boxWarning = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    LabelWarning = gtk_label_new("");
    gtk_box_append(GTK_BOX(boxWarning), LabelWarning);
    gtk_fixed_put(GTK_FIXED(fixed), boxWarning, 730, 620);

    // Menambahkan halaman ini ke dalam stack di main window
    gtk_stack_add_named(GTK_STACK(stack), page, "Page_1");
    return page;
}
    
//Fungsi untuk menambahkan pasien
void addPatient(GtkButton *button, gpointer user_data) {
    
    //Mengambil data dari entri
    GtkWidget *entry = GTK_WIDGET(user_data);
    gchar *data = g_strdup(gtk_editable_get_text(GTK_EDITABLE(entry)));
    GtkEntryBuffer *buffename = gtk_entry_get_buffer(GTK_ENTRY(name_entry));
    GtkEntryBuffer *bufferadress = gtk_entry_get_buffer(GTK_ENTRY(adress_entry));
    GtkEntryBuffer *buffercity = gtk_entry_get_buffer(GTK_ENTRY(city_entry));
    GtkEntryBuffer *bufferbirth_place = gtk_entry_get_buffer(GTK_ENTRY(birth_place_entry));
    GtkEntryBuffer *bufferbirth_date = gtk_entry_get_buffer(GTK_ENTRY(birth_date_entry));
    GtkEntryBuffer *bufferage = gtk_entry_get_buffer(GTK_ENTRY(age_entry));
    GtkEntryBuffer *bufferbpjs = gtk_entry_get_buffer(GTK_ENTRY(bpjs_entry));
    GtkEntryBuffer *bufferpatient_id = gtk_entry_get_buffer(GTK_ENTRY(patient_id_entry1));

    //Memasukkan data ke dalam variabel sementara
    gchar *dataTemps = "";
    dataTemps = data;
    char dataTemp[50];
    g_strlcpy(dataTemp, dataTemps, 50);

    //Memasukkan data ke masing-masing variabel sementara jika kondisi terpenuhi
    if (user_data == name_entry) {
        strcpy(name_Temp, dataTemp);
    } else if (user_data == adress_entry) {
        strcpy(adress_Temp, dataTemp);
    } else if (user_data == city_entry) {
        strcpy(city_Temp, dataTemp);
    } else if (user_data == birth_place_entry) {
        strcpy(birth_place_Temp, dataTemp);
    } else if (user_data == birth_date_entry) {
        strcpy(birth_date_Temp, dataTemp);
    } else if (user_data == age_entry) {
        strcpy(age_Temp, dataTemp);
    } else if (user_data == bpjs_entry) {
        strcpy(bpjs_Temp, dataTemp);
    } else if (user_data == patient_id_entry1) {
        strcpy(patient_id_Temp1, dataTemp);
    }

    //Mengecek apakah data sudah lengkap atau belum
    if (strcmp(name_Temp, "") != 0 && strcmp(adress_Temp, "") != 0 && strcmp(city_Temp, "") != 0 
             && strcmp(birth_place_Temp, "") != 0 && strcmp(birth_date_Temp, "") != 0 
             && strcmp(age_Temp, "") != 0 && strcmp(bpjs_Temp, "") != 0 && strcmp(patient_id_Temp1, "") != 0
             && atoi(age_Temp) > 0){
        if (patient_count >= MAX_PATIENTS) {
            gtk_label_set_text(GTK_LABEL(LabelWarning), "*Data pasien sudah penuh");
        }
        else{
            if (isDuplicatePatient(name_Temp, bpjs_Temp)) { //Mengecek apakah data pasien sudah ada atau belum
                gtk_label_set_text(GTK_LABEL(LabelWarning), "*Pasien dengan nama atau nomor BPJS tersebut sudah ada.");
            } 
            else {//Memasukkan data ke dalam struct
                patients[patient_count].id = patient_count +1;
                strcpy(patients[patient_count].name, name_Temp);
                strcpy(patients[patient_count].address, adress_Temp);
                strcpy(patients[patient_count].city, city_Temp);
                strcpy(patients[patient_count].birth_place, birth_place_Temp);
                strcpy(patients[patient_count].birth_date, birth_date_Temp);

                int day, year, month_number;
                char originalDate[MAX_STRING_LENGTH];
                char month[MAX_STRING_LENGTH];
                sscanf(birth_date_Temp, "%d %s %d", &day, month, &year);

                for(month_number = 0; month_number < 12 ; month_number++){
                    if (strcmp(month, months[month_number]) == 0){
                        month_number++;
                        break;
                    }
                }
                snprintf(patients[patient_count].birth_date, sizeof(patients[patient_count].birth_date), "%d-%d-%d", year, month_number, day);
                patients[patient_count].age = atoi(age_Temp);
                strcpy(patients[patient_count].bpjs, bpjs_Temp);
                strcpy(patients[patient_count].patient_id, patient_id_Temp1);

                //Menampilkan pesan data berhasil disimpan dan menghapus data pada entri
                gtk_label_set_text(GTK_LABEL(LabelWarning), "*Data berhasil disimpan");
                gtk_entry_buffer_set_text(buffename, "", -1);
                gtk_entry_buffer_set_text(bufferadress, "", -1);
                gtk_entry_buffer_set_text(buffercity, "", -1);
                gtk_entry_buffer_set_text(bufferbirth_place, "", -1);
                gtk_entry_buffer_set_text(bufferbirth_date, "", -1);
                gtk_entry_buffer_set_text(bufferage, "", -1);
                gtk_entry_buffer_set_text(bufferbpjs, "", -1);
                gtk_entry_buffer_set_text(bufferpatient_id, "", -1);

                patient_count++;
                WriteFileData();
            }
        }
    }
    else {
        //Menampilkan pesan data belum lengkap
        gtk_label_set_text(GTK_LABEL(LabelWarning), "*Data belum lengkap atau terdapat kesalahan input");
    }
}