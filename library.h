#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_STRING_LENGTH 100
#define MAX_PASIEN 100
#define MAX_RIWAYAT 100

typedef struct {
    int no;
    char aktivitas[MAX_STRING_LENGTH];
    int biaya;
} BiayaTindakan;

typedef struct {
    int no;
    char nama[MAX_STRING_LENGTH];
    char alamat[MAX_STRING_LENGTH];
    char kota[MAX_STRING_LENGTH];
    char tempat_lahir[MAX_STRING_LENGTH];
    char tanggal_lahir[MAX_STRING_LENGTH];
    int umur;
    char no_bpjs[MAX_STRING_LENGTH];
    char id_pasien[MAX_STRING_LENGTH];
} DataPasien;

typedef struct {
    int no;
    char tanggal[MAX_STRING_LENGTH];
    char id_pasien[MAX_STRING_LENGTH];
    char diagnosis[MAX_STRING_LENGTH];
    char tindakan[MAX_STRING_LENGTH];
    char kontrol[MAX_STRING_LENGTH];
    int biaya;
} RiwayatDatang;

int bacaBiayaTindakan(BiayaTindakan biaya_tindakan[], const char* filename);
int bacaDataPasien(DataPasien data_pasien[], const char* filename);
int bacaRiwayatDatang(RiwayatDatang riwayat_datang[], const char* filename);
DataPasien* cariPasienByID(DataPasien data_pasien[], int jumlah_pasien, const char* id_pasien);
void hitungTotalBiaya(RiwayatDatang riwayat_datang[], int jumlah_riwayat, DataPasien data_pasien[], int jumlah_pasien);
void tambahDataPasien(DataPasien data_pasien[], int* jumlah_pasien, DataPasien pasien_baru);
void ubahDataPasien(DataPasien data_pasien[], int jumlah_pasien, const char* id_pasien, DataPasien pasien_ubah);
void hapusDataPasien(DataPasien data_pasien[], int* jumlah_pasien, const char* id_pasien);
void tambahRiwayatDatang(RiwayatDatang riwayat_datang[], int* jumlah_riwayat, RiwayatDatang riwayat_baru);
void ubahRiwayatDatang(RiwayatDatang riwayat_datang[], int jumlah_riwayat, int no_riwayat, RiwayatDatang riwayat_ubah);
void hapusRiwayatDatang(RiwayatDatang riwayat_datang[], int* jumlah_riwayat, int no_riwayat);
void laporanPendapatanBulanan(RiwayatDatang riwayat_datang[], int jumlah_riwayat, int bulan, int tahun);
void laporanPendapatanTahunan(RiwayatDatang riwayat_datang[], int jumlah_riwayat, int tahun);
void rataRataPendapatanTahunan(RiwayatDatang riwayat_datang[], int jumlah_riwayat, int tahun_mulai, int tahun_selesai);
void jumlahPasienPerBulan(RiwayatDatang riwayat_datang[], int jumlah_riwayat, int bulan, int tahun);
void jumlahPenyakitPerBulan(RiwayatDatang riwayat_datang[], int jumlah_riwayat, int bulan, int tahun);
void pasienKontrol(RiwayatDatang riwayat_datang[], int jumlah_riwayat);
RiwayatDatang* cariRiwayatKedatanganPasien(RiwayatDatang riwayat_datang[], int jumlah_riwayat, const char* id_pasien);
void informasiPasienRiwayatMedis(RiwayatDatang riwayat_datang[], int jumlah_riwayat, const char* id_pasien);

#endif