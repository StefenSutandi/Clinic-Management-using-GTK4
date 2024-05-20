#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    char diagnosis[100];
    char treatment[100];
    int follow_up_days; // Hari kontrol berikutnya
} Patient;

Patient patients[100];
int patient_count = 0;

void add_patient(int id, const char *name, int age, const char *gender, const char *diagnosis, const char *treatment, int follow_up_days) {
    if (patient_count >= 100) {
        printf("Kapasitas maksimal pasien tercapai.\n");
        return;
    }
    
    patients[patient_count].id = id;
    strncpy(patients[patient_count].name, name, 50);
    patients[patient_count].age = age;
    strncpy(patients[patient_count].gender, gender, sizeof(patients[patient_count].gender));
    strncpy(patients[patient_count].diagnosis, diagnosis, sizeof(patients[patient_count].diagnosis));
    strncpy(patients[patient_count].treatment, treatment, sizeof(patients[patient_count].treatment));
    patients[patient_count].follow_up_days = follow_up_days;
    
    patient_count++;
    printf("Pasien berhasil ditambahkan!\n");
}

void update_patient() {
    int id;
    printf("Masukkan ID pasien yang ingin diubah: ");
    scanf("%d", &id);
    
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            printf("Masukkan nama baru pasien: ");
            scanf(" %[^\n]", patients[i].name);
            printf("Masukkan umur baru pasien: ");
            scanf("%d", &patients[i].age);
            printf("Masukkan jenis kelamin baru pasien: ");
            scanf(" %s", patients[i].gender);
            printf("Masukkan diagnosis baru: ");
            scanf(" %[^\n]", patients[i].diagnosis);
            printf("Masukkan perawatan baru: ");
            scanf(" %[^\n]", patients[i].treatment);
            printf("Masukkan hari kontrol baru: ");
            scanf("%d", &patients[i].follow_up_days);
            printf("Data pasien berhasil diperbarui!\n");
            return;
        }
    }
    printf("Pasien dengan ID tersebut tidak ditemukan.\n");
}

void delete_patient() {
    int id;
    printf("Masukkan ID pasien yang ingin dihapus: ");
    scanf("%d", &id);
    
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            for (int j = i; j < patient_count - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patient_count--;
            printf("Pasien berhasil dihapus!\n");
            return;
        }
    }
    printf("Pasien dengan ID tersebut tidak ditemukan.\n");
}

void search_patient() {
    int id;
    printf("Masukkan ID pasien yang ingin dicari: ");
    scanf("%d", &id);
    
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            printf("ID: %d\n", patients[i].id);
            printf("Nama: %s\n", patients[i].name);
            printf("Umur: %d\n", patients[i].age);
            printf("Jenis Kelamin: %s\n", patients[i].gender);
            printf("Diagnosis: %s\n", patients[i].diagnosis);
            printf("Perawatan: %s\n", patients[i].treatment);
            printf("Hari Kontrol: %d\n", patients[i].follow_up_days);
            return;
        }
    }
    printf("Pasien dengan ID tersebut tidak ditemukan.\n");
}

void list_patients() {
    if (patient_count == 0) {
        printf("Tidak ada pasien yang tercatat.\n");
        return;
    }
    
    for (int i = 0; i < patient_count; i++) {
        printf("ID: %d\n", patients[i].id);
        printf("Nama: %s\n", patients[i].name);
        printf("Umur: %d\n", patients[i].age);
        printf("Jenis Kelamin: %s\n", patients[i].gender);
        printf("Diagnosis: %s\n", patients[i].diagnosis);
        printf("Perawatan: %s\n", patients[i].treatment);
        printf("Hari Kontrol: %d\n", patients[i].follow_up_days);
        printf("-----------------------\n");
    }
}

void list_follow_up_patients() {
    if (patient_count == 0) {
        printf("Tidak ada pasien yang tercatat.\n");
        return;
    }

    printf("Pasien yang perlu kontrol:\n");
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].follow_up_days > 0) {
            printf("ID: %d\n", patients[i].id);
            printf("Nama: %s\n", patients[i].name);
            printf("Umur: %d\n", patients[i].age);
            printf("Jenis Kelamin: %s\n", patients[i].gender);
            printf("Diagnosis: %s\n", patients[i].diagnosis);
            printf("Perawatan: %s\n", patients[i].treatment);
            printf("Hari Kontrol: %d\n", patients[i].follow_up_days);
            printf("-----------------------\n");
        }
    }
}

