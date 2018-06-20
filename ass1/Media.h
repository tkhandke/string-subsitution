#ifndef Media_H
#define Media_H
#include<string>
using namespace std;

class Media {
  protected: // protected members can be accessed in child classes like in C#
    string title;
    string call_number;
    string subjects;
    string notes;
  public:
    //TO DO: constructor

    Media(const string &user_call_number, const string &user_title,const string &user_subjects, const string &user_notes);
    // Media is parent class
    // when we call destructor of child class,
    // destructor of parent class is also called coz of virtual keyword
    virtual ~Media();
    virtual void display() const;
    virtual bool compareByTitle(const string &user_title) const;
    virtual bool compareByCallNumber(const string &user_call_number) const;
    virtual bool compareBySubjects(const string &user_subjects) const;
    virtual bool compareByOther(const string &user_other) const = 0;

};
#endif


// following is the order of constructor and destructor invocation
// parent *p;
// p = new child;
// delete p;
//1.  Parent constructor
//2. child constructor
//3. child destructor
//4. parent destructor
