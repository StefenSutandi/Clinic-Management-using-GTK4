#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "struct.h"

Patient patients[MAX_PATIENTS];
MedicalRecord records[MAX_RECORDS];
int patient_count = 0;
int record_count = 0;
const char * months[12] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

// Implementasi fungsi untuk mengecek duplikasi data pasien berdasarkan nama atau nomor BPJS
bool isDuplicatePatient(const char *name, const char *bpjs) {
    for (int i = 0; i < patient_count; i++) {
        if (strcmp(patients[i].name, name) == 0 || strcmp(patients[i].bpjs, bpjs) == 0) {
            return true; // Duplikat ditemukan
        }
    }
    return false; // Tidak ada duplikat
}

// Menambah pasien baru
void addPatient() {
    if (patient_count >= MAX_PATIENTS) {
        printf("Data pasien penuh.\n");
        return;
    }
    Patient new_patient;
    new_patient.id = patient_count + 1;

    printf("Masukkan nama lengkap pasien: ");
    scanf(" %[^\n]", new_patient.name);

    printf("Masukkan alamat: ");
    scanf(" %[^\n]", new_patient.address);

    printf("Masukkan kota (contoh: Kota Palembang): ");
    scanf(" %[^\n]", new_patient.city);

    printf("Masukkan tempat lahir (contoh: Kota Batam): ");
    scanf(" %[^\n]", new_patient.birth_place);

    printf("Masukkan tanggal lahir (contoh: 28 April 1973): ");
    int day, year, month_number;
    char originalDate[MAX_STRING_LENGTH];
    char month[MAX_STRING_LENGTH];
    scanf("%d %s %d", &day, month, &year);
    snprintf(originalDate, sizeof(originalDate), "%d %s %d", day, month, year);

    for(month_number = 0; month_number < 12 ; month_number++){
        if (strcmp(month, months[month_number]) == 0){
            month_number++;
            break;
        }
    }
    snprintf(new_patient.birth_date, sizeof(new_patient.birth_date), "%d-%d-%d", year, month_number, day);

    printf("Masukkan umur: ");
    scanf("%d", &new_patient.age);

    printf("Masukkan nomor BPJS (format: 1234567xxx): ");
    scanf(" %s", new_patient.bpjs);

    printf("Masukkan ID pasien (format: 1230xxx): ");
    scanf(" %s", new_patient.patient_id);
    char storedID[MAX_STRING_LENGTH];
    strcpy(storedID, "KX ");
    strcat(storedID, new_patient.patient_id);

    if (isDuplicatePatient(new_patient.name, new_patient.bpjs)) {
        printf("Pasien dengan nama atau nomor BPJS tersebut sudah ada.\n");
    } else {
        patients[patient_count++] = new_patient;
        printf("Pasien berhasil ditambahkan.\n");

        // Tulis data pasien ke file CSV
        FILE *file = fopen("data_pasien.csv", "a");
        if (file == NULL) {
            printf("Gagal membuka file data_pasien.csv\n");
            return;
        }
        fprintf(file, "%d,%s,%s,%s,%s,%s,%d,%s,%s\n",
                new_patient.id,
                new_patient.name,
                new_patient.address,
                new_patient.city,
                new_patient.birth_place,
                originalDate,
                new_patient.age,
                new_patient.bpjs,
                storedID);
        fclose(file);
    }
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

// Mencari pasien berdasarkan ID Pasien
int findPatientById(const char* patient_id) {
    for (int i = 0; i < patient_count; i++) {
        if (strcmp(patients[i].patient_id, patient_id) == 0) {
            return i;
        }
    }
    return -1;
}

// Mengubah data pasien
void updatePatient() {
    char patient_id[15];
    printf("Masukkan ID pasien yang ingin diubah: ");
    scanf(" %s", patient_id);
    int index = findPatientById(patient_id);
    if (index == -1) {
        printf("Pasien tidak ditemukan.\n");
        return;
    }
    Patient *p = &patients[index];

    printf("Masukkan nama baru: ");
    scanf(" %[^\n]", p->name);
    printf("Masukkan alamat baru: ");
    scanf(" %[^\n]", p->address);
    printf("Masukkan kota baru: ");
    scanf(" %[^\n]", p->city);
    printf("Masukkan tempat lahir baru: ");
    scanf(" %[^\n]", p->birth_place);

    printf("Masukkan tanggal lahir baru (contoh: 28 April 1973): ");
    int day, year, month_number;
    char month[MAX_STRING_LENGTH];
    scanf("%d %s %d", &day, month, &year);
    for(month_number = 0 ; month_number < 12 ; month_number++){
        if (strcmp(month, months[month_number]) == 0){
            month_number++;
            break;
        }
    }
    
    snprintf(p->birth_date, sizeof(p->birth_date), "%d-%d-%d", year, month_number, day);

    printf("Masukkan umur baru: ");
    scanf("%d", &p->age);

    printf("Masukkan nomor BPJS baru: ");
    scanf(" %s", p->bpjs);



    printf("Data pasien berhasil diubah.\n");

    // Perbarui data pasien di file CSV
    FILE *file = fopen("data_pasien.csv", "w");
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

// Menghapus pasien
void deletePatient() {
    char patient_id[15];
    printf("Masukkan ID pasien yang ingin dihapus: ");
    scanf(" %s", patient_id);

    int index = findPatientById(patient_id);
    if (index == -1) {
        printf("Pasien tidak ditemukan.\n");
        return;
    }

    for (int i = index; i < patient_count - 1; i++) {
        patients[i] = patients[i + 1];
    }
    patient_count--;
    printf("Pasien berhasil dihapus.\n");

    // Buka file CSV untuk menulis ulang data pasien
    FILE *file = fopen("data_pasien.csv", "w");
    if (file == NULL) {
        printf("Gagal membuka file data_pasien.csv\n");
        return;
    }

    // Tulis kembali template header
    fprintf(file, "No,Nama Lengkap,Alamat,Kota,Tempat Lahir,Tanggal Lahir,Umur (th),No BPJS,ID Pasien\n");
    
    // Tulis ulang data pasien ke file CSV
    for (int i = 0; i < patient_count; i++) {
        Patient pt = patients[i];
        int year, month, day;
        sscanf(pt.birth_date, "%4d-%2d-%2d", &year, &month, &day);
        
        const char *month_name = getMonthName(month);
        char original_date[MAX_STRING_LENGTH];
        snprintf(original_date, sizeof(original_date), "%d %s %d", day, month_name, year);
        
        fprintf(file, "%d,%s,%s,%s,%s,%s,%d,%s,%s\n",
                pt.id,
                pt.name,
                pt.address,
                pt.city,
                pt.birth_place,
                original_date, // Menulis kembali dalam format asli
                pt.age,
                pt.bpjs,
                pt.patient_id); // Menulis kembali ID pasien tanpa modifikasi
    }

    fclose(file);
}

// Menampilkan informasi pasien
void displayPatient() {
    char patient_id[15];
    printf("Masukkan ID pasien: ");
    scanf(" %s", patient_id);
    int index = findPatientById(patient_id);
    if (index == -1) {
        printf("Pasien tidak ditemukan.\n");
        return;
    }
    Patient p = patients[index];
    printf("ID: %d\n", p.id);
    printf("Nama: %s\n", p.name);
    printf("Alamat: %s\n", p.address);
    printf("Kota: %s\n", p.city);
    printf("Tempat Lahir: %s\n", p.birth_place);
    printf("Tanggal Lahir: %s\n", p.birth_date);
    printf("Umur: %d\n", p.age);
    printf("No BPJS: %s\n", p.bpjs);
    printf("ID Pasien: %s\n", p.patient_id);
}

// Menambah riwayat medis baru
void addMedicalRecord() {
    if (record_count >= MAX_RECORDS) {
        printf("Data riwayat medis penuh.\n");
        return;
    }

    MedicalRecord new_record;
    new_record.id = record_count + 1;
    
    printf("Masukkan tanggal (contoh: 1 Januari 2022): ");
    int day, year;
    char month[MAX_STRING_LENGTH];
    int month_number = 0;
    scanf("%d %s %d", &day, month, &year);
    for (month_number; month_number < 12; month_number++){
        if (strcmp(months[month_number], month) == 0){
            month_number = month_number + 1;
            break;
        }
    }

    // Format tanggal lahir dalam format Tanggal Bulan Tahun untuk penyimpanan
    snprintf(new_record.date, sizeof(new_record.date), "%d-%d-%d", year, month_number, day);
    
    printf("Masukkan ID pasien: ");
    scanf(" %s", new_record.patient_id);
    
    printf("Masukkan diagnosis: ");
    scanf(" %[^\n]", new_record.diagnosis);
    
    printf("Masukkan tindakan: ");
    scanf(" %[^\n]", new_record.treatment);
    
    printf("Masukkan tanggal kontrol (contoh: 4 Januari 2022): ");
    scanf("%d %s %d", &day, month, &year);
    for (month_number = 0; month_number < 12; month_number++){
        if (strcmp(months[month_number], month) == 0){
            month_number = month_number + 1;
            break;
        }
    }

    // Format tanggal lahir dalam format Tanggal Bulan Tahun untuk penyimpanan
    snprintf(new_record.control_date, sizeof(new_record.control_date), "%d-%d-%d", year, month_number, day);
    
    printf("Masukkan biaya: ");
    scanf("%d", &new_record.cost);

    records[record_count++] = new_record;
    printf("Riwayat medis berhasil ditambahkan.\n");

    // Buka file CSV untuk menulis ulang data rekam medis
    FILE *file = fopen("riwayat_datang.csv", "w");
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

// Mencari riwayat medis berdasarkan ID
int findMedicalRecordById(int id) {
    for (int i = 0; i < record_count; i++) {
        if (records[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Mengubah riwayat medis
void updateMedicalRecord() {
    int id;
    printf("Masukkan ID riwayat medis yang ingin diubah: ");
    scanf("%d", &id);
    int index = findMedicalRecordById(id);
    if (index == -1) {
        printf("Riwayat medis tidak ditemukan.\n");
        return;
    }
    MedicalRecord *r = &records[index];
    
    printf("Masukkan tanggal baru (contoh: 1 Januari 2022): ");
    int day, year;
    char month[MAX_STRING_LENGTH];
    int month_number = 0;
    scanf("%d %s %d", &day, month, &year);
    for (month_number = 0; month_number < 12; month_number++){
        if (strcmp(months[month_number], month) == 0){
            month_number = month_number + 1;
            break;
        }
    }
    snprintf(r->date, sizeof(r->date), "%d-%d-%d", year, month_number, day);

    printf("Masukkan ID pasien baru: ");
    scanf(" %s", r->patient_id);
    printf("Masukkan diagnosis baru: ");
    scanf(" %[^\n]", r->diagnosis);
    printf("Masukkan tindakan baru: ");
    scanf(" %[^\n]", r->treatment);
    printf("Masukkan tanggal kontrol baru (contoh: 4 Januari 2022): ");
    scanf("%d %s %d", &day, month, &year);
    for (month_number = 0; month_number < 12; month_number++){
        if (strcmp(months[month_number], month) == 0){
            month_number = month_number + 1;
            break;
        }
    }
    snprintf(r->control_date, sizeof(r->control_date), "%d-%d-%d", year, month_number, day);

    printf("Masukkan biaya baru: ");
    scanf("%d", &r->cost);
    printf("Riwayat medis berhasil diubah.\n");

    // Buka file CSV untuk menulis ulang data rekam medis
    FILE *file = fopen("riwayat_datang.csv", "w");
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

// Menghapus riwayat medis
void deleteMedicalRecord() {
    char record_id[15];
    printf("Masukkan ID rekam medis yang ingin dihapus: ");
    scanf(" %s", record_id);

    int index = findMedicalRecordById(atoi(record_id));
    if (index == -1) {
        printf("Rekam medis tidak ditemukan.\n");
        return;
    }

    for (int i = index; i < record_count - 1; i++) {
        records[i] = records[i + 1];
    }
    record_count--;
    printf("Rekam medis berhasil dihapus.\n");

    // Buka file CSV untuk menulis ulang data rekam medis
    FILE *file = fopen("riwayat_datang.csv", "w");
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

        const char *month_name = getMonthName(month);
        char original_date[MAX_STRING_LENGTH];
        snprintf(original_date, sizeof(original_date), "%d %s %d", day, month_name, year);

        // Mendapatkan tanggal kontrol dalam format yang sama persis dengan tanggal
        sscanf(mr.control_date, "%4d-%2d-%2d", &year, &month, &day);
        const char *control_month_name = getMonthName(month);
        char original_control_date[MAX_STRING_LENGTH];
        snprintf(original_control_date, sizeof(original_control_date), "%d %s %d", day, control_month_name, year);

        // Tulis data rekam medis ke file CSV
        fprintf(file, "%d,%s,%s,%s,%s,%s,%d\n",
                mr.id,
                original_date,
                mr.patient_id,
                mr.diagnosis,
                mr.treatment,
                original_control_date, // Menggunakan tanggal kontrol dengan format yang sama persis dengan tanggal
                mr.cost);
    }

    fclose(file);
}

// Menampilkan riwayat medis
void displayMedicalRecord() {
    char id_str[20];
    printf("Masukkan ID pasien: ");
    scanf("%s", id_str);
    int found = 0;
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].patient_id, id_str) == 0) {
            printf("ID: %d\n", records[i].id);
            printf("Tanggal: %s\n", records[i].date);
            printf("ID Pasien: %s\n", records[i].patient_id);
            printf("Diagnosis: %s\n", records[i].diagnosis);
            printf("Tindakan: %s\n", records[i].treatment);
            printf("Tanggal Kontrol: %s\n", records[i].control_date);
            printf("Biaya: %d\n", records[i].cost);
            found = 1;
        }
    }
    if (!found) {
        printf("Riwayat medis tidak ditemukan untuk ID pasien tersebut.\n");
    }
}

// Menampilkan informasi pasien beserta riwayat medisnya
void displayPatientWithMedicalRecords() {
    char patient_id[15];
    printf("Masukkan ID pasien: ");
    scanf(" %s", patient_id);
    int patient_index = findPatientById(patient_id);
    if (patient_index == -1) {
        printf("Pasien tidak ditemukan.\n");
        return;
    }
    Patient p = patients[patient_index];
    printf("ID: %d\n", p.id);
    printf("Nama: %s\n", p.name);
    printf("Alamat: %s\n", p.address);
    printf("Kota: %s\n", p.city);
    printf("Tempat Lahir: %s\n", p.birth_place);
    printf("Tanggal Lahir: %s\n", p.birth_date);
    printf("Umur: %d\n", p.age);
    printf("No BPJS: %s\n", p.bpjs);
    printf("ID Pasien: %s\n", p.patient_id);
    printf("\nRiwayat Medis:\n");
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].patient_id, patient_id) == 0) {
            printf("\nID Riwayat Medis: %d\n", records[i].id);
            printf("Tanggal: %s\n", records[i].date);
            printf("Diagnosis: %s\n", records[i].diagnosis);
            printf("Tindakan: %s\n", records[i].treatment);
            printf("Tanggal Kontrol: %s\n", records[i].control_date);
            printf("Biaya: %d\n", records[i].cost);
        }
    }
}

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
    FILE* file = fopen("data_pasien.csv", "r"); 

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

    file = fopen("riwayat_datang.csv", "r"); 
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

