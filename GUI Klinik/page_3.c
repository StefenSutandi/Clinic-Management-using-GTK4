#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

//Inisialisasi stack untuk menyimpan sub halaman 3
GtkWidget *stack3;
GtkWidget *page3_1;
GtkWidget *page3_2;
GtkWidget* Page3_1();
GtkWidget* Page3_2();

// Fungsi untuk mencari data pasien dan mengubah data pasien
void findPatient(GtkButton *button, gpointer user_data);
void updatePatient(GtkButton *button, gpointer user_data);

//Inisialisasi box entri
GtkWidget *name_entry3;
GtkWidget *adress_entry3;
GtkWidget *city_entry3;
GtkWidget *birth_place_entry3;
GtkWidget *birth_date_entry3;
GtkWidget *age_entry3;
GtkWidget *bpjs_entry3;
GtkWidget *patient_id_entry3;
GtkWidget *report_label3_1;
GtkWidget *report_label3_2;

//Inisialisasi variabel sementara
int indexPatient3;
char name_Temp3[50];
char adress_Temp3[50];
char city_Temp3[50];
char birth_place_Temp3[50];
char birth_date_Temp3[50];
char age_Temp3[50];
char bpjs_Temp3[50];
char patient_id_Temp3[50];

GtkWidget* Page_3() {

    // Membuat box sebagai halaman ketiga
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 200);

    // Membuat stack untuk menyimpan sub halaman 3
    stack3 = gtk_stack_new();
    gtk_stack_set_transition_type(GTK_STACK(stack3), GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
    gtk_box_append(GTK_BOX(page), stack3);

    // Membuat sub halaman 1 dari halaman 3
    page3_1 = Page3_1();

    // Membut sub halaman 2 dari halaman 3
    page3_2 = Page3_2();

    // Menambahkan halaman 3 ke dalam stack di main window
    gtk_stack_add_named(GTK_STACK(stack), page, "Page_3");
    return page;
}

// Fungsi untuk mencari data pasien
void findPatient(GtkButton *button, gpointer user_data){
    
    // Mengambil data dari entri ID pasien
    GtkWidget *entry = GTK_WIDGET(user_data);
    gchar *data = g_strdup(gtk_editable_get_text(GTK_EDITABLE(entry)));
    GtkEntryBuffer *bufferId = gtk_entry_get_buffer(GTK_ENTRY(entry));

    // Mencari data pasien berdasarkan ID pasien
    char patient_id[15];
    g_strlcpy(patient_id, data, sizeof(patient_id));
    indexPatient3 = findPatientById(patient_id);

    if (indexPatient3 == -1) { //Menampilkan pesan jika pasien tidak ditemukan
        gtk_label_set_text(GTK_LABEL(report_label3_1), "*Pasien tidak ditemukan");

    } else {
        gtk_label_set_text(GTK_LABEL(report_label3_1), "");
        //Menampilkan subhalaman 2 jika data pasien ditemukan
        gtk_stack_set_visible_child(GTK_STACK(stack3), page3_2);
    }
    // Mengosongkan entri
    gtk_entry_buffer_set_text(bufferId, "", -1);
}

GtkWidget* Page3_1(){

    // Membuat box sebagai subhalaman ketiga
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_size_request(page, 1300, 762);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-page3_1");

    //Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed1 = addFixed(page);

    //Membuat box untuk entri ID pasien
    GtkWidget *box_id = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_size_request(box_id, 500, 50);
    GtkWidget *entry_Id = gtk_entry_new();
    setinput(entry_Id, "Masukkan ID Pasien Yang Akan Diubah", box_id, "icons/id.png");
    gtk_fixed_put(GTK_FIXED(fixed1), box_id, 330, 160);

    //Membuat tombol kembali ke menu utama
    GtkWidget* BackButton = iconButton("icons/back.png", "Kembali ke menu utama", "back-button", "back-title");
    gtk_widget_set_size_request(BackButton, 240, 60);
    gtk_fixed_put(GTK_FIXED(fixed1), BackButton, 60, 50);

    //Kembali ke menu utama ketika tombol diklik
    g_signal_connect(BackButton, "clicked", G_CALLBACK(on_go_to_main), NULL);

    //Membuat tombol cari data pasien
    GtkWidget* show_button = iconButton("icons/find.png", "Cari Data", "find-button", "find-title");
    gtk_widget_set_size_request(show_button,150,50);
    gtk_fixed_put(GTK_FIXED(fixed1), show_button, 860, 177);    

    //Memanggil fungsi findPatient ketika tombol cari data pasien ditekan
    g_signal_connect(show_button, "clicked", G_CALLBACK(findPatient), entry_Id);

    //Tambahkan box untuk Warning
    GtkWidget* box_report = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    report_label3_1 = addReport(box_report);
    gtk_widget_add_css_class(report_label3_1, "white-report");
    gtk_fixed_put(GTK_FIXED(fixed1), box_report, 350, 230);

    //Menambahkan sub halaman 1 ke dalam stack di halaman 3
    gtk_stack_add_named(GTK_STACK(stack3), page, "Page_3_1");
    return page;
}

