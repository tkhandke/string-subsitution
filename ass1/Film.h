#ifndef Film_H
#define Film_H
#include "Media.h"
#include<string>
using namespace std;

// by default inheritance is private in classes
// by default inheritance is public in structs
class Film: public Media {
  private:
    //Media m;
    string director;
    string year;
  public:
    Film(const string &user_call_number, const string &user_title,
      const string &user_subjects, const string &user_director,
      const string &user_notes,const string &user_year);
    ~Film();
    void display() const;
    bool compareByOther(const string &other) const;

};
#endif
