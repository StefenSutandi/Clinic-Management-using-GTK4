#include <stdio.h>
#include <string.h>
#include "struct.h"

Patient patients[MAX_PATIENTS];
MedicalRecord records[MAX_RECORDS];
int patient_count = 0;
int record_count = 0;

// Menambah pasien baru
void addPatient() {
    if (patient_count >= MAX_PATIENTS) {
        printf("Data pasien penuh.\n");
        return;
    }
    Patient new_patient;
    new_patient.id = patient_count + 1;
    printf("Masukkan nama pasien: ");
    scanf(" %[^\n]", new_patient.name);
    printf("Masukkan alamat: ");
    scanf(" %[^\n]", new_patient.address);
    printf("Masukkan kota: ");
    scanf(" %[^\n]", new_patient.city);
    printf("Masukkan tempat lahir: ");
    scanf(" %[^\n]", new_patient.birth_place);
    printf("Masukkan tanggal lahir (YYYY-MM-DD): ");
    scanf(" %s", new_patient.birth_date);
    printf("Masukkan umur: ");
    scanf("%d", &new_patient.age);
    printf("Masukkan nomor BPJS: ");
    scanf(" %s", new_patient.bpjs);
    printf("Masukkan ID pasien: ");
    scanf(" %s", new_patient.patient_id);
    patients[patient_count++] = new_patient;
    printf("Pasien berhasil ditambahkan.\n");
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
    printf("Masukkan tanggal lahir baru (YYYY-MM-DD): ");
    scanf(" %s", p->birth_date);
    printf("Masukkan umur baru: ");
    scanf("%d", &p->age);
    printf("Masukkan nomor BPJS baru: ");
    scanf(" %s", p->bpjs);
    printf("Data pasien berhasil diubah.\n");
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
    printf("Masukkan tanggal (YYYY-MM-DD): ");
    scanf(" %s", new_record.date);
    printf("Masukkan ID pasien: ");
    scanf(" %s", new_record.patient_id);
    printf("Masukkan diagnosis: ");
    scanf(" %[^\n]", new_record.diagnosis);
    printf("Masukkan tindakan: ");
    scanf(" %[^\n]", new_record.treatment);
    printf("Masukkan tanggal kontrol (YYYY-MM-DD): ");
    scanf(" %s", new_record.control_date);
    printf("Masukkan biaya: ");
    scanf("%d", &new_record.cost);
    records[record_count++] = new_record;
    printf("Riwayat medis berhasil ditambahkan.\n");
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
    printf("Masukkan tanggal baru (YYYY-MM-DD): ");
    scanf(" %s", r->date);
    printf("Masukkan ID pasien baru: ");
    scanf(" %s", r->patient_id);
    printf("Masukkan diagnosis baru: ");
    scanf(" %[^\n]", r->diagnosis);
    printf("Masukkan tindakan baru: ");
    scanf(" %[^\n]", r->treatment);
    printf("Masukkan tanggal kontrol baru (YYYY-MM-DD): ");
    scanf(" %s", r->control_date);
    printf("Masukkan biaya baru: ");
    scanf("%d", &r->cost);
    printf("Riwayat medis berhasil diubah.\n");
}

// Menghapus riwayat medis
void deleteMedicalRecord() {
    int id;
    printf("Masukkan ID riwayat medis yang ingin dihapus: ");
    scanf("%d", &id);
    int index = findMedicalRecordById(id);
    if (index == -1) {
        printf("Riwayat medis tidak ditemukan.\n");
        return;
    }
    for (int i = index; i < record_count - 1; i++) {
        records[i] = records[i + 1];
    }
    record_count--;
    printf("Riwayat medis berhasil dihapus.\n");
}

// Menampilkan riwayat medis
void displayMedicalRecord() {
    int id;
    printf("Masukkan ID riwayat medis: ");
    scanf("%d", &id);
    int index = findMedicalRecordById(id);
    if (index == -1) {
        printf("Riwayat medis tidak ditemukan.\n");
        return;
    }
    MedicalRecord r = records[index];
    printf("ID: %d\n", r.id);
    printf("Tanggal: %s\n", r.date);
    printf("ID Pasien: %s\n", r.patient_id);
    printf("Diagnosis: %s\n", r.diagnosis);
    printf("Tindakan: %s\n", r.treatment);
    printf("Tanggal Kontrol: %s\n", r.control_date);
    printf("Biaya: %d\n", r.cost);
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
            MedicalRecord r = records[i];
            printf("ID: %d\n", r.id);
            printf("Tanggal: %s\n", r.date);
            printf("Diagnosis: %s\n", r.diagnosis);
            printf("Tindakan: %s\n", r.treatment);
            printf("Tanggal Kontrol: %s\n", r.control_date);
            printf("Biaya: %d\n\n", r.cost);
        }
    }
}

