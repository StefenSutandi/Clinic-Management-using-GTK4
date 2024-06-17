#ifndef FUNGSI_H
#define FUNGSI_H

#include <gtk/gtk.h>

GtkWidget *stack;
GtkWidget *MainPage;
GtkWidget *StartingPage;
GtkWidget *Page[16];
GtkWidget *LabelWarning;
GtkWidget *name_show;
GtkWidget *adress_show;
GtkWidget *city_show;
GtkWidget *birth_place_show;
GtkWidget *birth_date_show;
GtkWidget *age_show;
GtkWidget *bpjs_show;
GtkWidget *patient_id_show;
GtkWidget *report_label4;
GtkWidget *report_label5;
GtkWidget *report_label7;
GtkWidget *ScrollGrid;
GtkWidget *name_show8;
GtkWidget *adress_show8;
GtkWidget *city_show8;
GtkWidget *birth_place_show8;
GtkWidget *birth_date_show8;
GtkWidget *age_show8;
GtkWidget *bpjs_show8;
GtkWidget *patient_id_show8;
GtkWidget *report_label8;
GtkWidget *ScrollGrid9;
GtkWidget *ScrollGrid9_2;
GtkWidget *ScrollGrid9_3;
GtkWidget *ScrollGrid9_4;
GtkWidget *MonthlyShow;
GtkWidget *AnnualShow;
GtkWidget *AverageShow;
GtkWidget *ScrollGrid12;

const char* getMonthName(int month);
const char * months[12];

void on_go_to_main(GtkButton *button, gpointer user_data);
void go_to_Page_1(GtkButton *button, gpointer user_data);
void go_to_Page_2(GtkButton *button, gpointer user_data);
void go_to_Page_3(GtkButton *button, gpointer user_data);
void go_to_Page_4(GtkButton *button, gpointer user_data);
void go_to_Page_5(GtkButton *button, gpointer user_data);
void go_to_Page_6(GtkButton *button, gpointer user_data);
void go_to_Page_7(GtkButton *button, gpointer user_data);
void go_to_Page_8(GtkButton *button, gpointer user_data);
void go_to_Page_9(GtkButton *button, gpointer user_data);
void go_to_Page_10(GtkButton *button, gpointer user_data);
void go_to_Page_11(GtkButton *button, gpointer user_data);
void go_to_Page_12(GtkButton *button, gpointer user_data);
void go_to_Page_13(GtkButton *button, gpointer user_data);

GtkWidget* addFixed(GtkWidget *destination);
GtkWidget* addButton(GtkWidget *destination, const char *namaButton);
GtkWidget* addReport(GtkWidget *destination);
GtkWidget* CreateButton(const char *label, GtkWidget *grid, int column, int row,const char *path) ;
GtkWidget* iconButton(const char *path, const char *label, const char *csst, const char *csst2);
GtkWidget* NextButton(const char *path, const char *label, const char *csst, const char *csst2);
GtkWidget* create_page(GtkWidget *notebook, const char *tab_label_text, const char *content_text, const char *namafoto);
GtkWidget* setinput(GtkWidget *namaVariabel, const char *namaPlaceholder, GtkWidget *nama_box, const char *path);

void EditGrid(GtkWidget *grid, GtkWidget **show, int column, int row);
void clearGrids(GtkWidget* gridx);

bool isDuplicatePatient(const char *name, const char *bpjs);
int findPatientById(const char* patient_id);
int findMedicalRecordById(int id);
void ConvertDate(char date[30], char *result);
void load_data();
const char* getMonthName(int month);
void displayPatientsForControl();
void WriteFileData();
void WriteFileRecord();

#endif //FUNGSI_H