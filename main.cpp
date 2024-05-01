    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;

    class HomeLibraryBook;

    class Book {
    protected:
        string author;
        string title;
        int pages;
        int year;

    public:
        Book() : author(""), title(""), pages(0), year(0) {}

        Book(const string& author, const string& title, int pages, int year)
            : author(author), title(title), pages(pages), year(year) {}

        virtual ~Book() {}

        virtual void display() const {
            cout << "Author: " << author << endl;
            cout << "Title: " << title << endl;
            cout << "Pages: " << pages << endl;
            cout << "Year: " << year << endl;
        }

        const string& getTitle() const { return title; }
    };

    class HomeLibraryBook : public Book {
    private:
        string location;
        bool borrowed;

    public:
        HomeLibraryBook(const string& author, const string& title, int pages, int year,
                        const string& location, bool borrowed)
            : Book(author, title, pages, year), location(location), borrowed(borrowed) {}

        virtual void display() const override {
            Book::display();
            cout << "Location: " << location << endl;
            cout << "Borrowed: " << (borrowed ? "Yes" : "No") << endl;
        }

        void borrow() {
            borrowed = true;
        }

        void returnBook() {
            borrowed = false;
        }
    };

    class HomeLibrary {
    private:
        vector<HomeLibraryBook> books;

    public:
        void addBook(const HomeLibraryBook& book) {
            books.push_back(book);
        }

        void removeBook(const string& title) {
            for (auto it = books.begin(); it != books.end(); ++it) {
                if (it->getTitle() == title) {
                    books.erase(it);
                    break;
                }
            }
        }

        void displayAllBooks() const {
            for (const auto& book : books) {
                book.display();
                cout << endl;
            }
        }
    };

    int main() {
        HomeLibrary library;

        HomeLibraryBook myBook("John Doe", "C++ Programming", 350, 2020, "Living Room", false);
        library.addBook(myBook);

        HomeLibraryBook myBook2("Penelope Sky", "Buttons and Lace", 350, 2016, "Living Room", false);
        library.addBook(myBook2);

        library.displayAllBooks();

        myBook.borrow();
        cout << "Book borrowed." << endl;
        library.displayAllBooks();

        return 0;
    }
