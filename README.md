# Structs and Pointers in C - Exercises

This repository contains a collection of programs developed in C, with the aim of practicing (and understanding) the use of **structs** and **pointers**.

## Exercises

### 1. **Person Registration with Pointer**

- **Description:** Create a struct `Person` with fields for `name` (string) and `age` (integer). Dynamically allocate memory for a `Person` and allow the user to input the data. Display the data using a pointer.

### 2. **Student Registration with Pointers**

- **Description:** Create a struct `Student` with fields for `name` (string), `registration number` (integer), and `grades` (floats). Dynamically allocate memory for **3 students**, allow the user to input their data, calculate each student's **average** grade, and indicate whether they passed (average ≥ 7) or failed. Free the allocated memory at the end.

### 3. **Book Catalog with Pointers**

- **Description:** Create a struct `Book` with fields for `title` (string), `author` (string), and `year of publication` (integer). Dynamically allocate memory for **up to 5 books**, allow the user to input their data, and then search for a book by its title and display the information.

### 4. **Inventory Control with Pointers**

- **Description:** Create a struct `StockItem` with fields for `item name` (string), `code` (integer), `quantity` (integer), and `unit price` (float). Dynamically allocate memory for **up to 10 items**, calculate the **total inventory value**, and display the results. Free the allocated memory at the end.

### 5. **Date Comparison with Pointers**

- **Description:** Create a struct `Date` with fields for `day` (integer), `month` (integer), and `year` (integer). Implement a function that compares two `Date` structs (using pointers) and returns the **latest date**.
