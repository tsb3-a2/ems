#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>

bool isEmployeeIDUnique(const char* employeeID);
bool isDateValid(int day, int month, int year);
void menu();
void addEmployee();
void updateEmployee();
void displayEmployee();
void searchEmployee();
void deleteEmployee();
void exitProgram();

typedef struct {
    int day;
    int month;
    int year;
} Date;

struct Employee {
    char employeeID[50];
    char employeeName[50];
    int employeeAge;
    char employeeGender[50];
    char employeeEmail[50];
    char employeePhoneNumber[50];
    char employeeRole[50];
    char employeeDepartment[50];
    double employeeSalary;
    Date employeeBirthday;
    Date employeeHireDate;
};

bool isEmployeeIDUnique(const char* employeeID) {
    char existingID[50];
    char line[50];
    FILE *fptr = fopen("employee.dat", "rb");
    if(fptr == NULL) {
        printf("Unable to open file!\n");
        exit(0);
    }
    while(fgets(line, sizeof(line), fptr)) {
        if(sscanf(line, "%s", existingID)) {
            if(strcmp(existingID, employeeID) == 0) {
                printf("Invalid input, employee ID already in use!\n");
                sleep(2);
                fclose(fptr);
                return false;
            }
        }
    }
    fclose(fptr);
    return true;
}