GtkWidget* Page3_2(){

    //Membuat box sebagai subhalaman ketiga
    GtkWidget* page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_size_request(page, 1300, 760);
    gtk_widget_add_css_class(GTK_WIDGET(page), "background-page3_2");

    //Widget fixed untuk mengatur posisi widget
    GtkWidget* fixed = addFixed(page);

    //Membuat box untuk entri data pasien
    GtkWidget *boxInput = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_size_request(boxInput, 300, 500);
    gtk_fixed_put(GTK_FIXED(fixed), boxInput, 710, 90);

    name_entry3 = gtk_entry_new();
    setinput(name_entry3, "Masukkan nama lengkap pasien: ", boxInput, "icons/name.png");
    adress_entry3 = gtk_entry_new();
    setinput(adress_entry3, "Masukkan alamat: ", boxInput, "icons/adress.png");
    city_entry3 = gtk_entry_new();
    setinput(city_entry3, "Masukkan kota (contoh: Kota Palembang): ", boxInput, "icons/city.png");
    birth_place_entry3 = gtk_entry_new();
    setinput(birth_place_entry3, "Masukkan tempat lahir (contoh: Kota Batam):", boxInput, "icons/city.png");
    birth_date_entry3 = gtk_entry_new();
    setinput(birth_date_entry3, "Masukkan tanggal lahir (contoh: 28 April 1973): ", boxInput, "icons/date.png");
    age_entry3 = gtk_entry_new();
    setinput(age_entry3, "Masukkan umur: ", boxInput, "icons/name.png");
    bpjs_entry3 = gtk_entry_new();
    setinput(bpjs_entry3, "Masukkan nomor BPJS (format: 1234567xxx): ", boxInput, "icons/name.png");
    patient_id_entry3 = gtk_entry_new();
    setinput(patient_id_entry3, "Masukkan ID pasien (format: 1230xxx): ", boxInput, "icons/name.png");

    //Membuat tombol simpan data
    GtkWidget* save_button = gtk_button_new_with_label("Simpan Data");
    gtk_widget_set_size_request(save_button,150,50);
    gtk_widget_add_css_class(save_button, "save-button");
    gtk_fixed_put(GTK_FIXED(fixed), save_button, 850, 650);

    //Memanggil fungsi updatePatient ketika tombol simpan ditekan
    g_signal_connect(save_button, "clicked", G_CALLBACK(updatePatient), name_entry3);
    g_signal_connect(save_button, "clicked", G_CALLBACK(updatePatient), adress_entry3);
    g_signal_connect(save_button, "clicked", G_CALLBACK(updatePatient), city_entry3);
    g_signal_connect(save_button, "clicked", G_CALLBACK(updatePatient), birth_place_entry3);
    g_signal_connect(save_button, "clicked", G_CALLBACK(updatePatient), birth_date_entry3);
    g_signal_connect(save_button, "clicked", G_CALLBACK(updatePatient), age_entry3); 
    g_signal_connect(save_button, "clicked", G_CALLBACK(updatePatient), bpjs_entry3);
    g_signal_connect(save_button, "clicked", G_CALLBACK(updatePatient), patient_id_entry3);

    //Tambahkan box untuk Warning
    GtkWidget* box_report = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    report_label3_2 = addReport(box_report);
    gtk_fixed_put(GTK_FIXED(fixed), box_report, 730, 620);

    //Menambahkan sub halaman 2 ke dalam stack di halaman 3
    gtk_stack_add_named(GTK_STACK(stack3), page, "Page_3_2");

    return page;
}

