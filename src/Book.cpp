#include "Book.h"
#include "string"
#include "iostream"
using namespace std;
int Book :: count = 1;
Book :: Book(string title, string isbn, string category){
    this->title=title;
    this->isbn=isbn;
    this->category=category;
    id=count++;
    this->avgRating=0.0;
    findAuthor=false;
    ratingCnt=0;
}
Book::Book() {
        title="";
        isbn="";
        category="";
        id=count++;
        avgRating=0.0;
        findAuthor=false;
        ratingCnt=0;
}
Book :: Book(const Book& book){
    this->title=book.title;
    this->isbn=book.isbn;
    this->category=book.category;
    this->id=book.id;
    this->findAuthor=book.findAuthor;
    this->author=book.author;
    this->avgRating=book.avgRating;
    this->ratingCnt=book.ratingCnt;
}
void Book :: setTitle(string title){
    this->title=title;
}
string Book :: getTitle(){
    return title;
}
void Book :: setISBN(string isbn){
    this->isbn=isbn;
}
string Book :: getISBN(){
    return isbn;
}
void Book :: setId(int id){
    this->id=id;
}
int Book :: getId(){
    return id;
}
double Book :: getRating(){
    return avgRating;
}
bool Book ::hasAuthor() {
    return findAuthor;
}
void Book :: setCategory(string category){
    this->category=category;
}
string Book :: getCategory(){
    return category;
}
void Book :: setAuthor(User user){
    this->author = user;
    findAuthor = true;
}
User Book :: getAuthor(){
    return author;
}
int total=0;
void Book :: rateBook(int Rating){
    if(Rating<=5){
        total+=Rating;
        ratingCnt++;
        this->avgRating=((float )total/ratingCnt);

    }
    else
        cout<<"THE RATE MUST BE FROM 5"<<endl;

}
void Book ::getBookInfo(Book book) {
    cout
            << "========Book " << book.id << " info ========" << endl
            << "Title: " << book.title << endl
            << "ISBN: " << book.isbn << endl
            << "Id: " << book.id << endl
            << "Category: " << book.category << endl
            << "Avg Rating: " << book.avgRating << endl
            << "Author: " <<book.author.getName() << endl
            << "================================================" << endl;
}
bool Book :: operator==(const Book& book){
    bool statues;
    if(title==book.title && isbn==book.isbn && category==book.category && id==book.id && author==book.author)
        return statues = true;
    else
        return statues = false;
}
ostream &operator<<(ostream &output, const Book &book ){
    {
        output
                << "========Book " << book.id << " info ========" << endl
                << "Title: " << book.title << endl
                << "ISBN: " << book.isbn << endl
                << "Id: " << book.id << endl
                << "Category: " << book.category << endl
                << "Avg Rating: " << book.avgRating << endl
                << "================================================" << endl;
        if (book.findAuthor)
        {
            output
                    << "======== Author info ========" << endl
                    << "Name: " << book.author.getName() << endl
                    << "Age: " << book.author.getAge() << endl
                    << "Id: " << book.author.getId() << endl
                    << "Email: " << book.author.getEmail() << endl
                    << "==============================================" << endl;
        }
        return output;
    }
}
istream &operator>>( istream &input, Book &book )
{

    cout<<"let's add a new book"<<endl;
    cout<<"Enter the user information in this order"<<endl;
    cout<<"Title Isbn Category (Space separated)"<<endl;
    input>>book.title>>book.isbn>>book.category;
    return input;
}
