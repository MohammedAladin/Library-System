//
// Created by kingston on ١٤/٠٢/٢٠٢٢.
//

#ifndef LIBRARY_SYSTEM_BOOK_H
#define LIBRARY_SYSTEM_BOOK_H

#include "Book.h"
#include "User.h"
class Book {
private:
    string title;
    string isbn;
    int id; // Make sure that the id is incremental. First id is 1, second is 2 and so on string category;
    User author;
    string category;
    double avgRating;
    int ratingCnt;
    bool findAuthor;
public:
    static int count;
    Book();
    Book(string title, string isbn, string category);
    Book(const Book& book);
    void setTitle(string title);
    string getTitle();
    void setISBN(string isbn);
    string getISBN();
    void setId(int id);
    int getId();
    void setCategory(string category);
    string getCategory();
    void setAuthor(User user);
    User getAuthor();
    double getRating();
    bool hasAuthor();
    void getBookInfo(Book book);

    // this function should update averageRating attribute as a new rating is //
    // introduced to the book so the average rating should be affected.
    // Check the main screenshot to know more information
    void rateBook(int avgRating);
    bool operator==(const Book& book);
    friend ostream &operator<<(ostream &output, const Book &book );
    friend istream &operator>>( istream &input, Book &book);

};


#endif //LIBRARY_SYSTEM_BOOK_H