// Mendapatkan laporan pendapatan bulanan
void getMonthlyRevenueReport(int month, int year) {
    int total = 0;
    for (int i = 0; i < record_count; i++) {
        int rec_year, rec_month, rec_day;
        sscanf(records[i].date, "%d-%d-%d", &rec_year, &rec_month, &rec_day);
        if (rec_year == year && rec_month == month) {
            total += records[i].cost;
        }
    }
    printf("Pendapatan bulan %d-%d: Rp %d\n", month, year, total);
}

// Mendapatkan laporan pendapatan tahunan
void getAnnualRevenueReport(int year) {
    int total = 0;
    for (int i = 0; i < record_count; i++) {
        int rec_year;
        sscanf(records[i].date, "%d", &rec_year);
        if (rec_year == year) {
            total += records[i].cost;
        }
    }
    printf("Pendapatan tahun %d: Rp %d\n", year, total);
}

// Mendapatkan rata-rata pendapatan per tahun
void getAverageAnnualRevenue() {
    int total_years = 0;
    int year_revenue[100] = {0};
    for (int i = 0; i < record_count; i++) {
        int rec_year;
        sscanf(records[i].date, "%d", &rec_year);
        year_revenue[rec_year - 2000] += records[i].cost; // Assuming data starts from year 2000
    }
    for (int i = 0; i < 100; i++) {
        if (year_revenue[i] > 0) {
            total_years++;
        }
    }
    int total_revenue = 0;
    for (int i = 0; i < 100; i++) {
        total_revenue += year_revenue[i];
    }
    if (total_years > 0) {
        printf("Rata-rata pendapatan per tahun: Rp %d\n", total_revenue / total_years);
    } else {
        printf("Data pendapatan tidak tersedia.\n");
    }
}

// Menghitung jumlah pasien dan penyakit per bulan dan per tahun
void getPatientAndDiseaseReport(int month, int year) {
    int disease_count[100] = {0};
    char diseases[100][100] = {0};
    int total_diseases = 0;
    
    for (int i = 0; i < record_count; i++) {
        int rec_year, rec_month, rec_day;
        sscanf(records[i].date, "%d-%d-%d", &rec_year, &rec_month, &rec_day);
        if (rec_year == year && rec_month == month) {
            int found = 0;
            for (int j = 0; j < total_diseases; j++) {
                if (strcmp(diseases[j], records[i].diagnosis) == 0) {
                    disease_count[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(diseases[total_diseases], records[i].diagnosis);
                disease_count[total_diseases]++;
                total_diseases++;
            }
        }
    }

    printf("Laporan Penyakit bulan %d-%d:\n", month, year);
    for (int i = 0; i < total_diseases; i++) {
        printf("%s: %d pasien\n", diseases[i], disease_count[i]);
    }
}

// Fungsi tambahan untuk mendapatkan laporan per tahun
void getAnnualPatientAndDiseaseReport(int year) {
    int disease_count[100] = {0};
    char diseases[100][100] = {0};
    int total_diseases = 0;
    
    for (int i = 0; i < record_count; i++) {
        int rec_year;
        sscanf(records[i].date, "%d", &rec_year);
        if (rec_year == year) {
            int found = 0;
            for (int j = 0; j < total_diseases; j++) {
                if (strcmp(diseases[j], records[i].diagnosis) == 0) {
                    disease_count[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(diseases[total_diseases], records[i].diagnosis);
                disease_count[total_diseases]++;
                total_diseases++;
            }
        }
    }

    printf("Laporan Penyakit tahun %d:\n", year);
    for (int i = 0; i < total_diseases; i++) {
        printf("%s: %d pasien\n", diseases[i], disease_count[i]);
    }
}

// Menampilkan pasien yang perlu kembali kontrol
void displayPatientsForControl() {
    char current_date[11];
    printf("Masukkan tanggal saat ini (YYYY-MM-DD): ");
    scanf(" %s", current_date);
    
    printf("Pasien yang perlu kembali kontrol:\n");
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].control_date, current_date) <= 0) {
            printf("ID Pasien: %s, Nama: %s, Tanggal Kontrol: %s\n", records[i].patient_id, patients[findPatientById(records[i].patient_id)].name, records[i].control_date);
        }
    }
}