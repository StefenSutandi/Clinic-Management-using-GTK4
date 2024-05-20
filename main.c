#include "library.h"
#include <stdio.h>
#include <stdlib.h>

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