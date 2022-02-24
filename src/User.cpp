#include "User.h"
int User :: count = 1;
User ::User() {
    this->age=0;
    this->id=count++;

}
User::User(string name, int age, string email, string password){

    this->name=name;
    this->age=age;
    this->email=email;
    this->password=password;
    this->id=count;
    count++;
}
User::User(const User&user){
    this->name=user.name;
    this->age=user.age;
    this->email=user.email;
    this->password=user.password;
    this->id=user.id;
}

bool User:: operator==(const User& user){
    bool statues;
    if ((name==user.name && email==user.email && age==user.age && id==user.id))
        return statues= true;
    else
        return statues= false;

}
void User :: setName(string name){
    this->name=name;
}
string User :: getName() const{
    return name;
}
void User :: setPassword(string password){
    this->password=password;
}
string User :: getPassword(){
    return password;
}
void User :: setEmail(string email){
    this->email=email;
}
string User :: getEmail() const {
    return email;
}
void User :: setAge(int age){
    this->age=age;
}
int User :: getAge() const {
    return age;
}
void User :: setId(int id){
    this->id=id;
}
int User :: getId() const {
    return id;
}
ostream &operator<<(ostream &output, const User &user ){
    output
            <<"=========== User "<<user.id<<" info ===========" << endl

            <<"Name: " << user.name << endl
            <<"Age: " << user.age << endl
            <<"Id: " << user.id << endl
            <<"Email: " << user.email << endl;
    return output;
}

istream &operator>>( istream &input, User &user )
{

    cout<<"let's add a user"<<endl;
    cout<<"Enter the user information in this order"<<endl;
    cout<<"Name Age Email password (Space separated)"<<endl;
    input>>user.name>>user.age>>user.email>>user.password;
    return input;
}