void updatePatient(GtkButton *button, gpointer user_data) {

    //Mengambil data dari entri
    GtkWidget *entry = GTK_WIDGET(user_data);
    gchar *data = g_strdup(gtk_editable_get_text(GTK_EDITABLE(entry)));
    GtkEntryBuffer *buffename = gtk_entry_get_buffer(GTK_ENTRY(name_entry3));
    GtkEntryBuffer *bufferadress = gtk_entry_get_buffer(GTK_ENTRY(adress_entry3));
    GtkEntryBuffer *buffercity = gtk_entry_get_buffer(GTK_ENTRY(city_entry3));
    GtkEntryBuffer *bufferbirth_place = gtk_entry_get_buffer(GTK_ENTRY(birth_place_entry3));
    GtkEntryBuffer *bufferbirth_date = gtk_entry_get_buffer(GTK_ENTRY(birth_date_entry3));
    GtkEntryBuffer *bufferage = gtk_entry_get_buffer(GTK_ENTRY(age_entry3));
    GtkEntryBuffer *bufferbpjs = gtk_entry_get_buffer(GTK_ENTRY(bpjs_entry3));
    GtkEntryBuffer *bufferpatient_id = gtk_entry_get_buffer(GTK_ENTRY(patient_id_entry3));

    //Menyalin data dari entri ke variabel sementara
    gchar *dataTemps = "";
    dataTemps = data;
    char dataTemp[50];
    g_strlcpy(dataTemp, dataTemps, 50);

    if (user_data == name_entry3) {
        strcpy(name_Temp3, dataTemp);
    } else if (user_data == adress_entry3) {
        strcpy(adress_Temp3, dataTemp);
    } else if (user_data == city_entry3) {
        strcpy(city_Temp3, dataTemp);
    } else if (user_data == birth_place_entry3) {
        strcpy(birth_place_Temp3, dataTemp);
    } else if (user_data == birth_date_entry3) {
        strcpy(birth_date_Temp3, dataTemp);
    } else if (user_data == age_entry3) {
        strcpy(age_Temp3, dataTemp);
    } else if (user_data == bpjs_entry3) {
        strcpy(bpjs_Temp3, dataTemp);
    } else if (user_data == patient_id_entry3) {
        strcpy(patient_id_Temp3, dataTemp);
    }

    //Mengubah data pasien jika data lengkap dan tidak ada duplikat
    if (strcmp(name_Temp3, "") != 0 && strcmp(adress_Temp3, "") != 0 && strcmp(city_Temp3, "") != 0 
             && strcmp(birth_place_Temp3, "") != 0 && strcmp(birth_date_Temp3, "") != 0 
             && strcmp(age_Temp3, "") != 0 && strcmp(bpjs_Temp3, "") != 0 && strcmp(patient_id_Temp3, "") != 0
             && atoi(age_Temp3) > 0){

        strcpy(patients[indexPatient3].name, name_Temp3);
        strcpy(patients[indexPatient3].address, adress_Temp3);
        strcpy(patients[indexPatient3].city, city_Temp3);
        strcpy(patients[indexPatient3].birth_place, birth_place_Temp3);
        strcpy(patients[indexPatient3].birth_date, birth_date_Temp3);

        int day, year, month_number;
        char originalDate[MAX_STRING_LENGTH];
        char month[MAX_STRING_LENGTH];
        sscanf(patients[indexPatient3].birth_date, "%d %s %d", &day, month, &year);

        for(month_number = 0; month_number < 12 ; month_number++){
            if (strcmp(month, months[month_number]) == 0){
                month_number++;
                break;
            }
        }
        snprintf(patients[indexPatient3].birth_date, sizeof(patients[indexPatient3].birth_date), "%d-%d-%d", year, month_number, day);
        patients[indexPatient3].age = atoi(age_Temp3);
        strcpy(patients[indexPatient3].bpjs, bpjs_Temp3);
        strcpy(patients[indexPatient3].patient_id, patient_id_Temp3);

        gtk_label_set_text(GTK_LABEL(report_label3_2), "");
        gtk_entry_buffer_set_text(buffename, "", -1);
        gtk_entry_buffer_set_text(bufferadress, "", -1);
        gtk_entry_buffer_set_text(buffercity, "", -1);
        gtk_entry_buffer_set_text(bufferbirth_place, "", -1);
        gtk_entry_buffer_set_text(bufferbirth_date, "", -1);
        gtk_entry_buffer_set_text(bufferage, "", -1);
        gtk_entry_buffer_set_text(bufferbpjs, "", -1);
        gtk_entry_buffer_set_text(bufferpatient_id, "", -1);

        //Kembali ke sub halaman utama    
        gtk_stack_set_visible_child(GTK_STACK(stack3), page3_1);
        gtk_stack_set_visible_child(GTK_STACK(stack), MainPage);

        WriteFileData();
    }
    else {
        gtk_label_set_text(GTK_LABEL(report_label3_2), "*Data belum lengkap atau terdapat kesalahan input");
    }
}