
#include "UserList.h"
 int UserList :: usersCount=0;
UserList :: UserList(int capacity){
    this->capacity=capacity;
    users=new User[capacity];
    usersCount=0;
}
void UserList :: addUser(User user) {
    if(capacity>usersCount){
        users[usersCount].setName(user.getName());
        users[usersCount].setAge(user.getAge());
        users[usersCount].setEmail(user.getEmail());
        users[usersCount].setPassword(user.getPassword());

        usersCount++;
    } else
        cout<<" capacity is only for "<<capacity <<" users"<<endl;

}
User* UserList :: searchUser(int id){

    for(int i=0; i<usersCount; i++){
        if(users[i].getId()==id){

            return &users[i];
        }
    }
    cout<<"This username is not exists"<<endl;
    return nullptr;
}
User * UserList :: searchUser(string name){
    for(int i=0; i<usersCount; i++){
        if(users[i].getName()==name){
            return &users[i];
        }
    }
        cout<<"This username is not exists"<<endl;
    return nullptr;
}
void UserList ::deleteUser(int id){
    bool isFound= false;
    for(int i=0; i<usersCount; i++) {
        if (users[i].getId() == id) {
            isFound = true;
            usersCount--;
         //   users[i]= 0;
            if(i<usersCount){
                for(int j=i; j<usersCount; j++){
                    users[j]=users[j+1];
                    users[j].setId(users[i].getId()-1);
                }
            }
        }
    }
    if(!isFound)
        cout<<"THIS USER ID IS NOT EXIST IN THE LIST.."<<endl;
}
User* UserList:: operator [] (int position){
    if(position>=0 || position<usersCount){
        return &users[position];
    }
}
void UserList ::deleteUser(string name){
    bool isFound= false;
    for(int i=0; i<usersCount; i++) {
        if (users[i].getName() == name) {
            isFound = true;
            usersCount--;
            if(i<usersCount){
                for(int j=i; j<usersCount; j++){
                    users[j]=users[j+1];
                    users[j].setId(users[i].getId()-1);

                }
            }
        }
    }
    if(!isFound)
        cout<<"THIS USER ID IS NOT EXIST IN THE LIST.."<<endl;
}


ostream &operator<<( ostream &output, UserList &userList ){
    for(int i=0; i<userList.usersCount; i++){
        output<<userList.users[i]<<endl;
    }
    return output;
}

