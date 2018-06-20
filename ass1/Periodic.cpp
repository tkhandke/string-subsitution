#include "Periodic.h"
#include "Media.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

Periodic::Periodic(const string &user_call_number, const string &user_title,
  const string &user_subjects,const string &user_author,
  const string &user_description,const string &user_publisher,
  const string &user_publishing_history,const string &user_series,
  const string &user_notes,const string &user_related_titles,
  const string &user_other_forms_of_title,
  const string &user_govt_doc_number):Media(user_call_number,user_title,
    user_subjects, user_notes), author(user_author),
    publishing_history(user_publishing_history),
    series(user_series), related_titles(user_related_titles),
    other_forms_of_title(user_other_forms_of_title),
    govt_doc_number(user_govt_doc_number)
{}

Periodic::~Periodic()
{}

void Periodic::display() const
{
  Media::display();
  cout << "author: " << author;
  cout << "description: " << description;
  cout << "publisher: " << publisher;
  cout << "publishing_history: " << publishing_history;
  cout << "series: " << series;
  cout << "related_titles: " << related_titles;
  cout << "other_forms_of_title: " << other_forms_of_title;
  cout << "govt_doc_number: " << govt_doc_number;
  cout << endl;
}


bool Periodic::compareByOther(const string &user_other) const
{
  if(description.find(user_other) != std::string::npos){
    return true;
  }
  else if(Media::notes.find(user_other) != std::string::npos){
    return true;
  }
  else if(series.find(user_other) != std::string::npos){
    return true;
  }
  else if(related_titles.find(user_other) != std::string::npos){
    return true;
  }
  else{
    return false;
  }
}
