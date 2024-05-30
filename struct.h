#ifndef STRUCT_H
#define STRUCT_H

#define MAX_PATIENTS 1000
#define MAX_RECORDS 10000

typedef struct {
    int id;
    char name[50];
    char address[100];
    char city[50];
    char birth_place[50];
    char birth_date[11]; // Format: YYYY-MM-DD
    int age;
    char bpjs[20];
    char patient_id[15];
} Patient;

typedef struct {
    int id;
    char date[11]; // Format: YYYY-MM-DD
    char patient_id[15];
    char diagnosis[100];
    char treatment[100];
    char control_date[11]; // Format: YYYY-MM-DD
    int cost;
} MedicalRecord;

extern Patient patients[MAX_PATIENTS];
extern MedicalRecord records[MAX_RECORDS];
extern int patient_count;
extern int record_count;

int findPatientById(const char* patient_id);
int findMedicalRecordById(int id);

#endif // STRUCT_H