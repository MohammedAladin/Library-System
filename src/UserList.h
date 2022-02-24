//
// Created by kingston on ١٤/٠٢/٢٠٢٢.
//

#ifndef LIBRARY_SYSTEM_USERLIST_H
#define LIBRARY_SYSTEM_USERLIST_H
#include "User.h"


class UserList {
private:
    User* users;
    int capacity;

public:
    int static usersCount;
    int arrCounter=0;
    explicit UserList(int capacity);
    ~UserList(){
        delete []users;
    }
    UserList(){
        capacity=0;
        usersCount=0;
    }
    void addUser(User user);// at the end of the array. User& searchUser(string name); User& searchUser(int id); void deleteUser(int id);
    User* searchUser(int id);
    User * searchUser(string name);
    void deleteUser(int id);
    void deleteUser(string name);
    User* operator [] (int position);
    User getUser(){
        return *users;
    }

    friend ostream &operator<<( ostream &output, UserList &userList );//to display all books ~UserList();

};


#endif //LIBRARY_SYSTEM_USERLIST_H
