//! Question 1: Person Registration with Pointer
// Create a struct called Person, containing:
//* Name (string up to 50 characters)
//* Age (integer)
// Dynamically allocate a variable of type Person, ask the user to input the data, and display the information using a pointer.

#include <stdio.h>
#include <stdlib.h>

// From my understanding, using a struct is like holding a bunch of variables into a single "name".
typedef struct
{
    char name[50];
    int age;
} Person;

// This is where it got tricky for me... Because I've had to research a lot about pointers and how to use them.
// So basically, pointers are variables that "play around" (in other words, store?) with memory addresses.
Person *createPerson()
{
    Person *p = (Person *)malloc(sizeof(Person));
    return p;
}

// To save on lines of code on the main, I can creates functions, that points to the sctruct.
// This is a function that registers a person.
void registerPerson(Person *p)
{
    printf("Enter the person's name: ");
    scanf("%s", p->name);
    printf("Enter the person's age: ");
    scanf("%d", &p->age);
}

// Same as before, but this time, it displays the person's information.
void displayPerson(Person *p)
{
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
}

int main()
{
    Person *p = createPerson(); // This is where the pointer is created.
    registerPerson(p);          // Instead of writing the same code over and over again, I can just call the function.
    displayPerson(p);           // Same as before.
    free(p);                    // Instead of leaving the memory allocated, it's better to free it. (despite computers nowadays being able to handle it)
    return 0;                   // And... That's it.
}