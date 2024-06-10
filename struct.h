#ifndef STRUCT_H
#define STRUCT_H

#define MAX_PATIENTS 100
#define MAX_RECORDS 100
#define MAX_LINE_LENGTH 1024
#define MAX_STRING_LENGTH 100

typedef struct {
    int id;
    char name[MAX_STRING_LENGTH];
    char address[MAX_STRING_LENGTH];
    char city[MAX_STRING_LENGTH];
    char birth_place[MAX_STRING_LENGTH];
    char birth_date[MAX_STRING_LENGTH];
    int age;
    char bpjs[MAX_STRING_LENGTH];
    char patient_id[MAX_STRING_LENGTH];
} Patient;

typedef struct {
    int id;
    char date[11];
    char patient_id[10];
    char diagnosis[100];
    char treatment[100];
    char control_date[11];
    int cost;
} MedicalRecord;

void ConvertDate(char date[30], char *result);
void load_data();
void addPatient();
void updatePatient();
void deletePatient();
void displayPatient();
void addMedicalRecord();
void updateMedicalRecord();
void deleteMedicalRecord();
void displayMedicalRecord();
void displayPatientWithMedicalRecords();
void getMonthlyRevenueReport(int month, int year);
void getAnnualRevenueReport(int year);
void getAverageAnnualRevenue();
void getPatientAndDiseaseReport(int month, int year);
void getAnnualPatientAndDiseaseReport(int year);
void displayPatientsForControl();

#endif