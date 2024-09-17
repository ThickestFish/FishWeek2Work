#include <iostream>
#include <conio.h>
#include <string> // My brother suggested I used this sorry if it isn't valid or something

struct Book {
    std::string title;
    std::string author;
    int yearPublished;
    int numPages;
};
int main()
{
    const int NUM_BOOKS = 4;
    Book books[NUM_BOOKS] = {
{ "To Kill a Mockingbird", "Harper Lee", 1960, 281 },
        { "1984", "", 1949, 328 }, // Missing author
        { "The Great Gatsby", "F. Scott Fitzgerald", 1925, 1 },
        { "The Catcher in the Rye", "J.D. Salinger", 0 , 277 }
    };

    for (int i = 0; i < NUM_BOOKS; i++)
    {
        std::cout << books[i].title << " " << books[i].author << "\n";
    }
    std::cout << "Book List:\n";
    for (int i = 0; i < NUM_BOOKS; i++) {
        std::cout << "ID: " << i << "\n";
        std::cout << "Title: " << books[i].title << "\n";
        std::cout << "Author: " << books[i].author << "\n";
        std::cout << "Year Published: " << books[i].yearPublished << "\n";
        std::cout << "Number of Pages: " << books[i].numPages << "\n\n";
    }
    int bookID;
    std::cout << "Enter the ID of the book you want to update (0 - " << NUM_BOOKS - 1 << "): ";
    std::cin >> bookID;
    if (bookID >= 0 && bookID < NUM_BOOKS) {
        // Update the book
        std::cout << "Updating details for: " << books[bookID].title << "\n";

        std::cout << "Enter new author: ";
        std::cin.ignore();  // Ignore the newline character left in the input buffer
        std::getline(std::cin, books[bookID].author);

        std::cout << "Enter new year of publication: ";
        std::cin >> books[bookID].yearPublished;

        std::cout << "Enter new number of pages: ";
        std::cin >> books[bookID].numPages;

        // Ask if the user wants to save the changes
        char saveChanges;
        std::cout << "Do you want to save the changes? (Y/N): ";
        std::cin >> saveChanges;

        if (saveChanges == 'Y' || saveChanges == 'y') {
            // Display updated book information
            std::cout << "\nUpdated Book Information:\n";
            std::cout << "Title: " << books[bookID].title << "\n";
            std::cout << "Author: " << books[bookID].author << "\n";
            std::cout << "Year Published: " << books[bookID].yearPublished << "\n";
            std::cout << "Number of Pages: " << books[bookID].numPages << "\n";
        }
        else {
            std::cout << "Changes not saved.\n";
        }
    }
    else {
        std::cout << "Invalid book ID. Book not found.\n";
    }

    return 0;
}