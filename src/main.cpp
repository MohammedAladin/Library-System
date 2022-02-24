#include <iostream>
using namespace std;
#include "UserList.h"
#include "BookList.h"

int main() {
    UserList *list;
    BookList *bookList1;

int mainMenuChoice=0;
    while (mainMenuChoice!=3){

        cout<<"SELECT ONE OF THE FOLLOWING CHOICES"<<endl;
        cout<<" 1- BOOKS MENU \n 2- USER MENU \n 3- EXIST"<<endl;
        cin>>mainMenuChoice;
        switch (mainMenuChoice) {
            case 1: {
                cout << "HOW MANY BOOKS WILL BE ADDED" << endl;
                int numOfBooks;
                cin >> numOfBooks;
                bookList1 = new BookList (numOfBooks);
                int bookMenuChoice = 0;
                while ( bookMenuChoice != 7) {
                   Book* newBook;
                    cout << "==== BOOK MENU ====" << endl;
                    cout << "1- CREATE A BOOK AND ADD IT TO THE LIST " << endl
                         << "2- SEARCH FOR A BOOK " << endl
                         << "3- DISPLAY ALL BOOKS" << endl
                         << "4- GET THE HIGHEST RATING BOOK" << endl
                         << "5- GET ALL BOOKS OF A USER" << endl
                         << "6- COPY THE CURRENT BOOK LIST TO A NEW BOOK LIST AND SWITCH TO IT" << endl
                         << "7- BACK TO MAIN MENU" << endl;
                    cin >> bookMenuChoice;
                    switch (bookMenuChoice) {
                        case 1:{
                            newBook = new Book();
                            cin>>*newBook;
                            int afterAdd=0;
                            while (afterAdd!=2){
                                cout << " 1- ASSIGN AUTHOR " << endl
                                     << " 2- CONTINUE " << endl;
                                cin>>afterAdd;
                                switch (afterAdd) {
                                    case 1:{
                                        cout<<"ENTER NEW AUTHOR NAME"<<endl;
                                        string assignedAuthor;
                                        cin>>assignedAuthor;
                                        if( list->searchUser(assignedAuthor)!= nullptr) {
                                            User *assignedUser = list->searchUser(assignedAuthor);
                                            newBook->setAuthor(*assignedUser);
                                        break;
                                    }

                                }
                            }
                            }
                            bookList1->addBook(*newBook);
                            break;
                        }
                        case 2:{
                            int searchForBookChoice = 0;
                            while (searchForBookChoice != 3) {
                                cout << "==== SEARCH FOR A BOOK ====" << endl
                                     << "1- SEARCH BY TITLE" << endl
                                     << "2- SEARCH BY BOOK ID" << endl
                                     << "3- RETURN TO BOOK MENU" << endl;
                                cin >> searchForBookChoice;
                                switch (searchForBookChoice) {
                                    case 1: {
                                        cout << "ENTER BOOK TITLE" << endl;
                                        string bookTitleForSearch;
                                        cin >> bookTitleForSearch;

                                        if(bookList1->searchBook(bookTitleForSearch)!= nullptr) {
                                            Book* searchedBook = bookList1->searchBook(bookTitleForSearch);
                                            searchedBook->getBookInfo(*searchedBook);
                                            int afterSearch = 0;
                                            while (afterSearch != 6) {
                                                cout << "1- Update author" << endl
                                                     << "2- UPDATE NAME" << endl
                                                     << "3- UPDATE CATEGORY" << endl
                                                     << "4- DELETE BOOK" << endl
                                                     << "5- RATE BOOK" << endl
                                                     << "6- BACK YO BOOKS MENU" << endl;
                                                cin >> afterSearch;
                                                switch (afterSearch) {
                                                    case 1: {
                                                        cout << "ENTER NEW AUTHOR NAME" << endl;
                                                        string updatedAuthor;
                                                        cin >> updatedAuthor;
                                                        if(list->searchUser(updatedAuthor)!= nullptr) {
                                                            User *updatedUser = list->searchUser(updatedAuthor);
                                                            searchedBook->setAuthor(*updatedUser);
                                                           searchedBook->getBookInfo(*searchedBook);
                                                        }
                                                        break;
                                                    }
                                                    case 2:{
                                                        cout << "ENTER NEW BOOK NAME" << endl;
                                                        string updatedBookName;
                                                        cin >> updatedBookName;
                                                        searchedBook->setTitle(updatedBookName);
                                                        searchedBook->getBookInfo(*searchedBook);
                                                        break;
                                                    }
                                                    case 3:{
                                                        cout << "ENTER NEW BOOK CATEGORY" << endl;
                                                        string updatedBookCat;
                                                        cin >> updatedBookCat;
                                                        searchedBook->setCategory(updatedBookCat);
                                                        searchedBook->getBookInfo(*searchedBook);
                                                        break;
                                                    }
                                                    case 4:{
                                                        bookList1->deleteBook(searchedBook->getTitle());
                                                        cout<<"BOOK HAS BEN DELETED SUCCESSFULLY"<<endl;
                                                        afterSearch=6;
                                                        break;
                                                    }
                                                    case 5:{
                                                        cout<<"ENTER RATE OUT OF 5"<<endl;
                                                        int rate;
                                                        cin>>rate;
                                                        searchedBook->rateBook(rate);
                                                        searchedBook->getBookInfo(*searchedBook);
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                        break;
                                    }
                                    case 2: {
                                        cout << "ENTER BOOK Id" << endl;
                                        int bookIdForSearch;
                                        cin >> bookIdForSearch;

                                        if(bookList1->searchBook(bookIdForSearch)!= nullptr) {
                                            Book* searchedBook = bookList1->searchBook(bookIdForSearch);
                                            cout<<*searchedBook;
                                            int afterSearch = 0;
                                            while (afterSearch != 6) {
                                                cout << "1- Update author" << endl
                                                     << "2- UPDATE NAME" << endl
                                                     << "3- UPDATE CATEGORY" << endl
                                                     << "4- DELETE BOOK" << endl
                                                     << "5- RATE BOOK" << endl
                                                     << "6- BACK YO BOOKS MENU" << endl;
                                                cin >> afterSearch;
                                                switch (afterSearch) {
                                                    case 1: {
                                                        cout << "ENTER NEW AUTHOR NAME" << endl;
                                                        string updatedAuthor;
                                                        cin >> updatedAuthor;
                                                        if(list->searchUser(updatedAuthor)!= nullptr) {
                                                            User *updatedUser = list->searchUser(updatedAuthor);
                                                            searchedBook->setAuthor(*updatedUser);
                                                            searchedBook->getBookInfo(*searchedBook);
                                                        }
                                                        break;
                                                    }
                                                    case 2:{
                                                        cout << "ENTER NEW BOOK NAME" << endl;
                                                        string updatedBookName;
                                                        cin >> updatedBookName;
                                                        searchedBook->setTitle(updatedBookName);
                                                        searchedBook->getBookInfo(*searchedBook);
                                                        break;
                                                    }
                                                    case 3:{
                                                        cout << "ENTER NEW BOOK CATEGORY" << endl;
                                                        string updatedBookCat;
                                                        cin >> updatedBookCat;
                                                        searchedBook->setCategory(updatedBookCat);
                                                        searchedBook->getBookInfo(*searchedBook);
                                                        break;
                                                    }
                                                    case 4:{
                                                        bookList1->deleteBook(searchedBook->getTitle());
                                                        cout<<"BOOK HAS BEN DELETED SUCCESSFULLY"<<endl;
                                                        afterSearch=6;
                                                        break;
                                                    }
                                                    case 5:{
                                                        cout<<"ENTER RATE OUT OF 5"<<endl;
                                                        int rate;
                                                        cin>>rate;
                                                        searchedBook->rateBook(rate);
                                                        searchedBook->getBookInfo(*searchedBook);
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 3: {
                            cout<<*bookList1;
                            break;
                        }
                        case 4:{
                            cout<<bookList1->getTheHighestRatedBook();
                            break;
                        }
                        case 5:{
                            cout<<"ENTER USER ID.."<<endl;
                            int authorId;
                            cin>>authorId;
                            if(list->searchUser(authorId)!= nullptr){
                                User *updatedUser = list->searchUser(authorId);
                                cout<<"==== AUTHOR IS FOUND ===="<<endl;
                                cout<<bookList1->getBooksForUser(*updatedUser);
                            }
                            break;
                        }
                        case 6:{
//                            BookList newBookList(*bookList1);
//                            cout<<"COPIED CURRENT LIST "<<bookList1->booksCount<<" TO A NEW LIST AND SWITCHED TO IT"<<endl;
                            break;
                        }
                    }
                    }
                break;
            }
            case 2: {
                cout << "HOW MANY USERS WILL BE ADDED" << endl;
                int numOfUsers;
                cin >> numOfUsers;
                list = new UserList(numOfUsers);
                int userMenuChoice = 0;
                while (userMenuChoice != 4) {
                    User *newUser = new User;
                    cout << "==== USER MENU ====" << endl;
                    cout << "1- CREATE A USER AND ADD IT TO THE LIST " << endl
                         << "2- SEARCH FOR A USER " << endl
                         << "3- DISPLAY ALL USERS" << endl
                         << "4- BACK TO MAIN MENU" << endl;
                    cin >> userMenuChoice;
                    switch (userMenuChoice) {
                        case 1: {
                            cin >> *newUser;
                            list->addUser(*newUser);

                            break;
                        }
                        case 2: {
                            int searchForUserChoice = 0;
                            while (searchForUserChoice != 3) {
                                cout << "==== SEARCH FOR A USER ====" << endl
                                     << "1- SEARCH BY USERNAME" << endl
                                     << "2- SEARCH BY USER ID" << endl
                                     << "3- RETURN TO USER MENU" << endl;
                                cin >> searchForUserChoice;
                                switch (searchForUserChoice) {
                                    case 1: {
                                        cout << "ENTER USERNAME" << endl;
                                        string userNameForSearch;
                                        cin >> userNameForSearch;
                                        if(list->searchUser(userNameForSearch)!= nullptr) {
                                            list->searchUser(userNameForSearch);

                                            cout << "1- DELETE USER" << endl
                                                 << "2- RETURN" << endl;

                                            int afterSearch = 0;
                                            cin >> afterSearch;

                                            if (afterSearch == 1) {
                                                list->deleteUser(userNameForSearch);
                                                cout << "==== USER IS DELETED ====" << endl;
                                            } else
                                                break;
                                        }
                                    }
                                        break;
                                    case 2: {
                                        cout << "ENTER USER ID" << endl;
                                        int userIdForSearch;
                                        cin >> userIdForSearch;
                                        list->searchUser(userIdForSearch);
                                        cout<<"1- DELETE USER" << endl
                                            <<"2- RETURN" << endl;

                                        int afterSearch=0;
                                        cin>>afterSearch;

                                        if(afterSearch==1){
                                            list->deleteUser(userIdForSearch);
                                            cout<<"==== USER IS DELETED ===="<<endl;
                                        } else
                                            break;
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 3: {
                            cout << *list;
                            break;
                        }

                    }
                }
                break;
            }
        }

    }

}
