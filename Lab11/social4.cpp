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

struct Post{
  string username;
  string message;
};

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
  static const int MAX_POSTS = 100;
  int numPosts;                    // number of posts
  Post posts[MAX_POSTS];           // array of all posts

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

 bool writePost(string usrn, string msg){
    if(numPosts < MAX_POSTS && findID(usrn) != -1){
        Post newPost;
        newPost.username = usrn;
        newPost.message = msg;
        posts[numPosts] = newPost;
        numPosts++;
        return true;
    }
    return false;
 }
 // Print user's "timeline"
 bool printTimeline(string usrn){
    for (int i = numPosts-1; i >= 0; i--){
        if(posts[i].username == usrn){
            cout << profiles[findID(usrn)].getFullName() << ": " << posts[i].message << endl;
        }
        for  (int j = 0; j < numUsers; j++){
            if (following[findID(usrn)][j] && posts[i].username == profiles[j].getUsername()){
                cout << profiles[j].getFullName() << ": " << posts[i].message << endl;
            }
        }
    }
    return true;
 }

};

int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}