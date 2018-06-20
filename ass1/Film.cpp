#include "Film.h"
#include "Media.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

Film::Film(const string &user_call_number, const string &user_title,
  const string &user_subjects, const string &user_director,
  const string &user_notes, const string &user_year):Media(user_call_number,
    user_title,user_subjects,user_notes),director(user_director),
    year(user_year)
{}

void Film::display() const
{
  Media::display();
  cout << "director: " << director;
  cout << "year: " << year;
  cout << endl;
}

Film::~Film()
{}

bool Film::compareByOther(const string &user_other) const
{
  if(Media::notes.find(user_other) != std::string::npos){
    return true;
  }
  else if(director.find(user_other) != std::string::npos){
    return true;
  }
  else if(year.find(user_other) != std::string::npos){
    return true;
  }
  else{
    return false;
  }
}
