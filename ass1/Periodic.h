#ifndef Periodic_H
#define Periodic_H
#include "Media.h"
#include<string>
using namespace std;

class Periodic: public Media {
  private:
    //Media m;
    string author;
    string description;
    string publisher;
    string publishing_history;
    string series;
    string related_titles;
    string other_forms_of_title;
    string govt_doc_number;
  public:
    Periodic(const string &user_call_number, const string &user_title,
      const string &user_subjects,const string &user_author,
      const string &user_description, const string &user_publisher,
      const string &user_publishing_history, const string &user_series,
      const string &user_notes, const string &user_related_titles,
      const string &user_other_forms_of_title,
      const string &user_govt_doc_number);
    ~Periodic();
    void display() const;
    bool compareByOther(const std::string &other) const;

};
#endif
