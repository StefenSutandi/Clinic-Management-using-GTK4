#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

int bacaBiayaTindakan(BiayaTindakan biaya_tindakan[], const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Gagal membuka file %s\n", filename);
        return 0;
    }

    char buffer[MAX_STRING_LENGTH];
    int count = 0;

    fgets(buffer, MAX_STRING_LENGTH, file);
    while (fgets(buffer, MAX_STRING_LENGTH, file)) {
        sscanf(buffer, "%d,%[^,],%d", &biaya_tindakan[count].no, biaya_tindakan[count].aktivitas, &biaya_tindakan[count].biaya);
        count++;
    }

    fclose(file);
    return count;
}

int bacaDataPasien(DataPasien data_pasien[], const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Gagal membuka file %s\n", filename);
        return 0;
    }

    char buffer[MAX_STRING_LENGTH];
    int count = 0;

    fgets(buffer, MAX_STRING_LENGTH, file);
    while (fgets(buffer, MAX_STRING_LENGTH, file)) {
        sscanf(buffer, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%d,%[^,],%s",
               &data_pasien[count].no, data_pasien[count].nama, data_pasien[count].alamat,
               data_pasien[count].kota, data_pasien[count].tempat_lahir, data_pasien[count].tanggal_lahir,
               &data_pasien[count].umur, data_pasien[count].no_bpjs, data_pasien[count].id_pasien);
        count++;
    }

    fclose(file);
    return count;
}

int bacaRiwayatDatang(RiwayatDatang riwayat_datang[], const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Gagal membuka file %s\n", filename);
        return 0;
    }

    char buffer[MAX_STRING_LENGTH];
    int count = 0;

    fgets(buffer, MAX_STRING_LENGTH, file);
    while (fgets(buffer, MAX_STRING_LENGTH, file)) {
        sscanf(buffer, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%d",
               &riwayat_datang[count].no, riwayat_datang[count].tanggal, riwayat_datang[count].id_pasien,
               riwayat_datang[count].diagnosis, riwayat_datang[count].tindakan, riwayat_datang[count].kontrol,
               &riwayat_datang[count].biaya);
        count++;
    }

    fclose(file);
    return count;
}

DataPasien* cariPasienByID(DataPasien data_pasien[], int jumlah_pasien, const char* id_pasien) {
    for (int i = 0; i < jumlah_pasien; i++) {
        if (strcmp(data_pasien[i].id_pasien, id_pasien) == 0) {
            return &data_pasien[i];
        }
    }
    return NULL;
}

void hitungTotalBiaya(RiwayatDatang riwayat_datang[], int jumlah_riwayat, DataPasien data_pasien[], int jumlah_pasien) {
    for (int i = 0; i < jumlah_pasien; i++) {
        int total_biaya = 0;
        for (int j = 0; j < jumlah_riwayat; j++) {
            if (strcmp(data_pasien[i].id_pasien, riwayat_datang[j].id_pasien) == 0) {
                total_biaya += riwayat_datang[j].biaya;
            }
        }
        printf("Pasien: %s, Total Biaya: %d\n", data_pasien[i].nama, total_biaya);
    }
}

void tambahDataPasien(DataPasien data_pasien[], int* jumlah_pasien, DataPasien pasien_baru) {
    data_pasien[*jumlah_pasien] = pasien_baru;
    (*jumlah_pasien)++;
}

void ubahDataPasien(DataPasien data_pasien[], int jumlah_pasien, const char* id_pasien, DataPasien pasien_ubah) {
    DataPasien* pasien = cariPasienByID(data_pasien, jumlah_pasien, id_pasien);
    if (pasien) {
        *pasien = pasien_ubah;
    } else {
        printf("Pasien dengan ID %s tidak ditemukan.\n", id_pasien);
    }
}

void hapusDataPasien(DataPasien data_pasien[], int* jumlah_pasien, const char* id_pasien) {
    for (int i = 0; i < *jumlah_pasien; i++) {
        if (strcmp(data_pasien[i].id_pasien, id_pasien) == 0) {
            for (int j = i; j < *jumlah_pasien - 1; j++) {
                data_pasien[j] = data_pasien[j + 1];
            }
            (*jumlah_pasien)--;
            return;
        }
    }
    printf("Pasien dengan ID %s tidak ditemukan.\n", id_pasien);
}

void tambahRiwayatDatang(RiwayatDatang riwayat_datang[], int* jumlah_riwayat, RiwayatDatang riwayat_baru) {
    riwayat_datang[*jumlah_riwayat] = riwayat_baru;
    (*jumlah_riwayat)++;
}

void ubahRiwayatDatang(RiwayatDatang riwayat_datang[], int jumlah_riwayat, int no_riwayat, RiwayatDatang riwayat_ubah) {
    if (no_riwayat >= 0 && no_riwayat < jumlah_riwayat) {
        riwayat_datang[no_riwayat] = riwayat_ubah;
    } else {
        printf("Nomor riwayat tidak valid.\n");
    }
}

