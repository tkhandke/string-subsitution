#include "Media.h"
#include <iostream>
#include <string>
using namespace std;

//1.
// const is a promise saying that passed by reference variables will not be
// manipulated
//2.
// Initialization steps saves compute overhead of invoking default constructors
// and copy constructors and then assigning values to member variables
Media::Media(const string &user_call_number,const string &user_title,const string &user_subjects,const string &user_notes):call_number(user_call_number),title(user_title),subjects(user_subjects),notes(user_notes)
{
}

// not having this destructor here was throwing comiple time error
// undefined reference to vtable class
Media::~Media()
{
}

// write a display function
void Media::display() const{
  cout << "title: " << title;
  cout << "call_number: " << call_number;
  cout << "subjects: " << subjects;
  cout << "notes: " << notes;
}

bool Media::compareByTitle(const string &user_title) const{
  // find is equivalent to string.contains in c#
  //cout << endl;
  //cout << "in compareByTitle" << endl;
  //cout << "user input: " <<  user_title;
  //cout << "current title:" << call_number;
  //cout << endl;
  if(title.find(user_title) != std::string::npos){
    return true;
  }
  else{
    return false;
  }
}


bool Media::compareByCallNumber(const string &user_call_number) const{
  if(title.find(call_number) != std::string::npos){
    return true;
  }
  else{
    return false;
  }
}

bool Media::compareBySubjects(const string &user_subjects) const{
  if(title.find(subjects) != std::string::npos){
    return true;
  }
  else{
    return false;
  }
}
