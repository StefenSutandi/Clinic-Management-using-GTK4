#ifndef STRUCT_H
#define STRUCT_H

#define MAX_PATIENTS 100
#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[50];
    char address[100];
    char city[50];
    char birth_place[50];
    char birth_date[11];
    int age;
    char bpjs[20];
    char patient_id[10];
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