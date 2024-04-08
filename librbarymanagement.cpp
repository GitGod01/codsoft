#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a book
struct Book {
    string title;
    string author;
    int id;
    bool available;
};

// Function to add a book to the library
void addBook(vector<Book>& library, const Book& book) {
    library.push_back(book);
}

// Function to display all available books
void displayAvailableBooks(const vector<Book>& library) {
    cout << "Available books:" << endl;
    for (const Book& book : library) {
        if (book.available) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", ID: " << book.id << endl;
        }
    }
}

// Function to lend a book
void lendBook(vector<Book>& library, int id) {
    for (Book& book : library) {
        if (book.id == id && book.available) {
            book.available = false;
            cout << "Book '" << book.title << "' has been successfully lent." << endl;
            return;
        }
    }
    cout << "Book with ID " << id << " is either not available or does not exist." << endl;
}

// Function to return a book
void returnBook(vector<Book>& library, int id) {
    for (Book& book : library) {
        if (book.id == id && !book.available) {
            book.available = true;
            cout << "Book '" << book.title << "' has been successfully returned." << endl;
            return;
        }
    }
    cout << "Book with ID " << id << " is either already available or does not exist." << endl;
}

int main() {
    vector<Book> library;

    // Sample books
    Book book1 = {"The Great Gatsby", "F. Scott Fitzgerald", 1, true};
    Book book2 = {"To Kill a Mockingbird", "Harper Lee", 2, true};
    Book book3 = {"1984", "George Orwell", 3, true};

    // Adding books to the library
    addBook(library, book1);
    addBook(library, book2);
    addBook(library, book3);

    int choice;
    do {
        cout << "\nLibrary Management System Menu:\n";
        cout << "1. Display available books\n";
        cout << "2. Lent a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAvailableBooks(library);
                break;
            case 2:
                int lendId;
                cout << "Enter the ID of the book to lend: ";
                cin >> lendId;
                lendBook(library, lendId);
                break;
            case 3:
                int returnId;
                cout << "Enter the ID of the book to return: ";
                cin >> returnId;
                returnBook(library, returnId);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
