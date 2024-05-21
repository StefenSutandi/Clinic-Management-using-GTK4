#include <stdio.h>
#include <string.h>
#include "library.h"

void tambahPasien(Pasien *data_p, int *jumlah_p) {
    if (*jumlah_p >= 100) {
        printf("Kapasitas data pasien penuh!\n");
        return;
    }
    printf("Nama Lengkap: ");
    scanf(" %[^\n]", data_p[*jumlah_p].nama_lengkap);
    printf("Alamat: ");
    scanf(" %[^\n]", data_p[*jumlah_p].alamat);
    printf("Kota: ");
    scanf(" %[^\n]", data_p[*jumlah_p].kota);
    printf("Tempat Lahir: ");
    scanf(" %[^\n]", data_p[*jumlah_p].tempat_lahir);
    printf("Tanggal Lahir (YYYY-MM-DD): ");
    scanf(" %[^\n]", data_p[*jumlah_p].tanggal_lahir);
    printf("Umur: ");
    scanf("%d", &data_p[*jumlah_p].umur);
    printf("No BPJS: ");
    scanf(" %[^\n]", data_p[*jumlah_p].no_bpjs);
    printf("ID Pasien: ");
    scanf(" %[^\n]", data_p[*jumlah_p].id_pasien);
    (*jumlah_p)++;
}

void lihatPasien(Pasien *data_p, int jumlah_p) {
    for (int i = 0; i < jumlah_p; i++) {
        printf("Pasien %d:\n", i + 1);
        printf("Nama Lengkap: %s\n", data_p[i].nama_lengkap);
        printf("Alamat: %s\n", data_p[i].alamat);
        printf("Kota: %s\n", data_p[i].kota);
        printf("Tempat Lahir: %s\n", data_p[i].tempat_lahir);
        printf("Tanggal Lahir: %s\n", data_p[i].tanggal_lahir);
        printf("Umur: %d\n", data_p[i].umur);
        printf("No BPJS: %s\n", data_p[i].no_bpjs);
        printf("ID Pasien: %s\n", data_p[i].id_pasien);
    }
}

void ubahPasien(Pasien *data_p, int jumlah_p) {
    char id[20];
    printf("Masukkan ID Pasien yang ingin diubah: ");
    scanf(" %[^\n]", id);
    for (int i = 0; i < jumlah_p; i++) {
        if (strcmp(data_p[i].id_pasien, id) == 0) {
            printf("Nama Lengkap: ");
            scanf(" %[^\n]", data_p[i].nama_lengkap);
            printf("Alamat: ");
            scanf(" %[^\n]", data_p[i].alamat);
            printf("Kota: ");
            scanf(" %[^\n]", data_p[i].kota);
            printf("Tempat Lahir: ");
            scanf(" %[^\n]", data_p[i].tempat_lahir);
            printf("Tanggal Lahir (YYYY-MM-DD): ");
            scanf(" %[^\n]", data_p[i].tanggal_lahir);
            printf("Umur: ");
            scanf("%d", &data_p[i].umur);
            printf("No BPJS: ");
            scanf(" %[^\n]", data_p[i].no_bpjs);
            printf("ID Pasien: ");
            scanf(" %[^\n]", data_p[i].id_pasien);
            return;
        }
    }
    printf("ID Pasien tidak ditemukan!\n");
}

void hapusPasien(Pasien *data_p, int *jumlah_p) {
    char id[20];
    printf("Masukkan ID Pasien yang ingin dihapus: ");
    scanf(" %[^\n]", id);
    for (int i = 0; i < *jumlah_p; i++) {
        if (strcmp(data_p[i].id_pasien, id) == 0) {
            for (int j = i; j < *jumlah_p - 1; j++) {
                data_p[j] = data_p[j + 1];
            }
            (*jumlah_p)--;
            printf("Pasien berhasil dihapus.\n");
            return;
        }
    }
    printf("ID Pasien tidak ditemukan!\n");
}

void tambahRiwayat(RiwayatKedatangan *data_r, int *jumlah_r) {
    printf("Tanggal (YYYY-MM-DD): ");
    scanf(" %[^\n]", data_r[*jumlah_r].tanggal);
    printf("Diagnosis: ");
    scanf(" %[^\n]", data_r[*jumlah_r].diagnosis);
    printf("Tindakan: ");
    scanf(" %[^\n]", data_r[*jumlah_r].tindakan);
    printf("Kontrol (YYYY-MM-DD): ");
    scanf(" %[^\n]", data_r[*jumlah_r].kontrol);
    printf("Biaya: ");
    scanf("%f", &data_r[*jumlah_r].biaya);
    printf("ID Pasien: ");
    scanf(" %[^\n]", data_r[*jumlah_r].id_pasien);
    (*jumlah_r)++;
}

void lihatRiwayat(RiwayatKedatangan *data_r, int jumlah_r) {
    for (int i = 0; i < jumlah_r; i++) {
        printf("Riwayat Kedatangan %d:\n", i + 1);
        printf("Tanggal: %s\n", data_r[i].tanggal);
        printf("Diagnosis: %s\n", data_r[i].diagnosis);
        printf("Tindakan: %s\n", data_r[i].tindakan);
        printf("Kontrol: %s\n", data_r[i].kontrol);
        printf("Biaya: %.2f\n", data_r[i].biaya);
        printf("ID Pasien: %s\n", data_r[i].id_pasien);
    }
}

void ubahRiwayat(RiwayatKedatangan *data_r, int jumlah_r) {
    char tanggal[11];
    printf("Masukkan tanggal kedatangan yang ingin diubah (YYYY-MM-DD): ");
    scanf(" %[^\n]", tanggal);
    for (int i = 0; i < jumlah_r; i++) {
        if (strcmp(data_r[i].tanggal, tanggal) == 0) {
            printf("Diagnosis: ");
            scanf(" %[^\n]", data_r[i].diagnosis);
            printf("Tindakan: ");
            scanf(" %[^\n]", data_r[i].tindakan);
            printf("Kontrol (YYYY-MM-DD): ");
            scanf(" %[^\n]", data_r[i].kontrol);
            printf("Biaya: ");
            scanf("%f", &data_r[i].biaya);
            printf("ID Pasien: ");
            scanf(" %[^\n]", data_r[i].id_pasien);
            return;
        }
    }
    printf("Tanggal kedatangan tidak ditemukan!\n");
}

void hapusRiwayat(RiwayatKedatangan *data_r, int *jumlah_r) {
    char tanggal[11];
    printf("Masukkan tanggal kedatangan yang ingin dihapus (YYYY-MM-DD): ");
    scanf(" %[^\n]", tanggal);
    for (int i = 0; i < *jumlah_r; i++) {
        if (strcmp(data_r[i].tanggal, tanggal) == 0) {
            for (int j = i; j < *jumlah_r - 1; j++) {
                data_r[j] = data_r[j + 1];
            }
            (*jumlah_r)--;
            printf("Riwayat kedatangan berhasil dihapus.\n");
            return;
        }
    }
    printf("Tanggal kedatangan tidak ditemukan!\n");
}