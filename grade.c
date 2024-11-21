#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

// Student structure to store individual student information
typedef struct {
    int student_id;
    char name[MAX_NAME_LENGTH];
    float math_grade;
    float science_grade;
    float english_grade;
    float average_grade;
    char grade_letter;
} Student;

// Global array to store students
Student students[MAX_STUDENTS];
int student_count = 0;

// Function prototypes
int validate_grade(float grade);
char calculate_grade_letter(float average);
void add_student();
void display_students();
void calculate_average();
void save_to_file();
void load_from_file();
void search_student();
void update_student();
void delete_student();
void sort_students_by_id();
void sort_students_by_name();
void sort_students_by_average();

int main() {
    int choice;
    
    // Load existing data if available
    load_from_file();
    
    while(1) {
        printf("\n--- Student Grade Management System ---\n");
        printf("1. Add New Student\n");
        printf("2. Display All Students\n");
        printf("3. Calculate Student Averages\n");
        printf("4. Search Student\n");
        printf("5. Update Student Information\n");
        printf("6. Delete Student\n");
        printf("7. Sort Students\n");
        printf("8. Save Data\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: add_student(); break;
            case 2: display_students(); break;
            case 3: calculate_average(); break;
            case 4: search_student(); break;
            case 5: update_student(); break;
            case 6: delete_student(); break;
            case 7: {
                printf("\nSort By:\n");
                printf("1. Student ID\n");
                printf("2. Student Name\n");
                printf("3. Average Grade\n");
                printf("Enter sort choice: ");
                scanf("%d", &choice);
                
                switch(choice) {
                    case 1: sort_students_by_id(); break;
                    case 2: sort_students_by_name(); break;
                    case 3: sort_students_by_average(); break;
                    default: printf("Invalid sort option.\n");
                }
                break;
            }
            case 8: save_to_file(); break;
            case 9: 
                printf("Exiting program.\n");
                exit(0);
            default: 
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Input validation for grades
int validate_grade(float grade) {
    return (grade >= 0.0 && grade <= 100.0);
}

// Calculate grade letter based on average
char calculate_grade_letter(float average) {
    if (average >= 90.0) return 'A';
    if (average >= 80.0) return 'B';
    if (average >= 70.0) return 'C';
    if (average >= 60.0) return 'D';
    return 'F';
}

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Maximum student limit reached!\n");
        return;
    }
    
    Student new_student;
    
    // Validate Student ID
    do {
        printf("Enter Student ID (unique, positive): ");
        scanf("%d", &new_student.student_id);
        
        // Check for duplicate ID
        int duplicate = 0;
        for (int i = 0; i < student_count; i++) {
            if (students[i].student_id == new_student.student_id) {
                printf("Error: Student ID must be unique.\n");
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) break;
    } while(1);
    
    // Name validation
    do {
        printf("Enter Student Name (max 50 characters): ");
        scanf(" %[^\n]s", new_student.name);
        
        // Validate name contains only letters and spaces
        int valid_name = 1;
        for (int i = 0; new_student.name[i]; i++) {
            if (!isalpha(new_student.name[i]) && !isspace(new_student.name[i])) {
                valid_name = 0;
                break;
            }
        }
        
        if (valid_name) break;
        printf("Invalid name. Use only letters and spaces.\n");
    } while(1);
    
    // Grade validation
    do {
        printf("Enter Math Grade (0-100): ");
        scanf("%f", &new_student.math_grade);
        if (validate_grade(new_student.math_grade)) break;
        printf("Invalid grade. Must be between 0 and 100.\n");
    } while(1);
    
    do {
        printf("Enter Science Grade (0-100): ");
        scanf("%f", &new_student.science_grade);
        if (validate_grade(new_student.science_grade)) break;
        printf("Invalid grade. Must be between 0 and 100.\n");
    } while(1);
    
    do {
        printf("Enter English Grade (0-100): ");
        scanf("%f", &new_student.english_grade);
        if (validate_grade(new_student.english_grade)) break;
        printf("Invalid grade. Must be between 0 and 100.\n");
    } while(1);
    
    // Calculate average and grade letter
    new_student.average_grade = (new_student.math_grade + 
                                  new_student.science_grade + 
                                  new_student.english_grade) / 3.0;
    new_student.grade_letter = calculate_grade_letter(new_student.average_grade);
    
    students[student_count++] = new_student;
    printf("Student added successfully!\n");
}

void display_students() {
    if (student_count == 0) {
        printf("No students in the system.\n");
        return;
    }
    
    printf("\n--- Student Records ---\n");
    printf("ID\tName\t\tMath\tScience\tEnglish\tAverage\tGrade\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d\t%s\t\t%.1f\t%.1f\t%.1f\t%.1f\t%c\n", 
               students[i].student_id, 
               students[i].name, 
               students[i].math_grade,
               students[i].science_grade,
               students[i].english_grade,
               students[i].average_grade,
               students[i].grade_letter);
    }
}

void calculate_average() {
    for (int i = 0; i < student_count; i++) {
        students[i].average_grade = (students[i].math_grade + 
                                     students[i].science_grade + 
                                     students[i].english_grade) / 3.0;
        students[i].grade_letter = calculate_grade_letter(students[i].average_grade);
    }
    printf("Averages and grade letters calculated and updated!\n");
    display_students();
}

void save_to_file() {
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    // Write student count first
    fwrite(&student_count, sizeof(int), 1, file);
    
    // Write all student records
    fwrite(students, sizeof(Student), student_count, file);
    
    fclose(file);
    printf("Data saved successfully!\n");
}

void load_from_file() {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("No existing data file found.\n");
        return;
    }
    
    // Read student count
    fread(&student_count, sizeof(int), 1, file);
    
    // Read student records
    fread(students, sizeof(Student), student_count, file);
    
    fclose(file);
    printf("Data loaded successfully!\n");
}

