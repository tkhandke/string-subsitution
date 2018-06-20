#ifndef CardCatalog_H
#define CardCatalog_H
#include <iostream>
#include <vector>
#include <string>
#include "Media.h"
#include "Book.h"
#include "Film.h"
#include "Video.h"
#include "Periodic.h"
using namespace std;

class CardCatalog {
  private:
    vector<Media *> cards;
    void readBooks();
    void readFilms();
    void readVideos();
    void readPeriodic();

  public:
    vector<Media *> searchByTitle(const string &user_title) const;
    vector<Media *> searchByCallNumber(const string &user_call_number) const;
    vector<Media *> searchBySubjects(const string &user_subjects) const;
    vector<Media *> searchByOthers(const string &user_other) const;
    void display(const vector<Media *> &output) const;
    CardCatalog(); // We will read media files in this
    ~CardCatalog(); // empty the cards vector in which all library records are read

    void showRecords();

};
#endif
