
#ifndef LIBRARY_SYSTEM_BOOKLIST_H
#define LIBRARY_SYSTEM_BOOKLIST_H

#include "Book.h"
#include "iostream"
using namespace std;


class BookList {
private: Book* books;
    int capacity;

public:
    int static booksCount;
    BookList(const BookList& anotherList);
    BookList(int capacity);
    BookList();
    Book * searchBook(string name);
    Book * searchBook(int id);
    void deleteBook(int id); //delete a book
    void deleteBook(string); //delete a book
    Book getTheHighestRatedBook();
    Book* getBooksForUser(User); // get all books of this author
    Book* operator [] (int position);
    void addBook(Book newBook);
    int static getBooksCount(){
        return booksCount;
    }
    friend ostream &operator<<( ostream &output, BookList &booklist ); //to display all books ~BookList();

};


#endif //LIBRARY_SYSTEM_BOOKLIST_H
