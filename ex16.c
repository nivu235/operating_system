#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the employee structure
struct Employee {
    int emp_id;
    char emp_name[50];
    float emp_salary;
};

int main() {
    FILE *file;
    struct Employee emp;
    int choice;
    int record_number;

    // Open the random access file in binary mode
    file = fopen("employee.dat", "rb+");

    if (file == NULL) {
        file = fopen("employee.dat", "wb+");
    }

    while (1) {
        printf("\nEmployee Record System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employee\n");
        printf("3. Update Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add Employee
                printf("Enter Employee ID: ");
                scanf("%d", &emp.emp_id);
                printf("Enter Employee Name: ");
                scanf("%s", emp.emp_name);
                printf("Enter Employee Salary: ");
                scanf("%f", &emp.emp_salary);

                // Move the file pointer to the end of the file
                fseek(file, 0, SEEK_END);

                // Write the employee data to the file
                fwrite(&emp, sizeof(struct Employee), 1, file);
                break;

            case 2: // Display Employee
                printf("Enter Employee Record Number: ");
                scanf("%d", &record_number);

                // Move the file pointer to the desired record
                fseek(file, (record_number - 1) * sizeof(struct Employee), SEEK_SET);

                // Read the employee data from the file
                if (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
                    printf("Employee ID: %d\n", emp.emp_id);
                    printf("Employee Name: %s\n", emp.emp_name);
                    printf("Employee Salary: %.2f\n", emp.emp_salary);
                } else {
                    printf("Record not found.\n");
                }
                break;

            case 3: // Update Employee
                printf("Enter Employee Record Number: ");
                scanf("%d", &record_number);

                // Move the file pointer to the desired record
                fseek(file, (record_number - 1) * sizeof(struct Employee), SEEK_SET);

                // Read the employee data from the file
                if (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
                    printf("Enter New Employee Name: ");
                    scanf("%s", emp.emp_name);
                    printf("Enter New Employee Salary: ");
                    scanf("%f", &emp.emp_salary);

                    // Move the file pointer back to the beginning of the record
                    fseek(file, (record_number - 1) * sizeof(struct Employee), SEEK_SET);

                    // Write the updated employee data to the file
                    fwrite(&emp, sizeof(struct Employee), 1, file);
                    printf("Record updated successfully.\n");
                } else {
                    printf("Record not found.\n");
                }
                break;

            case 4: // Exit
                fclose(file);
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
