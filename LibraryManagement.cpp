#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>
#include <ctime>
using namespace std;

// Book class to represent a book in the library
class Book
{
private:
	string title;  
        string author; 
        bool isAvailable;
public:
        // Constructor to initialize a book with its title and author
	Book(string t, string a) : title(t), author(a), isAvailable(true) {}

    // Getter for the book title
	string getTitle()
	{
		return title;
	}

    // Getter for the book author
	string getAuthor()
	{
		return author;
	}

    // Getter for the book availability status
	bool getIsAvailability()
	{
		return 		isAvailable = true;
	}

    // Method to borrow the book (set availability to false)
	void borrowBook()
	{
		isAvailable = false;
	}

    // Method to return the book (set availability to true)
	void returnBook()
	{
		isAvailable = true;
	}

    // Method to display the book information
	void displayInfo()
	{
		cout << "title : " << title << " author : " << author << " Available : \n" << (isAvailable ? "Yes" : "No") << endl;
	}
};


// Library class to manage a collection of books
class Library
{
private:
	vector<Book> books;    // Vector to store the books in the library   
public:
    // Method to add a book to the library
	void addBook(Book b)
	{
		books.push_back(b);
	}

    // Method to display all books in the library
	void displayBooks()
	{
		cout << "\n Books in the Library : \n";

		for (auto& b : books)
		{
			b.displayInfo();
		}
	}

    // Method to pause and clear the screen, then return to the main menu
	void GoBackToMainMenue()
	{
		cout << "\n\nPress in any key to go Main Menue...";
		system("pause>0");
		system("cls");

	}

    // Method to search for books by a keyword in the title or author
	void searchBook(string keyword)
	{
		for (auto& b : books)
		{
			if (b.getTitle().find(keyword) != string::npos || b.getAuthor().find(keyword) != string::npos)
			{
				b.displayInfo();
			}
		}
	}


    // Method to borrow a book by its title
	void borrowBook(string title)
	{
		for (auto& b : books)
		{
			if (b.getTitle() == title)
			{
				if (b.getIsAvailability())
				{
					b.borrowBook();
					cout << "\nYou borrowed:    " << title << endl;
				}
				else
				{
					cout << "\Sorry, the book is not available. \n";

				}
				return;


			}


		}				cout << "\Book not found. \n";

	}


};
int main()
{
	Library library;
	
	// Adding some books to the library
	library.addBook(Book("The Great Gatsby", "F.Fitzgeraid"));
	library.addBook(Book("1984", "George Orwell"));
	library.addBook(Book("To Kill a Mockungbird", "Harper Lee"));
	library.addBook(Book("To Kill a Mockungbird", "Harper Lee"));
	library.addBook(Book("One Hundred Years of Solitude", "Gabriel García Márquez"));
	library.addBook(Book("Educated", "Harper Lee"));
	library.addBook(Book("Atomic Habits", "James Clear"));

	int Choice;
	do
	{
                 // Displaying the main menu
		cout << "=====================================================================================\n";
		cout << "\t\t\t Library Menu\n";
		cout << "=====================================================================================\n";
		cout << "1. Display all  books \n";
		cout << "2. Search for a book \n";
		cout << "3. Borow a book\n";
		cout << "4. Exit\n";
		cout << "Exiter your choice: ";
		cin >> Choice;


		cin.ignore();

		if (Choice == 1)
		{
			system("cls");

			library.displayBooks();
			library.GoBackToMainMenue();
		}
		else if (Choice == 2)
		{
			system("cls");

			string keyword;
			cout << "Enter title or author to search:";
			getline(cin, keyword);
			library.searchBook(keyword);
			library.GoBackToMainMenue();

		}
		else if (Choice == 3)
		{
			system("cls");

			string title;
			cout << "Enter the title of book to borrow:";

			getline(cin, title);
			library.borrowBook(title);
			library.GoBackToMainMenue();

		}
	} while (Choice != 4);

	cout << "Goodbye!\n";


	return 0;
}
