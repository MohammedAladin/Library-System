//
// Created by kingston on ١٤/٠٢/٢٠٢٢.
//

#ifndef LIBRARY_SYSTEM_USER_H
#define LIBRARY_SYSTEM_USER_H


#include "iostream"
using namespace std;

class User {
private:
    string name;
    int age;
    int id=0; // Make sure that the id is incremental. First id is 1, second is 2 and so on string password; string email;
    string password;
    string email;
public:
    static int count;
    User();
    User(string name, int age, string email, string password);
    User(const User&user);
    bool operator==(const User& user);

    void setName(string name);
    string getName() const;
    void setPassword(string password);
    string getPassword();
    void setEmail(string email);
    string getEmail() const;
    void setAge(int age); int getAge() const; void setId(int id);
    int getId() const;
    friend ostream &operator<<(ostream &output, const User &user );
    friend istream &operator>>( istream &input, User &user );


    User(nullptr_t pVoid);
};


#endif //LIBRARY_SYSTEM_USER_H
