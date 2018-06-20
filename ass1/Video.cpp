#include "Video.h"
#include "Media.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Video::Video(const string &user_call_number,const string &user_title,
  const string &user_subjects,const string &user_description,
  const string &user_distributor,const string &user_notes,
  const string &user_series,const string &user_label):Media(user_call_number,
    user_title,user_subjects,user_notes), description(user_description),
    distributor(user_distributor), series(user_series), label(user_label)
{}

Video::~Video()
{}

void Video::display() const
{
  Media::display();
  cout << "description: " << description;
  cout << "distributor: " << distributor;
  cout << "series: " << series;
  cout << "label: " << label;
  cout << endl;
}


bool Video::compareByOther(const string &user_other) const
{
  if(description.find(user_other) != std::string::npos){
    return true;
  }
  else if(Media::notes.find(user_other) != std::string::npos){
    return true;
  }
  else if(distributor.find(user_other) != std::string::npos){
    return true;
  }
  else{
    return false;
  }
}