// Menampilkan semua pasien dan riwayat medis
void displayAllPatientsAndRecords() {
    printf("Data Pasien:\n");
    for (int i = 0; i < patient_count; i++) {
        printf("\nID: %d\n", patients[i].id);
        printf("Nama: %s\n", patients[i].name);
        printf("Alamat: %s\n", patients[i].address);
        printf("Kota: %s\n", patients[i].city);
        printf("Tempat Lahir: %s\n", patients[i].birth_place);
        printf("Tanggal Lahir: %s\n", patients[i].birth_date);
        printf("Umur: %d\n", patients[i].age);
        printf("No BPJS: %s\n", patients[i].bpjs);
        printf("ID Pasien: %s\n", patients[i].patient_id);

        printf("\nRiwayat Medis:\n");
        for (int j = 0; j < record_count; j++) {
            if (strcmp(records[j].patient_id, patients[i].patient_id) == 0) {
                printf("\nID Riwayat Medis: %d\n", records[j].id);
                printf("Tanggal: %s\n", records[j].date);
                printf("Diagnosis: %s\n", records[j].diagnosis);
                printf("Tindakan: %s\n", records[j].treatment);
                printf("Tanggal Kontrol: %s\n", records[j].control_date);
                printf("Biaya: %d\n", records[j].cost);
            }
        }
    }
}