void search_student() {
    int search_id;
    printf("Enter Student ID to search: ");
    scanf("%d", &search_id);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].student_id == search_id) {
            printf("Student Found:\n");
            printf("ID: %d\n", students[i].student_id);
            printf("Name: %s\n", students[i].name);
            printf("Math Grade: %.1f\n", students[i].math_grade);
            printf("Science Grade: %.1f\n", students[i].science_grade);
            printf("English Grade: %.1f\n", students[i].english_grade);
            printf("Average Grade: %.1f\n", students[i].average_grade);
            printf("Grade Letter: %c\n", students[i].grade_letter);
            return;
        }
    }
    printf("Student not found.\n");
}

void update_student() {
    int search_id;
    printf("Enter Student ID to update: ");
    scanf("%d", &search_id);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].student_id == search_id) {
            printf("Current Student Details:\n");
            printf("Name: %s\n", students[i].name);
            
            // Grade validation for updates
            do {
                printf("Enter New Math Grade (0-100): ");
                scanf("%f", &students[i].math_grade);
                if (validate_grade(students[i].math_grade)) break;
                printf("Invalid grade. Must be between 0 and 100.\n");
            } while(1);
            
            do {
                printf("Enter New Science Grade (0-100): ");
                scanf("%f", &students[i].science_grade);
                if (validate_grade(students[i].science_grade)) break;
                printf("Invalid grade. Must be between 0 and 100.\n");
            } while(1);
            
            do {
                printf("Enter New English Grade (0-100): ");
                scanf("%f", &students[i].english_grade);
                if (validate_grade(students[i].english_grade)) break;
                printf("Invalid grade. Must be between 0 and 100.\n");
            } while(1);
            
            // Recalculate average and grade letter
            students[i].average_grade = (students[i].math_grade + 
                                         students[i].science_grade + 
                                         students[i].english_grade) / 3.0;
            students[i].grade_letter = calculate_grade_letter(students[i].average_grade);
            
            printf("Student information updated!\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void delete_student() {
    int search_id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &search_id);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].student_id == search_id) {
            // Shift elements to remove the student
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student not found.\n");
}

// Sorting functions
void sort_students_by_id() {
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            if (students[j].student_id > students[j + 1].student_id) {
                // Swap students
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by ID.\n");
    display_students();
}

void sort_students_by_name() {
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                // Swap students
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by Name.\n");
    display_students();
}

void sort_students_by_average() {
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            if (students[j].average_grade < students[j + 1].average_grade) {
                // Swap students
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by Average Grade (Descending).\n");
    display_students();
}
