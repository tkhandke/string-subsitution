#include "Book.h"
#include "Media.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

Book::Book(const string &user_call_number,const string &user_title,
  const string &user_subjects, const string &user_author,
  const string &user_description,const string &user_publisher,
  const string &user_city,const string &user_year,const string &user_series,
  const string &user_notes):Media(user_call_number,user_title,user_subjects,user_notes),
  author(user_author), description(user_description),publisher(user_publisher),
  city(user_city), year(user_year),series(user_series)
{}

Book::~Book()
{}


void Book::display() const
{
  Media::display();
  cout << " author: " << author;
  cout << " description: " << description;
  cout << " publisher: " << publisher;
  cout << " city: " << city;
  cout << " year: " << year;
  cout << " series: " << series;
  cout << endl;
}


bool Book::compareByOther(const string &user_other) const
{
  if(description.find(user_other) != std::string::npos){
    return true;
  }
  // notes from Parent class (Media) is accessed by making it protected
  else if(Media::notes.find(user_other) != std::string::npos){
    return true;
  }
  else if(year.find(user_other) != std::string::npos){
    return true;
  }
  else{
    return false;
  }
}
