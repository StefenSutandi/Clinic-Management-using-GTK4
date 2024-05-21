#include <stdio.h>
#include "library.h"

int main() {
    Pasien dataPasien[100];
    RiwayatKedatangan dataRiwayat[100];
    int jumlahPasien = 0;
    int jumlahRiwayat = 0;
    int pilihan;

    do {
        printf("\nMenu Utama\n");
        printf("1. Tambah Pasien\n");
        printf("2. Lihat Pasien\n");
        printf("3. Ubah Pasien\n");
        printf("4. Hapus Pasien\n");
        printf("5. Tambah Riwayat Kedatangan\n");
        printf("6. Lihat Riwayat Kedatangan\n");
        printf("7. Ubah Riwayat Kedatangan\n");
        printf("8. Hapus Riwayat Kedatangan\n");
        printf("9. Import Data dari Excel\n");
        printf("10. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahPasien(dataPasien, &jumlahPasien);
                break;
            case 2:
                lihatPasien(dataPasien, jumlahPasien);
                break;
            case 3:
                ubahPasien(dataPasien, jumlahPasien);
                break;
            case 4:
                hapusPasien(dataPasien, &jumlahPasien);
                break;
            case 5:
                tambahRiwayat(dataRiwayat, &jumlahRiwayat);
                break;
            case 6:
                lihatRiwayat(dataRiwayat, jumlahRiwayat);
                break;
            case 7:
                ubahRiwayat(dataRiwayat, jumlahRiwayat);
                break;
            case 8:
                hapusRiwayat(dataRiwayat, &jumlahRiwayat);
                break;
            case 9:
                bacaFileExcel("DataPMC20232024.xlsx", dataPasien, &jumlahPasien);
                break;
            case 10:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 10);

    return 0;
}