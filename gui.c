#include <gtk/gtk.h>
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

// Function prototypes
void add_patient(int id, const char *name, int age, const char *gender, const char *diagnosis, const char *treatment, int follow_up_days);
void on_add_patient(GtkWidget *widget, gpointer data);
void on_search_patient(GtkWidget *widget, gpointer data);
void on_list_patients(GtkWidget *widget, gpointer data);
void create_add_patient_window();
void create_search_patient_window();
void create_list_patients_window();

void add_patient(int id, const char *name, int age, const char *gender, const char *diagnosis, const char *treatment, int follow_up_days) {
    if (patient_count >= 100) {
        g_print("Kapasitas maksimal pasien tercapai.\n");
        return;
    }

    patients[patient_count].id = id;
    strncpy(patients[patient_count].name, name, sizeof(patients[patient_count].name));
    patients[patient_count].age = age;
    strncpy(patients[patient_count].gender, gender, sizeof(patients[patient_count].gender));
    strncpy(patients[patient_count].diagnosis, diagnosis, sizeof(patients[patient_count].diagnosis));
    strncpy(patients[patient_count].treatment, treatment, sizeof(patients[patient_count].treatment));
    patients[patient_count].follow_up_days = follow_up_days;

    patient_count++;
    g_print("Pasien berhasil ditambahkan!\n");
}

void on_add_patient(GtkWidget *widget, gpointer data) {
    GtkWidget *entry_id = g_object_get_data(G_OBJECT(widget), "entry_id");
    GtkWidget *entry_name = g_object_get_data(G_OBJECT(widget), "entry_name");
    GtkWidget *entry_age = g_object_get_data(G_OBJECT(widget), "entry_age");
    GtkWidget *entry_gender = g_object_get_data(G_OBJECT(widget), "entry_gender");
    GtkWidget *entry_diagnosis = g_object_get_data(G_OBJECT(widget), "entry_diagnosis");
    GtkWidget *entry_treatment = g_object_get_data(G_OBJECT(widget), "entry_treatment");
    GtkWidget *entry_follow_up_days = g_object_get_data(G_OBJECT(widget), "entry_follow_up_days");

    int id = atoi(gtk_entry_get_text(GTK_ENTRY(entry_id)));
    const char *name = gtk_entry_get_text(GTK_ENTRY(entry_name));
    int age = atoi(gtk_entry_get_text(GTK_ENTRY(entry_age)));
    const char *gender = gtk_entry_get_text(GTK_ENTRY(entry_gender));
    const char *diagnosis = gtk_entry_get_text(GTK_ENTRY(entry_diagnosis));
    const char *treatment = gtk_entry_get_text(GTK_ENTRY(entry_treatment));
    int follow_up_days = atoi(gtk_entry_get_text(GTK_ENTRY(entry_follow_up_days)));

    add_patient(id, name, age, gender, diagnosis, treatment, follow_up_days);

    gtk_widget_destroy(GTK_WIDGET(data));
}

void on_search_patient(GtkWidget *widget, gpointer data) {
    GtkWidget *entry_id = g_object_get_data(G_OBJECT(widget), "entry_id");

    int id = atoi(gtk_entry_get_text(GTK_ENTRY(entry_id)));
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
                                                       "ID: %d\nNama: %s\nUmur: %d\nJenis Kelamin: %s\nDiagnosis: %s\nPerawatan: %s\nHari Kontrol: %d",
                                                       patients[i].id, patients[i].name, patients[i].age, patients[i].gender,
                                                       patients[i].diagnosis, patients[i].treatment, patients[i].follow_up_days);
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
            return;
        }
    }
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK,
                                               "Pasien dengan ID %d tidak ditemukan.", id);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void on_list_patients(GtkWidget *widget, gpointer data) {
    GtkWidget *window;
    GtkWidget *scrolled_window;
    GtkWidget *view;
    GtkTextBuffer *buffer;
    GtkTextIter iter;
    char patient_info[256];

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Daftar Pasien");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

view = gtk_text_view_new();
gtk_text_view_set_editable(GTK_TEXT_VIEW(view), FALSE);
gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(view), FALSE);
buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
gtk_container_add(GTK_CONTAINER(scrolled_window), view);

gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);

