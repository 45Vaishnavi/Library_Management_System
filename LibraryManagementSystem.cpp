#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;
};

class Library {
private:
    vector<Book> books;
    const string filename = "library_database.txt";

    void loadBooks() {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            books.clear();
            string line;
            while (getline(inFile, line)) {
                stringstream ss(line);
                string title, author, ISBN, availability;
                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, ISBN, ',');
                getline(ss, availability, ',');
                bool isAvailable = (availability == "1");
                books.push_back({title, author, ISBN, isAvailable});
            }
            inFile.close();
        }
    }

    void saveBooks() {
        ofstream outFile(filename);
        for (const auto& book : books) {
            outFile << book.title << "," << book.author << "," << book.ISBN << "," << book.isAvailable << endl;
        }
        outFile.close();
    }

public:
    Library() {
        loadBooks();
    }

    ~Library() {
        saveBooks();
    }

    void addBook() {
        
        displayAddBook();
        string title, author, ISBN;
        cout << "Enter book title: ";
        cin.ignore(); 
        getline(cin, title);
        cout << "Enter book author: ";
        getline(cin, author);
        cout << "Enter book ISBN: ";
        getline(cin, ISBN);
        Book newBook = {title, author, ISBN, true};
        books.push_back(newBook);
        cout << "Book added: " << title << " by " << author << endl;
        saveBooks();
    }

    void searchBook() {
        
        displaySearchBook();
        string query;
        cout << "Enter search query: ";
        cin.ignore(); 
        getline(cin, query);
        bool found = false;
        for (const auto& book : books) {
            if (book.title.find(query) != string::npos || 
                book.author.find(query) != string::npos || 
                book.ISBN.find(query) != string::npos) {
                cout << "Found: " << book.title << " by " << book.author << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No books found matching the query: " << query << endl;
        }
    }

    void checkoutBook() {
        
        displayCheckoutBook();
        string ISBN;
        cout << "Enter book ISBN to checkout: ";
        cin.ignore(); 
        getline(cin, ISBN);
        for (auto& book : books) {
            if (book.ISBN == ISBN) {
                if (book.isAvailable) {
                    book.isAvailable = false;
                    cout << "Book checked out: " << book.title << endl;
                } else {
                    cout << "Book is already checked out." << endl;
                }
                saveBooks();
                return;
            }
        }
        cout << "Book not found with ISBN: " << ISBN << endl;
    }

    void returnBook() {
        
        displayReturnBook();
        string ISBN;
        cout << "Enter book ISBN to return: ";
        cin.ignore(); 
        getline(cin, ISBN);
        for (auto& book : books) {
            if (book.ISBN == ISBN) {
                if (!book.isAvailable) {
                    book.isAvailable = true;
                    cout << "Book returned: " << book.title << endl;
                } else {
                    cout << "Book was not checked out." << endl;
                }
                saveBooks();
                return;
            }
        }
        cout << "Book not found with ISBN: " << ISBN << endl;
    }

    void displayBooks() {
        
        cout << "\n--- Library Books ---\n";
        if (books.empty()) {
            cout << "No books in the library.\n";
        } else {
            for (const auto& book : books) {
                cout << "Title: " << book.title 
                     << ", Author: " << book.author 
                     << ", ISBN: " << book.ISBN 
                     << ", Available: " << (book.isAvailable ? "Yes" : "No") 
                     << endl;
            }
        }
    }

    void displayAddBook() {
        cout << "\n--- Add Book ---\n";
        cout << "Please enter the following details:\n";
    }

    void displaySearchBook() {
        cout << "\n--- Search Book ---\n";
        cout << "Please enter a search query (title, author, or ISBN):\n";
    }

    void displayCheckoutBook() {
        cout << "\n--- Checkout Book ---\n";
        cout << "Please enter the ISBN of the book to checkout:\n";
    }

    void displayReturnBook() {
        cout << "\n--- Return Book ---\n";
        cout << "Please enter the ISBN of the book to return:\n";
    }

    void displayMenu() {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Checkout Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
    }
};

int main() {
    Library library;
    int choice;

    while (true) {
        system("CLS");
        char c;
        library.displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                cout << "\nPress any key to Contine...\n";
                cin >> c;
                break;
            case 2:
                library.searchBook();
                cout << "\nPress any key to Contine...\n";
                cin >> c;
                break;
            case 3:
                library.checkoutBook();
                cout << "\nPress any key to Contine...\n";
                cin >> c;
                break;
            case 4:
                library.returnBook();
                cout << "\nPress any key to Contine...\n";
                cin >> c;
                break;
            case 5:
                library.displayBooks();
                cout << "\nPress any key to Contine...\n";
                cin >> c;
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
