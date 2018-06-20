#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "CardCatalog.h"
#include "Media.h"
#include "Book.h"
#include "Video.h"
#include "Film.h"
#include "Periodic.h"
using namespace std;

CardCatalog::CardCatalog(){
  // get data in memory
  readBooks();
  readFilms();
  readVideos();
  readPeriodic();
}

void CardCatalog::showRecords(){
  for(int i = 0 ; i < cards.size(); i++){
    cards[i]->display();
  }
}

void CardCatalog::display(const vector<Media *> &output) const{
  int bookCount =0;
  int filmCount = 0;
  int videoCount = 0;
  int periodicCount = 0;

  for(int i = 0 ; i < output.size(); i++){
    output[i]->display();

    if (Book * obj = dynamic_cast<Book *>(output[i])) {
        bookCount++;
    }
    else if(Film * obj = dynamic_cast<Film *>(output[i])) {
        filmCount++;
    }
    else if(Video * obj = dynamic_cast<Video *>(output[i])) {
        videoCount++;
    }
    else if(Periodic * obj = dynamic_cast<Periodic *>(output[i])) {
        periodicCount++;
    }
    else{

    }
  }
  cout << "Total matching results count: " << output.size() << endl;
  cout << "Total Books count: " << bookCount << endl;
  cout << "Total Films count: " << filmCount << endl;
  cout << "Total Video count: " << videoCount  << endl;
  cout << "Total Periodic count: " << periodicCount  << endl;
}


CardCatalog::~CardCatalog()
{
  // free memory in private vector cards
  for(int i = 0 ; i < cards.size(); i++){
    delete cards[i];
  }
}

void CardCatalog::readBooks(){
  std::ifstream inf("book.txt");
  string user_call_number;
  while(!std::getline(inf, user_call_number, '|').eof())
  {
    Book * bk;
    std::string user_title;
    std::string user_subjects;
    std::string user_author;
    std::string user_description;
    std::string user_publisher;
    std::string user_city;
    std::string user_year;
    std::string user_series;
    std::string user_notes;
    //std::getline(inf, user_call_number, '|'); //#read thru pipe
    std::getline(inf, user_title, '|'); //#read thru pipe
    std::getline(inf, user_subjects, '|'); //#read thru pipe
    std::getline(inf, user_author, '|'); //#read thru pipe
    std::getline(inf, user_description, '|'); //#read thru pipe
    std::getline(inf, user_publisher, '|'); //#read thru pipe
    std::getline(inf, user_city, '|'); //#read thru pipe
    std::getline(inf, user_year, '|'); //#read thru pipe
    std::getline(inf, user_series, '|'); //#read thru pipe
    std::getline(inf, user_notes);        //#read thru newline
    bk = new Book(user_call_number,user_title,user_subjects,
      user_author,user_description,user_publisher,user_city,
      user_year,user_series,user_notes);

    cards.push_back(bk);
  }
}


void CardCatalog::readPeriodic(){
  std::ifstream inf("periodic.txt");
  string user_call_number;
  while(!std::getline(inf, user_call_number, '|').eof())
  {
    Periodic * pd;
    std::string user_title;
    std::string user_subjects;
    std::string user_author;
    std::string user_description;
    std::string user_publisher;
    std::string user_publishing_history;
    std::string user_series;
    std::string user_notes;
    std::string user_related_titles;
    std::string user_other_forms_of_title;
    std::string user_govt_doc_number;
    //std::getline(inf, user_call_number, '|'); //#read thru pipe
    std::getline(inf, user_title, '|'); //#read thru pipe
    std::getline(inf, user_subjects, '|'); //#read thru pipe
    std::getline(inf, user_author, '|'); //#read thru pipe
    std::getline(inf, user_description, '|'); //#read thru pipe
    std::getline(inf, user_publisher, '|'); //#read thru pipe
    std::getline(inf, user_publishing_history, '|'); //#read thru pipe
    std::getline(inf, user_series, '|'); //#read thru pipe
    std::getline(inf, user_notes, '|'); //#read thru pipe
    std::getline(inf, user_related_titles, '|'); //#read thru pipe
    std::getline(inf, user_other_forms_of_title, '|'); //#read thru pipe
    std::getline(inf, user_govt_doc_number);        //#read thru newline
    pd = new Periodic(user_call_number,user_title,user_subjects,
      user_author,user_description,user_publisher,user_publishing_history,
      user_series,user_notes,user_related_titles,user_other_forms_of_title,
      user_govt_doc_number);

    cards.push_back(pd);
  }
}



void CardCatalog::readFilms(){
  std::ifstream inf("film.txt");
  string user_call_number;
  while(!std::getline(inf, user_call_number, '|').eof())
  {
    Film * fm;
    std::string user_title;
    std::string user_subjects;
    std::string user_director;
    std::string user_notes;
    std::string user_year;
    //std::getline(inf, user_call_number, '|'); //#read thru pipe
    std::getline(inf, user_title, '|'); //#read thru pipe
    std::getline(inf, user_subjects, '|'); //#read thru pipe
    std::getline(inf, user_director, '|'); //#read thru pipe
    std::getline(inf, user_notes, '|'); //#read thru pipe
    std::getline(inf, user_year);
    fm = new Film(user_call_number,user_title,user_subjects,
      user_director,user_notes,user_year);

    cards.push_back(fm);
  }
}


void CardCatalog::readVideos(){
  std::ifstream inf("video.txt");
  string user_call_number;
  while(!std::getline(inf, user_call_number, '|').eof())
  {
    Video * vd;
    std::string user_title;
    std::string user_subjects;
    std::string user_description;
    std::string user_distributor;
    std::string user_notes;
    std::string user_series;
    std::string user_year;
    //std::getline(inf, user_call_number, '|'); //#read thru pipe
    std::getline(inf, user_title, '|'); //#read thru pipe
    std::getline(inf, user_subjects, '|'); //#read thru pipe
    std::getline(inf, user_description, '|'); //#read thru pipe
    std::getline(inf, user_distributor, '|'); //#read thru pipe
    std::getline(inf, user_notes, '|'); //#read thru pipe
    std::getline(inf, user_series, '|'); //#read thru pipe
    std::getline(inf, user_year);
    vd = new Video(user_call_number,user_title,user_subjects,
      user_description,user_distributor,user_notes,user_series,user_year);

    cards.push_back(vd);
  }
}


vector<Media *> CardCatalog::searchByTitle(const string &user_title) const{

  //cout << "in search by title with input:" << user_title << endl;
  vector<Media *> output;
  //cout << "cards size: " << cards.size() << endl;
  for(int i = 0; i < cards.size(); i++){
    if(cards[i]->compareByTitle(user_title)){
      output.push_back(cards[i]);
    }
  }
  return output;
}


vector<Media *> CardCatalog::searchByCallNumber(const string &user_call_number) const{
  vector<Media *> output;
  for(int i = 0; i < cards.size(); i++){
    if(cards[i]->compareByCallNumber(user_call_number)){
      output.push_back(cards[i]);
    }
  }
  return output;
}


vector<Media *> CardCatalog::searchBySubjects(const string &user_subjects) const{
  vector<Media *> output;
  for(int i = 0; i < cards.size(); i++){
    if(cards[i]->compareBySubjects(user_subjects)){
      output.push_back(cards[i]);
    }
  }
  return output;
}

vector<Media *> CardCatalog::searchByOthers(const string &user_other) const{
  vector<Media *> output;
  for(int i = 0; i < cards.size(); i++){
    if(cards[i]->compareByOther(user_other)){
      output.push_back(cards[i]);
    }
  }
  return output;
}