if (patient_count == 0) {
    gtk_text_buffer_insert(buffer, &iter, "Tidak ada pasien yang tercatat.\n", -1);
} else {
    for (int i = 0; i < patient_count; i++) {
        snprintf(patient_info, sizeof(patient_info), "ID: %d\nNama: %s\nUmur: %d\nJenis Kelamin: %s\nDiagnosis: %s\nPerawatan: %s\nHari Kontrol: %d\n-----------------------\n",
                 patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].diagnosis, patients[i].treatment, patients[i].follow_up_days);
        gtk_text_buffer_insert(buffer, &iter, patient_info, -1);
    }
}

gtk_widget_show_all(window);
}

void create_add_patient_window() {
GtkWidget *window;
GtkWidget *grid;
GtkWidget *label_id, *label_name, *label_age, *label_gender, *label_diagnosis, *label_treatment, *label_follow_up_days;
GtkWidget *entry_id, *entry_name, *entry_age, *entry_gender, *entry_diagnosis, *entry_treatment, *entry_follow_up_days;
GtkWidget *button;
window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window), "Tambah Pasien");
gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);

grid = gtk_grid_new();
gtk_container_add(GTK_CONTAINER(window), grid);

label_id = gtk_label_new("ID Pasien:");
entry_id = gtk_entry_new();

label_name = gtk_label_new("Nama Pasien:");
entry_name = gtk_entry_new();

label_age = gtk_label_new("Umur Pasien:");
entry_age = gtk_entry_new();

label_gender = gtk_label_new("Jenis Kelamin:");
entry_gender = gtk_entry_new();

label_diagnosis = gtk_label_new("Diagnosis:");
entry_diagnosis = gtk_entry_new();

label_treatment = gtk_label_new("Perawatan:");
entry_treatment = gtk_entry_new();

label_follow_up_days = gtk_label_new("Hari Kontrol:");
entry_follow_up_days = gtk_entry_new();

button = gtk_button_new_with_label("Tambah");
g_object_set_data(G_OBJECT(button), "entry_id", entry_id);
g_object_set_data(G_OBJECT(button), "entry_name", entry_name);
g_object_set_data(G_OBJECT(button), "entry_age", entry_age);
g_object_set_data(G_OBJECT(button), "entry_gender", entry_gender);
g_object_set_data(G_OBJECT(button), "entry_diagnosis", entry_diagnosis);
g_object_set_data(G_OBJECT(button), "entry_treatment", entry_treatment);
g_object_set_data(G_OBJECT(button), "entry_follow_up_days", entry_follow_up_days);
g_signal_connect(button, "clicked", G_CALLBACK(on_add_patient), window);

gtk_grid_attach(GTK_GRID(grid), label_id, 0, 0, 1, 1);
gtk_grid_attach(GTK_GRID(grid), entry_id, 1, 0, 1, 1);

gtk_grid_attach(GTK_GRID(grid), label_name, 0, 1, 1, 1);
gtk_grid_attach(GTK_GRID(grid), entry_name, 1, 1, 1, 1);

gtk_grid_attach(GTK_GRID(grid), label_age, 0, 2, 1, 1);
gtk_grid_attach(GTK_GRID(grid), entry_age, 1, 2, 1, 1);

gtk_grid_attach(GTK_GRID(grid), label_gender, 0, 3, 1, 1);
gtk_grid_attach(GTK_GRID(grid), entry_gender, 1, 3, 1, 1);

gtk_grid_attach(GTK_GRID(grid), label_diagnosis, 0, 4, 1, 1);
gtk_grid_attach(GTK_GRID(grid), entry_diagnosis, 1, 4, 1, 1);

gtk_grid_attach(GTK_GRID(grid), label_treatment, 0, 5, 1, 1);
gtk_grid_attach(GTK_GRID(grid), entry_treatment, 1, 5, 1, 1);

gtk_grid_attach(GTK_GRID(grid), label_follow_up_days, 0, 6, 1, 1);
gtk_grid_attach(GTK_GRID(grid), entry_follow_up_days, 1, 6, 1, 1);

gtk_grid_attach(GTK_GRID(grid), button, 0, 7, 2, 1);

gtk_widget_show_all(window);
}

void create_search_patient_window() {
GtkWidget *window;
GtkWidget *grid;
GtkWidget *label_id;
GtkWidget *entry_id;
GtkWidget *button;
window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window), "Cari Pasien");
gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

