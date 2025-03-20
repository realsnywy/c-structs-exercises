//! Question 2: Student Registration with Pointers
// Create a struct called Student, containing:
//* Name (string up to 50 characters)
//* Registration number (integer)
//* Grade 1 and Grade 2 (floats)
// Dynamically allocate 3 students, ask the user for the data, calculate each student’s average, and indicate if they were approved (average ≥ 7) or rejected. Finally, free the allocated memory.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char name[50];
    int registration;
    float grade1, grade2;
} Student;

// I could be using the word "allocate", but I'm going to use "create" instead, since it's easier for me to understand.
Student *createStudent()
{
    Student *s = (Student *)malloc(sizeof(Student));
    return s;
}

void registerStudent(Student *s)
{
    printf("Enter the student's name: ");
    scanf("%s", s->name);
    printf("Enter the student's registration number: ");
    scanf("%d", &s->registration);
    printf("Enter the student's first grade: ");
    scanf("%f", &s->grade1);
    printf("Enter the student's second grade: ");
    scanf("%f", &s->grade2);
}

void displayStudent(Student *s)
{
    printf("Name: %s\n", s->name);
    printf("Registration number: %d\n", s->registration);
    printf("Grade 1: %.2f\n", s->grade1);
    printf("Grade 2: %.2f\n", s->grade2);
}

// Now I'm going to create a function that returns the average of the student.
// Instead of using void, I'm going to use float, since it's going to return a value and not just print/scan it.
float averageStudent(Student *s)
{
    return (s->grade1 + s->grade2) / 2;
}

// Using the stdbool library, I can create a function that return `true` or `false` depending on the average of the student, that was "called" from previous function.
bool checkStudent(float average)
{
    if (average >= 7)
        return true;
    else
        return false;
}

int main()
{
    // Since it was asked to create 3 students, I'm going to use a loop (for) to create them.
    for (int i = 0; i < 3; i++)
    {
        printf("Student %d\n", i + 1);
        Student *s = createStudent();
        registerStudent(s);
        displayStudent(s);
        float average = averageStudent(s);
        bool check = checkStudent(average);
        if (check)
            printf("The student was approved.\n");
        else
            printf("The student was rejected.\n");
        free(s);
    }
    return 0;
}