void import_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error membuka file %s\n", filename);
        return;
    }
    
    char line[256];
    int id, age, follow_up_days;
    char name[50], gender[10], diagnosis[100], treatment[100];
    
    // Skip header line
    fgets(line, sizeof(line), file);
    
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d,%49[^,],%d,%9[^,],%99[^,],%99[^,],%d",
               &id, name, &age, gender, diagnosis, treatment, &follow_up_days);
        add_patient(id, name, age, gender, diagnosis, treatment, follow_up_days);
    }
    
    fclose(file);
}

void generate_revenue_report() {
    // Asumsi setiap pasien membayar biaya tetap
    const int revenue_per_patient = 100000; // Contoh biaya tetap per pasien (Rp)
    int monthly_revenue = patient_count * revenue_per_patient;
    int yearly_revenue = monthly_revenue * 12;

    printf("Laporan Pendapatan:\n");
    printf("Pendapatan Bulanan: Rp%d\n", monthly_revenue);
    printf("Pendapatan Tahunan: Rp%d\n", yearly_revenue);
    printf("Rata-rata Pendapatan Bulanan: Rp%d\n", monthly_revenue);
}

void generate_disease_statistics() {
    // Asumsi kita hanya mencari statistik dari diagnosis yang ada
    typedef struct {
        char diagnosis[100];
        int count;
    } DiseaseStatistic;

    DiseaseStatistic statistics[100];
    int stat_count = 0;

    for (int i = 0; i < patient_count; i++) {
        int found = 0;
        for (int j = 0; j < stat_count; j++) {
            if (strcmp(patients[i].diagnosis, statistics[j].diagnosis) == 0) {
                statistics[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(statistics[stat_count].diagnosis, patients[i].diagnosis);
            statistics[stat_count].count = 1;
            stat_count++;
        }
    }

    // Sort statistics by count (descending)
    for (int i = 0; i < stat_count - 1; i++) {
        for (int j = i + 1; j < stat_count; j++) {
            if (statistics[j].count > statistics[i].count) {
                DiseaseStatistic temp = statistics[i];
                statistics[i] = statistics[j];
                statistics[j] = temp;
            }
        }
    }

    printf("Statistik Penyakit:\n");
    for (int i = 0; i < stat_count; i++) {
        printf("%s: %d pasien\n", statistics[i].diagnosis, statistics[i].count);
    }
}

int main() {
    int choice;

    while (1) {
        printf("Aplikasi Pencatatan Pasien\n");
        printf("1. Tambah Pasien\n");
        printf("2. Ubah Pasien\n");
        printf("3. Hapus Pasien\n");
        printf("4. Cari Pasien\n");
        printf("5. Daftar Pasien\n");
        printf("6. Daftar Pasien yang Perlu Kontrol\n");
        printf("7. Laporan Pendapatan\n");
        printf("8. Statistik Penyakit\n");
        printf("9. Impor Data dari CSV\n");
        printf("10. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int id, age, follow_up_days;
                    char name[50], gender[10], diagnosis[100], treatment[100];
                    printf("Masukkan ID pasien: ");
                    scanf("%d", &id);
                    printf("Masukkan nama pasien: ");
                    scanf(" %[^\n]", name);
                    printf("Masukkan umur pasien: ");
                    scanf("%d", &age);
                    printf("Masukkan jenis kelamin pasien: ");
                    scanf(" %s", gender);
                    printf("Masukkan diagnosis: ");
                    scanf(" %[^\n]", diagnosis);
                    printf("Masukkan perawatan: ");
                    scanf(" %[^\n]", treatment);
                    printf("Masukkan hari kontrol: ");
                    scanf("%d", &follow_up_days);
                    add_patient(id, name, age, gender, diagnosis, treatment, follow_up_days);
                }
                break;
            case 2:
                update_patient();
                break;
            case 3:
                delete_patient();
                break;
            case 4:
                search_patient();
                break;
            case 5:
                list_patients();
                break;
            case 6:
                list_follow_up_patients();
                break;
            case 7:
                generate_revenue_report();
                break;
            case 8:
                generate_disease_statistics();
                break;
            case 9:
                {
                    char filename[100];
                    printf("Masukkan nama file CSV: ");
                    scanf(" %s", filename);
                    import_data(filename);
                }
                break;
            case 10:
                exit(0);
            default:
                printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}