bool isDateValid(int day, int month, int year) {
    if(year >= 1900 && year <= 9999) {
        if(month >= 1 && month <= 12) {
            if((day >= 1 && day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
                return true;
            } else if((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11)) {
                return true;
            } else if((day >= 1 && day <= 28) && (month == 2)) {
                return true;
            } else if(day == 29 && month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
                return true;
            } else {
                printf("Invalid input, please check your date!\n");
                sleep(2);
                return false;
            }
        } else {
            printf("Invalid input, please check your date!\n");
            sleep(2);
            return false;
        }
    } else {
        printf("Invalid input, please check your date!\n");
        sleep(2);
        return false;
    }
}

void menu() {
    int select;
    do {
        system("clear");
        printf("::::::::::::::::::::::::::::::::::::::::::\n");
        printf("::: [+] Employee Management System [+] :::\n");
        printf("::::::::::::::::::::::::::::::::::::::::::\n\n");
        printf("[1] Add employee\n");
        printf("[2] Update employee\n");
        printf("[3] Display employee\n");
        printf("[4] Search employee\n");
        printf("[5] Delete employee\n");
        printf("[0] Exit\n\n");
        printf("Enter number >> ");
        scanf("%d", &select);
        freopen(NULL, "r", stdin);
        switch(select) {
            case 1:
                addEmployee();
                break;
            case 2:
                updateEmployee();
                break;
            case 3:
                displayEmployee();
                break;
            case 4:
                searchEmployee();
                break;
            case 5:
                deleteEmployee();
                break;
            case 0:
                exitProgram();
                break;
            default:
                printf("Invalid input, function not found!\n");
                sleep(2);
        }
    } while(select != 1 && select != 2 && select != 3 && select != 4 && select != 5 && select != 0);
}

void addEmployee() {
    struct Employee employeeData;
    char confirmAdd, moreEmployee;
    FILE *fptr = fopen("employee.dat", "ab");
    if(fptr == NULL) {
        printf("Unable to open the file!\n");
        exit(0);
    }
    do {
        system("clear");
        printf("::::::::::::::::::::::::::::\n");
        printf("::: [+] Add Employee [+] :::\n");
        printf("::::::::::::::::::::::::::::\n\n");
        printf("Enter employee ID [Ex. A1]: ");
        scanf("%s", employeeData.employeeID);
        freopen(NULL, "r", stdin);
    } while(!isEmployeeIDUnique(employeeData.employeeID));
    printf("Enter employee name [Ex. Nickolas Barry]: ");
    scanf("%[^\n]s", employeeData.employeeName);
    freopen(NULL, "r", stdin);
    printf("Enter employee age [Ex. 30]: ");
    scanf("%d", &employeeData.employeeAge);
    freopen(NULL, "r", stdin);
    printf("Enter employee gender [Ex. Male]: ");
    scanf("%s", employeeData.employeeGender);
    freopen(NULL, "r", stdin);
    printf("Enter employee email [Ex. name@domain.com]: ");
    scanf("%s", employeeData.employeeEmail);
    freopen(NULL, "r", stdin);
    printf("Enter employee phone number [Ex. 0123456789]: ");
    scanf("%s", employeeData.employeePhoneNumber);
    freopen(NULL, "r", stdin);
    printf("Enter employee role [Ex. Programmer]: ");
    scanf("%[^\n]s", employeeData.employeeRole);
    freopen(NULL, "r", stdin);
    printf("Enter department [Ex. Software Engineering]: ");
    scanf("%[^\n]s", employeeData.employeeDepartment);
    freopen(NULL, "r", stdin);
    printf("Enter employee salary [Ex. 8500]: ");
    scanf("%lf", &employeeData.employeeSalary);
    freopen(NULL, "r", stdin);
    do {
        system("clear");
        printf(":::::::::::::::::::::::::::::::::\n");
        printf("::: [+] Employee Birthday [+] :::\n");
        printf(":::::::::::::::::::::::::::::::::\n\n");
        printf("Enter day [Ex. 1]: ");
        scanf("%d", &employeeData.employeeBirthday.day);
        freopen(NULL, "r", stdin);
        printf("Enter month [Ex. 1]: ");
        scanf("%d", &employeeData.employeeBirthday.month);
        freopen(NULL, "r", stdin);
        printf("Enter year [Ex. 1997]: ");
        scanf("%d", &employeeData.employeeBirthday.year);
        freopen(NULL, "r", stdin);
    } while(!isDateValid(employeeData.employeeBirthday.day, employeeData.employeeBirthday.month, employeeData.employeeBirthday.year));
    do {
        system("clear");
        printf("::::::::::::::::::::::::::::::::::\n");
        printf("::: [+] Employee Hire Date [+] :::\n");
        printf("::::::::::::::::::::::::::::::::::\n\n");
        printf("Enter day [Ex. 1]: ");
        scanf("%d", &employeeData.employeeHireDate.day);
        freopen(NULL, "r", stdin);
        printf("Enter month [Ex. 1]: ");
        scanf("%d", &employeeData.employeeHireDate.month);
        freopen(NULL, "r", stdin);
        printf("Enter year [Ex. 1997]: ");
        scanf("%d", &employeeData.employeeHireDate.year);
        freopen(NULL, "r", stdin);
    } while(!isDateValid(employeeData.employeeHireDate.day, employeeData.employeeHireDate.month, employeeData.employeeHireDate.year));
    do {
        system("clear");
        printf(":::::::::::::::::::::::::::::\n");
        printf("::: [+] Employee Data [+] :::\n");
        printf(":::::::::::::::::::::::::::::\n\n");
        printf("ID: %s\n", employeeData.employeeID);
        printf("Name: %s\n", employeeData.employeeName);
        printf("Age: %d\n", employeeData.employeeAge);
        printf("Gender: %s\n", employeeData.employeeGender);
        printf("Email: %s\n", employeeData.employeeEmail);
        printf("Phone number: %s\n", employeeData.employeePhoneNumber);
        printf("Role: %s\n", employeeData.employeeRole);
        printf("Department: %s\n", employeeData.employeeDepartment);
        printf("Salary: $ %.2lf\n", employeeData.employeeSalary);
        printf("Birthday: %d/%d/%d\n", employeeData.employeeBirthday.day, employeeData.employeeBirthday.month, employeeData.employeeBirthday.year);
        printf("Hire date: %d/%d/%d\n\n", employeeData.employeeHireDate.day, employeeData.employeeHireDate.month, employeeData.employeeHireDate.year);
        printf("Would you like to add this employee data? [y/n]: ");
        scanf("%c", &confirmAdd);
        freopen(NULL, "r", stdin);
        confirmAdd = toupper(confirmAdd);
        switch(confirmAdd) {
            case 'Y':
                fwrite(&employeeData, sizeof(struct Employee), 1, fptr);
                printf("Employee data added successfully!\n");
                sleep(2);
                break;
            case 'N':
                printf("Cancel, employee data didn't add!\n");
                sleep(2);
                break;
            default:
                printf("Invalid input, please select 'Y' or 'N'!\n");
                sleep(2);
        }
    } while(confirmAdd != 'Y' && confirmAdd != 'N');
    fclose(fptr);
    menu();
}

void updateEmployee() {
    struct Employee employeeData;
    int found = 0;
    char employeeID[50];
    char confirmEmployee, confirmUpdate, moreEmployee;
    FILE *fptr = fopen("employee.dat", "r");
    FILE *temp = fopen("temp.dat", "w");
    if(fptr == NULL || temp == NULL) {
        printf("Unable to open the file!\n");
        exit(0);
    }
    system("clear");
    printf(":::::::::::::::::::::::::::::::\n");
    printf("::: [+] Update Employee [+] :::\n");
    printf(":::::::::::::::::::::::::::::::\n\n");
    printf("Enter employee ID: ");
    scanf("%s", employeeID);
    freopen(NULL, "r", stdin);
    while(fread(&employeeData, sizeof(struct Employee), 1, fptr)) {
        if(strcmp(employeeData.employeeID, employeeID) == 0) {
            found = 1;
            do {
                system("clear");
                printf(":::::::::::::::::::::::::::::\n");
                printf("::: [+] Employee Data [+] :::\n");
                printf(":::::::::::::::::::::::::::::\n\n");
                printf("ID: %s\n", employeeData.employeeID);
                printf("Name: %s\n", employeeData.employeeName);
                printf("Age: %d\n", employeeData.employeeAge);
                printf("Gender: %s\n", employeeData.employeeGender);
                printf("Email: %s\n", employeeData.employeeEmail);
                printf("Phone number: %s\n", employeeData.employeePhoneNumber);
                printf("Role: %s\n", employeeData.employeeRole);
                printf("Department: %s\n", employeeData.employeeDepartment);
                printf("Salary: $ %.2lf\n", employeeData.employeeSalary);
                printf("Birthday: %d/%d/%d\n", employeeData.employeeBirthday.day, employeeData.employeeBirthday.month, employeeData.employeeBirthday.year);
                printf("Hire date: %d/%d/%d\n\n", employeeData.employeeHireDate.day, employeeData.employeeHireDate.month, employeeData.employeeHireDate.year);
                printf("Would you like to update this employee data? [y/n]: ");
                scanf("%c", &confirmEmployee);
                freopen(NULL, "r", stdin);
                confirmEmployee = toupper(confirmEmployee);
                switch(confirmEmployee) {
                    case 'Y':
                        do {
                            system("clear");
                            printf(":::::::::::::::::::::::::::::::\n");
                            printf("::: [+] Update Employee [+] :::\n");
                            printf(":::::::::::::::::::::::::::::::\n\n");
                            printf("Enter new employee ID [Ex. A1]: ");
                            scanf("%s", employeeData.employeeID);
                            freopen(NULL, "r", stdin);
                        } while(!isEmployeeIDUnique(employeeData.employeeID));
                        printf("Enter new employee name [Ex. Nickolas Barry]: ");
                        scanf("%[^\n]s", employeeData.employeeName);
                        freopen(NULL, "r", stdin);
                        printf("Enter new employee age [Ex. 30]: ");
                        scanf("%d", &employeeData.employeeAge);
                        freopen(NULL, "r", stdin);
                        printf("Enter new employee gender [Ex. Male]: ");
                        scanf("%s", employeeData.employeeGender);
                        freopen(NULL, "r", stdin);
                        printf("Enter new employee email [Ex. name@domain.com]: ");
                        scanf("%s", employeeData.employeeEmail);
                        freopen(NULL, "r", stdin);
                        printf("Enter new employee phone number [Ex. 0123456789]: ");
                        scanf("%s", employeeData.employeePhoneNumber);
                        freopen(NULL, "r", stdin);
                        printf("Enter new employee role [Ex. Programmer]: ");
                        scanf("%[^\n]s", employeeData.employeeRole);
                        freopen(NULL, "r", stdin);
                        printf("Enter new department [Ex. Software Engineering]: ");
                        scanf("%[^\n]s", employeeData.employeeDepartment);
                        freopen(NULL, "r", stdin);
                        printf("Enter new employee salary [Ex. 8500]: ");
                        scanf("%lf", &employeeData.employeeSalary);
                        freopen(NULL, "r", stdin);
                        do {
                            system("clear");
                            printf(":::::::::::::::::::::::::::::::::\n");
                            printf("::: [+] Employee Birthday [+] :::\n");
                            printf(":::::::::::::::::::::::::::::::::\n\n");
                            printf("Enter new day [Ex. 1]: ");
                            scanf("%d", &employeeData.employeeBirthday.day);
                            freopen(NULL, "r", stdin);
                            printf("Enter new month [Ex. 1]: ");
                            scanf("%d", &employeeData.employeeBirthday.month);
                            freopen(NULL, "r", stdin);
                            printf("Enter new year [Ex. 1997]: ");
                            scanf("%d", &employeeData.employeeBirthday.year);
                            freopen(NULL, "r", stdin);
                        } while(!isDateValid(employeeData.employeeBirthday.day, employeeData.employeeBirthday.month, employeeData.employeeBirthday.year));
                        do {
                            system("clear");
                            printf("::::::::::::::::::::::::::::::::::\n");
                            printf("::: [+] Employee Hire Date [+] :::\n");
                            printf("::::::::::::::::::::::::::::::::::\n\n");
                            printf("Enter new day [Ex. 1]: ");
                            scanf("%d", &employeeData.employeeHireDate.day);
                            freopen(NULL, "r", stdin);
                            printf("Enter new month [Ex. 1]: ");
                            scanf("%d", &employeeData.employeeHireDate.month);
                            freopen(NULL, "r", stdin);
                            printf("Enter new year [Ex. 1997]: ");
                            scanf("%d", &employeeData.employeeHireDate.year);
                            freopen(NULL, "r", stdin);
                        } while(!isDateValid(employeeData.employeeHireDate.day, employeeData.employeeHireDate.month, employeeData.employeeHireDate.year));
                        do {
                            system("clear");
                            printf(":::::::::::::::::::::::::::::\n");
                            printf("::: [+] Employee Data [+] :::\n");
                            printf(":::::::::::::::::::::::::::::\n\n");
                            printf("ID: %s\n", employeeData.employeeID);
                            printf("Name: %s\n", employeeData.employeeName);
                            printf("Age: %d\n", employeeData.employeeAge);
                            printf("Gender: %s\n", employeeData.employeeGender);
                            printf("Email: %s\n", employeeData.employeeEmail);
                            printf("Phone number: %s\n", employeeData.employeePhoneNumber);
                            printf("Role: %s\n", employeeData.employeeRole);
                            printf("Department: %s\n", employeeData.employeeDepartment);
                            printf("Salary: $ %.2lf\n", employeeData.employeeSalary);
                            printf("Birthday: %d/%d/%d\n", employeeData.employeeBirthday.day, employeeData.employeeBirthday.month, employeeData.employeeBirthday.year);
                            printf("Hire date: %d/%d/%d\n\n", employeeData.employeeHireDate.day, employeeData.employeeHireDate.month, employeeData.employeeHireDate.year);
                            printf("Would you like to update this employee data? [y/n]: ");
                            scanf("%c", &confirmUpdate);
                            freopen(NULL, "r", stdin);
                            confirmUpdate = toupper(confirmUpdate);
                            switch(confirmUpdate) {
                                case 'Y':
                                    fwrite(&employeeData, sizeof(struct Employee), 1, temp);
                                    printf("Employee data updated successfully!\n");
                                    sleep(2);
                                    remove("employee.dat");
                                    rename("temp.dat", "employee.dat");
                                    break;
                                case 'N':
                                    fwrite(&employeeData, sizeof(struct Employee), 1, temp);
                                    printf("Cancel, employee data didn't update!\n");
                                    sleep(2);
                                    break;
                                default:
                                    printf("Invalid input, please select 'Y' or 'N'!\n");
                                    sleep(2);
                            }
                        } while(confirmUpdate != 'Y' && confirmUpdate != 'N');
                        break;
                    case 'N':
                        fwrite(&employeeData, sizeof(struct Employee), 1, temp);
                        printf("Cancel, employee data didn't update!\n");
                        sleep(2);
                        break;
                    default:
                        printf("Invalid input, please select 'Y' or 'N'!\n");
                        sleep(2);
                }
            } while(confirmEmployee != 'Y' && confirmEmployee != 'N');
        } else {
            fwrite(&employeeData, sizeof(struct Employee), 1, temp);
        }
    }
    if(!found) {
        printf("Invalid input, employee not found!\n");
        sleep(2);
    }
    fclose(fptr);
    fclose(temp);
    menu();
}

void displayEmployee() {
    struct Employee employeeData;
    FILE *fptr = fopen("employee.dat", "rb");
    if(fptr == NULL) {
        printf("Unable to open file!\n");
        exit(0);
    }
    system("clear");
    printf(" %-25s %-25s %-25s %-25s %-30s %-25s %-25s %-25s %-25s %-25s %-25s \n", "Employee ID", "Employee Name", "Employee Age", "Employee Gender", "Employee Email", "Employee Phone Number", "Employee Role", "Department", "Employee Salary", "Employee Birthday", "Employee Hire Date");
    printf("=============================================================================================================================================================================================================================================================================================\n");
    while(fread(&employeeData, sizeof(struct Employee), 1, fptr)) {
        printf(" %-25s %-25s %-25d %-25s %-30s %-25s %-25s %-25s %-25.2lf %02d/%02d/%02d                %02d/%02d/%02d                \n", employeeData.employeeID, employeeData.employeeName, employeeData.employeeAge, employeeData.employeeGender, employeeData.employeeEmail, employeeData.employeePhoneNumber, employeeData.employeeRole, employeeData.employeeDepartment, employeeData.employeeSalary, employeeData.employeeBirthday.day, employeeData.employeeBirthday.month, employeeData.employeeBirthday.year, employeeData.employeeHireDate.day, employeeData.employeeHireDate.month, employeeData.employeeHireDate.year);
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
    printf("\nPress ENTER to continue!\n");
    getchar();
    fclose(fptr);
    menu();
}

void searchEmployee() {
    struct Employee employeeData;
    int found = 0;
    char employeeID[50];
    FILE *fptr = fopen("employee.dat", "rb");
    if(fptr == NULL) {
        printf("Unable to open file!\n");
        exit(0);
    }
    system("clear");
    printf(":::::::::::::::::::::::::::::::\n");
    printf("::: [+] Search Employee [+] :::\n");
    printf(":::::::::::::::::::::::::::::::\n\n");
    printf("Enter employee ID: ");
    scanf("%s", employeeID);
    freopen(NULL, "r", stdin);
    while(fread(&employeeData, sizeof(struct Employee), 1, fptr)) {
        if(strcmp(employeeData.employeeID, employeeID) == 0) {
            found = 1;
            system("clear");
            printf(":::::::::::::::::::::::::::::\n");
            printf("::: [+] Employee Data [+] :::\n");
            printf(":::::::::::::::::::::::::::::\n\n");
            printf("ID: %s\n", employeeData.employeeID);
            printf("Name: %s\n", employeeData.employeeName);
            printf("Age: %d\n", employeeData.employeeAge);
            printf("Gender: %s\n", employeeData.employeeGender);
            printf("Email: %s\n", employeeData.employeeEmail);
            printf("Phone number: %s\n", employeeData.employeePhoneNumber);
            printf("Role: %s\n", employeeData.employeeRole);
            printf("Department: %s\n", employeeData.employeeDepartment);
            printf("Salary: $ %.2lf\n", employeeData.employeeSalary);
            printf("Birthday: %d/%d/%d\n", employeeData.employeeBirthday.day, employeeData.employeeBirthday.month, employeeData.employeeBirthday.year);
            printf("Hire date: %d/%d/%d\n\n", employeeData.employeeHireDate.day, employeeData.employeeHireDate.month, employeeData.employeeHireDate.year);
            printf("Press ENTER to continue!\n");
            getchar();
        }
    }
    if(!found) {
        printf("Invalid input, employee not found!\n");
        sleep(2);
    }
    fclose(fptr);
    menu();
}

void deleteEmployee() {
    struct Employee employeeData;
    int found = 0;
    char confirmDelete, moreEmployee;
    char employeeID[50];
    FILE *fptr = fopen("employee.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if(fptr == NULL || temp == NULL) {
        printf("Unable to open file!\n");
        exit(0);
    }
    system("clear");
    printf(":::::::::::::::::::::::::::::::\n");
    printf("::: [+] Delete Employee [+] :::\n");
    printf(":::::::::::::::::::::::::::::::\n\n");
    printf("Enter employee ID: ");
    scanf("%s", employeeID);
    freopen(NULL, "r", stdin);
    while(fread(&employeeData, sizeof(struct Employee), 1, fptr)) {
        if(strcmp(employeeData.employeeID, employeeID) == 0) {
            found = 1;
            do {
                system("clear");
                printf(":::::::::::::::::::::::::::::\n");
                printf("::: [+] Employee Data [+] :::\n");
                printf(":::::::::::::::::::::::::::::\n\n");
                printf("ID: %s\n", employeeData.employeeID);
                printf("Name: %s\n", employeeData.employeeName);
                printf("Age: %d\n", employeeData.employeeAge);
                printf("Gender: %s\n", employeeData.employeeGender);
                printf("Email: %s\n", employeeData.employeeEmail);
                printf("Phone number: %s\n", employeeData.employeePhoneNumber);
                printf("Role: %s\n", employeeData.employeeRole);
                printf("Department: %s\n", employeeData.employeeDepartment);
                printf("Salary: $ %.2lf\n", employeeData.employeeSalary);
                printf("Birthday: %d/%d/%d\n", employeeData.employeeBirthday.day, employeeData.employeeBirthday.month, employeeData.employeeBirthday.year);
                printf("Hire date: %d/%d/%d\n\n", employeeData.employeeHireDate.day, employeeData.employeeHireDate.month, employeeData.employeeHireDate.year);
                printf("Would you like to delete this employee data? [y/n]: ");
                scanf("%c", &confirmDelete);
                freopen(NULL, "r", stdin);
                confirmDelete = toupper(confirmDelete);
                switch(confirmDelete) {
                    case 'Y':
                        printf("Employee data deleted successfully!\n");
                        sleep(2);
                        remove("employee.dat");
                        rename("temp.dat", "employee.dat");
                        break;
                    case 'N':
                        fwrite(&employeeData, sizeof(struct Employee), 1, temp);
                        printf("Cancel, employee data didn't delete!\n");
                        sleep(2);
                        remove("employee.dat");
                        rename("temp.dat", "employee.dat");
                        break;
                    default:
                        printf("Invalid input, please select 'Y' or 'N'!\n");
                        sleep(2);
                }
            } while(confirmDelete != 'Y' && confirmDelete != 'N');
        } else {
            fwrite(&employeeData, sizeof(struct Employee), 1, temp);
        }
    }
    if(!found) {
        printf("Invalid input, employee not found!\n");
        sleep(2);
    }
    fclose(fptr);
    fclose(temp);
    menu();
}

void exitProgram() {
    system("clear");
    printf("Goodbye!\n");
    exit(0);
}

int main() {
    menu();
    return 0;
}