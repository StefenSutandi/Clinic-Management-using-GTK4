#include <stdio.h>
#include "struct.h"

void addPatient();
void updatePatient();
void deletePatient();
void displayPatient();
void addMedicalRecord();
void updateMedicalRecord();
void deleteMedicalRecord();
void displayMedicalRecord();
void displayPatientWithMedicalRecords();
void getMonthlyRevenueReport(int month, int year);
void getAnnualRevenueReport(int year);
void getAverageAnnualRevenue();
void getPatientAndDiseaseReport(int month, int year);
void getAnnualPatientAndDiseaseReport(int year);
void displayPatientsForControl();

int main() {
    int choice;
    while (1) {
        printf("\nAplikasi Pencatatan Pasien Klinik X\n");
        printf("1. Tambah Pasien\n");
        printf("2. Tampilkan Pasien\n");
        printf("3. Ubah Pasien\n");
        printf("4. Hapus Pasien\n");
        printf("5. Tambah Riwayat Medis\n");
        printf("6. Tampilkan Riwayat Medis\n");
        printf("7. Ubah Riwayat Medis\n");
        printf("8. Hapus Riwayat Medis\n");
        printf("9. Informasi Pasien dan Riwayat Medis\n");
        printf("10. Laporan Pendapatan Bulanan\n");
        printf("11. Laporan Pendapatan Tahunan\n");
        printf("12. Rata-rata Pendapatan Tahunan\n");
        printf("13. Laporan Pasien dan Penyakit Bulanan\n");
        printf("14. Laporan Pasien dan Penyakit Tahunan\n");
        printf("15. Informasi Pasien Kembali Kontrol\n");
        printf("16. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatient();
                break;
            case 3:
                updatePatient();
                break;
            case 4:
                deletePatient();
                break;
            case 5:
                addMedicalRecord();
                break;
            case 6:
                displayMedicalRecord();
                break;
            case 7:
                updateMedicalRecord();
                break;
            case 8:
                deleteMedicalRecord();
                break;
            case 9:
                displayPatientWithMedicalRecords();
                break;
            case 10: {
                int month, year;
                printf("Masukkan bulan (1-12): ");
                scanf("%d", &month);
                printf("Masukkan tahun: ");
                scanf("%d", &year);
                getMonthlyRevenueReport(month, year);
                break;
            }
            case 11: {
                int year;
                printf("Masukkan tahun: ");
                scanf("%d", &year);
                getAnnualRevenueReport(year);
                break;
            }
            case 12:
                getAverageAnnualRevenue();
                break;
            case 13: {
                int month, year;
                printf("Masukkan bulan (1-12): ");
                scanf("%d", &month);
                printf("Masukkan tahun: ");
                scanf("%d", &year);
                getPatientAndDiseaseReport(month, year);
                break;
            }
            case 14: {
                int year;
                printf("Masukkan tahun: ");
                scanf("%d", &year);
                getAnnualPatientAndDiseaseReport(year);
                break;
            }
            case 15:
                displayPatientsForControl();
                break;
            case 16:
                return 0;
            default:
                printf("Opsi tidak valid.\n");
        }
    }
}
