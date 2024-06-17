#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include "struct.h"
#include "fungsi.h"

Patient patients[MAX_PATIENTS];
MedicalRecord records[MAX_RECORDS];
int patient_count = 0;
int record_count = 0;
const char * months[12] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

// Fungsi fungsi untuk berpindah halaman 
void on_back_to_main_page(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), StartingPage);
}

void on_go_to_main(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), MainPage);
    gtk_label_set_text(GTK_LABEL(LabelWarning), "");
    gtk_label_set_text(GTK_LABEL(name_show), "");
    gtk_label_set_text(GTK_LABEL(adress_show), "");
    gtk_label_set_text(GTK_LABEL(city_show), "");
    gtk_label_set_text(GTK_LABEL(birth_place_show), "");
    gtk_label_set_text(GTK_LABEL(age_show), "");
    gtk_label_set_text(GTK_LABEL(birth_date_show), "");
    gtk_label_set_text(GTK_LABEL(bpjs_show), "");
    gtk_label_set_text(GTK_LABEL(patient_id_show), "");
    gtk_label_set_text(GTK_LABEL(report_label4), "");
    gtk_label_set_text(GTK_LABEL(report_label5), "");
    gtk_label_set_text(GTK_LABEL(report_label7), "");
    gtk_label_set_text(GTK_LABEL(name_show8), "");
    gtk_label_set_text(GTK_LABEL(adress_show8), "");
    gtk_label_set_text(GTK_LABEL(city_show8), "");
    gtk_label_set_text(GTK_LABEL(birth_place_show8), "");
    gtk_label_set_text(GTK_LABEL(age_show8), "");
    gtk_label_set_text(GTK_LABEL(birth_date_show8), "");
    gtk_label_set_text(GTK_LABEL(bpjs_show8), "");
    gtk_label_set_text(GTK_LABEL(patient_id_show8), "");
    clearGrids(ScrollGrid);
    clearGrids(ScrollGrid9);
    clearGrids(ScrollGrid9_2);
    clearGrids(ScrollGrid9_3);
    clearGrids(ScrollGrid9_4);
    gtk_label_set_text(GTK_LABEL(MonthlyShow), "");
    gtk_label_set_text(GTK_LABEL(AnnualShow), "");
    gtk_label_set_text(GTK_LABEL(AverageShow), "");
    clearGrids(ScrollGrid12);
}

void go_to_Page_1(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), Page[1]);
}

void go_to_Page_2(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), Page[2]);
}

void go_to_Page_3(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), Page[3]);
}

void go_to_Page_4(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), Page[4]);
}

void go_to_Page_5(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), Page[5]);
}

void go_to_Page_6(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), Page[6]);
}

void go_to_Page_7(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), Page[7]);
}

void go_to_Page_8(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), Page[8]);
}

void go_to_Page_9(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), Page[9]);
}

void go_to_Page_10(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), Page[10]);
}

void go_to_Page_11(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), Page[11]);
}

void go_to_Page_12(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), Page[12]);
    displayPatientsForControl();
}

void go_to_Page_13(GtkButton *button, gpointer user_data) {
    gtk_stack_set_visible_child(GTK_STACK(stack), Page[13]);
}

//  Fungsi untuk membuat widget fixed yang mengatur posisi widget
GtkWidget* addFixed(GtkWidget *destination){
    GtkWidget *fixed = gtk_fixed_new();
    gtk_box_append(GTK_BOX(destination), fixed);
    return fixed;
}

// Fungsi untuk membuat label
GtkWidget* addButton(GtkWidget *destination, const char *namaButton){
    GtkWidget *button = gtk_button_new_with_label(namaButton);
    gtk_box_append(GTK_BOX(destination), button);
    return button;
}

// Fungsi untuk membuat label
GtkWidget* addReport(GtkWidget *destination){
    GtkWidget* report_label = gtk_label_new("");
    gtk_box_append(GTK_BOX(destination), report_label);
    return report_label;
}