grid = gtk_grid_new();
gtk_container_add(GTK_CONTAINER(window), grid);

label_id = gtk_label_new("ID Pasien:");
entry_id = gtk_entry_new();

button = gtk_button_new_with_label("Cari");
g_object_set_data(G_OBJECT(button), "entry_id", entry_id);
g_signal_connect(button, "clicked", G_CALLBACK(on_search_patient), NULL);

gtk_grid_attach(GTK_GRID(grid), label_id, 0, 0, 1, 1);
gtk_grid_attach(GTK_GRID(grid), entry_id, 1, 0, 1, 1);
gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 2, 1);

gtk_widget_show_all(window);

}

void create_list_patients_window() {
GtkWidget *window;
GtkWidget *scrolled_window;
GtkWidget *view;
GtkTextBuffer *buffer;
GtkTextIter iter;
char patient_info[256];
window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window), "Daftar Pasien");
gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

scrolled_window = gtk_scrolled_window_new(NULL, NULL);
gtk_container_add(GTK_CONTAINER(window), scrolled_window);

view = gtk_text_view_new();
gtk_text_view_set_editable(GTK_TEXT_VIEW(view), FALSE);
gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(view), FALSE);
buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
gtk_container_add(GTK_CONTAINER(scrolled_window), view);

gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);

if (patient_count == 0) {
    gtk_text_buffer_insert(buffer, &iter, "Tidak ada pasien yang tercatat.\n", -1);
} else {
    for (int i = 0; i < patient_count; i++) {
        snprintf(patient_info, sizeof(patient_info), "ID: %d\nNama: %s\nUmur: %d\nJenis Kelamin: %s\nDiagnosis: %s\nPerawatan: %s\nHari Kontrol: %d\n-----------------------\n",
                 patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].diagnosis, patients[i].treatment, patients[i].follow_up_days);
        gtk_text_buffer_insert(buffer, &iter, patient_info, -1);
    }
}

gtk_widget_show_all(window);
}

int main(int argc, char *argv[]) {
GtkWidget *window;
GtkWidget *grid;
GtkWidget *button_add, *button_search, *button_list;

gtk_init(&argc, &argv);

window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window), "Aplikasi Pencatatan Pasien");
gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

grid = gtk_grid_new();
gtk_container_add(GTK_CONTAINER(window), grid);

button_add = gtk_button_new_with_label("Tambah Pasien");
g_signal_connect(button_add, "clicked", G_CALLBACK(create_add_patient_window), NULL);

button_search = gtk_button_new_with_label("Cari Pasien");
g_signal_connect(button_search, "clicked", G_CALLBACK(create_search_patient_window), NULL);

button_list = gtk_button_new_with_label("Daftar Pasien");
g_signal_connect(button_list, "clicked", G_CALLBACK(create_list_patients_window), NULL);

gtk_grid_attach(GTK_GRID(grid), button_add, 0, 0, 1, 1);
gtk_grid_attach(GTK_GRID(grid), button_search, 0, 1, 1, 1);
gtk_grid_attach(GTK_GRID(grid), button_list, 0, 2, 1, 1);

gtk_widget_show_all(window);

gtk_main();

return 0;

}


// Penjelasan kode:
// 1. **Struct `Patient`**: Menyimpan data pasien.
// 2. **`add_patient`**: Fungsi untuk menambahkan pasien ke array `patients`.
// 3. **GUI Functions**:
//     - `create_add_patient_window`: Membuat jendela untuk menambahkan pasien baru.
//     - `create_search_patient_window`: Membuat jendela untuk mencari pasien berdasarkan ID.
//     - `create_list_patients_window`: Membuat jendela untuk menampilkan daftar semua pasien.
// 4. **Callback Functions**:
//     - `on_add_patient`: Menangani aksi penambahan pasien.
//     - `on_search_patient`: Menangani aksi pencarian pasien.
//     - `on_list_patients`: Menampilkan daftar pasien dalam jendela baru.
// 5. **Main Function**:
//     - Inisialisasi GTK dan membuat jendela utama dengan tiga tombol (Tambah Pasien, Cari Pasien, Daftar Pasien).

// Untuk mengompilasi dan menjalankan program ini, gunakan perintah berikut (dengan asumsi Anda menggunakan gcc):
// ```sh
// gcc -o patient_app main.c `pkg-config --cflags --libs gtk+-3.0`
// ./patient_app