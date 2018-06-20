#ifndef Video_H
#define Video_H
#include "Media.h"
#include<string>
using namespace std;

class Video: public Media {
  private:
    //Media m;
    string description;
    string distributor;
    string series;
    string label;
  public:
    Video(const string &user_call_number,const string &user_title,
      const string &user_subjects, const string &user_description,
      const string &user_distributor,const string &user_notes,
      const string &user_series, const string &user_label);
    ~Video();
    void display() const;
    bool compareByOther(const std::string &other) const;

};
#endif