// Fungsi untuk membuat tombol menu
GtkWidget* CreateButton(const char *label, GtkWidget *grid, int column, int row, const char *path) {
    
    //Mendapatkan path icon
    char *IconName = g_strdup_printf("icons/%s.png", path);

    //Membuat tombol menu
    GtkWidget* button = gtk_button_new();
    gtk_widget_add_css_class(button, "menu");

    //Menambahkan tombol menu ke grid
    gtk_grid_attach(GTK_GRID(grid), button, column, row, 1,1);

    //Membuat box untuk menampung icon dan judul
    GtkWidget* box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 7);

    GtkWidget* Space = gtk_label_new (" "); //Membuat spasi
    gtk_widget_add_css_class(Space, "Title");
    gtk_box_append (GTK_BOX (box), Space);

    GtkWidget* image = gtk_image_new_from_file (IconName);//Memuat icon dari path
    gtk_widget_set_size_request(image, 60, 60);
    gtk_box_append (GTK_BOX (box), image);

    GtkWidget* Title = gtk_label_new (label); //Memasukkan judul
    gtk_widget_add_css_class(Title, "menu-title");
    gtk_box_append (GTK_BOX (box), Title);

    Space = gtk_label_new (" ");//Membuat spasi
    gtk_widget_add_css_class(Space, "Title");
    gtk_box_append (GTK_BOX (box), Space);

    //Menambahkan box ke dalam tombol menu
    gtk_button_set_child (GTK_BUTTON (button), box);

    return button;
}

// Fungsi untuk membuat tombol  dengan icon
GtkWidget* iconButton(const char *path, const char *label, const char *csst, const char *csst2) {
    
    //Membuat tombol menu
    GtkWidget* button = gtk_button_new();
    gtk_widget_add_css_class(button, csst);

    //Membuat box untuk menampung icon dan judul
    GtkWidget* box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 7);

    GtkWidget* Space = gtk_label_new (" "); //Membuat spasi
    gtk_widget_add_css_class(Space, "Title");
    gtk_box_append (GTK_BOX (box), Space);

    GtkWidget* image = gtk_image_new_from_file (path);//Memuat icon dari path
    gtk_widget_set_size_request(image, 25, 25);
    gtk_box_append (GTK_BOX (box), image);

    GtkWidget* Title = gtk_label_new (label); //Memasukkan judul
    gtk_box_append (GTK_BOX (box), Title);
    gtk_widget_add_css_class(Title, csst2);

    //Menambahkan box ke dalam tombol menu
    gtk_button_set_child (GTK_BUTTON (button), box);

    return button;
}

// Fungsi untuk membuat next dengan icon
GtkWidget* NextButton(const char *path, const char *label, const char *csst, const char *csst2) {
    
    //Membuat tombol menu
    GtkWidget* button = gtk_button_new();
    gtk_widget_add_css_class(button, csst);

    //Membuat box untuk menampung icon dan judul
    GtkWidget* box = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 7);

    GtkWidget* Title = gtk_label_new (label); //Memasukkan judul
    gtk_box_append (GTK_BOX (box), Title);
    gtk_widget_add_css_class(Title, csst2);

    GtkWidget* image = gtk_image_new_from_file (path);//Memuat icon dari path
    gtk_widget_set_size_request(image, 25, 25);
    gtk_box_append (GTK_BOX (box), image);

    GtkWidget* Space = gtk_label_new (" "); //Membuat spasi
    gtk_widget_add_css_class(Space, "Title");
    gtk_box_append (GTK_BOX (box), Space);
    //Menambahkan box ke dalam tombol menu
    gtk_button_set_child (GTK_BUTTON (button), box);

    return button;
}

// Fungsi untuk membuat halaman
GtkWidget* create_page(GtkWidget *notebook, const char *tab_label_text, const char *content_text, const char *namafoto) {

    //Membuat path icon
    char *namapath = g_strdup_printf("icons/%s.png", namafoto);

    //Membuat halaman
    GtkWidget *page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    //Membuat label untuk judul halaman
    GtkWidget *label = gtk_label_new(content_text);
    gtk_box_append(GTK_BOX(page), label);

    //Membuat ukuran halaman
    gtk_widget_set_size_request(page, 600, -1);

    return page;
}

// Fungsi untuk membuat entri box dengan icon dan judul entri box
GtkWidget* setinput(GtkWidget *namaVariabel, const char *namaPlaceholder, GtkWidget *nama_box, const char *path){
    gtk_widget_set_size_request(namaVariabel, 430, 65); //Mengatur ukuran entri box
    gtk_entry_set_placeholder_text(GTK_ENTRY(namaVariabel), namaPlaceholder); //Mengatur judul entri box
    gtk_entry_set_max_length(GTK_ENTRY(namaVariabel), 50);//Mengatur panjang maksimal string dalam entri box
    gtk_box_append(GTK_BOX(nama_box), namaVariabel); //Menambahkan entri box ke dalam box
    gtk_widget_add_css_class(namaVariabel, "box-nama"); //Menambahkan class css
    GtkWidget *icon = gtk_image_new_from_file(path); //Membuat icon
    GdkPaintable *paintable = gtk_image_get_paintable(GTK_IMAGE(icon));
    gtk_entry_set_icon_from_paintable(GTK_ENTRY(namaVariabel), GTK_ENTRY_ICON_PRIMARY, paintable);
}

