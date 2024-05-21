#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

int main() {
    // Deklarasi variabel
    int choice, year, month;
    RiwayatDatang riwayat_datang[100];
    DataPasien data_pasien[100];
    BiayaTindakan biaya_tindakan[100];
    int jumlah_riwayat = 0;
    int jumlah_pasien = 0;
    int jumlah_tindakan = 0;

    // Baca data dari file csv
    jumlah_pasien = bacaDataPasien(data_pasien, "data_pasien.csv");
    jumlah_riwayat = bacaRiwayatDatang(riwayat_datang, "riwayat_datang.csv");
    jumlah_tindakan = bacaBiayaTindakan(biaya_tindakan, "biaya_tindakan.csv");

    do {
        // Tampilkan menu
        printf("\n=== APLIKASI PENCATATAN PASIEN KLINIK X ===\n");
        printf("1. Tambah Data Pasien\n");
        printf("2. Ubah Data Pasien\n");
        printf("3. Hapus Data Pasien\n");
        printf("4. Cari Data Pasien\n");
        printf("5. Tambah Riwayat Kedatangan Pasien\n");
        printf("6. Ubah Riwayat Kedatangan Pasien\n");
        printf("7. Hapus Riwayat Kedatangan Pasien\n");
        printf("8. Cari Riwayat Kedatangan Pasien\n");
        printf("9. Informasi Pasien dan Riwayat Medis\n");
        printf("10. Laporan Pendapatan Bulanan\n");
        printf("11. Laporan Pendapatan Tahunan\n");
        printf("12. Rata-rata Pendapatan Tahunan\n");
        printf("13. Jumlah Pasien per Bulan\n");
        printf("14. Jumlah Penyakit per Bulan\n");
        printf("15. Pasien yang Perlu Kembali Kontrol\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        // Proses pilihan menu
        switch (choice) {
            case 1:
                tambahDataPasien(data_pasien, &jumlah_pasien, (DataPasien){});
                break;
            case 2:
                ubahDataPasien(data_pasien, jumlah_pasien, "", (DataPasien){});
                break;
            case 3:
                hapusDataPasien(data_pasien, &jumlah_pasien, "");
                break;
            case 4:
                cariDataPasien(data_pasien, jumlah_pasien, "");
                break;
            case 5:
                tambahRiwayatKedatanganPasien(riwayat_datang, &jumlah_riwayat, (RiwayatDatang){});
                break;
            case 6:
                ubahRiwayatKedatanganPasien(riwayat_datang, jumlah_riwayat, -1, (RiwayatDatang){});
                break;
            case 7:
                hapusRiwayatKedatanganPasien(riwayat_datang, &jumlah_riwayat, -1);
                break;
            case 8:
                cariRiwayatKedatanganPasien(riwayat_datang, jumlah_riwayat, "");
                break;
            case 9:
                informasiPasienRiwayatMedis(riwayat_datang, jumlah_riwayat, "");
                break;
            case 10:
                printf("Masukkan bulan (1-12): ");
                scanf("%d", &month);
                printf("Masukkan tahun: ");
                scanf("%d", &year);
                laporanPendapatanBulanan(riwayat_datang, jumlah_riwayat, month, year);
                break;
            case 11:
                printf("Masukkan tahun: ");
                scanf("%d", &year);
                laporanPendapatanTahunan(riwayat_datang, jumlah_riwayat, year);
                break;
            case 12:
                printf("Masukkan tahun mulai: ");
                scanf("%d", &year);
                printf("Masukkan tahun selesai: ");
                int year_end;
                scanf("%d", &year_end);
                rataRataPendapatanTahunan(riwayat_datang, jumlah_riwayat, year, year_end);
                break;
            case 13:
                printf("Masukkan bulan (1-12): ");
                scanf("%d", &month);
                printf("Masukkan tahun: ");
                scanf("%d", &year);
                jumlahPasienPerBulan(riwayat_datang, jumlah_riwayat, month, year);
                break;
            case 14:
                printf("Masukkan bulan (1-12): ");
                scanf("%d", &month);
                printf("Masukkan tahun: ");
                scanf("%d", &year);
                jumlahPenyakitPerBulan(riwayat_datang, jumlah_riwayat, month, year);
                break;
            case 15:
                pasienKontrol(riwayat_datang, jumlah_riwayat);
                break;
            case 0:
                printf("Terima kasih telah menggunakan aplikasi ini.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih lagi.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}