// Implementasi fungsi untuk laporan pendapatan bulanan
void getMonthlyRevenueReport(int month, int year) {
    int total = 0;
    for (int i = 0; i < record_count; i++) {
        int rec_year, rec_month, rec_day;
        sscanf(records[i].date, "%4d-%2d-%2d", &rec_year, &rec_month, &rec_day);
        if (rec_year == year && rec_month == month) {
            total += records[i].cost;
        }
    }
    printf("Pendapatan bulan %02d/%04d: %d\n", month, year, total);
}

// Implementasi fungsi untuk laporan pendapatan tahunan
void getAnnualRevenueReport(int year) {
    int total = 0;
    for (int i = 0; i < record_count; i++) {
        int rec_year, rec_month, rec_day;
        sscanf(records[i].date, "%4d-%2d-%2d", &rec_year, &rec_month, &rec_day);
        if (rec_year == year) {
            total += records[i].cost;
        }
    }
    printf("Pendapatan tahun %04d: %d\n", year, total);
}

// Implementasi fungsi untuk rata-rata pendapatan tahunan
void getAverageAnnualRevenue() {
    int total = 0;
    int years = 0;
    int current_year = 0;
    for (int i = 0; i < record_count; i++) {
        int rec_year, rec_month, rec_day;
        sscanf(records[i].date, "%4d-%2d-%2d", &rec_year, &rec_month, &rec_day);
        if (rec_year != current_year) {
            years++;
            current_year = rec_year;
        }
        total += records[i].cost;
    }
    if (years == 0) {
        printf("Tidak ada data untuk dihitung.\n");
    } else {
        printf("Rata-rata pendapatan tahunan: %d\n", total / years);
    }
}