// Fungsi untuk menambahkan data ke grid
void EditGrid(GtkWidget *grid, GtkWidget **show, int column, int row) {
    *show = gtk_label_new(""); //Membuat label
    gtk_widget_set_halign(*show, GTK_ALIGN_START); //Mengatur posisi label rata ke kiri
    gtk_grid_attach(GTK_GRID(grid), *show, column, row, 1, 1); //Menambahkan label ke dalam grid
    gtk_widget_add_css_class(*show, "label");
}

// Fungsi untuk menghapus data di grid
void clearGrids(GtkWidget* gridx){
    GtkWidget *child = gtk_widget_get_first_child(GTK_WIDGET(gridx));
    while (child != NULL) {
        gtk_widget_unparent(child);
        child = gtk_widget_get_first_child(GTK_WIDGET(gridx));
    }
}

// Fungsi untuk mengecek apakah data duplikat
bool isDuplicatePatient(const char *name, const char *bpjs) {
    for (int i = 0; i < patient_count; i++) {
        if (strcmp(patients[i].name, name) == 0 || strcmp(patients[i].bpjs, bpjs) == 0) {
            return true; // Duplikat ditemukan
        }
    }
    return false; // Tidak ada duplikat
}

// Fungsi untuk mencari pasien berdasarkan ID
int findPatientById(const char* patient_id) {
    for (int i = 0; i < patient_count; i++) {
        if (strcmp(patients[i].patient_id, patient_id) == 0) {
            return i;
        }
    }
    return -1;
}

