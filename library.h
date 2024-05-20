#ifndef library_h
#define library_h

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    char diagnosis[100];
    char treatment[100];
    int follow_up_days; // Hari kontrol berikutnya
} Patient;

extern Patient patients[100];
extern int patient_count;

void add_patient(int id, const char *name, int age, const char *gender, const char *diagnosis, const char *treatment, int follow_up_days);
void update_patient();
void delete_patient();
void search_patient();
void list_patients();
void list_follow_up_patients();
void import_data(const char *filename);
void generate_revenue_report();
void generate_disease_statistics();

#endif