void hapusRiwayatDatang(RiwayatDatang riwayat_datang[], int* jumlah_riwayat, int no_riwayat) {
    if (no_riwayat >= 0 && no_riwayat < *jumlah_riwayat) {
        for (int i = no_riwayat; i < *jumlah_riwayat - 1; i++) {
            riwayat_datang[i] = riwayat_datang[i + 1];
        }
        (*jumlah_riwayat)--;
    } else {
        printf("Nomor riwayat tidak valid.\n");
    }
}

void laporanPendapatanBulanan(RiwayatDatang riwayat_datang[], int jumlah_riwayat, int bulan, int tahun) {
    int total_pendapatan = 0;
    for (int i = 0; i < jumlah_riwayat; i++) {
        int riwayat_bulan, riwayat_tahun;
        sscanf(riwayat_datang[i].tanggal, "%d-%d", &riwayat_bulan, &riwayat_tahun);
        if (riwayat_bulan == bulan && riwayat_tahun == tahun) {
            total_pendapatan += riwayat_datang[i].biaya;
        }
    }
    printf("Laporan Pendapatan Bulan %d Tahun %d: %d\n", bulan, tahun, total_pendapatan);
}

void laporanPendapatanTahunan(RiwayatDatang riwayat_datang[], int jumlah_riwayat, int tahun) {
    int total_pendapatan = 0;
    for (int i = 0; i < jumlah_riwayat; i++) {
        int riwayat_tahun;
        sscanf(riwayat_datang[i].tanggal, "%*d-%d", &riwayat_tahun);
        if (riwayat_tahun == tahun) {
            total_pendapatan += riwayat_datang[i].biaya;
        }
    }
    printf("Laporan Pendapatan Tahun %d: %d\n", tahun, total_pendapatan);
}

void rataRataPendapatanTahunan(RiwayatDatang riwayat_datang[], int jumlah_riwayat, int tahun_mulai, int tahun_selesai) {
    int total_pendapatan = 0;
    int tahun = tahun_mulai;
    int tahun_count = 0;

    while (tahun <= tahun_selesai) {
        for (int i = 0; i < jumlah_riwayat; i++) {
            int riwayat_tahun;
            sscanf(riwayat_datang[i].tanggal, "%*d-%d", &riwayat_tahun);
            if (riwayat_tahun == tahun) {
                total_pendapatan += riwayat_datang[i].biaya;
                tahun_count++;
            }
        }
        tahun++;
    }

    double rata_rata = (tahun_count > 0) ? (double)total_pendapatan / tahun_count : 0;
    printf("Rata-rata Pendapatan Tahun %d sampai %d: %.2lf\n", tahun_mulai, tahun_selesai, rata_rata);
}

void jumlahPasienPerBulan(RiwayatDatang riwayat_datang[], int jumlah_riwayat, int bulan, int tahun) {
    int count = 0;
    for (int i = 0; i < jumlah_riwayat; i++) {
        int riwayat_bulan, riwayat_tahun;
        sscanf(riwayat_datang[i].tanggal, "%d-%d", &riwayat_bulan, &riwayat_tahun);
        if (riwayat_bulan == bulan && riwayat_tahun == tahun) {
            count++;
        }
    }
    printf("Jumlah Pasien pada Bulan %d Tahun %d: %d\n", bulan, tahun, count);
}

void jumlahPenyakitPerBulan(RiwayatDatang riwayat_datang[], int jumlah_riwayat, int bulan, int tahun) {
    int count = 0;
    char penyakit[MAX_STRING_LENGTH][MAX_STRING_LENGTH];
    for (int i = 0; i < jumlah_riwayat; i++) {
        int riwayat_bulan, riwayat_tahun;
        sscanf(riwayat_datang[i].tanggal, "%d-%d", &riwayat_bulan, &riwayat_tahun);
        if (riwayat_bulan == bulan && riwayat_tahun == tahun) {
            int found = 0;
            for (int j = 0; j < count; j++) {
                if (strcmp(penyakit[j], riwayat_datang[i].diagnosis) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(penyakit[count], riwayat_datang[i].diagnosis);
                count++;
            }
        }
    }
    printf("Jumlah Penyakit pada Bulan %d Tahun %d: %d\n", bulan, tahun, count);
}

void pasienKontrol(RiwayatDatang riwayat_datang[], int jumlah_riwayat) {
    printf("Daftar Pasien yang Perlu Kembali Kontrol:\n");
    for (int i = 0; i < jumlah_riwayat; i++) {
        if (strcmp(riwayat_datang[i].kontrol, "Ya") == 0) {
            printf("Pasien: %s, Diagnosis: %s\n", riwayat_datang[i].id_pasien, riwayat_datang[i].diagnosis);
        }
    }
}