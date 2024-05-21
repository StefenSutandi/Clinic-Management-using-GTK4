#ifndef library_h
#define library_h

typedef struct {
    char nama_lengkap[100];
    char alamat[200];
    char kota[100];
    char tempat_lahir[100];
    char tanggal_lahir[11]; // format: YYYY-MM-DD
    int umur;
    char no_bpjs[20];
    char id_pasien[20];
} Pasien;

typedef struct {
    char tanggal[11]; // format: YYYY-MM-DD
    char diagnosis[100];
    char tindakan[100];
    char kontrol[11]; // format: YYYY-MM-DD
    float biaya;
    char id_pasien[20];
} RiwayatKedatangan;

void tambahPasien(Pasien *data_p, int *jumlah_p);
void lihatPasien(Pasien *data_p, int jumlah_p);
void ubahPasien(Pasien *data_p, int jumlah_p);
void hapusPasien(Pasien *data_p, int *jumlah_p);

void tambahRiwayat(RiwayatKedatangan *data_r, int *jumlah_r);
void lihatRiwayat(RiwayatKedatangan *data_r, int jumlah_r);
void ubahRiwayat(RiwayatKedatangan *data_r, int jumlah_r);
void hapusRiwayat(RiwayatKedatangan *data_r, int *jumlah_r);

void bacaFileExcel(const char *namaFile, Pasien *data_p, int *jumlah_p);

#endif