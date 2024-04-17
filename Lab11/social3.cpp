/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 11A

profile class
*/
//

#include <iostream>
#include <cctype> //for isalnum
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn){
        username = usrn;
        displayname = dspn;
    }
    // Default Profile constructor (username="", displayname="")
    Profile(){
        username = "";
        displayname = "";
    }
    // Return username
    string getUsername(){
        return username;
    }
    // Return name in the format: "displayname (@username)"
    string getFullName(){
        string full = displayname + " (@" + username + ")";
        return full;
    }
    // Change display name
    void setDisplayName(string dspn){
        displayname = dspn;
    }
};

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
 // following[id1][id2] == true when id1 is following id2
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn){
    for (int i = 0; i < numUsers; i++){
        //cout << profiles[i].getUsername() << endl;
        if (profiles[i].getUsername() == usrn){
            return i;
        }
    }
    return -1;
  }
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network(){
    numUsers = 0;
    for (int r = 0; r < MAX_USERS; r++){
        for (int c = 0; c < MAX_USERS; c++){
            following[r][c] = false;
        }
    }
  }
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn){
    //cout << "ID" << findID(usrn) << endl;
    if (numUsers < MAX_USERS && (findID(usrn) == -1)){
        //check if alphanumeric
        for(int i = 0;i < usrn.length();i++){
            if (!isalnum(usrn[i])){
                return false;
            }
        }
        profiles[numUsers] = Profile(usrn, dspn);
        numUsers++;
        return true;
    }
    return false;
  }

   // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
 // return true if success (if both usernames exist), otherwise return false
 bool follow(string usrn1, string usrn2){
    if(findID(usrn1) != -1 && findID(usrn2) != -1){
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    }
    return false;
 }

 // Print Dot file (graphical representation of the network)
 void printDot(){
    cout << "digraph {" << endl;
    for(int i = 0; i < numUsers; i++){
        cout << "\"@" << profiles[i].getUsername() << "\"" << endl;
    }
    cout << endl;

    for (int r = 0; r < numUsers; r++){
        for (int c = 0; c < numUsers; c++){
            if(following[r][c] == true){
                cout << "\"@" << profiles[r].getUsername() << "\" -> \"@" << profiles[c].getUsername() << "\"" << endl;;
            }
        }
    }
    cout << "}";
 }

};

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}