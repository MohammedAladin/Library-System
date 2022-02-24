#include "BookList.h"

int BookList :: booksCount=0;
BookList::BookList(int capacity) {
    this->capacity = capacity;
    books = new Book[capacity];
    booksCount = 0;
}
void BookList :: addBook(Book newBook){
    if(capacity>booksCount){
        books[booksCount].setCategory(newBook.getCategory());
        books[booksCount].setISBN(newBook.getISBN());
        books[booksCount].setTitle(newBook.getTitle());
        if(newBook.hasAuthor()){
            books[booksCount].setAuthor(newBook.getAuthor());
        }

        booksCount++;
    }
    else
        cout<<"SORRY THE CAPACITY IS FULL"<<endl;
}
Book * BookList:: searchBook(string name){
    for(int i=0; i<booksCount; i++){
        if(name==books[i].getTitle()){
            return &books[i];

        }
    }
        cout<<"SORRY, THIS BOOK IS NOT EXIST.."<<endl;
    return nullptr;

}
Book* BookList:: searchBook(int id){
    for(int i=0; i<booksCount; i++){
        if(id==books[i].getId()){
            return &books[i];
        }
    }

        cout<<"SORRY, THIS BOOK IS NOT EXIST.."<<endl;
    return nullptr;
}
void BookList :: deleteBook(int id){
    bool isFound= false;
    for(int i=0; i<booksCount; i++) {
        if (books[i].getId() == id) {
            isFound = true;
            booksCount--;
            //   users[i]= 0;
            if(i<booksCount){
                for(int j=i; j<booksCount; j++){
                    books[j]=books[j+1];
                    books[j].setId(books[i].getId()-1);
                }
            }
        }
    }
    if(!isFound)
        cout<<"THIS USER ID IS NOT EXIST IN THE LIST.."<<endl;
} //delete a book
void BookList :: deleteBook(string name){
    bool isFound= false;
    for(int i=0; i<booksCount; i++) {
        if (books[i].getTitle() == name) {
            isFound = true;
            booksCount--;
            //   users[i]= 0;
            if(i<booksCount){
                for(int j=i; j<booksCount; j++){
                    books[j]=books[j+1];
                    books[j].setId(books[i].getId()-1);

                }
            }
        }
    }
    if(!isFound)
        cout<<"THIS USER ID IS NOT EXIST IN THE LIST.."<<endl;

}
Book BookList:: getTheHighestRatedBook(){
    double max=0.0;
    int maxRatIndex;
    for(int i=0; i<booksCount; i++){
        if(books[i].getRating()>max)
        {
            max=books[i].getRating();
            maxRatIndex=i;
        }
    }
    return books[maxRatIndex];
}
Book* BookList:: getBooksForUser(User author){

    for(int i=0; i<booksCount; i++){
        if(books[i].getAuthor()==author)
        {
            return &books[i];
        }
    }
    return nullptr;
}

Book* BookList:: operator [] (int position){
     if(position>=0 || position<booksCount){
         return &books[position];
     } else
         return nullptr;
}
ostream &operator<<( ostream &output, BookList &booklist ){
    for(int i=0; i<booklist.booksCount; i++){
        output<<booklist.books[i]<<endl;
    }
    return output;
}
