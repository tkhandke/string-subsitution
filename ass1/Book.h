#ifndef Book_H
#define Book_H
#include"Media.h"
#include<string>
using namespace std;


class Book: public Media {
  private:
    //Media m;
    string author;
    string description;
    string publisher;
    string city;
    string year;
    string series;
  public:
    Book(const string &user_call_number,const string &user_title,
      const string &user_subjects,const string &user_author,
      const string &user_description,const string &user_publisher,
      const string &user_city, const string &user_year,
      const string &user_series,const string &user_notes);
    ~Book();
    void display() const;
    bool compareByOther(const string &user_other) const;

};
#endif