// Implementasi fungsi untuk laporan pasien dan penyakit bulanan
void getPatientAndDiseaseReport(int month, int year) {
    printf("Laporan pasien dan penyakit bulan %02d/%04d:\n", month, year);
    for (int i = 0; i < record_count; i++) {
        int rec_year, rec_month, rec_day;
        sscanf(records[i].date, "%4d-%2d-%2d", &rec_year, &rec_month, &rec_day);
        if (rec_year == year && rec_month == month) {
            int patient_index = findPatientById(records[i].patient_id);
            if (patient_index != -1) {
                printf("Nama Pasien: %s, Diagnosis: %s\n", patients[patient_index].name, records[i].diagnosis);
            }
        }
    }
}

// Implementasi fungsi untuk laporan pasien dan penyakit tahunan
void getAnnualPatientAndDiseaseReport(int year) {
    printf("Laporan pasien dan penyakit tahun %04d:\n", year);
    for (int i = 0; i < record_count; i++) {
        int rec_year, rec_month, rec_day;
        sscanf(records[i].date, "%4d-%2d-%2d", &rec_year, &rec_month, &rec_day);
        if (rec_year == year) {
            int patient_index = findPatientById(records[i].patient_id);
            if (patient_index != -1) {
                printf("Nama Pasien: %s, Diagnosis: %s\n", patients[patient_index].name, records[i].diagnosis);
            }
        }
    }
}

// Implementasi fungsi untuk menampilkan pasien untuk kontrol
void displayPatientsForControl() {
    printf("Pasien untuk kontrol:\n");
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].control_date, "") != 0) {
            int patient_index = findPatientById(records[i].patient_id);
            if (patient_index != -1) {
                printf("Nama Pasien: %s, Tanggal Kontrol: %s\n", patients[patient_index].name, records[i].control_date);
            }
        }
    }
}