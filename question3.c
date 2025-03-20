//! Question 3: Book Catalog with Pointers
// Create a struct called Book, containing:
//* Title (string up to 100 characters)
//* Author (string up to 50 characters)
//* Year of publication (integer)
// Dynamically allocate a vector for up to 5 books. After the registration, allow the user to search for a book by its title and display its information.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // I'm going to use the strcmp function to compare the strings.

typedef struct
{
    char title[100];
    char author[50];
    int year;
} Book;

Book *createBook()
{
    Book *b = (Book *)malloc(sizeof(Book));
    return b;
}

void registerBook(Book *b)
{
    printf("Enter the book's title: ");
    scanf("%s", b->title);
    printf("Enter the book's author: ");
    scanf("%s", b->author);
    printf("Enter the book's year of publication: ");
    scanf("%d", &b->year);
}

void displayBook(Book *b)
{
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("Year of publication: %d\n", b->year);
}

int main()
{
    // While previously I've used a loop to create 3 students, now I'm going to create 5 books on an vector (or array, dunno how the "hip kids" calls nowadays), then I'm going to use a loop to register them.
    Book *books[5];
    for (int i = 0; i < 5; i++)
    {
        books[i] = createBook();
        printf("Registering book %d\n", i + 1);
        registerBook(books[i]);
    }

    // I've could made the search function in a separate function, but I'm going to do it here, since it's a simple search.
    char search[100];
    printf("Enter the title of the book you want to search: ");
    scanf("%s", search);

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(search, books[i]->title) == 0)
        {
            displayBook(books[i]);
            break;
        }
    }

    // Since we're talking about a vector, we gotta use a loop to free the memory.
    for (int i = 0; i < 5; i++)
    {
        free(books[i]);
    }

    //TODO I could fix the scan so it reads the entire string, but I'm too lazy to do it now.
    return 0;
}