// Fungsi untuk mencari rekam medis berdasarkan ID
int findMedicalRecordById(int id) {
    for (int i = 0; i < record_count; i++) {
        if (records[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Fungsi untuk menghapus data pasien
void ConvertDate(char date[30], char *result){
    char DD[3], MM[10];
    int YYYY;
    if(strlen(date) > 9){
        sscanf(date, "%s %s %d", DD, MM, &YYYY);
    }
    else{
        sscanf(date, "%[^-]-%[^-]-%d", DD, MM, &YYYY);
    }
    if (strcmp(MM, "Januari") == 0 || strcmp(MM, "Jan") == 0) {
        strcpy(MM, "01");
    } else if (strcmp(MM, "Februari") == 0 || strcmp(MM, "Feb") == 0) {
        strcpy(MM, "02");
    } else if (strcmp(MM, "Maret") == 0 || strcmp(MM, "Mar") == 0) {
        strcpy(MM, "03");
    } else if (strcmp(MM, "April") == 0 || strcmp(MM, "Apr") == 0) {
        strcpy(MM, "04");
    } else if (strcmp(MM, "Mei") == 0 || strcmp(MM, "May") == 0) {
        strcpy(MM, "05");
    } else if (strcmp(MM, "Juni") == 0 || strcmp(MM, "Jun") == 0) {
        strcpy(MM, "06");
    } else if (strcmp(MM, "Juli") == 0 || strcmp(MM, "Jul") == 0) {
        strcpy(MM, "07");
    } else if (strcmp(MM, "Agustus") == 0 || strcmp(MM, "Aug") == 0) {
        strcpy(MM, "08");
    } else if (strcmp(MM, "September") == 0 || strcmp(MM, "Sep") == 0) {
        strcpy(MM, "09");
    } else if (strcmp(MM, "Oktober") == 0 || strcmp(MM, "Oct") == 0) {
        strcpy(MM, "10");
    } else if (strcmp(MM, "November") == 0 || strcmp(MM, "Nov") == 0) {
        strcpy(MM, "11");
    } else if (strcmp(MM, "Desember") == 0 || strcmp(MM, "Dec") == 0) {
        strcpy(MM, "12");
    }

    char YYYYstr[5];
    if ( YYYY > 25 && YYYY <= 99){    
        YYYY += 1900;
    }
    else if (YYYY <= 25){
        YYYY += 2000;
    }
    sprintf(YYYYstr, "%d", YYYY);
    strcat(result, YYYYstr);
    strcat(result, "-");
    strcat(result, MM);
    strcat(result, "-");
    if (strlen(DD) == 1){
        strcat(result, "0");
    }
    strcat(result, DD);
}

// Memuat data dari file CSV dan memasukkannya ke dalam struct
void load_data(){
    char namafile[100];
    char dataFile[256]; 
    char tempDate[30];
    char tempDate2[30];
    char IDCode[3];
    FILE* file = fopen("CSV/data_pasien.csv", "r"); 

    fgets(dataFile, sizeof(dataFile), file);
    while (fgets(dataFile, sizeof(dataFile), file) != NULL) {
        sscanf(dataFile, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%d,%[^,],%s %s", 
            &patients[patient_count].id,
            patients[patient_count].name, 
            patients[patient_count].address, 
            patients[patient_count].city, 
            patients[patient_count].birth_place, 
            tempDate, 
            &patients[patient_count].age, 
            patients[patient_count].bpjs,
            IDCode, 
            patients[patient_count].patient_id);
        ConvertDate(tempDate, patients[patient_count].birth_date);
        patient_count++;
    }
    fclose(file); 

    file = fopen("CSV/riwayat_datang.csv", "r"); 
    fgets(dataFile, sizeof(dataFile), file);
    while (fgets(dataFile, sizeof(dataFile), file) != NULL) {
        sscanf(dataFile, "%d,%[^,],%s %[^,],%[^,],%[^,],%[^,],%d", 
            &records[record_count].id,
            tempDate,
            IDCode,
            records[record_count].patient_id,
            records[record_count].diagnosis,
            records[record_count].treatment,
            tempDate2,
            &records[record_count].cost);
        ConvertDate(tempDate, records[record_count].date);
        ConvertDate(tempDate2, records[record_count].control_date);
        record_count++;
    }
    fclose(file); 
}

const char* getMonthName(int month) {
    switch (month) {
        case 1: return "Januari";
        case 2: return "Februari";
        case 3: return "Maret";
        case 4: return "April";
        case 5: return "Mei";
        case 6: return "Juni";
        case 7: return "Juli";
        case 8: return "Agustus";
        case 9: return "September";
        case 10: return "Oktober";
        case 11: return "November";
        case 12: return "Desember";
        default: return "";
    }
}

// Fungsi untuk menulis data pasien ke file CSV
void WriteFileData(){
    FILE *file = fopen("data_pasien1.csv", "w");
    if (file == NULL) {
        printf("Gagal membuka file data_pasien.csv\n");
        return;
    }
    fprintf(file, "No,Nama Lengkap,Alamat,Kota,Tempat Lahir,Tanggal Lahir,Umur (th),No BPJS,ID Pasien\n");
    for (int i = 0; i < patient_count; i++) {
        Patient pt = patients[i];
        
        int year, month, day;
        sscanf(pt.birth_date, "%4d-%2d-%2d", &year, &month, &day);
        
        const char *month_name = getMonthName(month);
        char original_date[MAX_STRING_LENGTH];
        snprintf(original_date, sizeof(original_date), "%d %s %d", day, month_name, year);

        char id[MAX_STRING_LENGTH] = "KX ";
        strcat(id, pt.patient_id);
        fprintf(file, "%d,%s,%s,%s,%s,%s,%d,%s,%s\n",
                pt.id,
                pt.name,
                pt.address,
                pt.city,
                pt.birth_place,
                original_date,
                pt.age,
                pt.bpjs,
                id);
    }
    fclose(file);
}


// Fungsi untuk menulis data rekam medis ke file CSV
void WriteFileRecord(){
    FILE *file = fopen("riwayat_datang2.csv", "w");
    if (file == NULL) {
        printf("Gagal membuka file riwayat_datang.csv\n");
        return;
    }

    // Tulis kembali template header
    fprintf(file, "No,Tanggal,ID Pasien,Diagnosis,Tindakan,Kontrol,Biaya (Rp)\n");

    // Tulis ulang data rekam medis ke file CSV
    for (int i = 0; i < record_count; i++) {
        MedicalRecord mr = records[i];
        int year, month, day;
        sscanf(mr.date, "%4d-%2d-%2d", &year, &month, &day);

        char month_name[MAX_STRING_LENGTH];
        strcpy(month_name, months[month-1]);
        char original_date[MAX_STRING_LENGTH];
        snprintf(original_date, sizeof(original_date), "%d %s %d", day, month_name, year);

        sscanf(mr.control_date, "%4d-%2d-%2d", &year, &month, &day);
        strcpy(month_name, months[month-1]);
        
        char original_control_date[MAX_STRING_LENGTH];
        snprintf(original_control_date, sizeof(original_control_date), "%d %s %d", day, month_name, year);

        char id[MAX_STRING_LENGTH] = "KX ";
        strcat(id, mr.patient_id);

        // Tulis data rekam medis ke file CSV
        fprintf(file, "%d,%s,%s,%s,%s,%s,%d\n",
                mr.id,
                original_date,
                id,
                mr.diagnosis,
                mr.treatment,
                original_control_date,
                mr.cost);
    }

    fclose(file);
}